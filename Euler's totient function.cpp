Euler's totient function



counts the number of integers between 1 and n, inclusive, which are co-prime to n
. Two numbers are co-prime if their greatest common divisor equals 1

```
#include<bits/stdc++.h> 
using namespace std; 
long long  phi(long long n) { 
    long long result = n; 
    for (long long  i = 2; i * i <= n; i++) { 
        if (n % i == 0) { 
            while (n % i == 0) 
                n /= i; 
            result -= result / i; 
        } 
    } 
    if (n > 1) 
        result -= result / n; 
    return result; 
} 
int main() 
{ 
      long long n; 
   while(cin>>n && n!=0) 
   { 
       if(n==1) 
        { 
           cout<<"0/1"<<endl; 
           continue; 
        } 
      cout<<n<<"/"<<phi(n)<<endl; 
  } 
    return 0; 
}
```
