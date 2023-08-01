#include<bits/stdc++.h>
using namespace std;

int searchinrotated(vector<int> vec, int k){
    for(int i=0; i<vec.size(); i++)
        if(vec[i]==k)
            return i;
    return -1;
}

int srchinrotated(vector<int> nums, int target){
    int low=0, high=nums.size()-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]==target) return mid;

        else if(nums[mid]<=nums[high]){
            if(nums[mid]<=target && target<=nums[high])
                low=mid+1;
            else high=mid-1;
        }

        else{
            if(nums[mid]>=target && target>=nums[low])
                high=mid-1;
            else low=mid+1;
        }
    }
    return -1;
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<srchinrotated(v,t);
}