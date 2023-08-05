#include<bits/stdc++.h>
using namespace std;

int kthelementin2sortedarr(vector<int> arr1, vector<int> arr2, int target){
    int n=arr1.size();
    int m=arr2.size();
    int i=0, j=0, counter=0, ans=0;
    while(i<n & j<m){
        if(counter==target) break;
        if(arr1[i]<arr2[j])
            ans=arr1[i++];
        else 
            ans=arr2[j++];
        ++counter;
    }

    if(counter!=target){
        if(i!=n-1) ans=arr1[target-counter];
        else ans=arr2[target-counter];
    }
    return ans;
}

int kthelement(vector<int> arr1, vector<int> arr2, int k) {
    int m=arr1.size(), n=arr2.size();
    if(m > n) {
        return kthelement(arr1, arr2, k); 
    }
        
    int low = max(0,k-m), high = min(k,n);
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}

int main(){
    int k;
    cin>>k;
    int m,n;
    cin>>m>>n;

    vector<int> vec1(n), vec2(m);
    for(int i=0; i<n; i++)
        cin>>vec1[i];
    for(int i=0; i<m; i++)
        cin>>vec2[i];
    
    cout<<kthelement(vec1, vec2, k);
}