#include "gtest/gtest.h"
#include "doubly_linked_list.h"

class Lab06Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
    }
    virtual void TearDown() {
    }
public:
};
TEST(Lab06Fixture, sort){
    lab6::doubly_linked_list hi;
    hi.append(10);
    hi.append(9);
    hi.append(8);
    hi.append(7);
    hi.append(6);
    hi.append(5);
    hi.append(4);
    hi.append(3);
    hi.append(2);
    hi.append(1);
    hi.sort();
}
