#include "bigInt.h"
#include <cstddef>
#include <iostream>
#include <cassert>
#include <limits>
#include <stdexcept>
#include <sstream>
using namespace std;
const size_t MaxSizeT = numeric_limits<size_t>::max();
BigInt::BigInt(const string& s) 
	: isNegative(false)
{
	size_t i = 0;//    12
	while(i < s.size() and isspace(s[i])) {
		++i;
	}
	if(i == s.size())
	{
		throw runtime_error("BigInt(str): incorrect str");
	}
	if(s[i] == '+' or s[i] == '-') {
		isNegative = s[i] == '-';
		++i;
	}
	while(i < s.size() and isdigit(s[i])) {
		mDigits.push_back(s[i] - '0');
		++i;
	}
	while(i < s.size() and isspace(s[i])) {
		++i;
	}
	if(i != s.size()) {
		throw runtime_error("BigInt(str): incorrect str");
	}
	eraseleadingZeroes();

}

BigInt::BigInt(const int& n)
	:isNegative(false)
{
	string s = to_string(n);
	size_t i = 0;
	if(s[i] == '-') {
		isNegative = s[i] == '-';
		++i;
	}
	while(i < s.size() and isdigit(s[i])) {
		mDigits.push_back(s[i] - '0');
		++i;
	}
}



string BigInt::toStr() const 
{
	string r;

	if(isNegative) {
		r += "-";
	}

	for(auto d: mDigits)
	{
		//r += to_string(d);
		r += char(d + '0');
	}
	return r;
}

void BigInt::eraseleadingZeroes(){
	while(1 < mDigits.size() and mDigits[0] == 0)
	{
		mDigits.erase(mDigits.begin());
	}
}
istream& operator>> (istream& in,  BigInt& x)
{
	string a;
	int o;
	if(in >> a) {
		x = BigInt(a);
		return in;
	}
	if(in >> o) {
		x = BigInt(0);
		return in;
	}
	throw runtime_error("operator>>: not implemented yet");
			
}

ostream& operator<< (ostream& outp,const BigInt& x)
{
	return outp << x.toStr();			
}

BigInt operator+ (const BigInt& x, const BigInt& y)
{
	if(x.isNegative == y.isNegative) {
		BigInt r = BigInt::addAbsNumbers(x, y);
		r.isNegative = x.isNegative;
		return r;
	} else if(x.isNegative){
		BigInt r = BigInt::substrNumbers(x, y);
		if(BigInt::isBigger(x, y)) r.isNegative = x.isNegative;
		return r;
	} else if(y.isNegative){
		BigInt r = BigInt::substrNumbers(x, y);
		if(!(BigInt::isBigger(x, y)) && (r.mDigits[0]!=0)) r.isNegative = y.isNegative;
		return r;
	} 
	throw runtime_error("operator+: not implemented yet");


}
BigInt operator- (const BigInt& x, const BigInt& y)
{
	if(x.isNegative == y.isNegative) {
		BigInt r = BigInt::substrNumbers(x, y);
		if(x.isNegative) {
			if(BigInt::isBigger(x, y)) {
				r.isNegative = x.isNegative;
			}
		} else {
			if(!(BigInt::isBigger(x, y)) && (r.mDigits[0]!=0)) {
				r.isNegative = true;
			}
		}
		return r;
	} else if(x.isNegative or y.isNegative) {
		BigInt r = BigInt::addAbsNumbers(x,y);
		r.isNegative = x.isNegative;
		return r;
	} throw runtime_error("operator+: not implemented yet");
}

BigInt operator* (const BigInt& x, const BigInt& y)
{
	BigInt r = BigInt::multAbsNumbers(x, y);
	if(x.isNegative == y.isNegative or r.mDigits[0] == 0) {
		r.isNegative = false;
	} else r.isNegative = true;
	return r;
}
/*BigInt operator/ (const BigInt& x, const BigInt& y) 
{
	BigInt r = BigInt::divAbsNumbers(x,y);
	if(x.isNegative == y.isNegative or r.mDigits[0] == 0) {
		r.isNegative = false;
	} else r.isNegative = true;
	return r;
}*/

BigInt operator*= (BigInt& x, const BigInt& y)
{
	x = x * y;
	return y;
} 

BigInt operator+= (BigInt& x, const BigInt& y)
{
	x = x + y;
	return x;
}
BigInt operator-= (BigInt& x, const BigInt& y)
{
	x = x - y;
	return x;
}
BigInt operator--(BigInt& x)
{
	x -= BigInt("1");
	return x;
}
BigInt operator++(BigInt& x)
{
	x += BigInt("1");
	return x;
}
const BigInt operator--(BigInt& x, int)
{
	BigInt z = x;
	--x;
	return z;
}
const BigInt operator++(BigInt&x, int) 
{
	BigInt z = x;
	++x;
	return z;
}

BigInt operator+(BigInt& x)
{
	return x;
}
BigInt operator-(BigInt& x)
{
	if(x.isNegative or x.mDigits[0] == 0) x.isNegative = false;
	else x.isNegative = true;
	return x;
}
bool operator== (const BigInt& x, const BigInt& y)
{
	BigInt r = x - y;
	if(r.toStr() == "0") return true;
	else return false;
}
bool operator!= (const BigInt& x, const BigInt& y)
{
	BigInt r = x - y;
	if(r.toStr() == "0") return false;
	else return true;
}

