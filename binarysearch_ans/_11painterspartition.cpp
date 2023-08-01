#include<bits/stdc++.h>
using namespace std;
int countPainters(vector<int>, int);

int findLargestMinDistance_brute(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    for (int time = low; time <= high; time++) {
        if (countPainters(boards, time) <= k) {
            return time;
        }
    }
    return low;
}


int countPainters(vector<int> boards, int time) {
    int n = boards.size(); //size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
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

    cout<<findLargestMinDistance(vec, k);
}
