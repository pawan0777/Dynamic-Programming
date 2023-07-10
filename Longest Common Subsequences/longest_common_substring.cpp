#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m){
    int t[n+1][m+1];
    int ma = 0;
    for (int i=0; i<n+1; i++) t[i][0] = 0;
    for (int i=0; i<m+1; i++) t[0][i] = 0;
    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                ma = max(ma, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }
    return ma;
}

int main(){
    string x = "babad";
    string y = "dabab";
    cout<<lcs(x, y, x.size(), y.size());
    return 0;
}