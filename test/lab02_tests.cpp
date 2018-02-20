#include "gtest/gtest.h"
#include "stringVector.h"

class Lab02Fixture : public ::testing::Test {

};
#include "gtest/gtest.h"
#include "stringVector.h"

TEST(stringVector,constructorTest) {
    lab2::stringVector stringVec;
    EXPECT_EQ(true,stringVec.empty()); //expected empty to be true because empty function returns true if stringVec is empty
    EXPECT_EQ(0,stringVec.size());// size returns length which is 0
    EXPECT_EQ(0,stringVec.capacity()); //size returns allocated_length which is 0
}
TEST(stringVector, rhs){
    lab2::stringVector copy;
    copy.append("Black Panther");// appends black panther into the 0th element of copy
    EXPECT_EQ("Black Panther", copy[0]);// Checks if this is true
    copy[0] = "Spider-Man";// Changes the 0th element to Spider-Man from Black Panther
    EXPECT_EQ("Spider-Man", copy[0]);//Checks if this is true
}
TEST(stringVector, Bubble){
    lab2::stringVector alpha;
    alpha.append("Spiderman");//0th element
    alpha.append("Thor");//1st element
    alpha.append("BlackPanther");//second element
    alpha.append("Superman");//third element
    alpha.append("Batman");//fourth element
    alpha.append("Antman");//fifth element
    alpha.append("Obama");//sixth element
    EXPECT_NO_THROW(alpha.sort());//This will put this in order via alphabetical
    EXPECT_EQ("Antman", alpha[0]);//The following is now in order
    EXPECT_EQ("Batman", alpha[1]);
    EXPECT_EQ("BlackPanther", alpha[2]);
    EXPECT_EQ("Obama", alpha[3]);
    EXPECT_EQ("Spiderman", alpha[4]);
    EXPECT_EQ("Superman", alpha[5]);
    EXPECT_EQ("Thor", alpha[6]);

}
TEST(stringVector, Append){
    lab2::stringVector amount;
    amount.append("The size of this should be 1, the capacity should be 1");
    EXPECT_EQ(1, amount.size());
    EXPECT_EQ(1, amount.capacity());
    amount.append("The size of this should 2, the capacity should be 1*2=2");
    EXPECT_EQ(2, amount.size());
    EXPECT_EQ(2, amount.capacity());
    amount.append("The size of this should be 3, the capacity should be 2*2=4");
    EXPECT_EQ(3, amount.size());
    EXPECT_EQ(4, amount.capacity());
}