bool operator> (const BigInt& x, const BigInt& y) 
{
	BigInt r = x - y;
	if(r.toStr() != "0" and !(r.isNegative)) return true;
	else return false;
}
bool operator< (const BigInt& x, const BigInt& y) 
{
	BigInt r = x - y;
	if(r.toStr() != "0" and r.isNegative) return true;
	else return false;
}
bool operator>= (const BigInt& x, const BigInt& y)
{
	BigInt r = x - y;
	if(r.toStr() == "0" or !(r.isNegative)) return true;
	else return false;
}
bool operator<= (const BigInt& x, const BigInt& y)
{
	BigInt r = x - y;
	if(r.toStr() == "0" or r.isNegative) return true;
	else return false;
}

BigInt BigInt::substrNumbers(const BigInt& x, const BigInt& y) 
{
	BigInt r;
	r.mDigits.resize(max(x.mDigits.size(), y.mDigits.size()));
	
	size_t i = x.mDigits.size() - 1;
	size_t j = y.mDigits.size() - 1;
	size_t k = r.mDigits.size() - 1;

	vector<int> temp1 = x.mDigits;
	vector<int> temp2 = y.mDigits;
	int c = 0; 
	int s = 0;
	size_t t1 = i;
	size_t t2 = j;
	if(!(BigInt::isBigger(x, y))){
		temp1 = y.mDigits;
		temp2 = x.mDigits;
		t1 = j;
		t2 = i;

	}//-1 22
		while(t1 != MaxSizeT or t2 != MaxSizeT) {
		      if(t1 != MaxSizeT) {
		        c = temp1[t1] + s;//2
		        --t1;
		        s = 0;
		      }
		      if(t2 != MaxSizeT) {
		        c -= temp2[t2];
		        --t2;
		      }
		      if(c < 0) {
		        c+=10;
		        s -= 1;
		      }
			
			r.mDigits[k] = c;
    		k--;

	 
	}
  	r.eraseleadingZeroes();
  	return r;
}
BigInt BigInt::addAbsNumbers(const BigInt& x, const BigInt& y) 
{
	BigInt r;
	r.mDigits.resize(max(x.mDigits.size(), y.mDigits.size()) + 1);
	size_t i = x.mDigits.size() - 1;
	size_t j = y.mDigits.size() - 1;
	size_t k = r.mDigits.size() - 1;


	int carry = 0;
	while(i != MaxSizeT or j != MaxSizeT) {
	  
	    int c = carry;
	    if (i != MaxSizeT) {
	      c += x.mDigits[i];
	      i--;

	    }
	    if (j != MaxSizeT) {
	      c += y.mDigits[j];
	      j--;

	    }

	    r.mDigits[k] = c % 10;
	    carry = c / 10;
	    k--;
	}
	if (carry != 0) {
	    r.mDigits[0] = carry;
	} else {
	    r.mDigits.erase(r.mDigits.begin());
	}
	  
	  return r;
}

BigInt BigInt::multAbsNumbers(const BigInt& x, const BigInt& y)
{	
	BigInt r;
 	if(x.mDigits.size() == 1 or y.mDigits.size() == 1) 
	 r.mDigits.resize(max(x.mDigits.size(), y.mDigits.size()) + 1, 0);
  	else r.mDigits.resize(x.mDigits.size() + y.mDigits.size(), 0);
	
	size_t i = x.mDigits.size() - 1;
	size_t j = y.mDigits.size() - 1;
	size_t k = r.mDigits.size() - 1;

	vector<int> temp1 = x.mDigits;
	vector<int> temp2 = y.mDigits;
	int c = 0; 
	int s = 0;
	size_t t1 = i;
	size_t t2 = j;
	if(!(BigInt::isBigger(x, y))){
		temp1 = y.mDigits;
		temp2 = x.mDigits;
		t1 = j;
		t2 = i;
	}
	size_t q = 1;
	size_t h = t1;
	
	while(t2 != MaxSizeT) {
		h = t1;
		while(h != MaxSizeT) {
		c = temp1[h] * temp2[t2] + s;  
		r.mDigits[k] += c % 10;
		if(r.mDigits[k] > 9) {
			r.mDigits[k - 1] += r.mDigits[k] / 10; 
			r.mDigits[k] %= 10;
		}
		h--;
		s = c / 10;
		k--;
		}
		if(h == MaxSizeT) {
			if(s > 0) r.mDigits[k] += s;
		}
		t2--;
		s = 0;
		++q;  
		k = r.mDigits.size() - q;
		
	}
	r.eraseleadingZeroes();
	return r;
}
/*BigInt BigInt::divAbsNumbers(const BigInt& x, const BigInt& y)
{
	

}
*/
bool BigInt::isBigger(const BigInt& x, const BigInt& y) {
	if(x.mDigits.size() > y.mDigits.size()) {
		return true;
	}
	else if(x.mDigits.size() < y.mDigits.size()) {
		return false;
	}
	for(size_t i= 0; i < x.mDigits.size(); i++) {
		if(x.mDigits[i] > y.mDigits[i]) {
			return true;
		}
		else if (x.mDigits[i] < y.mDigits[i]) {
			return false;
		}
	}
	return false;

}
BigInt BigInt::abs(BigInt& x)
{
	x.isNegative = false;
	return x;
}