// https://www.codechef.com/problems/TSORT

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

LL partition(LL a[], LL s, LL e){
    LL i = s, j = e+1;
    
	while(true){
	    while(a[++i]<a[s])
	        if(i==e) break;
	        
	    while(a[s]<a[--j])
	        if(j==s) break;
	        
	   	if(i>=j)
	        break;
	        
       	swap(a[i], a[j]);
	}
	
	swap(a[s], a[j]);
	return j;
}

void quick_sort(LL a[], LL s, LL e){
	if(s<e){
		LL p = partition(a, s, e);
		quick_sort(a, s, p-1);
		quick_sort(a, p+1, e); 
	}
}

int main()
{
	fastio;
	LL n;
	cin>>n;
	LL a[n];
	read(a, n);
	quick_sort(a, 0, n-1);
	
	for(LL i=0; i<n; i++)
		cout<<a[i]<<endl;

	return 0;
}
