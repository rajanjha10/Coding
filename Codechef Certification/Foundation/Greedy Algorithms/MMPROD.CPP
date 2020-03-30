//https://www.codechef.com/problems/MMPROD

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool cmp(const LL x, const LL y){
	return abs(x)>abs(y);
}

int sgn(LL v){
	return (v>0) - (v<0);
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;

		LL a[n];
		read(a, n);
		sort(a, a+n, cmp);

		LL ans=1;
		int s=1;
		for(int i=0; i<k; i++){
			ans = (ans * a[i])%MOD;
			s *= sgn(a[i]);
		}
		
		if(s>=0){
			cout<<(ans+MOD)%MOD<<endl;
			continue;
		}	

		int pk=-1, nk=-1, pok=-1, nok=-1;
		for(int i=k-1; i>=0; i--){
			if(a[i]<0 && nk==-1)
				nk = i;

			if(a[i]>0 && pk==-1)
				pk = i;

			if(nk!=-1 && pk!=-1)
				break;
		}

		for(int i=k; i<n; i++){
			if(a[i]<0 && nok==-1)
				nok = i;

			if(a[i]>0 && pok==-1)
				pok = i;

			if(nok!=-1 && pok!=-1)
				break;
		}

		ans = 1;

		if((pk==-1 || nok==-1) && (nk==-1 || pok==-1)){
			for(int i=n-1; i>=n-k; i--)
				ans = (ans * a[i])%MOD;
		}
		else if(pk==-1 || nok==-1){
			for(int i=0; i<k; i++){
				if(i==nk)
					ans = (ans * a[pok])%MOD;
				else
					ans  = (ans * a[i])%MOD;
			}
		}
		else if(nk==-1 || pok==-1){
			for(int i=0; i<k; i++){
				if(i==pk)
					ans  = (ans * a[nok])%MOD;
				else
					ans  = (ans * a[i])%MOD;
			}
		}
		else if(a[nk]*a[nok] > a[pk]*a[pok]){
			for(int i=0; i<k; i++){
				if(i==pk)
					ans  = (ans * a[nok])%MOD;
				else
					ans  = (ans * a[i])%MOD;
			}
		}
		else{
			for(int i=0; i<k; i++){
				if(i==nk)
					ans  = (ans * a[pok])%MOD;
				else
					ans = (ans * a[i])%MOD;
			}
		}

		cout<<(ans+MOD)%MOD<<endl;
	}

	return 0;
}
