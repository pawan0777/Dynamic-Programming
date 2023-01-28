#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> arr, int sum)
{
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
    // for (int i = 0; i < arr.size() + 1; i++){
    //     for (int j = 0; j < sum; j++)
    //         cout << t[i][j] << " ";
    //     cout << endl;
    // }
    return t[arr.size()][sum];
}

int main()
{
    vector<int> arr = {2,-1,0,4,-2,-9};
    int sum = 6;
    cout << solve(arr, sum);
    return 0;
}