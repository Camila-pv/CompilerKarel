/**
 * @file gramaticaKarel_test.cpp
 * @author Camila
 * @date 16/09/2022
 *
 * @brief Test file where are located the TEST_CASE functions.
 */


#include <catch.hpp>

#include <gramaticaKarel.h>


SCENARIO( "#number" ){

  GIVEN( "A string with a number" ){

    WHEN( "it is only digits" ){

      THEN( "must return true" ){
	REQUIRE(number("3567") == true);
      }
    }

    WHEN( "it has spaces before and after the digits" ){

      THEN( "must return true" ){
	REQUIRE(number("   76757") == true);
	REQUIRE(number("9757   ") == true);
	REQUIRE(number("   9725527    ") == true);
      }
    }

    WHEN( "it has spaces between the digits" ){

      THEN( "must return false" ){
	REQUIRE(number("   767   57") == false);
	REQUIRE(number("97   57") == false);
	REQUIRE(number("   972 5527    ") == false);
      }
    }
  }
}

