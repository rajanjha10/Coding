//http://www.spoj.com/problems/HISTOGRA/

#include<bits/stdc++.h>
#define LL long long
#define M 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
    fastio;
    while(1){
        int n;
        cin>>n;
        if(!n)
            break;
        LL h[n+1], maxArea = INT_MIN;
        read(h, n);
        h[n]=-1;
        stack<int> index;
        for(int i=0; i<=n; i++){
            if(index.empty() || h[i]>=h[index.top()])
                index.push(i);
            else{
                while(!index.empty() && h[i]<h[index.top()]){
                    int maxHIndex = index.top();
                    index.pop();

                    if(index.empty())
                        maxArea = max(maxArea, h[maxHIndex]*i);
                    else
                        maxArea = max(maxArea, h[maxHIndex] * (i - index.top() -1));
                }
                index.push(i);
            }
        }
        
        cout<<maxArea<<endl;
    }
    return 0;    
}