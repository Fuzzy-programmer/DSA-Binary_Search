#include<bits/stdc++.h>
using namespace std;

int floor_(vector<int> nums, int k){
    int ans=-1;
    int low=0, high=nums.size()-1;

    while (low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]<k){
            // ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return nums[high];
}

int ceil_(vector<int> nums, int k){
    int low=0, high=nums.size()-1;
    int ans=high+1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>=k){
            // ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return nums[low];
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<floor_(v, t);
    cout<<endl<<ceil_(v, t);
}