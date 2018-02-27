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

TEST(Lab04Fixture, parse){
    std::string test1 = "1+2";
    lab4::calculator::calculator(test1);
    EXPECT_EQ("12+","12+");
}