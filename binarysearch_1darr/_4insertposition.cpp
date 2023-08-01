#include<bits/stdc++.h>
using namespace std;

int lowrbound(vector<int> arr, int t){

    int left=0, right=arr.size()-1;

    int ans=right;
    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[left]>=t){
            ans=left;
            right=mid-1;
        }
        else left=mid+1;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

}