#include <iostream>
#include "../MedianFilt.hpp"

#define SIZE 5
int input[] = {1, 2, 3, 4, 5, 10, 0, 8, 9, 9900, 10, 10, 10, 10};

MedianFilt<double, SIZE> filter;

int main(int argc, char const *argv[])
{
    std::cout << "Median Filter Test" << std::endl;

    for (size_t i = 0; i < sizeof(input)/sizeof(int); i++)
    {
        std::cout << "Input: " << input[i] << " -> ";
        filter.update(input[i]);
        std::cout << " -> " << filter.getOutput() << std::endl;
    }
}
