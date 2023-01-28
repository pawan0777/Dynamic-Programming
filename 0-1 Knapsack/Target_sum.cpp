// Same as count number of subset with given sum
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,1,1,1,1};
    int target = 3;
    int sum = 0;
    for(int it: arr)
        sum += it;
    if((sum+target)%2==1 or abs(target)>sum)
        return 0;
    sum = (sum + target)/2;
    int t[arr.size()+1][sum+1];
    for (int i = 0; i < sum+1; i++) t[0][i] = 0;
    for (int i = 0; i < arr.size()+1; i++) t[i][0] = 1;
    for (int i = 1; i < arr.size()+1; i++){
        for (int j = 0; j < sum+1; j++){
            if(arr[i-1]<=j)
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            else
                t[i][j] = t[i-1][j];
        }
    }
    cout<<t[arr.size()][sum];
    return 0;
}