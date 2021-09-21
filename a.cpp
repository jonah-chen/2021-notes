#include <iostream>
#include <omp.h>
#include <chrono>
#include <ctime>
#include <random>

int main() {
    using namespace std;
    using namespace std::chrono;

    const unsigned N = 10000000;
    float* table1 = new float[N];
    float* table2 = new float[N];
    float* table3 = new float[N];

    std::mt19937 RND(123);
    std::uniform_real_distribution<float> dist(0,1);

    for (unsigned n = 0; n < N; ++n) { /*Initialize table1 and table2*/
        table1[n]=dist(RND);
        table2[n]=dist(RND);
    }

    auto start = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    
    for(unsigned k=0;k<500;k++) { /*Do inner loop a lot*/

        //#pragma omp parallel for
        //#pragma omp simd
        for (unsigned n = 0; n < N; ++n) /*VECTORIZE ME*/
        { 
            table3[n]=table1[n]+table2[n];
        }

    }

    auto end = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
    std::cout << "Time " << end.count() - start.count() << std::endl;
        
    for (unsigned n = 0; n < N; ++n) 
    { /*Use* the result.*/
        if (abs(table3[n]-(table1[n]+table2[n]))>0.01) {
            throw false;
        }
    }
}