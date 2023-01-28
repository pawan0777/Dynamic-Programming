#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& arr) {
    int sum = 0;
    for(int it: arr)
        sum+=it;
    if(sum%2==1)
        return false;
    else{
        sum = sum/2;
        bool t[arr.size() + 1][sum + 1];
        for (int i=0; i<sum+1; i++) t[0][i] = false;
        for (int i=0; i<arr.size()+1; i++) t[i][0] = true;
        for (int i=1; i<arr.size()+1; i++){
            for (int j=1; j<sum+1; j++){
                if(arr[i-1] <= j)
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[arr.size()][sum];
    }
}

int main(){
    vector<int> arr = {1, 2, 5};
    cout<<canPartition(arr);
    return 0;
}