#include "gtest/gtest.h"
#include "fifo.h"
#include "lifo.h"
#include "calculator.h"

class Lab04Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

public:
};

TEST(calculator, addTest){
    std::string A ="90+80";
    lab4::calculator Add(A);
    EXPECT_EQ(170, Add.calculate());
}

TEST(calculator, hello){
    std::string M = "5*(4-2)";
    lab4::calculator calc(M);
    EXPECT_EQ(10, calc.calculate());
}

TEST(calculator, hellw){
    std::string M = "(4-2)*5";
    lab4::calculator calc(M);
    EXPECT_EQ(10, calc.calculate());
}
TEST(calculator,divisionTest){
    std::string D ="4/2";
lab4::calculator div(D);
EXPECT_EQ(2,div.calculate());
}

TEST(calculator, multTest){
    std::string G = "8*9";
    lab4::calculator mult(G);
    EXPECT_EQ(72, mult.calculate());
}
TEST(calculator, quiz){
    std::string E = "2-(3*4/6)+4";
    lab4::calculator tues(E);
    EXPECT_EQ(4,tues.calculate());
}
