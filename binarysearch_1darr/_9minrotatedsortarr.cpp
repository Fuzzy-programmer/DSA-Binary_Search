#include<bits/stdc++.h>
using namespace std;

int mineleinrotatsortarr(vector<int> arr, int t){
    int mini=INT_MAX;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<mini)
            mini=arr[i];
    }
    return mini;
}

int minrotatsortarrelement(vector<int> nums){
    int low=0, high=nums.size()-1;
    int mini=INT_MAX;
    while(low<=high){
        int mid=low+(high-low)/2;

        // Optimization
        if(nums[low]<=nums[high]){
            mini=min(mini, nums[low]);
            break;
        }

        if(nums[mid]<=nums[high]){
            mini=min(nums[mid], mini);
            high=mid-1;
        }
        else{
            mini=min(nums[low], mini);
            low=mid+1;
        }
    }
    return mini;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<minrotatsortarrelement(v);
}