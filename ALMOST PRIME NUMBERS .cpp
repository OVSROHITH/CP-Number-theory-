ALMOST PRIME NUMBERS 



```
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
static char* primes; 
void cachePrimes(int n) 
{ 
    int i,j,k; 
    primes = (char*) malloc((n+1)*sizeof(char)); 
    for(i = 0;i<=n;i++) 
        primes[i] = 0; 
    primes[0]=1; 
    primes[1] = 1; 
    k = sqrt(n); 
    for(i = 2;i<=k;i++) 
        if(!primes[i]) 
            for(j=i*i;j<=n;j+=i) 
                primes[j] = 1; 
} 
int main() 
{ 
    cachePrimes(1000000); 
    int c ; 
    register long long int i; 
    register long long int j; 
    long long int almost[80070]; 
    long long int n,m; 
    int top = 0; 
    int count = 0; 
    for(i=2;i<=1000000;i++) 
        if(!primes[i]) 
            for(j=i*i;j<=1000000000000;j*=i) 
                almost[top++] = j; 
    scanf("%d",&c); 
    while(c>0) 
    { 
        scanf("%lld %lld",&n,&m); 
        count = 0; 
        for(i=0;i<80070;i++) 
            if(almost[i]>=n&&almost[i]<=m) 
                count++; 
        printf("%d\n",count); 
        c--; 
    } 
    return 0; 
}
```
