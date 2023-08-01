#include<bits/stdc++.h>
using namespace std;

int smalldivforthreshold(vector<int> arr, int threshold){
    int maxi=INT_MIN;
    for(auto it: arr)
        maxi=max(maxi, it);
    // if(arr.size()<threshold) return -1;
    for(int i=1; i<=maxi; i++){
        int sum=0;
        for(int j=0; j<arr.size(); j++){
            sum+=ceil((double)arr[j]/(double)i);
        }
        if(sum<=threshold) return i;
    }
    return -1;
}

bool possible(vector<int> arr, int threshold, int i){
    int sum=0;
    for(int j=0; j<arr.size(); j++){
        sum+=ceil((double)arr[j]/(double)i);
    }
    return (sum<=threshold);
}
int sumofarrsmalldivslessthanthreshold(vector<int> nums, int threshold){
    int maxi=INT_MIN;
    for(auto it: nums)
        maxi=max(maxi, it);
    
    int low=1, high=maxi;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(possible(nums, threshold, mid)) high=mid-1;

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
    int m;
    cin>>m;

    cout<<sumofarrsmalldivslessthanthreshold(v, m);
}