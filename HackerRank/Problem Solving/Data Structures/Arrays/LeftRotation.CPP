//https://www.hackerrank.com/challenges/array-left-rotation/problem

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
    int n, d;
    cin>>n>>d;
    int a[n], i=d;
    read(a, n);
    do{
    	cout<<a[i]<<" ";
    	i=(i+1)%n;
    }while(i!=d);
    cout<<endl;
    return 0;    
}
