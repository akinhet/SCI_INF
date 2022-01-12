#include "sort.h"


template<typename T>
inline void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}


void printVector(std::vector<int> t)
{
    printf("[ ");
    for (int i : t)
        printf("%d, ", i);
    printf("]\n");
}


Sort::Sort()
{
    srand(time(NULL));
}


void Sort::randomize(std::vector<int> &t, int min, int max)
{
    for (int i = 0; i < t.size(); i++)
        t[i] = rand() % (max - min) + min;
}


void Sort::bubbleSort(std::vector<int> &t)
{
    for (int i = 0; i < t.size() - 1; i++)
        for (int j = 0; j < t.size() - i - 1; j++)
            if (t[j] > t[j+1])
                swap<int>(t[j], t[j+1]);
}


void Sort::insertSort(std::vector<int> &t)
{
    int hole, value;
    for (int i = 1; i < t.size(); i++) {
        hole = i;
        value = t[i];

        while (hole > 0 && t[hole - 1] > value) {
            t[hole] = t[hole-1];
            hole--;
        }

        if (hole != i)
            t[hole] = value;
    }
}
