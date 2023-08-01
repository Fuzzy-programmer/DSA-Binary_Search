#include<bits/stdc++.h>
using namespace std;
int cangiven(vector<int>, int);

int BookAllocate(vector<int> arr, int m){
    int n=arr.size();

    int low=*max_element(arr.begin(), arr.end());
    int high=accumulate(arr.begin(), arr.end(), 0);
    
    for(int i=low; i<=high; i++){
        if(cangiven(arr, i)==m)
            return i;
    }
    return low;
}


int cangiven(vector<int> books, int distrubutedpgs){
    long long pagestds=0;
    int cntstds=1;
    for(int i=0; i<books.size(); i++){
        if(pagestds+books[i]>distrubutedpgs){
            cntstds++;
            pagestds=books[i];
        }
        else{
            pagestds+=books[i];
        }
    }
    return cntstds;
}

int bookallocate(vector<int> books, int m){

    if(books.size()<m) return -1;

    int sum=0, maxi=INT_MIN;
    for(int i=0; i<books.size(); i++){
        sum+=books[i];
        maxi=max(maxi, books[i]);
    }

    int low=maxi, high=sum;

    while(low<=high){

        int mid=low+(high-low)/2;

        int countstudents=cangiven(books, mid);

        if(countstudents>m) 
            low=mid+1;

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

    cout<<BookAllocate(vec, k);
    // cout<<bookallocate(vec, k);
}