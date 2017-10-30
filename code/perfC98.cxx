/* 
 * File:   perfC98.cxx
 * Author: rt1
 * gcc compil as follow :
 * g++ perfC98.cxx -o perfC98
 * grant rights :
 * chmod u+x perfC98
 */

//#include <boost>
#include <iostream>
#include <vector>
#include <sys/time.h>
#include <ctime>
#include <string>
#include <sstream>
#include <map>
#include <math.h>
//demangle part inc
#include <stdlib.h>
#include <cxxabi.h>

static const unsigned int L1 = 10, 
                          L2 = 100,
                          L3 = 10000,
                          L4 = 100000,
                          L5 = 1000000,
                          L6 = 100000000,
                          L7 = 1000000000;

#include "write_test_here.h"

std::vector<double> vecSecs;

typedef unsigned int timestamp_t;

static timestamp_t get_timestamp()
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

void outstreamPERF1()
{
    vecSecs.clear();
    for(unsigned int j = 0; j < TRYNUMBER; ++j)
    {
        timestamp_t t0 = get_timestamp(); 
        for(unsigned int i = 0; i < ITERATION; ++i)
        {
            #ifdef T1
                test1();
            #endif
            
            #ifdef T2
                test2();
            #endif
        }
        timestamp_t t1 = get_timestamp();
        vecSecs.push_back((t1 - t0) / 1000000.0L);
    }
    
    double average = 0;
    for(unsigned int k = 0; k < TRYNUMBER; average += vecSecs[++k]);
    std::cout.precision(10);
    std::cout << "\e[34m\e[1mTEST1 \ntime : " << std::fixed << (average/vecSecs.size()) << "s" << "\nover : " << ITERATION << " iterations \ndone : " << TRYNUMBER << " time repeated\e[0m" << std::endl;
}

int main(int argc, char **argv)
{
    if(argc && argc == 2)
    {
        int st = 0;
        const char *demangledName = abi::__cxa_demangle(argv[1], 0, 0, &st);
        switch(st)
        {
            case  0: std::cout << argv[1] << demangledName << std::endl; break;
            case -1: std::cout << "A memory allocation failure occurred : " << argv[1] << std::endl; break;
            case -2: std::cout << argv[1] << " is not a valid name under the C++ ABI mangling rules." << std::endl; break;
            default: std::cout << "UB status val : [" << st << "] check :\n https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a01696.html" << std::endl; break;
        }
        //@see A region of memory, allocated with malloc, of *length bytes, into which the demangled name is stored.
        free((void *)demangledName);
    }
    else
        outstreamPERF1();
    
    return 0;
}
