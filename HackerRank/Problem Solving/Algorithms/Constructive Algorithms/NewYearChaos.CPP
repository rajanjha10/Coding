//https://www.hackerrank.com/challenges/new-year-chaos/problem

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
    int t;
    cin>>t;
    while(t--){
    	int n, i, flag=0, cnt=0;
    	cin>>n;
    	int a[n];
    	read(a, n);
    	for(i=n-1; i>=0; i--){
    		if(a[i]==i+1)
    			continue;
    		if(a[i-1]==i+1)
    		{
    			cnt++;
    			swap(a[i], a[i-1]);
    		}
    		else if(a[i-2]==i+1){
    			cnt+=2;
    			swap(a[i-2], a[i-1]);
    			swap(a[i-1], a[i]);
    		}
    		else{
    			flag=1;
    			break;
    		}
    	}
    	if(flag)
    		cout<<"Too chaotic"<<endl;
    	else
    		cout<<cnt<<endl;
    }
    return 0;    
}
