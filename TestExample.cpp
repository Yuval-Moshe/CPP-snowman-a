/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

#include <stdexcept>

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code")
{
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
	CHECK(nospaces(snowman()) == nospaces());
}

TEST_CASE("False Input - Input Too Long / Input Too Short")
{
	CHECK_THROWS_AS(snowman(1243124),std::exception)); // Length = 7;
	CHECK_THROWS_AS(snowman(134214),std::exception)); // Length = 6;
	CHECK_THROWS_AS(snowman(143244123),std::exception));// Length = 9;
	CHECK_THROWS_AS(snowman(1),std::exception));// Length = 1;
	CHECK_THROWS_AS(snowman(123),std::exception));// Length = 3;
	CHECK_THROWS_AS(snowman(1243224123),std::exception));// Length = 10;
}

TEST_CASE("False Input - Inserted Out of Range Numbers ( > 4 || < 1)")
{
	CHECK_THROWS_AS(snowman(52134221),std::out_of_range)); // (5)
	CHECK_THROWS_AS(snowman(26412321),std::out_of_range)); // (6)
	CHECK_THROWS_AS(snowman(41732143),std::out_of_range));// (7)
	CHECK_THROWS_AS(snowman(412-14123),std::out_of_range));// (-1)
	CHECK_THROWS_AS(snowman(1243-4412),std::out_of_range));// (-4)
	CHECK_THROWS_AS(snowman(88812341),std::out_of_range));// (8) x 3
	CHECK_THROWS_AS(snowman(123-1-2-342),std::out_of_range));// (-1), (-2), (-3)
}

TEST_CASE("Flase Input - Input is Not an Int")
{
	CHECK_THROWS(snowman("Hey")); // string
	CHECK_THROWS(snowman('c'));	  // char
	CHECK_THROWS(snowman(1.0));	  // double
}

/* Add more test cases here *