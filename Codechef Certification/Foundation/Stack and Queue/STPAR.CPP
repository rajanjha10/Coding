//https://www.spoj.com/problems/STPAR/

#include<bits/stdc++.h>
#define LL long long
#define M 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl;
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
    fastio;
    int n;
    cin>>n;
    while(n!=0){
    	int a[n], flag=0, currCar=1, i=0;
    	read(a, n);
    	stack<int> sideStreet;
    	while(i<n){
    		if(a[i]==currCar){
    			currCar++;
    			i++;
    		}
    		else if(sideStreet.empty()){
    			sideStreet.push(a[i]);
    			i++;
    		}
    		else if(sideStreet.top()==currCar){
    			sideStreet.pop();
    			currCar++;
    		}
    		else if(a[i]<sideStreet.top()){
    			sideStreet.push(a[i]);
    			i++;
    		}
    		else{
    			flag=1;
    			break;
    		}
    	}

    	if(flag)
    		cout<<"no"<<endl;
    	else
    		cout<<"yes"<<endl;
    	
    	cin>>n;
    }
    return 0;    
}
