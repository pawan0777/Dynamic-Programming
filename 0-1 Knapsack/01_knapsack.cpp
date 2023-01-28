#include<bits/stdc++.h>
using namespace std;

// Recursive Code
// int knapsack01(int w, int wt[], int val[], int n){
//     if(n==0 or w==0)
//         return 0;
//     if(wt[n-1]<=w)
//         return max(val[n-1] + knapsack01(w-wt[n-1],wt,val,n-1), knapsack01(w,wt,val,n-1));
//     if(wt[n-1]>w)
//         return knapsack01(w,wt,val,n-1);
// }

// Memoize Code
// int static t[4][5];
// int knapsack01(int w, int wt[], int val[], int n){
//     memset(t,-1,sizeof(t)); //initialise all elements of t = -1
//     if(n==0 or w==0)
//         return 0;
//     if(t[n][w]!=-1)
//         return t[n][w];
//     if(wt[n-1]<=w)
//         return t[n][w] = max(val[n-1] + knapsack01(w-wt[n-1],wt,val,n-1), knapsack01(w,wt,val,n-1));
//     if(wt[n-1]>w)
//         return t[n][w] = knapsack01(w,wt,val,n-1);
// }

// Top-Down Approach
int knapsack01(int w, int wt[], int val[], int n){
    int t[n+1][w+1];
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < w+1; j++){
            if(i==0 or j==0){
                t[i][j]=0;
            }
            else if(wt[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}

int main(){
    int n = 3;
    int w = 4;
    int val[] = {1,2,3};
    int wt[] = {4,5,1};
    cout<<knapsack01(w,wt,val,n);
    return 0;
}