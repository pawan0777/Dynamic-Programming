#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int sum){
    int t[arr.size()+1][sum+1];
    for (int i = 0; i < sum+1; i++) t[0][i] = 0;
    for (int i = 0; i < arr.size()+1; i++) t[i][0] = 1;
    for (int i = 1; i < arr.size()+1; i++){
        for (int j = 1; j < sum+1; j++){
            if(arr[i-1]<=j)
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[arr.size()][sum];
}

int main(){
    vector<int> arr = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    cout<<solve(arr, sum);
    return 0;
}