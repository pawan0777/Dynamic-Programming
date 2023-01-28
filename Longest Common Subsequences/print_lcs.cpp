#include<bits/stdc++.h>
using namespace std;

// Aditya Verma Approach
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
            if(t[i][j-1] > t[i-1][j])
                j--;
            else
                i--;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

string printlcs(string x, string y, int n, int m){
    string t[n+1][m+1];
    for (int i=0; i<n+1; i++) t[i][0] = "";
    for (int i=0; i<m+1; i++) t[0][i] = "";
    
    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            if(x[i-1] == y[j-1])
                t[i][j] = t[i-1][j-1] + x[i-1];
            else{
                if(t[i-1][j].size()>=t[i][j-1].size())
                    t[i][j] = t[i-1][j];
                else
                    t[i][j] = t[i][j-1];
            }
        }
    }
    return t[n][m];
}

int main(){
    string x = "abcdgh";
    string y = "aedfhr";
    cout<<lcs(x, y, x.size(), y.size());
    return 0;
}