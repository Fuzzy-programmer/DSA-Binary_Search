#include<bits/stdc++.h>
using namespace std;

// Brute force approach TC->O(N) SC->O(1)
int uprbound(vector<int> arr, int t){
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]>t) return i;
    }
    return arr.size();
}

// Optimal approach TC->O(logN) SC->O(1)
int upperbound(vector<int> nums, int t){
    int left=0, right=nums.size()-1;
    // int ans=right;

    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]>t){
            // ans=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    return left;
}

int main(){
    int n,x;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cin>>x;
    cout<<upperbound(v, x);
}