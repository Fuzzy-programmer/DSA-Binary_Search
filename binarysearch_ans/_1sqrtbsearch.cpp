#include<bits/stdc++.h>
using namespace std;

int floorsqrt(int n){
    int ans=1;
    for(int i=0; i<n; i++){
        long long val=i*i;
        if(val<=n)
            ans=i;
        else break;
    }
    return ans;
}

int florqrt(int n){
    return sqrt(n);
}

int FloorSqrt(int n){
    int low=0, high=n;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(mid*mid<=n) low=mid+1;

        else high=mid-1;
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    cout<<FloorSqrt(n)<<endl; 
}