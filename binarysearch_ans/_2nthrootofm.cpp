#include<bits/stdc++.h>
using namespace std;

// Brute force approach TC->O(M*logN) logN for power function SC->O(1)
int Nthroot(int n, int m){
    int ans=-1;
    for(int i=1; i<m; i++){
        if(pow(i, n)<=m)
            ans=i;
        else break;
    }
    return ans;
}

// Optimal approach TC->O(log(N+M)) SC->O(1)
int pwerfunc(int mid, int n, int m){
    long long ans=1;
    for(int i=0; i<n; i++){
        ans*=mid;
        if(ans>m) return 2;
    }
    if(ans==m) return 0;
    return 1;
}
int NthRoot(int n, int m)
{
    // Code here.
    int low=1, high=m;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        int midN=pwerfunc(mid, n, m);
        
        if(midN==0) return mid;
        
        else if(midN==2) high=mid-1;
        
        else low=mid+1;
    }
    return -1;
}  

int main(){
    int n, m;
    cin>>n>>m;
    cout<<NthRoot(n,m);
}