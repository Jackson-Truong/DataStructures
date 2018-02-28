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

TEST(calculator,divisionTest){
    std::string D ="4/2";
lab4::calculator obj3(D);
EXPECT_EQ(2,obj3.calculate());
}
