 UVa 10006: Carmichael numbers

ProcessThere’s a lot of math in this one. The problem is asking us to identify Carmichael numbers – non-primes that satisfy the equation a^n mod n = a for n from 2 to n – 1. It should be apparent that for large n, we won’t be able to store a^n in any data type (outside of BigInteger, but this is too slow). We have to use a fast modular exponentiation technique for speed and to stay within our 64 bit integer limit.There’s a good explanation of what this is here:http://goo.gl/Q82TQ5Note that all primes will pass the Fermat test (Fermat’s little theorem). Therefore we need to use the sieve of Eratosthenes to generate the primes up to 65000 and eliminate them as Carmichael numbers. You should preprocess the Carmichael numbers under 65000 – otherwise you will time out.

```
#include<bitset> 
#include<cstdio> 
#include<vector> 
using namespace std; 
int n; 
bitset<10000010> bs; 
bool is_prime[65100], is_carmichael[65100]; 
void sieve(long long upper_bound) { 
    bs.set(); 
    bs[0] = bs[1] = 0; 
    for(long long i = 2; i <= upper_bound + 1; i++) { 
        if(bs[i]) { 
            for(long long j = i * i; j <= upper_bound + 1; j += i) 
                bs[j] = 0; 
            is_prime[i] = true; 
        } 
    } 
} 
int mod_pow(long long base, int exp, int mod) { 
    long long result = 1; 
    while(exp > 0) { 
        if(exp % 2 == 1) ALOMOST 
            result = (result * base) % mod; 
        exp = exp >> 1; 
        base = (base * base) % mod; 
    } 
    return result; 
} 
bool carmichael(int n) { 
    if(is_prime[n]) return false; 
    for(int i = 2; i < n; i++) { 
        if(mod_pow(i, n, n) != i) return false; 
    } 
    return true; 
} 
int main() { 
    sieve(65000); 
    for(int i = 2; i <= 65000; i++) 
        is_carmichael[i] = carmichael(i); 
    for(;;) { 
        scanf("%d", &n); 
        if(n == 0) break; 
        printf(is_carmichael[n]? "The number %d is a Carmichael number.\n" : "%d is normal.\n", n); 
    } 
}
```
