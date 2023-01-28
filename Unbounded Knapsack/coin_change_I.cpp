#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> coins, int amount){
    int t[coins.size()+1][amount+1];
    for (int i = 0; i < amount+1; i++) t[0][i] = INT_MAX-1;
    for (int i = 1; i < coins.size()+1; i++) t[i][0] = 0;
    for (int i = 1; i < amount+1; i++){
        if(i%coins[0]==0)
            t[1][i] = i/coins[0];
        else
            t[1][i] = INT_MAX - 1;
    }
    for (int i = 2; i < coins.size()+1; i++){
        for (int j = 1; j < amount+1; j++){
            if(coins[i-1]<=j)
                t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[coins.size()][amount];
}

int main(){
    vector<int> coins = {1,2,5,5};
    int amount = 11;
    cout<<solve(coins, amount);
    return 0;
}