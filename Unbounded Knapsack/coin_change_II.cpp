#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> coins, int amount){
    int t[coins.size()+1][amount+1];
    for (int i = 0; i < amount+1; i++) t[0][i] = 0;
    for (int i = 0; i < coins.size()+1; i++) t[i][0] = 1;
    for (int i = 1; i < coins.size()+1; i++){
        for (int j = 1; j < amount+1; j++){
            if(coins[i-1]<=j)
                t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
            else
                t[i][j] = t[i-1][j];
        }
    }
    for (int i = 0; i < coins.size()+1; i++){
        for (int j = 0; j < amount+1; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return t[coins.size()][amount];
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;
    cout<<solve(coins, amount);
    return 0;
}