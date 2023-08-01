#include<bits/stdc++.h>
using namespace std;

int pkele(vector<int> nums){
    for(int i=0; i<nums.size(); i++){
        if((i==0|| nums[i]>nums[i-1]) && (i==nums.size()-1 || nums[i]>nums[i+1]))
            return i;
    }
    return -1;
}

int peakelement(vector<int> vec){
    int n=vec.size();
    if(n==1) return 0;

    if(vec[0]>vec[1]) return 0;

    if(vec[n-1]>vec[n-2]) return n-1;

    int left=1, right=n-2;

    while(left<=right){
        int mid=left+(right-left)/2;

        if(vec[mid]>vec[mid-1] && vec[mid]>vec[mid+1]){
            return mid;
        }

        else if(vec[mid]>vec[mid-1]) left=mid+1;
        // if(vec[mid]>vec[mid+1])
        else right=mid-1;
    }
    return -1;
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<peakelement(v);
}