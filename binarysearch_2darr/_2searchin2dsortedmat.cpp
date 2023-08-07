#include<bits/stdc++.h>
using namespace std;

bool searchin2d(vector<vector<int>> mat, int k){
    int m=mat[0].size(), n=mat.size();
    int low=0, high=(m*n)-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(mat[mid/m][mid%m]==k)
            return true;
        
        else if(mat[mid/m][mid%m]>k)
            low = mid+1;
    }
    return false;
}
