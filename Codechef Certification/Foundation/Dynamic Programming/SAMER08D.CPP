//https://www.spoj.com/problems/SAMER08D/

#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

int main()
{
  fastio;
  int k;
  while(cin>>k){
    if(k==0)
      break;

    string s1, s2;
    cin>>s1>>s2;
    int n1 = s1.size(), n2 = s2.size();
    int dp[n1+1][n2+1], comSub[n1+1][n2+1];

    memset(dp, 0, sizeof(dp));
    memset(comSub, 0, sizeof(comSub));

    for(int i=1; i<=n1; i++){
      for(int j=1; j<=n2; j++)
        if(s1[i-1]==s2[j-1])
          comSub[i][j] = comSub[i-1][j-1] + 1;
    }

    for(int i=1; i<=n1; i++){
      for(int j=1; j<=n2; j++){
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        if(comSub[i][j]>=k){
          for(int x=k; x<=comSub[i][j]; x++)
            dp[i][j] = max(dp[i][j], x + dp[i-x][j-x]);
        }
      }
    }

    cout<<dp[n1][n2]<<endl;
  }

  return 0;
}

//Improved time complexity
int main()
{
  fastio;
  int k;
  while(cin>>k){
    if(k==0)
      break;

    string s1, s2;
    cin>>s1>>s2;
    int n1 = s1.size(), n2 = s2.size();
    int dp[n1+1][n2+1][2], comSub[n1+1][n2+1];

    memset(dp, 0, sizeof(dp));
    memset(comSub, 0, sizeof(comSub));

    for(int i=1; i<=n1; i++){
      for(int j=1; j<=n2; j++)
        if(s1[i-1]==s2[j-1])
          comSub[i][j] = comSub[i-1][j-1] + 1;
    }

    for(int i=1; i<=n1; i++){
      for(int j=1; j<=n2; j++){
        dp[i][j][0] = dp[i][j][1] = max(dp[i-1][j][1], dp[i][j-1][1]);

        if(s1[i-1]==s2[j-1]){
          dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][0] + 1);
          
          if(comSub[i][j]>=k)
            dp[i][j][1] = max(dp[i][j][1], k + dp[i-k][j-k][0]);
        }
      }
    }

    cout<<dp[n1][n2][1]<<endl;
  }

  return 0;
}

