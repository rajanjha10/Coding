//https://www.codechef.com/problems/LECANDY

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
    	int n;
    	LL c, a;
    	cin>>n>>c;
    	for(int i=0; i<n; i++){
    		cin>>a;
    		c-=a;
    	}
    	if(c<0)
    		cout<<"No"<<endl;
    	else
    		cout<<"Yes"<<endl;
    }
    return 0;    
}
