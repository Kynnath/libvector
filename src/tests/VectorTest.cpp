/* 
 * File:   VectorTest.cpp
 * Author: JoPe
 *
 * Created on 25/08/2013, 19:34:46
 */

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

void test1() {
    std::cout << "VectorTest test 1" << std::endl;
}

void test2() {
    std::cout << "VectorTest test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (VectorTest) message=error message sample" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% VectorTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% test1 (VectorTest)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (VectorTest)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (VectorTest)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (VectorTest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

