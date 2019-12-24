#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "bigInt.h"

using namespace std;

TEST_CASE("constructors") 
{
	//test driven development
	SECTION("no-args ctor") 
	{
		//REQUIRE(BigInt().toStr() == "0");
	}

	SECTION("ctor BigInt(str)")
	{
		REQUIRE(BigInt("123").toStr() == "123");
		REQUIRE(BigInt("+123").toStr() == "123");
		REQUIRE(BigInt("-123").toStr() == "-123");
		REQUIRE(BigInt("       123        ").toStr() == "123");
		REQUIRE(BigInt("0000").toStr() == "0");
		REQUIRE(BigInt("00123").toStr() == "123");

		REQUIRE_THROWS_AS(BigInt("      "), runtime_error);
		REQUIRE_THROWS_AS(BigInt("hello"), runtime_error);
		REQUIRE_THROWS_AS(BigInt("1  2"), runtime_error);
		REQUIRE_THROWS_AS(BigInt("123j1221"), runtime_error);
		REQUIRE_THROWS_AS(BigInt("++122"), runtime_error);
		REQUIRE_THROWS_AS(BigInt("---123"), runtime_error);
	}
	SECTION("ctor BigInt(int)")
	{
		REQUIRE(BigInt(555).toStr() == "555");
		REQUIRE(BigInt("+123").toStr() == "123");
		REQUIRE(BigInt("-123").toStr() == "-123");
		REQUIRE(BigInt("       123        ").toStr() == "123");
		REQUIRE(BigInt("0000").toStr() == "0");
		REQUIRE(BigInt("00123").toStr() == "123");

		REQUIRE_THROWS_AS(BigInt("      "), runtime_error);
		REQUIRE_THROWS_AS(BigInt("hello"), runtime_error);
		REQUIRE_THROWS_AS(BigInt("1  2"), runtime_error);
		REQUIRE_THROWS_AS(BigInt("123j1221"), runtime_error);
		REQUIRE_THROWS_AS(BigInt("++122"), runtime_error);
		REQUIRE_THROWS_AS(BigInt("---123"), runtime_error);
	}
}
TEST_CASE("operator+")
{
		for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				BigInt z = a + b;
				REQUIRE(z.toStr() == to_string((i + j))); 
			}
		}
		
}	

TEST_CASE("operator-")
{
		for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				BigInt z = a - b;
				REQUIRE(z.toStr() == to_string((i - j))); 
			}
		}
}
TEST_CASE("operator==") 
{
		for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				bool z = a == b;
				REQUIRE(z == (i == j)); 
			}
		}	
		
}
TEST_CASE("operator!=") 
{
		for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				bool z = a != b;
				REQUIRE(z == (i != j)); 
			}
		}
}
TEST_CASE("operator>") 
{
		for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				bool z = a > b;
				REQUIRE(z == (i > j)); 
			}
		}
}
TEST_CASE("operator<") 
{
		for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				bool z = a < b;
				REQUIRE(z == (i < j)); 
			}
		}
}
TEST_CASE("operator>=") 
{
		for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				bool z = a >= b;
				REQUIRE(z == (i >= j)); 
			}
		}
}
TEST_CASE("operator<=") 
{
		for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				bool z = a <= b;
				REQUIRE(z == (i <= j)); 
			}
		}
}
TEST_CASE("operator+=") 
{
		for(int i = 1; i < 1000; i++) {
			for(int j = 1; j < 1000; j++) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				a += b;
				i += j;
				REQUIRE(a.toStr() == to_string(i)); 
			}
		}
}
TEST_CASE("operator-=") 
{
		for(int i = 1000000; i > -1000; i--) {
			int j = 1;
			BigInt a = to_string(i);
			BigInt b = to_string(j);
			a -= b;
			REQUIRE(a.toStr() == to_string(i - j));
		}
}

TEST_CASE("operator--") 
{
		for(int i = 1000000; i > 0; ){
				BigInt a = to_string(i);
				--a;
				REQUIRE(a.toStr() == to_string(--i));
		}
}
TEST_CASE("operator++") 
{
		for(int i = 0; i <1000000;){
				BigInt a = to_string(i);
				++a;
				REQUIRE(a.toStr() == to_string(++i));
		}
}
TEST_CASE("operator--(int)") 
{

		
		for(int i = 1000; i > -1000; i--) {
			BigInt x = to_string(i);
			BigInt y = to_string(10);
			REQUIRE((x--).toStr() == to_string(i--));
		}
		
		
}

TEST_CASE("operator++(int)") 
{

		///DOES NOT WORK YET!!
		for(int i = -1000; i < 1000; i++) {
			BigInt x = to_string(i);
			BigInt y = to_string(10);
			REQUIRE((x++).toStr() == to_string(i++));
		}
		
		
}

TEST_CASE("fuction abs") {
		//DOES NOT WORK
		for(int i = 1000; i > -1000; i--){
				BigInt a = to_string(i);
				BigInt b = BigInt::abs(a);
				REQUIRE(b.toStr() == to_string(abs(i)));
		}
		
}

TEST_CASE("operator*")
{
	for(int i = -1000; i < 1000; i++) {
		for(int j = -1000; j < 1000; j++) {
			BigInt a = to_string(i);
			BigInt b = to_string(j);
			BigInt z = a * b; 
			REQUIRE(z.toStr() == to_string(i * j));
		}
	}
	BigInt a = to_string(896);
	BigInt b = to_string(78);
	BigInt z = a * b; 
	REQUIRE(z.toStr() == to_string(896 * 78));
}
TEST_CASE("operator*=")
{
	for(int i = -1000; i < 1000; i++) {
		for(int j = -1000; j < 1000; j++) {
			int k = i;
			int l = j;
			BigInt a = to_string(k);
			BigInt b = to_string(l);
			a *= b; 
			k *= l;
			REQUIRE(a.toStr() == to_string(k));
			
		}
	}

}

TEST_CASE("unary operator+")
{
	for(int i = -1000000; i < 1000000; i++) {
		BigInt a = i;
		BigInt b = +a;
		REQUIRE(b.toStr() == to_string(i));
	}

}
TEST_CASE("unary operator-")
{
	for(int i = -1000000; i < 1000000; i++) {
		BigInt a = i;
		BigInt b = -a;
		REQUIRE(b.toStr() == to_string(-i));
	}
}


TEST_CASE("output")
{
	BigInt r("111111111111111111111111");
	cout << r;
}



/*TEST_CASE("input and output") {
	BigInt a, b;
	cin >> a >> b;
	cout << a * b;
}*/
/*TEST_CASE("input")
{
	BigInt r;
	cin >> r;
	REQUIRE(r.toStr() == to_string(20));
}*/