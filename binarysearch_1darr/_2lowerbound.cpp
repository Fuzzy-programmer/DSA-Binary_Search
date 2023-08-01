#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> vec, int t){
    for(int i=0; i<vec.size(); i++){
        if(vec[i]>=t)
            return i;
    }
    return vec.size();
}

int lowrbound(vector<int> arr, int t){

    int left=0, right=arr.size()-1;

    int ans=right+1;
    while(left<=right){
        int mid=left+(right-left)/2;

        if(arr[mid]>=t){
            // ans=mid;
            right=mid-1;
        }
        else left=mid+1;
    }
    return left;
}

int main(){
    int n, x;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cin>>x;
    cout<<lowrbound(v,x);
}