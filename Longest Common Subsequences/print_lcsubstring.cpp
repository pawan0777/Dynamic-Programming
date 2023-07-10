#include<bits/stdc++.h>
using namespace std;

string lcs(string x, string y, int n, int m){
    string t[n+1][m+1];
    string ma = "";
    for (int i=0; i<n+1; i++) t[i][0] = "";
    for (int i=0; i<m+1; i++) t[0][i] = "";
    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            if(x[i-1] == y[j-1]){
                t[i][j] = t[i-1][j-1] + x[i-1];
                if(t[i][j].size() >= ma.size())
                    ma = t[i][j];
            }
            else
                t[i][j] = "";
        }
    }
    return ma;
}

int main(){
    string x = "babxd";
    string y = "dxbab";
    cout<<lcs(x, y, x.size(), y.size());
    return 0;
}