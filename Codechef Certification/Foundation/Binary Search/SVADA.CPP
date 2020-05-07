// https://www.spoj.com/problems/SVADA/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

const int maxN = 110, maxM = 110;
LL a[maxN][2], b[maxM][2];

bool eval(LL k, LL n, LL m, LL t){
	LL cnt1 = 0, cnt2 = 0;
	for(int i=0; i<n; i++)
		if(k-a[i][0]>=0)
			cnt1 += (k-a[i][0])/a[i][1] + 1; 
	
	for(int i=0; i<m; i++){
		if(t-k-b[i][0]>=0)
			cnt2 += (t-k-b[i][0])/b[i][1] + 1;
	}

	return cnt1<=cnt2;
}

int main()
{
	fastio;
	LL t;
	cin>>t;
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i][0]>>a[i][1];

	int m;
	cin>>m;
	for(int i=0; i<m; i++)
		cin>>b[i][0]>>b[i][1];

	LL low = 0, high = t;
	while(low<high){
		LL mid = low + (high-low+1)/2;
		if(eval(mid, n, m, t))
			low = mid;
		else
			high = mid - 1;
 	}

 	cout<<low<<"\n";

	return 0;
}
