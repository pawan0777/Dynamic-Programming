// Not Completed
// Works only for Positive numbers
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {-36,36};
    int sum = 0;
    int n = arr.size();
    for(int it: arr)
        sum+=abs(it);
    bool t[n+1][sum+1];
    for (int i=0; i<sum+1; i++) t[0][i] = false;
    for (int i=0; i<n+1; i++) t[i][0] = true;
    for (int i=1; i<n+1; i++){
        for (int j=0; j<sum+1; j++){
            if(abs(arr[i-1])<=j)
                t[i][j] = t[i-1][j] or t[i-1][j-abs(arr[i-1])];
            else
                t[i][j] = t[i-1][j];
        }
    }
    // for (int i = 0; i < arr.size() + 1; i++){
    //     for (int j = 0; j < sum+1; j++)
    //         cout << t[i][j] << " ";
    //     cout << endl;
    // }
    int ans = INT_MAX;
    for (int i=0; i<sum/2+1; i++){
        if(t[n][i]==true){
            // cout<<i<<endl;
            ans = min(ans,sum-2*i);
        }
    }
    cout<<ans;
    return 0;
}