#include <stdint.h>
#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
T median_of_medians(T *list, unsigned char size, unsigned char index)
{
    uint8_t sublist_c = (int)ceil((float)size / 5.0);

    std::vector<T> sublists[sublist_c];
    // Split the list into sublists with length <= 5
    for (size_t i = 0; i < size; i++)
    {
        std::cout << list[i] << " ";
        sublists[i / 5].push_back(list[i]);
    }
    std::cout << std::endl;
    // Allocate space for the median of each sublist
    T medians[sublist_c];

    // Sort each sublist w/ bubble sort, bubble is probably okay cause all the lists are guaranteed to only be 5 elements long at this point
    for (size_t i = 0; i < sublist_c; i++)
    {
        for (size_t j = 1; j < sublists[i].size(); j++)
        {
            for (size_t k = 0; k < sublists[i].size() - j; k++)
            {
                if (sublists[i][k] > sublists[i][k + 1])
                {
                    T tmp = sublists[i][k + 1];
                    sublists[i][k + 1] = sublists[i][k];
                    sublists[i][k] = tmp;
                }
            }
        }
        // Sublist i sorted
        medians[i] = sublists[i][sublists[i].size() / 2];
    }

    std::cout << "Sublists:" << std::endl;

    for (size_t i = 0; i < sublist_c; i++)
    {
        for (size_t j = 0; j < sublists[i].size(); j++)
        {
            std::cout << sublists[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Medians:" << std::endl;
    for (size_t j = 0; j < sublist_c; j++)
    {
        std::cout << medians[j] << " ";
    }
    std::cout << std::endl;

    return 0.0;
}
