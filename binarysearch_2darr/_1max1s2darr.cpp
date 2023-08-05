#include<bits/stdc++.h>
using namespace std;

int findMaxRow(vector<vector<int>> mat, int N) {
    int i=0, j=mat[0].size()-1;
    int cnt=0, row=0;
    
    while(i<N && j>=0){
        if(mat[i][j]==1){
            row=i;
            cnt++;
            j--;
        }
        else{
            i++;
        } 
    }
    return row;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int> (m,0));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>matrix[i][j];
    
    cout<<findMaxRow(matrix, n);

}