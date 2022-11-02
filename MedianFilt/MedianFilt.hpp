#include "../MemFilt.hpp"
#include <iostream>

template <typename T, int size>
class MedianFilt : public MemFilt<T, size>
{
private:
    T calculate();
    void sort();

public:
    void update(T val);
    MedianFilt();
};

template <typename T, int size>
MedianFilt<T, size>::MedianFilt()
{
}

template <typename T, int size>
void MedianFilt<T, size>::update(T val)
{
    MemFilt<T, size>::shift(val);
    this->sort();
    for (size_t i = 0; i < size; i++)
    {
        std::cout << this->m_taps[i] << " ";
    }
    this->calculate();
}

template <typename T, int size>
T MedianFilt<T, size>::calculate()
{
    if (size % 2 == 0)
    {
        this->m_output = (this->m_taps[size / 2] + this->m_taps[size / 2 + 1]) / 2;
    }
    else
    {
        this->m_output = (this->m_taps[size / 2]);
    }
    return this->m_output;
}

template <typename T, int size>
void MedianFilt<T, size>::sort()
{
    /*
        i ← 1
while i < length(A)
    x ← A[i]
    j ← i - 1
    while j >= 0 and A[j] > x
        A[j+1] ← A[j]
        j ← j - 1
    end while
    A[j+1] ← x[3]
    i ← i + 1
end while
    */

    // TODO this is sorting backwards, compared to how the values are shifted in
    // Not using std::sort b/c of possible recursion/heap usage, trying to avoid that on an embedded chip, not that I know if it will actually cause a problem

    for (unsigned int i = 1; i < this->m_length; i++)
    {
        T x = this->m_taps[i];
        unsigned int j = 0;
        j = i - 1;
        while ((j >= 0) && (this->m_taps[j] > x))
        {
            this->m_taps[j + 1] = this->m_taps[j];
            if (j == 0)
            {
                break;
            }
            else
            {
                j--;
            }
        }
        this->m_taps[j + 1] = x;
    }

    for (unsigned int i = this->m_length-1; i <= 0 ; i++)
    {
        /* code */
    }
    
}