#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void printVector(std::vector<int> t);

class Sort {
    public:
        Sort();
        void randomize(std::vector<int> &t, int min, int max);
        void bubbleSort(std::vector<int> &t);
        void insertSort(std::vector<int> &t);
        void quickSort(std::vector<int> &t);
        void selectionSort(std::vector<int> &t);
        void stdSort(std::vector<int> &t);
};
