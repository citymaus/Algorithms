
#define MAXN        45
#define UNKNOWN     -1

long f[MAXN+1];

long fibonacci_caching(int n)
{
    if (f[n] == UNKNOWN)
        f[n] = fibonacci_caching(n-1) + fibonacci_caching(n-2);
    return f[n];
}

long fibonacci_driver(int n)
{
    int i;
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= n; i++)
        f[i] = UNKNOWN;
    return fibonacci_caching(n);
}
