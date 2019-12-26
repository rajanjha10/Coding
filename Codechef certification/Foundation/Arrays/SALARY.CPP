//https://www.codechef.com/problems/SALARY

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
    	LL cnt=0;
    	cin>>n;
    	int a[n];
    	read(a, n);
    	sort(a, a+n);
    	for(int i=1; i<n; i++)
    		cnt+=a[i]-a[0];
    	cout<<cnt<<endl;
    }
    return 0;    
}
