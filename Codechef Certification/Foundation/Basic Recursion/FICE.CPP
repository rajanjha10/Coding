//https://www.codechef.com/problems/FICE

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

string memo[1010];

string sum(string str1, string str2) 
{ 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    string str = ""; 
  
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
  
    int carry = 0; 
  
    for (int i=n1-1; i>=0; i--) 
    { 
        int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    if (carry) 
        str.push_back(carry+'0'); 
  
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

uint64_t mod(string num, int a) 
{ 
    uint64_t res = 0; 
  
    for(int i=0; i<num.length(); i++) 
        res = (res*10 + (int)num[i] - '0') %a; 
  
    return res; 
} 

string eval(int n){
    if(n<0)
        return "";
    if(n==0)
        return "1";
    if(!memo[n].empty())
        return memo[n];
    
	string res="";
	for(int i=1; i<=n; i+=2)
		res = sum(res, eval(n-i));

	return memo[n]=res;
}

int main()
{
	fastio;
	int t;
	cin>>t;
	for(int i=0; i<=1000; i++)
	    memo[i] = "";

	memo[1]="1";
	eval(1001);

	while(t--){
		int n, m;
		cin>>n>>m;
		uint64_t ans = (mod(memo[n], m) * 2)%m;
		cout<<ans<<endl;
	}

	return 0;
}
