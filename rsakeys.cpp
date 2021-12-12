#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>
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


long long powmod(long long t, long long e, long long n)
{
    long long r = 1;

    for (e; e > 0; e /= 2) {
        if (e % 2)
            r = (r * t) % n;
        t = (t * t) % n;
    }
    return r;
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


void rsaencrypt(std::string message, long long e, long  long n)
{
    for (size_t i = 0; i < message.size(); i++) {
        std::cout << powmod(message[i], e, n) << " ";
    }
    std::cout << std::endl;
}


void rsadecrypt(long long c[], size_t size, long long d, long long n)
{
    for (size_t i = 0; i < size; i++) {
        std::cout << (char)powmod(c[i], d, n);
    }
    std::cout << std::endl;
}


int main()
{
    int temp;
    std::string message;
    long long e, n;
    long long *c;
    size_t count;
    std::cout << "1. Generate RSA keys\n2. Encrypt a message using RSA keys\n3. Decrypt a number using RSA keys\n";
    std::cin >> temp;
    switch (temp) {
        case 1: {
            std::pair<struct publickey, struct privatekey>keys = genrsakeys();
            std::cout << "Private key: n=" << keys.second.n << " d=" << keys.second.d << "\nPublic key: n=" << keys.first.n << " e=" << keys.first.e << std::endl;
            break; }
        case 2:
            std::cout << "Message you want to encrypt: ";
            std::cin >> message;
            std::cout << "E: ";
            std::cin >> e;
            std::cout << "N: ";
            std::cin >> n;
            rsaencrypt(message, e, n);
            break;
        case 3:
            std::cout << "How long is the message? ";
            std::cin >> count;
            c = new long long[count];
            std::cout << "Message you want to decrypt: ";
            std::copy_n(std::istream_iterator<long long>(std::cin), count, c);
            std::cout << "D: ";
            std::cin >> e;
            std::cout << "N: ";
            std::cin >> n;
            rsadecrypt(c, count, e, n);
            break;
        default:
            break;
    }

    return 0;
}
