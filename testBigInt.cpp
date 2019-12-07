#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "bigInt.h"

using namespace std;

TEST_CASE("Constructors") 
{
	//test driven development
	SECTION("no-args ctor") 
	{

		//REQUIRE(BigInt().toStr() == "0");
	}

	SECTION("ctor BigInt(str)")
	{
		/*REQUIRE(BigInt("123").toStr() == "123");
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
		REQUIRE_THROWS_AS(BigInt("---123"), runtime_error);*/
	}
	SECTION("operator+")
	{
	/*
		for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				BigInt z = a + b;
				REQUIRE(z.toStr() == to_string((i + j))); 
			}
		}
		*/
		
	}
	
	SECTION("operator-")
	{
		/*for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				BigInt z = a - b;
				REQUIRE(z.toStr() == to_string((i - j))); 
			}
		}*/
	}
	SECTION("operator==") 
	{
		/*for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				bool z = a == b;
				REQUIRE(z == (i == j)); 
			}
		*/
	}
	SECTION("operator>") {
		/*for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				bool z = a > b;
				REQUIRE(z == (i > j)); 
			}
		*/
	}
	SECTION("operator<") {
		/*for(int i = 1000; i > -1000; i--) {
			for(int j = 1000; j > -1000; j--) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				bool z = a < b;
				REQUIRE(z == (i < j)); 
			}
		*/
	}
	SECTION("operator+=") {
		/*for(int i = 1; i < 1000; i++) {
			for(int j = 1; j < 1000; j++) {
				BigInt a = to_string(i);
				BigInt b = to_string(j);
				a += b;
				i += j;
				REQUIRE(a.toStr() == to_string(i)); 
			}
		}*/
	}
	SECTION("operator-=") {
		/*for(int i = 1000000; i > -1000; i--) {
			int j = 1;
			BigInt a = to_string(i);
			BigInt b = to_string(j);
			a -= b;
			REQUIRE(a.toStr() == to_string(i - j));
		}*/
	}

	SECTION("operator--") {
		/*for(int i = 1000000; i > 0; ){
				BigInt a = to_string(i);
				--a;
				REQUIRE(a.toStr() == to_string(--i));
		}*/
	}
	SECTION("operator++") {
		/*for(int i = 0; i <1000000;){
				BigInt a = to_string(i);
				++a;
				REQUIRE(a.toStr() == to_string(++i));
		}*/
	}

	SECTION("operator++(int)") {

		///DOES NOT WORK YET!!
		/*
		int i = 10;
		BigInt x = to_string(i);
		BigInt y = to_string(10);
		x--;
		REQUIRE(x.toStr() == to_string(i--));*/
	}



}





