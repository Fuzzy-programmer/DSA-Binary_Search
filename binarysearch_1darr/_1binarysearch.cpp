#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> vec, int k){
    int n=vec.size();
    int left=0, right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(vec[mid]==k) return mid;
        else if(vec[mid]<k) left=mid+1; 
        else right=mid-1;
    }
    return -1;
}

int bsearch(vector<int> nums, int low, int high, int target){
    if (low > high) return -1;

    int mid=low+(high-low)/2;

    if(nums[mid]==target) return mid;

    else if(nums[mid]>target) bsearch(nums, mid+1, high, target);

    else bsearch(nums, low, mid-1, target);
}

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    cout<<binarysearch(nums, target);
}