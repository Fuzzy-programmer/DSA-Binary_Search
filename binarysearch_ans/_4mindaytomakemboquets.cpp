#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}



int mindaystomakeMboquets(vector<int> nums, int m, int k){

    if(nums.size()<(long long)m*k) return -1;

    int maxi=INT_MIN, mini=INT_MAX;
    for(auto it: nums){
        maxi=max(maxi, it);
        mini=min(mini, it);
    }

    for(int i=mini; i<=maxi; i++){
        if(possible(nums, i, m, k)) return i;
    }
    return -1;
}



int mindays(vector<int> arr, int m, int k){

    // Edge Case
    if(arr.size()<(long long)m*k) return -1;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    

    // Binary Search
    int low=mini, high=maxi;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(possible(arr, mid, m, k)) high=mid-1;

        else low=mid+1;
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    int m, k;
    cin>>m>>k;

    cout<<mindays(v, m, k);
}