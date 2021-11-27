#include <iostream>
#include <utility>
#include <time.h>
#include <stdlib.h>

const int primes[] = {  2,  3,  5,  7, 11,
                       13, 17, 19, 23, 29,
                       31, 37, 41, 43, 47,
                       53, 59, 61, 67, 71,
                       73, 79, 83, 89, 97, };

struct privatekey {
    int n, d;
};

struct publickey {
    int n, e;
};


int gcd(int a, int b)
{
    int temp;
    while (1) {
        temp = a % b;
        if (temp == 0)
            return b;
        a = b;
        b = temp;
    }
}


std::pair<struct publickey, struct privatekey> genrsakeys()
{
    std::pair<struct publickey, struct privatekey>keys;

    srand(time(NULL));
    int random = rand() % (sizeof(primes) / sizeof(primes[0] - 2)) + 1;

    const int p = primes[random],  q = primes[random+1];
    int n = p*q;
    int phi = (p - 1) * (q - 1);
    int e = 2;

    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    keys.first = {n,e};

    int d = 2;
    while (d*e % phi != 1)
        d++;
    keys.second = {n,d};

    return keys;
}


int main()
{
    std::pair<struct publickey, struct privatekey>keys = genrsakeys();
    std::cout << "Private key: n=" << keys.second.n << " d=" << keys.second.d << "\nPublic key: n=" << keys.first.n << " e=" << keys.first.e << std::endl;

    return 0;
}
