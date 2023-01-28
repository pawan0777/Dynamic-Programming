#include <bits/stdc++.h>
using namespace std;

// Recursive Code
// bool solve(string a, string b){
//     if(a.compare(b) == 0)
//         return true;
//     if(a.length() <= 1)
//         return false;
//     int n = a.length();
//     bool flag = false;
//     for (int i = 1; i < n; i++){
//         if(solve(a.substr(0,i), b.substr(n-i,i))==true and solve(a.substr(i,n-i), b.substr(0,n-i))==true){
//             flag = true;
//             break;
//         }
//         if(solve(a.substr(0,i), b.substr(0,i))==true and solve(a.substr(i,n-i), b.substr(i,n-i))==true){
//             flag = true;
//             break;
//         }
//     }
//     return flag;
// }

// Memoization Code
// unordered_map<string, bool> umap;
// bool solve(string a, string b){
//     if(a.compare(b) == 0)
//         return true;
//     if(a.length() <= 1)
//         return false;
//     string st = a;
//     st.push_back(' ');
//     st.append(b);
//     if(umap.find(st)!=umap.end()){
//         return umap[st];
//     }
//     int n = a.length();
//     bool flag = false;
//     for (int i = 1; i < n; i++){
//         if(solve(a.substr(0,i), b.substr(n-i,i))==true and solve(a.substr(i,n-i), b.substr(0,n-i))==true){
//             flag = true;
//             break;
//         }
//         if(solve(a.substr(0,i), b.substr(0,i))==true and solve(a.substr(i,n-i), b.substr(i,n-i))==true){
//             flag = true;
//             break;
//         }
//     }
//     return umap[st] = flag;
// }

// Top Down Approach
bool solve(string s1, string s2)
{
    int n = s1.size();
    bool dp[n][n][n + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (s1[i] == s2[j]){
                dp[i][j][0] = true;
            }
        }
    }

    for (int len = 2; len <= n; len++){
        for (int i = 0; i <= n - len; i++){
            for (int j = 0; j <= n - len; j++){
                for (int len1 = 1; len1 <= len - 1; len1++){
                    int len2 = len - len1;
                    dp[i][j][len - 1] |= dp[i][j][len1 - 1] && dp[i + len1][j + len1][len2 - 1];
                    dp[i][j][len - 1] |= dp[i][j + len2][len1 - 1] && dp[i + len1][j][len2 - 1];
                }
            }
        }
    }
    return dp[0][0][n - 1];
}

int main()
{
    string a = "great";
    string b = "rgeat";
    cout << solve(a, b);
    return 0;
}