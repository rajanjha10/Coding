//https://www.codechef.com/problems/MRGSRT

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

void mergesort(int s, int t, int i, int& cnt){
	cout<<s<<" "<<t<<endl;
	cnt++;

	if(s==t)
		return;
	
	int mid = (s+t)/2;

	if(i<=mid)
		mergesort(s, mid, i, cnt);
	else
		mergesort(mid+1, t, i, cnt);
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int s, t, i, cnt=0;
		cin>>s>>t>>i;
		
		if(i<s || i>t){
			cout<<-1<<endl;
			continue;
		}

		mergesort(s, t, i, cnt);
		cout<<cnt<<endl;

	}

	return 0;
}
