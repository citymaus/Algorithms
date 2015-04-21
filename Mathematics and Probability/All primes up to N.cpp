/*
  Find the number of prime numbers up to n.
*/
#include <cstring>    /* memset */

int num_primes(int n)
{
    int primes = (n + 1) - 2; // Between 0 and m inclusive, subtract two: 0 and 1, not primes
    int sq = sqrt(n);
    bool sieve[n+1];
    memset(sieve, true, sizeof(sieve));
    sieve[0] = false;       // 0 not prime
    sieve[1] = false;       // 1 not prime
    
    for (int i = 2; i <= sq; i++)
    {
        if (sieve[i])
        {
            // Remove all multiples of i, they are not prime
            for (int j = i*i; j <= n; j+=i)
            {
                if (sieve[j])
                {
                    //cout << "removing " << j << endl;
                    primes--;
                    sieve[j] = false;
                }
            }
        }
    }    
    return primes;
}