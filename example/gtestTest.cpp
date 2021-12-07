// git clone https://github.com/google/googletest
// cd googletest
// cmake CMakeLists.txt
// sudo make install
// g++ gtestTest.cpp -lgtest -std=c++17
// run all testCase: ./a.out 
// run some testCase: ./a.out --gtest_filter="testCase.test0"

#include <gtest/gtest.h>

int add(int a,int b){
  return a + b;
}

TEST(testCase,test0){
  EXPECT_EQ(3, add(1, 2)) << "wrong? impossible!\n";
}

TEST(testCase,test1){
  EXPECT_EQ(1, add(1, 1)) << "Right? impossible!\n";
}

int main(int argc,char **argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}