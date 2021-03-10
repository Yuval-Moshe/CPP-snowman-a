/**
 * Tests for snowman-a.
 *
 * AUTHOR: Yuval Moshe
 * 
 * Date: 2021-03
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

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
    // Mixed Options:
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(33232124)) == nospaces("  _  \n /_\\\n(\\(o_O)\n (] [)>\n (   )"));
    CHECK(nospaces(snowman(12222212)) == nospaces("_===_\n\\(o.o)/\n( : )\n (\" \")"));
    CHECK(nospaces(snowman(44444432)) == nospaces("  ___\n (_*_)\n(- -)\n(> <)\n (\" \")"));
    CHECK(nospaces(snowman(22222222)) == nospaces("  ___\n .....\n\\(o.o)/\n (] [)\n (\" \")"));
    CHECK(nospaces(snowman(12341214)) == nospaces("_===_\n (O.-)/\n<( : )\n (   )"));
    CHECK(nospaces(snowman(23232223)) == nospaces("  ___\n .....\n\\(o_O)/\n (] [)\n (___)"));
    CHECK(nospaces(snowman(31311411)) == nospaces("  _  \n /_\\\n (._.)\n<(   )>\n( : )"));
    CHECK(nospaces(snowman(14243341)) == nospaces("_===_\n (o -)\n/(   )\\\n ( : )"));

    // Hat:
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));       // (1)
    CHECK(nospaces(snowman(21111111)) == nospaces(" ___\n.....\n(.,.)\n<( : )>\n( : )")); // (2)
    CHECK(nospaces(snowman(31111111)) == nospaces(" _ \n/_\\\n(.,.)\n<( : )>\n( : )"));   // (3)
    CHECK(nospaces(snowman(41111111)) == nospaces(" ___\n(_*_)\n(.,.)\n<( : )>\n( : )")); // (4)

    // Nose/Mouth:
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // (1)
    CHECK(nospaces(snowman(12111111)) == nospaces("_===_\n(...)\n<( : )>\n( : )")); // (2)
    CHECK(nospaces(snowman(13111111)) == nospaces("_===_\n(._.)\n<( : )>\n( : )")); // (3)
    CHECK(nospaces(snowman(14111111)) == nospaces("_===_\n(. .)\n<( : )>\n( : )")); // (4)

    // Left Eye:
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // (1)
    CHECK(nospaces(snowman(11211111)) == nospaces("_===_\n(o,.)\n<( : )>\n( : )")); // (2)
    CHECK(nospaces(snowman(11311111)) == nospaces("_===_\n(O,.)\n<( : )>\n( : )")); // (3)
    CHECK(nospaces(snowman(11411111)) == nospaces("_===_\n(-,.)\n<( : )>\n( : )")); // (4)

    // Right Eye:
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // (1)
    CHECK(nospaces(snowman(11121111)) == nospaces("_===_\n(.,o)\n<( : )>\n( : )")); // (2)
    CHECK(nospaces(snowman(11131111)) == nospaces("_===_\n(.,O)\n<( : )>\n( : )")); // (3)
    CHECK(nospaces(snowman(11141111)) == nospaces("_===_\n(.,-)\n<( : )>\n( : )")); // (4)

    // Left Arm:
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));  // (1)
    CHECK(nospaces(snowman(11112111)) == nospaces("_===_\n\\(.,.)\n( : )>\n( : )")); // (2)
    CHECK(nospaces(snowman(11113111)) == nospaces("_===_\n(.,.)\n/( : )>\n( : )"));  // (3)
    CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));   // (4)

    // Right Arm:
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));  // (1)
    CHECK(nospaces(snowman(11111211)) == nospaces("_===_\n(.,.)/\n<( : )\n( : )"));  // (2)
    CHECK(nospaces(snowman(11111311)) == nospaces("_===_\n(.,.)\n<( : )\\\n( : )")); // (3)
    CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));   // (4)

    // Torso:
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )")); // (1)
    CHECK(nospaces(snowman(11111121)) == nospaces("_===_\n(.,.)\n<(] [)>\n( : )")); // (2)
    CHECK(nospaces(snowman(11111131)) == nospaces("_===_\n(.,.)\n<(> <)>\n( : )")); // (3)
    CHECK(nospaces(snowman(11111141)) == nospaces("_===_\n(.,.)\n<(   )>\n( : )")); // (4)

    // Base:
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));   // (1)
    CHECK(nospaces(snowman(11111112)) == nospaces("_===_\n(.,.)\n<( : )>\n(\" \")")); // (2)
    CHECK(nospaces(snowman(11111113)) == nospaces("_===_\n(.,.)\n<( : )>\n(___)"));   // (3)
    CHECK(nospaces(snowman(11111114)) == nospaces("_===_\n(.,.)\n<( : )>\n(   )"));   // (4)
}

TEST_CASE("False Input - Input Too Long / Input Too Short")
{
    CHECK_THROWS_AS(snowman(1243124), std::exception);    // Length = 7;
    CHECK_THROWS_AS(snowman(134214), std::exception);     // Length = 6;
    CHECK_THROWS_AS(snowman(143244123), std::exception);  // Length = 9;
    CHECK_THROWS_AS(snowman(1), std::exception);          // Length = 1;
    CHECK_THROWS_AS(snowman(123), std::exception);        // Length = 3;
    CHECK_THROWS_AS(snowman(1243224123), std::exception); // Length = 10;
}

TEST_CASE("False Input - Inserted Out of Range Numbers ( > 4 || < 1)")
{
    CHECK_THROWS_AS(snowman(52134221), std::out_of_range);  // (5)
    CHECK_THROWS_AS(snowman(26412321), std::out_of_range);  // (6)
    CHECK_THROWS_AS(snowman(41732143), std::out_of_range);  // (7)
    CHECK_THROWS_AS(snowman(-41214123), std::out_of_range); // (-4)
    CHECK_THROWS_AS(snowman(12434912), std::out_of_range);  // (9)
    CHECK_THROWS_AS(snowman(88812341), std::out_of_range);  // (8) x 3
    CHECK_THROWS_AS(snowman(-12312342), std::out_of_range); // (-1)
    CHECK_THROWS_AS(snowman(00000000), std::out_of_range);  // (0) x 8
}
