//https://www.codechef.com/problems/TACHSTCK

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
	fastio;
	LL n, d, cnt=0;
	cin>>n>>d;
	LL a[n];
	for(LL i=0; i<n; i++)
		cin>>a[i];

	sort(a, a+n);

	for(LL i=1; i<n; i++){
		if(a[i]-a[i-1]<=d){
			cnt++;
			i++;
		}
	}
	
	cout<<cnt<<endl;
	
	return 0;
}
