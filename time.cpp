#include "sort.h"
#include <chrono>

int main()
{
    Sort s = Sort();
    std::chrono::steady_clock::time_point start, end;
    std::vector<int> v1(1000);
    std::vector<int> v2(10000);
    double times[3];

    scanf("%c", (char *)NULL);

    printf("Bubble sort\n-----------\n\n1000 elements:\n\n");

    for (int i = 0; i < 3; i++) {
        s.randomize(v1, 1, 101);
        printf("%d:\n", i);
        start = std::chrono::steady_clock::now();
        s.bubbleSort(v1);
        end = std::chrono::steady_clock::now();
        times[i] = double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        printf("Elapsed time: %fs\n\n", times[i]);
    }

    printf("Average time: %fs\n\n10000 elements:\n\n", (times[0] + times[1] + times[2])/3);

    for (int i = 0; i < 3; i++) {
        s.randomize(v2, 1, 101);
        printf("%d:\n", i);
        start = std::chrono::steady_clock::now();
        s.bubbleSort(v2);
        end = std::chrono::steady_clock::now();
        times[i] = double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        printf("Elapsed time: %fs\n\n", times[i]);
    }

    printf("Average time: %fs\n\n", (times[0] + times[1] + times[2])/3);

    scanf("%c", (char *)NULL);

    printf("Insertion sort\n-----------\n\n1000 elements:\n\n");

    for (int i = 0; i < 3; i++) {
        s.randomize(v1, 1, 101);
        printf("%d:\n", i);
        start = std::chrono::steady_clock::now();
        s.insertSort(v1);
        end = std::chrono::steady_clock::now();
        times[i] = double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        printf("Elapsed time: %fs\n\n", times[i]);
    }

    printf("Average time: %fs\n\n10000 elements:\n\n", (times[0] + times[1] + times[2])/3);

    for (int i = 0; i < 3; i++) {
        s.randomize(v2, 1, 101);
        printf("%d:\n", i);
        start = std::chrono::steady_clock::now();
        s.insertSort(v2);
        end = std::chrono::steady_clock::now();
        times[i] = double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        printf("Elapsed time: %fs\n\n", times[i]);
    }

    printf("Average time: %fs\n\n", (times[0] + times[1] + times[2])/3);

    scanf("%c", (char *)NULL);

    printf("Selection sort\n-----------\n\n1000 elements:\n\n");

    for (int i = 0; i < 3; i++) {
        s.randomize(v1, 1, 101);
        printf("%d:\n", i);
        start = std::chrono::steady_clock::now();
        s.selectionSort(v1);
        end = std::chrono::steady_clock::now();
        times[i] = double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        printf("Elapsed time: %fs\n\n", times[i]);
    }

    printf("Average time: %fs\n\n10000 elements:\n\n", (times[0] + times[1] + times[2])/3);

    for (int i = 0; i < 3; i++) {
        s.randomize(v2, 1, 101);
        printf("%d:\n", i);
        start = std::chrono::steady_clock::now();
        s.selectionSort(v2);
        end = std::chrono::steady_clock::now();
        times[i] = double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        printf("Elapsed time: %fs\n\n", times[i]);
    }

    printf("Average time: %fs\n\n", (times[0] + times[1] + times[2])/3);

    scanf("%c", (char *)NULL);

    printf("Quick sort\n-----------\n\n1000 elements:\n\n");

    for (int i = 0; i < 3; i++) {
        s.randomize(v1, 1, 101);
        printf("%d:\n", i);
        start = std::chrono::steady_clock::now();
        s.quickSort(v1);
        end = std::chrono::steady_clock::now();
        times[i] = double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        printf("Elapsed time: %fs\n\n", times[i]);
    }

    printf("Average time: %fs\n\n10000 elements:\n\n", (times[0] + times[1] + times[2])/3);

    for (int i = 0; i < 3; i++) {
        s.randomize(v2, 1, 101);
        printf("%d:\n", i);
        start = std::chrono::steady_clock::now();
        s.quickSort(v2);
        end = std::chrono::steady_clock::now();
        times[i] = double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        printf("Elapsed time: %fs\n\n", times[i]);
    }

    printf("Average time: %fs\n\n", (times[0] + times[1] + times[2])/3);

    scanf("%c", (char *)NULL);

    printf("Standard sort\n-----------\n\n1000 elements:\n\n");

    for (int i = 0; i < 3; i++) {
        s.randomize(v1, 1, 101);
        printf("%d:\n", i);
        start = std::chrono::steady_clock::now();
        s.stdSort(v1);
        end = std::chrono::steady_clock::now();
        times[i] = double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        printf("Elapsed time: %fs\n\n", times[i]);
    }

    printf("Average time: %fs\n\n10000 elements:\n\n", (times[0] + times[1] + times[2])/3);

    for (int i = 0; i < 3; i++) {
        s.randomize(v2, 1, 101);
        printf("%d:\n", i);
        start = std::chrono::steady_clock::now();
        s.stdSort(v2);
        end = std::chrono::steady_clock::now();
        times[i] = double((end - start).count()) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        printf("Elapsed time: %fs\n\n", times[i]);
    }

    printf("Average time: %fs\n\n", (times[0] + times[1] + times[2])/3);
}
