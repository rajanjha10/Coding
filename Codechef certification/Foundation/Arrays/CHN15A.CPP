//https://www.codechef.com/problems/CHN15A

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
    	int n, k, cnt=0, a;
    	cin>>n>>k;
    	for(int i=0; i<n; i++){
    		cin>>a;
    		if(((a+k)%7)==0)
    			cnt++;
    	}
    	cout<<cnt<<endl;
    }
    return 0;    
}
