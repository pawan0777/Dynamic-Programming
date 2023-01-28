#include<bits/stdc++.h>
using namespace std;

// Recursive Code
// int solve(vector<int> arr, int i, int j){
//     if(i>=j)
//         return 0;
//     int mn = INT_MAX;
//     for (int k = i; k <= j-1; k++){
//         int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
//         mn = min(mn,temp);
//     }
//     return mn;
// }

// Memoization Code
int static t[1001][1001];
int solve(vector<int> arr, int i, int j){
    if(i>=j)
        return 0;
    if(t[i][j] != -1)
        return t[i][j];
    int mn = INT_MAX;
    for (int k = i; k <= j-1; k++){
        int temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        mn = min(mn,temp);
    }
    return t[i][j] = mn;
}

int main(){
    vector<int> arr= {40, 20, 30, 10, 30};
    memset(t, -1, sizeof(t));
    cout<<solve(arr, 1, arr.size()-1);
    return 0;
}