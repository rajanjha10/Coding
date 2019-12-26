//https://www.codechef.com/problems/COPS

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
    	int x, y, m, i, ans=0, p=0;
    	cin>>m>>x>>y;
    	x = x*y;
    	int a[m];
    	read(a, m);
    	sort(a, a+m);
    	for(i=0; i<m; i++){
    		if(a[i]-x>p)
    			ans += (a[i]-x)-p-1;
    		p = a[i]+x;
    		if(p>100)
    			break;
    	}
    	if(p<100)
    		ans+=100-p;
    	cout<<ans<<endl;
    }
    return 0;    
}
