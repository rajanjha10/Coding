//https://www.spoj.com/problems/JNEXT/

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
    	LL n, dindex, i, sindex;
    	cin>>n;
    	int a[n];
    	read(a, n);
    	for(i=n-1;i>0; i--){
    		if(a[i]>a[i-1])
    			break;
    	}
    	if(i==0){
    		cout<<-1<<endl;
    		continue;
    	}
    	dindex=i-1;
    	sindex=i;
    	for(i=i+1; i<n; i++){
    		if(a[i]>a[dindex] && a[i]<a[sindex])
    			sindex = i;
    	}
    	swap(a[dindex], a[sindex]);
    	sort(a+dindex+1, a+n);
    	print(a, n);
    }    
}
