#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i=0, j=0, k=0;
    int n=nums1.size(), m=nums2.size();
    vector<int> arr(n+m, 0);

    while(i<n && j<m){
        if(nums1[i]<nums2[j]){
            arr[k++]=nums1[i++];
        }
        else{
            arr[k++]=nums2[j++];
        }
    }
    while(i<n) arr[k++]=nums1[i++];
    while(j<m) arr[k++]=nums2[j++];

    n = n+m;
    if(n%2==1)  
        return arr[((n+1)/2)-1];
    else 
        return ((float)arr[(n/2)-1]+(float)arr[(n/2)])/2;
}

double findmedianofsortedArr(vector<int> arr1, vector<int> arr2){
    if(arr2.size() < arr1.size()) return findmedianofsortedArr(arr2, arr1);

    int n1=arr1.size();
    int n2=arr2.size();
    int low=0, high=n1;

    while (low<=high)
    {
        int cut1=(low+high)/2;
        int cut2=(n1+n2+1)/2-cut1;
        
        int left1=(cut1==0)?INT_MIN: arr1[cut1-1];
        int left2=(cut2==0)?INT_MIN: arr2[cut2-1];

        int right1=(cut1==n1)?INT_MAX: arr1[cut1];
        int right2=(cut2==n2)?INT_MAX: arr2[cut2];

        if(left1<=right2 && left2<=right1){
            if((n1+n2)%2==0)
                return (max(left1, left2)+min(right1, right2))/2.0;
            else
                return max(left1, left2);
        }
        else if(left1> right2){
            high=cut1-1 ;
        }
        else low=cut1+1;
    }
    return 0.0;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> vec1(n), vec2(m);
    for(int i=0; i<n; i++)
        cin>>vec1[i];
    for(int i=0; i<m; i++)
        cin>>vec2[i];
    cout<<findmedianofsortedArr(vec1, vec2) ;   
}