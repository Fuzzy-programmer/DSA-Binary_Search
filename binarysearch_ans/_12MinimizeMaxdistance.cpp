#include<bits/stdc++.h>
using namespace std;

long double Minimaxdistgasstations(vector<int> nums, int k){
    vector<int> howmany(nums.size()-1);
    for(int i=1; i<=k; i++){
        long double maxdiff=-1;
        int maxidx=-1;
        for(int j=0; j<nums.size()-1; j++){
            long double diff=nums[j+1]-nums[j];
            long double seclen= diff/ (howmany[j]+1);
            if(maxdiff<seclen){
                maxdiff=seclen;
                maxidx=j;
            }
        }
        howmany[maxidx]++;
    }

    long double maxans=-1;
    for(int j=0; j<nums.size()-1; j++){
        long double diff=nums[j+1]-nums[j];
        long double seclen= diff/ (howmany[j]+1);
        maxans=max(maxans, seclen);
    }
    return maxans;
}

long double minmizemaxdistb2wgasstations(vector<int> vec, int k){
    int n=vec.size();
    vector<int> howmany(n-1, 0);

    priority_queue<pair<long double, int>> pq;

    for(int i=0; i<n-1; i++){
        pq.push({vec[i+1]-vec[i], i});
    }

    for(int gasstation=1; gasstation<=k; gasstation++){
        auto tp=pq.top(); pq.pop();
        int secIdx=tp.second;   
        howmany[secIdx]++;

        long double newsecdiff=(long double)tp.first/(long double)(howmany[secIdx]+1);

        pq.push({newsecdiff, secIdx});
    }

    return pq.top().first;
}


int numberofGasStationsReqerd(long double dist, vector<int> arr){
    int cnt=0;
    for(int i=1; i<arr.size(); i++){
        int numbersinbtw= (arr[i]-arr[i-1])/(dist);
        if((arr[i]-arr[i-1]) == numbersinbtw*dist)
            numbersinbtw--;
        
        cnt+=numbersinbtw;
        return cnt;
    }
}
long double minimiseMaxDistance(vector<int> &nums, int k){
    int n=nums.size();
    long double low=0;
    long double high=0;

    for(int i=1; i<n; i++){
        high=max(high, (long double) nums[i-1]-nums[i]);
    }

    long double diff=1e-6;
    long ans;
    while(high-low>diff){
        long double mid=(low+high)/2.0;
        int cnt=numberofGasStationsReqerd(mid, nums);

        if(cnt>k) low=mid;
        else{
            ans=high;
            high=mid;
        }
    }
    return high;
}


int main(){
    int n, k;
    cin>>n;
    vector<int> vec(n);

    for(int i=0; i<n; i++)
        cin>>vec[i];
    
    cin>>k;

    cout<<Minimaxdistgasstations(vec, k);
}