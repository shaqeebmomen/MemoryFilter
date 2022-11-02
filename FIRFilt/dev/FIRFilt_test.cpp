#include <stdlib.h>
#include <iostream>
#include "../FIRFilt.hpp"

#define SIZE 10

#define impulse                         \
    {                                   \
        1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
    }

double coeffs[] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
double input[] = impulse;

FIRFilt<double, SIZE> filter(coeffs);

int main(int argc, char *argv[])
{
    std::cout << "FIR" << std::endl;

    for (size_t i = 0; i < SIZE; i++)
    {
        filter.update(input[i]);
        std::cout << filter.getOutput() << std::endl;
    }
}