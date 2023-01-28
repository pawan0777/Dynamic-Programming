#include<bits/stdc++.h>
using namespace std;

string lcs(string x, string y, int n, int m){
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
    int i=n, j=m;
    string s = "";
    while(i>0 and j>0){
        if(x[i-1] == y[j-1]){
            s.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1] > t[i-1][j]){
                s.push_back(y[j-1]);
                j--;
            }
            else{
                s.push_back(x[i-1]);
                i--;
            }
        }
    }
    if(i>0){
        while(i>0){
            s.push_back(x[i-1]);
            i--;
        }
    }
    if(j>0){
        while(j>0){
            s.push_back(y[j-1]);
            j--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}


int main(){
    string x = "abac";
    string y = "cab";
    cout<<lcs(x, y, x.size(), y.size());
    return 0;
}