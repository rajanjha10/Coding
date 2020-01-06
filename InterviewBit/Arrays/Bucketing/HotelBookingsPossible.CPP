//https://www.interviewbit.com/problems/hotel-bookings-possible/

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int cnt=1, i=1, j=0;
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    while(i<arrive.size() && j<depart.size()){
        if(arrive[i]>=depart[j]){
            cnt--;
            j++;
        }
        else{
            cnt++;
            i++;
        }
        if(cnt>K)
            return false;
    }
    return true;
}
