
#pragma once
#include <vector>
#include <string>
#include <stdexcept>

class BigInt 
{
	friend BigInt operator+ (const BigInt& x, const BigInt& y);
	friend BigInt operator- (const BigInt& x, const BigInt& y);

	friend BigInt operator+= (BigInt& x, const BigInt& y);
	friend BigInt operator-= (BigInt& x, const BigInt& y);
	friend BigInt operator--(BigInt& x);
	friend BigInt operator++(BigInt& x);
	friend const BigInt operator--(BigInt& x, int);

	friend bool operator== (const BigInt& x, const BigInt& y);
	friend bool operator> (const BigInt& x, const BigInt& y);
	friend bool operator< (const BigInt& x, const BigInt& y);
	static BigInt substrNumbers(const BigInt& x, const BigInt& y);
	static BigInt addAbsNumbers(const BigInt& x, const BigInt& y);
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

	std::string toStr() const;
};

BigInt operator+(const BigInt& x, const BigInt& y);
BigInt operator- (const BigInt& x, const BigInt& y);

BigInt operator+= (BigInt& x, const BigInt& y);
BigInt operator-= (BigInt& x, const BigInt& y);
BigInt operator--(BigInt& x);
BigInt operator++(BigInt& x);
const BigInt operator--(BigInt& x, int);


bool operator== (const BigInt& x, const BigInt& y);
bool operator> (const BigInt& x, const BigInt& y);
bool operator< (const BigInt& x, const BigInt& y);



