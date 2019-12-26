//https://www.hackerrank.com/challenges/arrays-ds/problem

#include<bits/stdc++.h>
#define LL long long
#define M 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]; cout<<endl;
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
    fastio;
    int n, i;
    cin>>n;
    int a[n];
    read(a, n);
    for(i=n-1; i>=0; i--)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;    
}
