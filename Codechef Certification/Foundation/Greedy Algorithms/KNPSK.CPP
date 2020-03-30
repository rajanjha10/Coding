//https://www.codechef.com/problems/KNPSK

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
	int n;
	cin>>n;
	vector<LL> w1, w2;
	int w;
	LL c, sum=0;

	while(n--){
		cin>>w>>c;
		sum += w;
		if(w==1)
			w1.push_back(c);
		else
			w2.push_back(c);
	}

	sort(w1.begin(), w1.end(), greater<LL>());
	sort(w2.begin(), w2.end(), greater<LL>());
	
	int n1=w1.size(), n2=w2.size();
	LL ansOdd = 0, ansEven = 0;
	int cnto1=0, cnto2=0, cnte1=0, cnte2=0;

	if(cnto1<n1)
		ansOdd += w1[cnto1++];
	cout<<ansOdd<<" ";

	for(LL i=2; i<=sum; i++){
		c = 0;
		if(i&1){
			if(cnto1<n1)
				c = w1[cnto1];
			if(cnto1+1<n1)
				c += w1[cnto1+1];

			if(cnto2<n2 && w2[cnto2]>c){
				ansOdd += w2[cnto2];
				cnto2++;
			}
			else if(c!=0){
				ansOdd += c;
				cnto1 += (cnto1<n1) + ((cnto1+1)<n1);
			}
			
			cout<<ansOdd<<" ";
		}
		else{
			if(cnte1<n1)
				c = w1[cnte1];
			if(cnte1+1<n1)
				c += w1[cnte1+1];

			if(cnte2<n2 && w2[cnte2]>c){
				ansEven += w2[cnte2];
				cnte2++;
			}
			else if(c!=0){
				ansEven += c;
				cnte1 += (cnte1<n1) + ((cnte1+1)<n1);
			}
			
			cout<<ansEven<<" ";
		}		
	}
	
	return 0;
}
