#include<bits/stdc++.h>
using namespace std;

// Brute force approach TC->O(N) SC->O(1)
vector<int> firstlastocc(vector<int> vec, int k){
    int n = (int)(vec.size());
    int first=-1, last=-1;

    for(int i=0; i<n; i++){
        if(vec[i]==k){
            if(first==-1) first=i;
            last=i;
        }
    }

    return {first, last};
}



vector<int> firstlastoccurence(vector<int> arr, int k){
    int lwrbnd= lower_bound(arr.begin(), arr.end(), k) -arr.begin(), uprbnd;

    if(arr[lwrbnd]!=k || lwrbnd==arr.size()) return {-1, -1};

    uprbnd= upper_bound(arr.begin(), arr.end(), k)-arr.begin();

    return {lwrbnd, uprbnd-1};
}

// Optimal approach TC->O(logN) SC->O(1)
vector<int> first_lastocc(vector<int> nums, int K){
    int n=nums.size();
    int first=-1, last=-1;

    int low=0, high=nums.size()-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]==K){
            first=mid;
            high=mid-1;
        }
        else if(nums[mid]>K){
            high=mid-1;
        }
        else low=mid+1;
    }
    
    if (first == -1) return { -1, -1};

    low=0, high=nums.size()-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]==K){
            last=mid;
            low=mid+1;
        }
        else if(nums[mid]>K){
            high=mid-1;
        }
        else low=mid+1;
    }

    return {first, last};
}


int main(){
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    // v=first_lastocc(v,t);
    // v=firstlastocc(v,t);
    v=firstlastoccurence(v,t);
    cout<<v[0]<<" "<<v[1];
}