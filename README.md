# 4thRoot
Calculating 4thRoots without using any library fubctions.

This algorithm uses Newton's method to calculate 4th roots for real numbers.
Then Google Tests run to check the result.


to compile, link:

$ gcc roots.c -c

$ g++ -std=c++11 -Wall testGo.cpp roots.o -lgtest -lgtest_main -lpthread -o ./gt

to run:

./gt --gtest_repeat=100 > gogTest.log
