#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string st, int i, int j){
    while(i<j){
        if(st[i]!=st[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// Recursive code
// int solve(string st, int i, int j){
//     if(i>=j)
//         return 0;
//     if(ispalindrome(st,i,j))
//         return 0;
//     int mn = INT_MAX;
//     for (int k = i; k < j; k++){
//         int temp = solve(st,i,k) + solve(st,k+1,j) + 1;
//         mn = min(mn, temp);
//     }
//     return mn;
// }

// Memoizaition Code
// int static t[17][17];
// int solve(string st, int i, int j){
//     if(i>=j)
//         return 0;
//     if(ispalindrome(st,i,j))
//         return 0;
//     if(t[i][j]!=-1)
//         return t[i][j];
//     int mn = INT_MAX;
//     for (int k = i; k < j; k++){
//         int temp = solve(st,i,k) + solve(st,k+1,j) + 1;
//         mn = min(mn, temp);
//     }
//     return t[i][j] = mn;
// }

//Memoization More optimised code
int static t[17][17];
int solve(string st, int i, int j){
    if(i>=j)
        return 0;
    if(ispalindrome(st,i,j))
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    int mn = INT_MAX;
    for (int k = i; k < j; k++){
        int temp = 1;
        if(t[i][k]!=-1)
            temp+=t[i][k];
        else{
            t[i][k]=solve(st,i,k);
            temp+=t[i][k];
        }
        if(t[k+1][j]!=-1)
            temp+=t[k+1][j];
        else{
            t[k+1][j] = solve(st,k+1,j);
            temp += t[k+1][j];
        }
        mn = min(mn, temp);
    }
    return t[i][j] = mn;
}

int main(){
    string st = "pawan";
    memset(t, -1, sizeof(t));
    cout<<solve(st, 0, st.size()-1);
    return 0;
}