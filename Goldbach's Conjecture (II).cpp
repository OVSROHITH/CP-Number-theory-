 686 - Goldbach's Conjecture (II)



```
#include<bits/stdc++.h> 
#define M 1000009 
using namespace std; 
bool marked[M]; 
vector<int>vec; 
void sieve(int n) 
{ 
    for(int i=4; i<=n; i+=2) 
        marked[i]=true; 
    for(int i=3; i*i<=n; i+=2) 
    { 
        if(marked[i]==false) 
        { 
            for(int j=i*i; j<=n; j+=i) 
            { 
                marked[j]=true; 
            } 
        } 
    } 
    vec.push_back(2); 
    for(int i=3; i<=n; i+=2) 
    { 
        if(marked[i]==false) 
        { 
            vec.push_back(i); 
        } 
    } 
} 
main() 
{ 
    int m,r,f,i,t; 
    sieve(1000009); 
    int n; 
   while (cin >> n) { 
		if (n == 0) break; 
		int pos = 0; 
		int counter = 0; 
		while (vec[pos] <= n/2) { 
		 auto it = find (vec.begin(), vec.end(), n - vec[pos]); 
			if (it != vec.end()) counter++; 
			++pos; 
		} 
		cout << counter << endl; 
	} 
}
```
