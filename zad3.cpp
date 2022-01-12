#include "sort.h"


int main()
{
    int choice;
    Sort s = Sort();
    std::vector<int> v(10);

    do {
        s.randomize(v, 1, 101);
        printf("\nChoose a sorting algorithm: \n0. Exit program\n1. Bubble sort\n2. Insertion sort\n: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nValues:\n");
                printVector(v);
                s.bubbleSort(v);
                printf("\nResult:\n");
                printVector(v);
                printf("\n===============================================================================\n\n");
                break;
            case 2:
                printf("\nValues:\n");
                printVector(v);
                s.insertSort(v);
                printf("\nResult:\n");
                printVector(v);
                printf("\n===============================================================================\n\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
