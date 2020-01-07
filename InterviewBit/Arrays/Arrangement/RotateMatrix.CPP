//https://www.interviewbit.com/problems/rotate-matrix/

void Solution::rotate(vector<vector<int> > &A){
    int n=A.size();
    for(int i=0; i<n/2; i++){
        for(int j=i; j<n-i-1; j++){
            int temp = A[i][j];
            A[i][j] = A[n-j-1][i];
            A[n-j-1][i] = A[n-i-1][n-j-1];
            A[n-i-1][n-j-1] = A[j][n-i-1];
            A[j][n-i-1] = temp;
        }
    } 
}

//A more Intuitive Approach
void Solution::rotate(vector<vector<int> > &A){
    int n=A.size();
    //transpose
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            swap(A[i][j], A[j][i]);
        }
    }
    //flip
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            swap(A[i][j], A[i][n-1-j]);
        }
    }
}

