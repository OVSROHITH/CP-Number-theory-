Rational Numbers from Repeating Fractions


```
#include<bits/stdc++.h> 
using namespace std; 
int main() 
{ 
  int n,k; 
  while(cin>>n && n!=-1) 
  { 
    string s; 
    cin>>s; 
    long long a=0,b=0,p1=1,p2=1; 
    long long l=s.length()-n-2; 
    for(int i=2;i<s.length();i++) 
    { 
        a=a*10; 
        a+=s[i]-'0'; 
        p1*=10; 
        if(i-1==l) 
        { 
                b = a; 
                p2 = p1; 
         }     
    } 
     int c=1; 
     if (n != 0) a -= b, p1 -= p2;  
        long long  g =__gcd(a, p1);  
        a /= g, p1 /= g; 
        printf("Case %d: %lld/%lld\n", c++, a, p1); 
    } 
    return 0; 
}
```
