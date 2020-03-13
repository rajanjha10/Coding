//https://www.hackerrank.com/challenges/2d-array/problem

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
    int a[6][6], i, j, k, m=INT_MIN;
    for(i=0; i<6; i++){
    	for(j=0; j<6; j++)
    		cin>>a[i][j];
    }
    for(i=0; i<4; i++){
    	for(j=0; j<4; j++){
    		int sum=0;
    		for(k=j; k<j+3; k++)
    			sum+=a[i][k]+a[i+2][k];
    		sum+=a[i+1][j+1];
    		m = max(m, sum);
    	}
    }
    cout<<m<<endl;
    return 0;    
}
