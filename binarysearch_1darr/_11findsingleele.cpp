#include<bits/stdc++.h>
using namespace std;

int singleeleserch(vector<int> nums){
    if(nums.size()==1) return nums[0];
    for(int i=0; i<nums.size(); i++){
        if(i==0){
            nums[i]!=nums[i+1];
            return nums[i];
        }
        else if(i==nums.size()-1){
            nums[i]!=nums[i-1];
            return nums[i];
        }
        else{
            if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
    }
    return -1;
}

int singleNonDuplicate(vector<int> arr){
    int n=arr.size(), ans=0;
    for(int i=0; i<n; i++){
        ans^=arr[i];
    }
    return ans;
}

int singlenotdup(vector<int> vec){
    int n=vec.size();

    if(n==1) return vec[0];
    if(vec[0]!=vec[1]) return vec[0];
    if(vec[n-1]!=vec[n-2]) return vec[n-1];

    int low=1, high=n-2;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(vec[mid]!=vec[mid-1] && vec[mid]!=vec[mid+1])
            return vec[mid];

        else if((mid%2!=0 && vec[mid]==vec[mid-1]) || mid%2==0 && vec[mid]==vec[mid+1]){
            low=mid+1;
        }

        else high=mid-1;
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
    cout<<singleNonDuplicate(v);
}