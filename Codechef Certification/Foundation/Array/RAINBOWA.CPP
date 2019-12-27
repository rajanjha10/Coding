//https://www.codechef.com/problems/RAINBOWA

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
    int t;
    cin>>t;
    while(t--){
    	int n, flag=0, c=1;
    	cin>>n;
    	int a[n];
    	read(a, n);
    	map<int, bool> mark;
    	for(int i=0; i<n; i++)
    		mark[a[i]]=1;
    	for(int i=1; i<=7; i++)
    		if(mark[i]==0){
    			cout<<"no"<<endl;
    			flag=1;
    			break;
    		}
    	if(flag)
    		continue;
    	for(int i=0, j=n-1; i<=(n-1)/2; i++, j--){
    		if((a[i]-c)>1 || a[i]<c || a[i]!=a[j] || a[i]>7 || a[j]>7){
    			flag=1;
    			break;
    		}
    		if(c!=a[i])
    			c = a[i];
    	}
    	if(flag)
    		cout<<"no"<<endl;
    	else
    		cout<<"yes"<<endl;
    }
    return 0;    
}
