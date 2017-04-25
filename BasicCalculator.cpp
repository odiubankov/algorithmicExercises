#include "BasicCalculator.h"
#include <gtest/gtest.h>


TEST(BasicCalculator, test)
{
    basiccalc::Solution basicCalc;
    EXPECT_EQ(basicCalc.calculate("3+2*2"), 7);
    EXPECT_EQ(basicCalc.calculate(" 3/2 "), 1);
    EXPECT_EQ(basicCalc.calculate(" 3+5 / 2 "), 5);
    EXPECT_EQ(basicCalc.calculate("0"), 0);
    EXPECT_EQ(basicCalc.calculate("1+1-1"), 1);
    EXPECT_EQ(basicCalc.calculate("2+3+4"), 9);
}