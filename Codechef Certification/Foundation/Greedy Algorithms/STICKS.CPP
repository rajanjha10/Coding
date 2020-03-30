//https://www.codechef.com/problems/STICKS

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

		int a[n];
		read(a, n);
		sort(a, a+n, greater<int>());

		int m1=-1, m2=-1;
		for(int i=0; i<n-1; i++){
			if(a[i]==a[i+1]){
				if(m1==-1)
					m1 = a[i];
				else
					m2 = a[i];
				i++;
			}

			if(m1!=-1 && m2!=-1)
				break;
		}

		if(m1==-1 || m2==-1)
			cout<<-1<<endl;
		else
			cout<<(LL)m1 * m2<<endl;
	}

	return 0;
}
