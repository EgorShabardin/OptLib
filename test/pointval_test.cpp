#include "../SetOfPoints/PointVals/PointVal.h"
#include "../SetOfPoints/PointVals/Point/PointOperatorsSerial.h"
#include <catch2/catch_test_macros.hpp>
TEST_CASE("PointOperators")
{
    auto firstPoint = OptLib::Point<3>{1.0, 2.0, 4.9};
    CHECK(firstPoint[0] == 1.0);
    CHECK(firstPoint[1] == 2.0);
    CHECK(firstPoint[2] == 4.9);
    auto secondPoint = OptLib::Point<3>{3.0, 1.2, 5.8};
    CHECK(secondPoint[0] == 3.0);
    CHECK(secondPoint[1] == 1.2);
    CHECK(secondPoint[2] == 5.8);

    auto sum = firstPoint + secondPoint;
    for(size_t i{0ull}; i < 3ull; ++i)
        CHECK(firstPoint[i] + secondPoint[i] == sum[i]);
    auto prod = firstPoint * secondPoint;
    for(size_t i{0ull}; i < 3ull; ++i)
        CHECK(firstPoint[i] * secondPoint[i] == prod[i]);
    auto minus = firstPoint - secondPoint;
    for(size_t i{0ull}; i < 3ull; ++i)
        CHECK(firstPoint[i] - secondPoint[i] == minus[i]);

    
}