#include "sort.h"
#include <chrono>


int main()
{
    int choice;
    Sort s = Sort();
    std::chrono::steady_clock::time_point start, end;
    std::vector<int> v(100);

    do {
        s.randomize(v, 1, 101);
        printf("\nChoose a sorting algorithm: \n0. Exit program\n1. Bubble sort\n2. Insertion sort\n3. Selection sort\n4. Quick sort\n5. std::sort\n: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nValues:\n");
                printVector(v);
                start = std::chrono::steady_clock::now();
                s.bubbleSort(v);
                end = std::chrono::steady_clock::now();
                printf("\nResult:\n");
                printVector(v);
                printf("Elapsed time: %fs", double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den );
                printf("\n===============================================================================\n\n");
                break;
            case 2:
                printf("\nValues:\n");
                printVector(v);
                start = std::chrono::steady_clock::now();
                s.insertSort(v);
                end = std::chrono::steady_clock::now();
                printf("\nResult:\n");
                printVector(v);
                printf("Elapsed time: %fs", double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den );
                printf("\n===============================================================================\n\n");
                break;
            case 3:
                printf("\nValues:\n");
                printVector(v);
                start = std::chrono::steady_clock::now();
                s.selectionSort(v);
                end = std::chrono::steady_clock::now();
                printf("\nResult:\n");
                printVector(v);
                printf("Elapsed time: %fs", double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den );
                printf("\n===============================================================================\n\n");
                break;
            case 4:
                printf("\nValues:\n");
                printVector(v);
                start = std::chrono::steady_clock::now();
                s.quickSort(v);
                end = std::chrono::steady_clock::now();
                printf("\nResult:\n");
                printVector(v);
                printf("Elapsed time: %fs", double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den );
                printf("\n===============================================================================\n\n");
                break;
            case 5:
                printf("\nValues:\n");
                printVector(v);
                start = std::chrono::steady_clock::now();
                s.stdSort(v);
                end = std::chrono::steady_clock::now();
                printf("\nResult:\n");
                printVector(v);
                printf("Elapsed time: %fs", double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den );
                printf("\n===============================================================================\n\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
