//https://www.spoj.com/problems/MMASS/

#include<bits/stdc++.h>
#define LL long long
#define M 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int eval_mass(char a){
	if(a=='H')
		return 1;
	if(a=='C')
		return 12;
	
	return 16;
}

int main()
{
    fastio;
    string s;
    stack<int> mass;
    cin>>s;
    for(int i=0; i<s.size(); i++){
    	if(isdigit(s[i])){
    		int m = mass.top();
    		mass.pop();
    		mass.push(m*(s[i]-'0'));
    	}
    	else if(s[i]=='(')
    		mass.push(-1);
    	else if(s[i]==')'){
    		int m = 0;
    		while(mass.top()!=-1){
    			m += mass.top();
    			mass.pop();
    		}
    		mass.pop();
    		mass.push(m);
    	}
    	else
    		mass.push(eval_mass(s[i]));	
    	
    }
    int ans=0;
    while(!mass.empty()){
    	ans += mass.top();
    	mass.pop();
    }

    cout<<ans<<endl;

    return 0;    
}

//By expanding the given formula
int main()
{
    fastio;
    string s, exps="";
    int mass=0;
    stack<int> index;
    cin>>s;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(')
            index.push(exps.size());
        else if(s[i]==')'){
            if(!isdigit(s[i+1])){
                index.pop();
                continue;
            }
            int cnt = s[i+1]-'0'-1;
            string add = exps.substr(index.top());
            index.pop();
            while(cnt--)
                exps += add;
            i++;
        }
        else{
            if(isdigit(s[i])){
                for(int j=0; j<s[i]-'0'-1; j++)
                    exps += s[i-1]; 
            }
            else
                exps += s[i];
        }
    }
    for(int i=0; i<exps.size(); i++)
        mass += eval_mass(exps[i]);

    cout<<mass<<endl;

    return 0;    
}