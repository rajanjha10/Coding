// https://www.codechef.com/FLPAST01/problems/RADGEE

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
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;

		LL a[n+m/2], b[n+m/2], c[m];
		read(a, n);
		read(b, n);
		read(c, m);

		int cnta=0, cntb=0;
		int i, j, k;
		for(i=0, j=0, k=n; i<n && j<m; i++, j+=2, k++){
			if(a[i]>b[i]){
				cnta++;
				a[k] = c[j];
				b[k] = c[j+1];
			}
			else{
				cntb++;
				a[k] = c[j+1];
				b[k] = c[j];
			}
		}

		while(i<n+m/2){
			if(a[i]>b[i])
				cnta++;
			else
				cntb++;
			i++;
		}

		if(cnta>cntb)
			cout<<"Radhesh wins\n";
		else if(cnta==cntb)
			cout<<"Tie\n";
		else
			cout<<"Geethakoomaree wins\n";

	}

	return 0;
}
