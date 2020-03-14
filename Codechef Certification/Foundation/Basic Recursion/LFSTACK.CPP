#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

bool eval(vector<int> p, vector<vector<int> > b, int index){

	if(index==p.size())
		return true;

	for(int i=0; i<b.size(); i++){
		if(!b[i].empty() && b[i].back()==p[index]){
			b[i].pop_back();
			if(eval(p, b, index+1))
				return true;
			b[i].push_back(p[index]);
		}
	}

	return false;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--){
		int n, a, ps=0, flag=0;
		cin>>n;
		vector<vector<int> > b(n);
		for(int i=0; i<n; i++){
			cin>>a;
			ps+=a;
			b[i] = vector<int>(a);
			read(b[i], a);
		}

		vector<int> p(ps);
		read(p, ps);
		
		if(eval(p, b, 0))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}

	return 0;
}
