#include "sort.h"

#include <algorithm>


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


void Sort::selectionSort(std::vector<int> &t)
{
    int min;
    for (int i = 0; i < t.size() - 1; i++) {
        min = i;
        for (int j = i+1; j < t.size(); j++)
            if (t[min] > t[j])
                min = j;
        swap<int>(t[i], t[min]);
    }
}


int qspartition(std::vector<int> &t, int left, int right, int pivot)
{
    int leftptr = left - 1,
        rightptr = right;

    while (1) {
        while (t[++leftptr] < pivot);
        while (rightptr > 0 && t[--rightptr] > pivot);

        if (leftptr >= rightptr)
            break;
        else
            swap(t[leftptr], t[rightptr]);
    }

    swap(t[leftptr], t[right]);
    return leftptr;
}

void qsmain(std::vector<int> &t, int left, int right)
{
    if (right - left <= 0)
        return;
    else {
        int pivot = t[right];
        int partpoint = qspartition(t, left, right, pivot);
        qsmain(t, left, partpoint - 1);
        qsmain(t, partpoint + 1, right);
    }
}

void Sort::quickSort(std::vector<int> &t)
{
    qsmain(t, 0, t.size() - 1);
}


void Sort::stdSort(std::vector<int> &t)
{
    std::sort(t.begin(), t.end());
}
