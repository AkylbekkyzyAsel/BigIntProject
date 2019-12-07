#include "bigInt.h"
#include <cstddef>
#include<iostream>
#include <limits>
#include <stdexcept>
using namespace std;
const size_t MaxSizeT = numeric_limits<size_t>::max();
BigInt::BigInt(const std::string& s) 
	: isNegative(false)
{
	size_t i = 0;
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
	size_t i = 0; 
	while(i + 1 < mDigits.size() and mDigits[0] == 0)
	{
		mDigits.erase(mDigits.begin());
	}
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
{// -5 - -3
	//-3 - -5
	// 5 - 3 
	// 3 - 5


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
	return BigInt(z);
}
bool operator== (const BigInt& x, const BigInt& y)
{
	BigInt r = x - y;
	if(r.toStr() == "0") return true;
	else return false;


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