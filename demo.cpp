#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>

// Function to compute `g^m mod n`
long long int compute(long long int g,long long int m,long long int n)
{
    long long int r;
    long long int y = 1;

    while (m > 0)
    {
        r = m % 2;

        if (r == 1) {
            y = (y * g) % n;
        }
        g = (g * g) % n;
        m = m / 2;
    }

    return y;
}


int main()
{
    srand(time(NULL));
    long long int n, g, a, b, A, B;
    // `a` – A's private key, `b` – B's private key.
    // `A` – A's public key, `B` – B's public key
        n = 999983;        // prime number for modulus    
        g = 5;//11;        // base - primitive root of n
        int lc = 3;

    
    while (lc > 0) {
        // Private integer for A's private key (only known to A)
        a = rand();

        // Calculate A's public key (A will send `A` to B)
        A = compute(g, a, n);

        // Private integer for B's private key (only known to B)
        b = 56849865165;

        // Calculate B's public key (B will send `B` to A)
        B = compute(g, b, n);

        // A and B Exchange their public key `A` and `B` with each other

        // Find secret key
        long long int keyA = compute(B, a, n);
        long long int keyB = compute(A, b, n);
        printf("-------------------------\t-----------------Demo %d-----------------\t----------------------------\n",lc);
        printf("-------------------------\t-----------------------------------------\t----------------------------\n");
        printf("\t\tPublic Key is n = %lld, g = %lld\n\n", n, g);
        printf("A's private key: %lld\t\t\tB's private key:%lld\n\n", a, b);
        printf("A's calculated public key: %lld\tB's calculated public key: %lld\n\n", A, B);
        printf("A's secret key: %lld\t\t\tB's secret key: %lld\n\n", keyA, keyB);
        printf("-------------------------\t-----------------------------------------\t----------------------------\n");
        printf("-------------------------\t------------------END--------------------\t----------------------------\n");
        lc--;
    }
    
    return 0;
}