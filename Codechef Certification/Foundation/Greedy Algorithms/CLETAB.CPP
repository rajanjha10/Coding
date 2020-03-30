//https://www.codechef.com/problems/CLETAB

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
		int c[m];
		read(c, m);

		int order[m][401];

		for(int i=0; i<m; i++){
			for(int j=0; j<401; j++)
				order[i][j] = INT_MAX;
		}

		order[m-1][c[m-1]] = m-1;
		for(int i=m-2; i>=0; i--){
			order[i][c[i]] = i;
			
			for(int j=0; j<401; j++)
				order[i][j] = min(order[i][j], order[i+1][j]);
		}

		int a[n], ans=0;
		memset(a, -1, sizeof(a));

		for(int i=0; i<m; i++){
			int maxIndex = -1, maxOrder=INT_MIN, flag=0;

			for(int j=0; j<n; j++){
				if(a[j]==c[i]){
					flag = 1;
					break;
				}

				if(a[j]==-1){
					maxIndex = j;
					break;
				}

				if(order[i][a[j]]>maxOrder){
					maxOrder = order[i][a[j]];
					maxIndex = j;
				}				
			}

			if(!flag){
				a[maxIndex] = c[i];
				ans++;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}
