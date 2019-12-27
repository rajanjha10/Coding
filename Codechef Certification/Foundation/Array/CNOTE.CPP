//https://www.codechef.com/problems/CNOTE

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
    	int n, x, y, k, p, c, flag=0;
    	cin>>x>>y>>k>>n;
    	x-=y;
    	for(int i=0; i<n; i++){
    		cin>>p>>c;
    		if(!flag && p>=x && c<=k)
    			flag=1;	
    	}
    	if(flag)
    		cout<<"LuckyChef"<<endl;
    	else
    		cout<<"UnluckyChef"<<endl;
    }
    return 0;    
}
