//https://www.interviewbit.com/problems/simple-queries/

#define LL long long

bool comp(const pair<int, LL> &p, const LL &v){
    return p.second<v;
}

int product_divisors(int a){
    LL m = 1000000007, p=1;
    for(int i=1; i*i<=a; i++){
        if(a%i==0){
            p = (p*i)%m;
            if(!(a/i==i))
                p = (p*(a/i))%m;
        }
    }
    return (int)(p+m)%m;
}

void frequency_cnt(vector<int> &l, vector<int> &r, vector<int> &A){
    fill(l.begin(), l.end(), 0);
    fill(r.begin(), r.end(), 0);
    stack<int> a;
    for(int i=0; i<A.size(); i++){
        while(!a.empty() && A[i]>=A[a.top()]){
            l[i] += l[a.top()] + 1;
            a.pop();
        }
        a.push(i);
    }
    
    while(!a.empty()) a.pop();
    
    for(int i=A.size()-1; i>=0; i--){
        while(!a.empty() && A[i]>A[a.top()]){
            r[i] += r[a.top()] + 1;
            a.pop();
        }
        a.push(i);
    }

}

void prefix_sum(vector<int> &l, vector<int> &r, vector<int> &A, vector<pair<int, LL> > &x){
    for(int i=0; i<A.size(); i++){
        x[i].first = product_divisors(A[i]);
        x[i].second = (l[i]+1)*(r[i]+1);
    }
    
    sort(x.begin(), x.end(), greater<pair<int, LL> >());
    for(int i=1; i<x.size(); i++)
        x[i].second+=x[i-1].second;    
    
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    vector<int> l(A.size()), r(A.size());
    vector<pair<int, LL> > x(A.size());
    
    frequency_cnt(l, r, A);
    prefix_sum(l, r, A, x);
    
    for(int i=0; i<B.size(); i++){
        int index = lower_bound(x.begin(), x.end(), B[i], comp) - x.begin();
        ans.push_back(x[index].first);
    }
    return ans;
}

//Another way to cal freq of each element as max element
//using Next greater Index (r) and Previous greater Index(l)
void frequency_cnt(vector<int> &l, vector<int> &r, vector<int> &A){
    fill(l.begin(), l.end(), -1);
    fill(r.begin(), r.end(), A.size());
    stack<int> a;
    for(int i=0; i<A.size(); i++){
        while(!a.empty() && A[i]>=A[a.top()]){
            r[a.top()] = i;
            a.pop();
        }
        a.push(i);
    }
    
    while(!a.empty()) a.pop();
    
    for(int i=A.size()-1; i>=0; i--){
        while(!a.empty() && A[i]>A[a.top()]){
            l[a.top()] = i;
            a.pop();
        }
        a.push(i);
    }

}

void prefix_sum(vector<int> &l, vector<int> &r, vector<int> &A, vector<pair<int, LL> > &x){
    for(int i=0; i<A.size(); i++){
        x[i].first = product_divisors(A[i]);
        x[i].second = (i-l[i])*(r[i]-i);
    }
    
    sort(x.begin(), x.end(), greater<pair<int, LL> >());
    for(int i=1; i<x.size(); i++)
        x[i].second+=x[i-1].second;    
    
}