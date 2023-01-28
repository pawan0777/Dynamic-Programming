#include<bits/stdc++.h>
using namespace std;

int lcs(string x, int n){
    string y = x;
    int t[n+1][n+1];
    for (int i=0; i<n+1; i++) t[i][0] = 0;
    for (int i=0; i<n+1; i++) t[0][i] = 0;
    
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            if(x[i-1] == y[j-1] and i!=j)
                t[i][j] = 1 + t[i-1][j-1];
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[n][n];
}

int main(){
    string x = "aabebcdd";
    cout<<lcs(x, x.size());
    return 0;
}