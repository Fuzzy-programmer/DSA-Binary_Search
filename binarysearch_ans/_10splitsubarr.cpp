#include<bits/stdc++.h>
using namespace std;
int subarrcnt(vector<int>, int);

int sumofsplitarr(vector<int> a, int k){
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    for (int maxSum = low; maxSum <= high; maxSum++) {
        if (subarrcnt(a, maxSum) == k)
            return maxSum;
    }
    return low;
}

int subarrcnt(vector<int>nums, int mid){
    int cnt=1, sum=0;
    for(int i=0; i<nums.size(); i++){
        if(sum+nums[i]<=mid)
            sum+=nums[i];
        else{
            cnt++;
            sum=nums[i];
        }
    }
    return cnt;
}
int splitArray(vector<int>& nums, int k) {
    int low=*max_element(nums.begin(), nums.end());
    int high=accumulate(nums.begin(), nums.end(), 0);

    while(low<=high){
        int mid=low+(high-low)/2;

        int cnt=subarrcnt(nums, mid);

        if(cnt>k) low=mid+1;

        else high=mid-1;
    }
    return low;
}

int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];
    int k;
    cin>>k;

    cout<<splitArray(vec, k);
}