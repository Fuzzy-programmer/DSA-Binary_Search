#include<bits/stdc++.h>
using namespace std;

// Extreme Brute force TC->O(N^2) SC->O(1)
int kthmissinpositivenum(vector<int> arr, int k){
    int cnt=0;
    for(int i=0; i<=arr[arr.size()-1]; i++){
        bool present=false;
        for(int j=0; j<arr.size(); j++){
            if(arr[j]==i){
                present=true;
                break;
            }
        }
        if(present==false) cnt++;
        if(cnt==k) return i; 
    }
    return arr.size()+(k-cnt);
}


// Assume that upto k the elements are missing if find any in the given array means that is not missing number so we increment k such that it gives the answer which is the kth missing number
int kthmissing(vector<int> nums, int k){
    for(int i=0; i<nums.size(); i++)
        if(nums[i]<=k) k++;
        else break;
    return k;
}

int missingK(vector<int> vec, int k){
    int n=vec.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        // missing numbers= arr[i]-i+1
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1;
    // return low+k; is because high+1= low
    // kth missing number => arr[high]+more | more=>(k-missing number)=(k-(vec[high]-(high+1)) => (k-vec[high]+high+1)
    // kth missing number => arr[high]+k-arr[high]+high+1 => k+high+1
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    int k;
    cin>>k;
    cout<<missingK(a, k);
}