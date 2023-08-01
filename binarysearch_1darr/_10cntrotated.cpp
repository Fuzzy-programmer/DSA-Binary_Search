#include<bits/stdc++.h>
using namespace std;

int cntrotated(vector<int> nums){
    int idx=-1;
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i]>nums[i+1])
            idx=i;
    }
    return idx+1;
}

int cntrotationsarr(vector<int> arr){
    int low=0, high=arr.size()-1, idx=-1;

    while(low<=high){
        int mid=low+(high-low)/2;
        // Optimization
        if(arr[low]<=arr[high]){
            idx=low;
            break;
        }

        if(arr[mid]<=arr[high]){
            idx=mid;
            high=mid-1;
        }
        else{
            idx=low;
            low=mid+1;
        }
    }
    return idx;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<cntrotated(v);
}