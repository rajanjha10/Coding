#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(a, n) for(LL e=0; e<n; e++) cout<<a[e]<<" "; cout<<endl
#define read(a, n) for(LL e=0; e<n; e++) cin>>a[e];
using namespace std;

vector<LL> pow3, pown3, powAll;
const LL limit = 3141LL * 3141LL * 3141LL * 3141LL * 3141LL;

LL my_sqrt(LL x){
	LL y = sqrt(x);

	while(y*y > x)
		y--;
	
	while((y+1)*(y+1) <= x)
		y++;

	return y;
}

bool is_square(LL x){
	LL y = my_sqrt(x);
	if(y*y == x)
		return true;

	return false;
}

void powers(){
	for(LL i=2; ; i++){
		if(is_square(i))
			continue;

		LL x = i*i*i;
		if(x > limit)
			break;

		pow3.push_back(x);
	}
    
	for(LL i=2; i<=3141; i++){
		if(is_square(i))
			continue;

		LL x = i*i*i*i*i;
		while(1){
			pown3.push_back(x);

			if(x > limit/ i / i)
				break;

			x *= i*i;
		}
	}
    
	sort(pown3.begin(), pown3.end());
	powAll.resize(pow3.size() + pown3.size());

	merge(pow3.begin(), pow3.end(), pown3.begin(), pown3.end(), powAll.begin());
	powAll.erase(unique(powAll.begin(), powAll.end()), powAll.end());
}

LL binary_search(LL x){
	LL ans = (LL)log2(x);

	if(pow(2, ans) == x)
		return ans;

	ans += 1;
	LL high = pow(2, ans), low = high/2;
	while(low<=high){
		ans++;
		LL mid = (low + high)/2;

		if(mid==x)
			break;

		if(mid > x)
			high = mid;
		else
			low = mid;
	}

	return ans;
}

LL eval(LL x){
	if(x<=1)
		return 2-x;

	LL y = my_sqrt(x);
	LL index = lower_bound(powAll.begin(), powAll.end(), x) - powAll.begin();
	bool exists = (index<powAll.size() && powAll[index]==x);
	bool square = (y*y==x);

	if(square || exists)
		return (y-1) + (index+1) - square;
	else
		return binary_search(x+1 - (y-1) - index);
}

int main()
{
	fastio;
	powers();
	LL n, a;
	cin>>n;

	for(LL i=0; i<n; i++){
		cin>>a;
		cout<<eval(a)<<" ";
	}
	cout<<endl;

	return 0;
}
