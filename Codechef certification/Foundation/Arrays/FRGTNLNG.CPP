//https://www.codechef.com/problems/FRGTNLNG

#include<bits/stdc++.h>
#include<unordered_map>
#define LL long long
#define M 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]; cout<<endl;
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
    fastio;
    int t;
    cin>>t;
    while(t--){
    	int n, k, i, l;
    	cin>>n>>k;
    	unordered_map<string, string> a;
    	string in[n];
    	string s;
    	for(i=0; i<n; i++){
    		cin>>s;
    		a[s]="NO";
    		in[i] = s;
    	}
    	while(k--){
    		cin>>l;
    		for(i=0; i<l; i++){
    			cin>>s;
    			if(a.find(s)!=a.end())
    				a[s]="YES";
    		}
    	}
    	for(i=0; i<n; i++)
    		cout<<a[in[i]]<<" ";
    	cout<<endl;
    }
    return 0;    
}
