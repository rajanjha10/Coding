#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;
  
int decode(char c){
	if(c<='9')
		return c - '0';
	else
		return c - 'A' + 10;
}

vector<bool> sides(int x){
	vector<bool> s(4, 1);
	int i=0;
	while(x){
		if(x&1)
			s[i]=0;
		
		i++;
		x>>=1;
	}

	return s;
}

int main()
{
	fastio;
	int cnt = 1;
	while(1){
		int n, m;
		cin>>n>>m;
		if(n==0 && m==0)
			break;

		int row[n+1][m], col[n][m+1];
		memset(row, -1, sizeof(row));
		memset(col, -1, sizeof(col));

		cout<<"Maze "<<cnt<<": "<<"\n";
		for(int i=0, x=-1, y=0; i<n*m; i++, y=(y+1)%m){
			char c;
			cin>>c;

			if(y==0)
				x++;

			int d = decode(c);
			cout<<d<<": ";
			vector<bool> v = sides(d);
			print(v, v.size());

			if(row[x][y]==-1)
				row[x][y] = v[0];
			else if((v[0] && row[x][y]==0) || (!v[0] && row[x][y]))
				row[x][y] = 2;

			if(row[x+1][y]==-1)
				row[x+1][y] = v[2];
			else if((v[2] && row[x+1][y]==0) || (!v[2] && row[x+1][y]))
				row[x+1][y] = 2;

			if(col[x][y]==-1)
				col[x][y] = v[3];
			else if((v[3] && col[x][y]==0) || (!v[3] && col[x][y]))
				col[x][y] = 2;
			
			if(col[x][y+1]==-1)
				col[x][y+1] = v[1];
			else if((v[1] && col[x][y+1]==0) || (!v[1] && col[x][y+1]))
				col[x][y+1] = 2;		

			cout<<row[x][y]<<" "<<row[x+1][y]<<" "<<col[x][y]<<" "<<col[x][y+1]<<endl;
			cout<<endl;
			
		}

		for(int i=0; i<=n; i++){
			for(int j=0; j<m; j++)
				cout<<row[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;

		for(int i=0; i<n; i++){
			for(int j=0; j<=m; j++)
				cout<<col[i][j]<<" ";
			cout<<endl;
		}

	}
	return 0;
}
