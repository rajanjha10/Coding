//https://www.hackerrank.com/challenges/crush/problem

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
    LL n, m, i;
    cin>>n>>m;
    map<long, long> arr;
    LL a, b, k;
    for(i=0; i<m; i++){
    	cin>>a>>b>>k;
    	if(b<a)
    		swap(a, b);
    	arr[a]+=k;
    	arr[b+1]-=k;
    }
    LL mx = arr[0], sum=0;
    for(auto it=arr.begin(); it!=arr.end(); it++){
    	sum+=it->second;
    	mx = max(sum, mx);
    }
    cout<<mx<<endl;
    return 0;    
}
