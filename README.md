# Cache Performance Simulator

## Project Overview

This project aims to develop and analyze cache performance using a simulator written in C++. The simulator evaluates the performance of different cache types by generating memory addresses through six memory generator functions (memGen1 to memGen6). Each function generates 1,000,000 memory references per experiment to simulate various memory access patterns. The performance is measured by calculating hit ratios for both direct mapped (DM) and fully associative (FA) caches. The collected data is then used to plot graphs that help draw conclusions about the impact of line size and cache type on performance. The purpose of this project is to provide insights into optimizing cache design and configuration for different types of workloads.

## Files

- **cache.cpp**: Main file that runs the simulator and allows for the parameters to be adjusted for each experiment. Also contains functions that serve as test cases.
- **TestCases.h**: Header file that contains our Test Case functions which we call in the main function.

## Building the Simulator
1. **Clone the Repository:**
   ```bash
   git clone https://github.com/KareemElnaghy/Cache-Performance.git
   cd cache-performance
2. **Build the Simulator:**
   ```bash
   g++ -o cachesim cache.cpp
3. **Run the Program using the following format:**
   ```bash  
   ./cachesim
## Test Cases

### Test Case 1
- **Description**: This test case verifies the cache's handling of a mixed access pattern, which includes both sequential and random memory addresses.
- **Configuration**: Line Size: 128 bytes
- **Expected Outcome**: Hit Rate (FA): 25%, Hit Rate (DM): 16.7%
  
### Test Case 2
- **Description**: Used to test for capacity misses when simulating the fully associative (FA) cache.
- **Configuration**: Line Size: 16,384 bytes
- **Expected Outcome**: Hit Rate: 25%

### Test Case 3
- **Description**: Used to check how the direct mapped (DM) cache handles conflict misses.
- **Configuration**: Line Size: 64 bytes
- **Expected Outcome**: Hit Rate: 0%

### Test Case 4
- **Description**: Used to check how the fully associative (FA) cache handles memory references near the boundaries of the block.
- **Configuration**: Line Size: 64 bytes
- **Expected Outcome**: Hit Rate: 41.7%

### Test Case 5
- **Description**: Used to check the behavior of the direct mapped (DM) cache when dealing with addresses that are accessed multiple times.
- **Configuration**: Line Size: 64 bytes
- **Expected Outcome**: Hit Rate: 50%

- ## Contributions
- [Kareem Elnaghy](https://github.com/KareemElnaghy) 
- [Malek Mahmoud](https://github.com/malekrouk)
- [Mazin Bersy](https://github.com/mazinbersy) 



