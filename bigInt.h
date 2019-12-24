
#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <iostream>

class BigInt 
{
	friend std::istream& operator>> (std::istream& in,  BigInt& x);
	friend std::ostream& operator<< (std::ostream& outp, const BigInt& x);
	friend BigInt operator+ (const BigInt& x, const BigInt& y);
	friend BigInt operator- (const BigInt& x, const BigInt& y);
	friend BigInt operator* (const BigInt& x, const BigInt& y);
	friend BigInt operator/ (const BigInt& x, const BigInt& y);

	friend BigInt operator+= (BigInt& x, const BigInt& y);
	friend BigInt operator-= (BigInt& x, const BigInt& y);
	friend BigInt operator*= (BigInt& x, const BigInt& y);
	friend BigInt operator--(BigInt& x);
	friend BigInt operator++(BigInt& x);

	friend const BigInt operator--(BigInt& x, int);
	friend const BigInt operator++(BigInt& x, int);

	friend BigInt operator+(BigInt& x);
	friend BigInt operator-(BigInt& x);

	friend bool operator== (const BigInt& x, const BigInt& y);
	friend bool operator!= (const BigInt& x, const BigInt& y);
	friend bool operator> (const BigInt& x, const BigInt& y);
	friend bool operator>= (const BigInt& x, const BigInt& y);
	friend bool operator< (const BigInt& x, const BigInt& y);
	friend bool operator<= (const BigInt& x, const BigInt& y);
	static BigInt substrNumbers(const BigInt& x, const BigInt& y);
	static BigInt addAbsNumbers(const BigInt& x, const BigInt& y);
	static BigInt multAbsNumbers(const BigInt& x, const BigInt& y);
	//static BigInt divAbsNumbers(const BigInt& x, const BigInt& y);
	std::vector<int> mDigits;
	bool isNegative;
	void eraseleadingZeroes();
	static bool isBigger(const BigInt& x, const BigInt& y);
	

public:
	BigInt()
		:isNegative(false)
	{
		mDigits.push_back(0);
	}

	BigInt(const std::string& s);

	BigInt(const int& s);
	std::string toStr() const;
	
	static BigInt abs(BigInt& x);
};
std::istream& operator>> (std::istream& in,  BigInt& x);
std::ostream& operator<< (std::ostream& outp, const BigInt& x);
BigInt operator+(const BigInt& x, const BigInt& y);
BigInt operator- (const BigInt& x, const BigInt& y);
BigInt operator* (const BigInt& x, const BigInt& y);
BigInt operator/ (const BigInt& x, const BigInt& y);


BigInt operator+= (BigInt& x, const BigInt& y);
BigInt operator-= (BigInt& x, const BigInt& y);
BigInt operator*= (BigInt& x, const BigInt& y);
BigInt operator--(BigInt& x);
BigInt operator++(BigInt& x);
const BigInt operator--(BigInt& x, int);
const BigInt operator++(BigInt& x, int);
BigInt operator+(BigInt& x);
BigInt operator-(BigInt& x);

bool operator== (const BigInt& x, const BigInt& y);
bool operator!= (const BigInt& x, const BigInt& y);
bool operator> (const BigInt& x, const BigInt& y);
bool operator< (const BigInt& x, const BigInt& y);
bool operator>= (const BigInt& x, const BigInt& y);
bool operator<= (const BigInt& x, const BigInt& y);


