//
// Created by Asus on 7/21/2024.
//

#ifndef CACHE_PERFORMANCE_TESTCASES_H
#define CACHE_PERFORMANCE_TESTCASES_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;


#define		CACHE_SIZE		(64*1024)


// Test Cases

vector<unsigned int> testcase1()
{
// Line size: 128
// FA and DM
// General Test for functionality of DM and FM

    vector<unsigned int> addr;
    addr.push_back(0x00000000);
    addr.push_back(0x00000010);
    addr.push_back(0x00000100);
    addr.push_back(0x00001000);
    addr.push_back(0x00010000);
    addr.push_back(0x00100000);
    addr.push_back(0x01000000);
    addr.push_back(0x00000011);
    addr.push_back(0x00000050);
    addr.push_back(0x00011111);
    addr.push_back(0x00111110);
    addr.push_back(0x01111100);

    return addr;
}

vector<unsigned int> testcase2()
{
// Fully Associative
// Line size: 16384
// Test Case to test for capacity miss in fully associative cache
    vector<unsigned int> addr;
    for (int i = 0; i < 8; i++)
    {
        if(i == 5 || i == 6)
            addr.push_back(0 + ((i%4) * 16384));
        else
            addr.push_back(0 + (i * 16384));

    }

    return addr;
}

vector<unsigned int> testcase3()
{
    // Fully Associative and Direct Mapped
    // Line Size: 64
    // Test Case which results in a 100 percent miss rate with DM Cache and with a high hit rate with the FA cache
    vector<unsigned int> addr;
    for(int i = 0; i < 64; i++)
    {
        addr.push_back(i);
        addr.push_back(i+CACHE_SIZE);
    }
    return addr;
}

vector<unsigned int> testcase4()
{
// Fully Associative
// Line Size: 64
// Test Case which access addresses near the boundaries of line
    vector<unsigned int> addr;
    for (int i = 0; i < 6; i++)
    {
        addr.push_back((i+1)*(64)-1);
        addr.push_back(((i+1)*(64)));
    }

    return addr;
}

vector<unsigned int> testcase5()
{
// Direct Mapped
// Line Size: 64
// Test Case which tests several features of direct mapped cache i.e. conflict misses and reaccessing previous addr.
    vector<unsigned int> addr;
    for (int i = 0; i < 5; i++)
    {
        addr.push_back(i*64);
    }
    for(int i = 1; i<16; i+=4)
    {
        addr.push_back(i*(0x7));
    }
    addr.push_back(0x0);
    addr.push_back(64*1024);
    addr.push_back((64*1024)+10);
    return addr;
}
#endif //CACHE_PERFORMANCE_TESTCASES_H
