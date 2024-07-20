#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <bitset>
using namespace std;

#define		DBG				1
#define		DRAM_SIZE		(64*1024*1024)
#define		CACHE_SIZE		(64*1024)
#define     LINE_SIZE       (128)

unsigned int cacheFA[CACHE_SIZE/LINE_SIZE];
unsigned int cacheDM[CACHE_SIZE/LINE_SIZE];
bool valid[CACHE_SIZE/LINE_SIZE];
unsigned int blocks = CACHE_SIZE / LINE_SIZE;

enum cacheResType {MISS=0, HIT=1};
int COUNT = 0;

/* The following implements a random number generator */
unsigned int m_w = 0xABABAB55;    /* must not be zero, nor 0x464fffff */
unsigned int m_z = 0x05080902;    /* must not be zero, nor 0x9068ffff */
unsigned int rand_()
{
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;  /* 32-bit result */
}

vector<unsigned int> testcase1()
{
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

unsigned int memGen1()
{
	static unsigned int addr=0;
	return (addr++)%(DRAM_SIZE);
}

unsigned int memGen2()
{
	static unsigned int addr=0;
	return  rand_()%(24*1024);
}

unsigned int memGen3()
{
	return rand_()%(DRAM_SIZE);
}

unsigned int memGen4()
{
	static unsigned int addr=0;
	return (addr++)%(4*1024);
}

unsigned int memGen5()
{
	static unsigned int addr=0;
	return (addr++)%(1024*64);
}

unsigned int memGen6()
{
	static unsigned int addr=0;
	return (addr+=32)%(64*4*1024);
}


// Direct Mapped Cache Simulator
cacheResType cacheSimDM(unsigned int addr) {
	unsigned int shamt = log2(LINE_SIZE);
    unsigned int indexBits = log2(blocks);
	unsigned int indexx = (pow(2,indexBits+1)-1);
    unsigned int index = (addr >> shamt) & indexx;
    unsigned int tag = addr >> (shamt + indexBits);


    if (cacheDM[index] == tag && valid[index])
        return HIT;
    else
    {
        cacheDM[index] = tag;
        valid[index] = true;
    }
    return MISS;
}


// Fully Associative Cache Simulator
cacheResType cacheSimFA(unsigned int addr)
{
	// This function accepts the memory address for the read and
	// returns whether it caused a cache miss or a cache hit
    unsigned int shamt = log2(LINE_SIZE);   // Number of bits used for offset
    unsigned int tag = addr >> shamt;          // Extract Tag from address

    for(int i = 0; i < COUNT; i++)             // Compare Tag with tags stored in each cache block
    {
        if(cacheFA[i] == tag)                   // If tag is found in the cache it is a cache hit
            return HIT;
    }

    if(COUNT != CACHE_SIZE/LINE_SIZE)           // If the cache is not full, store tag in the first available location
        cacheFA[COUNT++] = tag;
    else
    {
        int randomIndex = rand()%(CACHE_SIZE/LINE_SIZE);    // Randomise cache location to store tag
        cacheFA[randomIndex] = tag;
    }
    return MISS;
}
char *msg[2] = {"Miss","Hit"};

#define		NO_OF_Iterations	1000000		// CHange to 1,000,000
int main()
{
	unsigned int hit = 0;
	cacheResType r;

	// Experiment
        unsigned int addr;
        cout << "Cache Simulator\n";
        for(int inst=0;inst<NO_OF_Iterations;inst++)
        {
            addr = memGen1();
//            r = cacheSimFA(addr);
            r = cacheSimDM(addr);


            if(r == HIT) hit++;
            cout <<"0x" << setfill('0') << setw(8) << hex << addr <<" ("<< msg[r] <<")\n";
        }
        cout << "Hit ratio = " << dec<<(100.0*hit/NO_OF_Iterations)<< endl;

    // Test Cases

//    vector<unsigned int> addrT = testcase1();
//
//    cout << "Test Case Cache Simulator\n";
//    for(int inst=0;inst<addrT.size();inst++)
//    {
//        r = cacheSimFA(addrT[inst]);
//        //r = cacheSimDM(addrT[inst]);
//
//        if(r == HIT) hit++;
//        cout <<"0x" << setfill('0') << setw(8) << hex << addrT[inst] <<" ("<< msg[r] <<")\n";
//    }
//    cout << "Hit ratio = " << dec<<(100.0*hit/addrT.size())<< endl;


}