//https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/

void calmax(float a, float *max1A, float *max2A, float *max3A){
    if(a>*max1A){
        *max3A = *max2A;
        *max2A = *max1A;
        *max1A = a;
    }
    else if(a>*max2A){
        *max3A = *max2A;
        *max2A = a;
    }
    else if(a>*max3A)
        *max3A = a;
}

void calmin(float a, float *min1, float *min2){
    if(a<*min1){
        *min2 = *min1;
        *min1 = a;
    }
    else if(a<*min2)
        *min2 = a;
}

bool underflow(float max1A,float max2A,float max3A,float maxB){
    if((max1A + max2A + max3A)>1.0)
        return 1;
    if((max1A + max2A + maxB)>1.0 && (max1A + max2A + maxB)<2.0)
        return 1;
    return 0;
}

bool overflow(float min1A, float min2A, float min1B, float min2B, float minC){
    if((min1A+min2A+min1B)>1.0 && (min1A+min2A+min1B)<2.0)
        return 1;
    if((min1A+min2A+minC)<2.0)
        return 1;
    if((min1A+min1B+min2B)<2.0)
        return 1;
    if((min1A+min1B+minC)<2.0)
        return 1;
    return 0;
}

int Solution::solve(vector<string> &A) {
    if(A.size()<3)
        return 0;
    vector<float> a(A.size());
    float min1A, min2A, min1B, min2B, minC;
    min1A = min2A = min1B = min2B = minC = INT_MAX;
    float max1A, max2A, max3A, maxB;
    max1A = max2A = max3A = maxB = INT_MIN;
    for(int i=0; i<A.size(); i++){
        a[i]=float(stof(A[i]));
        if(a[i]<2.0/3){
            calmin(a[i], &min1A, &min2A);
            calmax(a[i], &max1A, &max2A, &max3A);
        }
        else if(a[i]<1.0){
            calmin(a[i], &min1B, &min2B);
            maxB = max(maxB, a[i]);
        }
        else if(a[i]<2.0)
            minC = min(minC, a[i]);
    }
    return underflow(max1A, max2A, max3A, maxB) || overflow(min1A, min2A, min1B, min2B, minC);   
}
