//https://www.hackerrank.com/challenges/dynamic-array/problem

#include<bits/stdc++.h>
#define LL long long
#define M 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]; cout<<endl;
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
    fastio;
    int n, q, i;
    cin>>n>>q;
    LL lans=0;
    vector<vector<LL> > seqlist(n);
    int t, x, y;
    for(i=0; i<q; i++){
    	cin>>t>>x>>y;
    	int seq = (lans^x)%n;
    	if(t==1)
    		seqlist[seq].push_back(y);
    	else{
    		int size = seqlist[seq].size();
    		lans = seqlist[seq][y%size];
    		cout<<lans<<endl;
    	}
    }
    return 0;    
}
