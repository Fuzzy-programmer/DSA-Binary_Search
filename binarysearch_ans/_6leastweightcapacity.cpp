#include<bits/stdc++.h>
using namespace std;

int leastweightcaptoshipindays(vector<int> arr, int d){
    int maxi=INT_MIN, sum=0;

    for(auto it: arr){
        sum+=it;
        maxi=max(maxi, it);
    }

    for(int i=maxi; i<=sum; i++){
        int load=0, days=1;
        for(int j=0; j<arr.size(); j++){
            if(load+arr[j]>i){
                days++;
                load=arr[j];
            }
            else{
                load+=arr[j];
            }
        }
        if(days<=d) return i;
    }
    return -1;
}

// Helper function to calculate the number of days required by a given vector and maximum capacity limit
int findDays(vector<int> vec, int maxload){
    int days=1, load=0;

    for(int i=0; i<vec.size(); i++){
        if(load+vec[i]>maxload){
            days++;
            load=vec[i];
        }
        else load+=vec[i];
    }
    return days;
}
int leastcapacity(vector<int> nums, int maxdays){
    int maxi=INT_MIN, sum=0;

    for(auto it: nums){
        sum+=it;
        maxi=max(maxi, it);
    }

    int low=maxi, high=sum;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(findDays(nums, mid)<=maxdays) high=mid-1;

        else low=mid+1;
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];
    int days;
    cin>>days;

    // cout<<leastweightcaptoshipindays(vec, days);
    cout<<leastcapacity(vec, days);
}