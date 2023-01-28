#include<bits/stdc++.h>
using namespace std;

//Recursive Code
// int solve(string s, int i, int j, bool istrue){
//     if(i>j)
//         return false;
//     if(i==j){
//         if(istrue == true)
//             return s[i]=='T';
//         else
//             return s[i]=='F';
//     }
//     int ans = 0;
//     for (int k=i+1; k<=j-1; k+=2){
//         int lt = solve(s,i,k-1,true);
//         int lf = solve(s,i,k-1,false);
//         int rt = solve(s,k+1,j,true);
//         int rf = solve(s,k+1,j,false);
//         if(s[k] == '&'){
//             if(istrue == true)
//                 ans += lt*rt;
//             else
//                 ans += lf*rt + lt*rf + lf*rf; 
//         }
//         else if(s[k] == '|'){
//             if(istrue == true)
//                 ans += lt*rt + lt*rf + lf*rt;
//             else
//                 ans += lf*rf;
//         }
//         else if(s[k] == '^'){
//             if(istrue == true)
//                 ans += lf*rt + lt*rf;
//             else
//                 ans + lf*rf + lt*rt;
//         }
//     }
//     return ans;
// }

// Memoization Code 
int t[201][201][2];
int solve(string s, int i, int j, bool istrue){
    if(t[i][j][istrue]!=-1)
        return t[i][j][istrue];
    if(i>j)
        return false;
    if(i==j){
        if(istrue == 1)
            return s[i]=='T';
        else
            return s[i]=='F';
    }
    int ans = 0;
    for (int k=i+1; k<=j-1; k+=2){
        int lt,lf,rt,rf;
        if(t[i][k-1][1] != -1)
            lt = t[i][k-1][1];
        else{
            lt = solve(s,i,k-1,1);
            t[i][k-1][1] = lt;
        }
        if(t[i][k-1][0] != -1)
            lf = t[i][k-1][0];
        else{
            lf = solve(s,i,k-1,0);
            t[i][k-1][0] = lf;
        }
        if(t[k+1][j][1] != -1)
            rt = t[k+1][j][1];
        else{
            rt = solve(s,k+1,j,1);
            t[k+1][j][1] = rt;
        }
        if(t[k+1][j][0] != -1)
            rf = t[k+1][j][0];
        else{
            rf = solve(s,k+1,j,0);
            t[k+1][j][0] = rf;
        }
        if(s[k] == '&'){
            if(istrue == 1)
                ans += lt*rt;
            else
                ans += lf*rt + lt*rf + lf*rf; 
        }
        else if(s[k] == '|'){
            if(istrue == 1)
                ans += lt*rt + lt*rf + lf*rt;
            else
                ans += lf*rf;
        }
        else if(s[k] == '^'){
            if(istrue == 1)
                ans += lf*rt + lt*rf;
            else
                ans += lf*rf + lt*rt;
        }
    }
    return ans;
}

int main(){
    string s = "T^F|F";
    memset(t, -1, sizeof(t));
    cout<<solve(s,0,s.size()-1,true);
    return 0;
}