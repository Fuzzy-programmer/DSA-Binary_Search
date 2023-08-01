#include<bits/stdc++.h>
using namespace std;

int canweplace(vector<int> stalls, int k, int dist){
    int last=stalls[0], countcows=1;
    for(int i=1; i<stalls.size(); i++){
        if(stalls[i]-last>=dist){
            countcows++;
            last=stalls[i];
        }
        if(countcows>=k) return true;
    }
    return false;
}

int Mindistance(vector<int> stalls, int k){
    int n=stalls.size();
    sort(stalls.begin(), stalls.end());
    int limit=stalls[0]-stalls[n-1];

    for(int i=1; i<=limit; i++){
        if(canweplace(stalls, k, i)==false)
            return i;
    }
    return limit;
}

int MinDistanceBtwAgressiveCows(vector<int> stalls, int k){
    sort(stalls.begin(), stalls.end());

    int low=1, high=stalls[0]-stalls[stalls.size()-1];

    while (low<=high)
    {
        int mid=low+(high-low)/2;

        if(canweplace(stalls, k, mid)==false) high=mid-1;

        else low=mid+1; // in search of max value (min distance btw cows)
    }
    return high;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<Mindistance(v, k);
}