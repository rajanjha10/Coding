//https://www.hackerrank.com/challenges/sparse-arrays/problem

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
    int n;
    cin>>n;
    map<string, int> a;
    string s;
    while(n--){
    	cin>>s;
    	if(a.find(s)!=a.end())
    		a[s]++;
    	else
    		a[s]=1;
    }
    cin>>n;
    while(n--){
    	cin>>s;
    	if(a.find(s)!=a.end())
    		cout<<a[s]<<endl;
    	else
    		cout<<0<<endl;
    }
    return 0;    
}
