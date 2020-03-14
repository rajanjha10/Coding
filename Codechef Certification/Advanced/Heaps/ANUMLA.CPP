//https://www.codechef.com/problems/ANUMLA

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
		multiset<LL> mh;
		LL a;
		for(int i=0; i<(1<<n); i++){
			cin>>a;
			if(a==0)
				continue;
			mh.insert(a);
		}

		if(n==1){
			cout<<*mh.begin()<<endl;
			continue;
		}

		vector<LL> ans, sums;
		LL first = *mh.begin();
		mh.erase(mh.begin());
		LL second = *mh.begin();
		mh.erase(mh.begin());

		ans.push_back(first);
		ans.push_back(second);
		sums.push_back(first+second);
		mh.erase(mh.find(first+second));

		while(!mh.empty()){
			LL index = sums.size();

			for(LL i=0; i<ans.size(); i++)
				sums.push_back(*mh.begin()+ans[i]);
			for(LL i=0; i<index; i++)
				sums.push_back(*mh.begin()+sums[i]);

			ans.push_back(*mh.begin());
			mh.erase(mh.begin());

			for(LL i=index; i<sums.size(); i++)
				mh.erase(mh.find(sums[i]));
		}

		print(ans, n);
	}
	return 0;
}
