Prime Ring Problem UVa-524
 
 https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=465





```
#include<stdio.h> 
#include<string.h> 
#include<algorithm> 
using namespace std; 
const int N=20; 
int n; 
int a[N],b[N];       //b is to check whether we have used it or  not untill now  //a strores the value
int p (int x) // prime number is determined; 
{ 
    if(x<2) 
        return 0; 
    else 
    { 
        for(int i=2;i*i<=x;i++) 
        { 
            if(x%i==0) 
                return 0; 
        } 
    } 
    return 1; 
} 
void dfs(int x) 
{ 
    if (x == n && p (a [1] + a [n])) // note interface ring; 
    { 
                 for (int i = 1; i <n; i ++) // output format attention; 
                       printf("%d ",a[i]); 
        printf("%d\n",a[n]); 
    } 
    else 
    { 
        for(int i=2; i<=n; i++) 
        { 
            if(b[i]==0&&p(a[x]+i)) 
            { 
                                 b [i] = 1; // tag is used; 
                                 a [x + 1] = i; // store down; 
                                 dfs (x + 1); // search for the next; 
                                 b [i] = 0; // back, changed back marker; 
            } 
        } 
    } 
    return ; 
} 
int main() 
{ 
    int c=0; 
    while(~scanf("%d",&n)) 
    { 
        memset(b,0,sizeof b); 
        a[1]=1; 
                 if (c!= 0) // Note that the output format; 
                    printf("\n"); 
        c++; 
        printf("Case %d:\n",c); 
                 dfs (1); // search; 
    } 
    return 0; 
}
```
