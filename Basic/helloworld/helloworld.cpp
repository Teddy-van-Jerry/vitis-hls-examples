/**
 * @file helloworld.cpp
 * @brief helloworld module implementation
 * @author Wuqiong Zhao
 * @version 1.0 (2022-04-18)
 */

#include "helloworld.h"

void helloworld(int a, int& b) {
    b = a >> 1; // right shift one bit
}