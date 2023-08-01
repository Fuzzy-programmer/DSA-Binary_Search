#include<bits/stdc++.h>
using namespace std;


int Maxi(vector<int> arr){
    int maxi=INT_MIN;
    for(int i=0; i<arr.size(); i++)
        maxi=max(maxi, arr[i]);
    return maxi;
}

int kokoeatbananas(vector<int> arr, int h){
    int cnt=0, maxi=Maxi(arr);
    for(int k=1; k<=maxi; k++){
        cnt=0;
        for(int i=0; i<arr.size(); i++){
            cnt+=ceil((double)arr[i]/(double)k);
        }
        if(cnt<=h) return k;
    }
    return maxi;
}


int kokoeatingbananas(vector<int> piles, int h){
    int maxi=INT_MIN;
    for(auto it: piles)
    maxi=max(it, maxi);

    int low=1, high=maxi;

    while(low<=high){
        int mid=low+(high-low)/2;

        long long cnt=0;
        for(int i=0; i<piles.size(); i++){
            cnt+=ceil((double)piles[i]/(double)mid);
        }

        if(cnt<=h){
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}

int main(){
    int n,h;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cin>>h;
    cout<<kokoeatbananas(v, h);
}