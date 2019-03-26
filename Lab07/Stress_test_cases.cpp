#include "catch.hpp"
#include "Stress.h"
#include "exceptions.h"
using Stress::ipow_s;
using Stress::slice_sum_s;
using Stress::lots_of_ints;

TEST_CASE("Testing stress class") {
	SECTION("Testing ipow_s function") {
		REQUIRE(ipow_s(0, 2) == 0);
		REQUIRE(ipow_s(2, 0) == 1);
		REQUIRE(ipow_s(2, 2) == 4);
		REQUIRE(ipow_s(10, 5) == 100000);
		REQUIRE_THROWS_AS(ipow_s(10, 1000), OverflowException);
	}

	SECTION("Testing slice_sum_s") {
		const int SIZE = 10;
		int arr[SIZE] = { 5, 8, 70, 90, 0, 3, 23 };
		REQUIRE(slice_sum_s(arr, 0, 2, SIZE) == 13);
		REQUIRE(slice_sum_s(arr, 2, 2, SIZE) == 160);
		REQUIRE_THROWS_AS(slice_sum_s(arr, 0, 11, SIZE), SubscriptException);
	}

	SECTION("Testing lots_of_ints") {
		REQUIRE(lots_of_ints(9) == 512);
		REQUIRE(lots_of_ints(5) == 32);
		REQUIRE_THROWS_AS(lots_of_ints(1000), MemoryException);
		REQUIRE_THROWS_AS(lots_of_ints(-1), MemoryException);
	}
}