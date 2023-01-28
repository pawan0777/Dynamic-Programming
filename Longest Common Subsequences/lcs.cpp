#include<bits/stdc++.h>
using namespace std;

// Recursive Code
// int lcs(string x, string y, int n, int m){
//     if(m==0 or n==0)
//         return 0;
//     if(x[n-1] == y[m-1])
//         return 1 + lcs(x,y,n-1,m-1);
//     else
//         return max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
// }

// Memoization approach
// int static t[1001][1001];
// int lcs(string x, string y, int n, int m){
//     if(m==0 or n==0)
//         return 0;
//     if(t[n][m]!=-1)
//         return t[n][m];
//     if(x[n-1] == y[m-1])
//         return t[n][m] = 1 + lcs(x,y,n-1,m-1);
//     else
//         return t[n][m] = max(lcs(x,y,n,m-1), lcs(x,y,n-1,m));
// }

//Top Down Approach
int lcs(string x, string y, int n, int m){
    int t[n+1][m+1];
    for (int i=0; i<n+1; i++) t[i][0] = 0;
    for (int i=0; i<m+1; i++) t[0][i] = 0;
    
    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            if(x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[n][m];
}

int main(){
    string x = "abcdfh";
    string y = "abedghr";
    // memset(t, -1, sizeof(t));
    cout<<lcs(x, y, x.size(), y.size());
    return 0;
}