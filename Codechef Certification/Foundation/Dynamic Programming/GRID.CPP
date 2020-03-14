//https://www.codechef.com/problems/GRID

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
		int n;
		cin>>n;
		char a[n][n];
		read(a, n);

		int row[n][n], col[n][n];
		for(int i=0; i<n; i++){
			row[i][n-1] = (a[i][n-1]=='#')?0:1;
			for(int j=n-2; j>=0; j--){
				if(row[i][j+1]==0 || a[i][j]=='#')
					row[i][j] = 0;
				else
					row[i][j] = 1;
			}
		}

		for(int j=0; j<n; j++){
			col[n-1][j] = (a[n-1][j]=='#')?0:1;
			for(int i=n-2; i>=0; i--){
				if(col[i+1][j]==0 || a[i][j]=='#')
					col[i][j] = 0;
				else
					col[i][j] = 1;
			}
		}
		
		LL ans=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(row[i][j] && col[i][j])
					ans++;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}
