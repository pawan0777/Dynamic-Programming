#include <bits/stdc++.h>
using namespace std;

// Recursive Code
// int solve(int e, int f){
//     if(f==0 or f==1)
//         return f;
//     if(e==1)
//         return f;
//     int mn = INT_MAX;
//     for (int k = 1; k <= f; k++){
//         int temp = 1 + max(solve(e-1,k-1), solve(e, f-k));
//         mn = min(mn,temp);
//     }
//     return mn;
// }

// Memoization Code
// int t[201][201];
// int solve(int e, int f)
// {
//     if (f == 0 or f == 1)
//         return f;
//     if (e == 1)
//         return f;
//     if (t[e][f] != -1)
//         return t[e][f];
//     int mn = INT_MAX;
//     for (int k = 1; k <= f; k++)
//     {
//         int low, high;
//         if (t[e - 1][k - 1] != -1)
//             low = t[e - 1][k - 1];
//         else
//         {
//             low = solve(e - 1, k - 1);
//             t[e - 1][k - 1] = low;
//         }
//         if (t[e][f - k] != -1)
//             high = t[e][f - k];
//         else
//         {
//             high = solve(e, f - k);
//             t[e][f - k] = high;
//         }
//         int temp = 1 + max(low, high);
//         mn = min(mn, temp);
//     }
//     return t[e][f] = mn;
// }

// Top down Approach
int solve(int K, int N)
{
    if (N == 0 || N == 1)
        return N; // Think for base case
    if (K == 1)
        return N;
    int dp[K + 1][N + 1];
    for (int i = 0; i <= K; i++)
        dp[i][0] = 0, dp[i][1] = 1; // Filling from base case as if N==0 ans=0 , N==1 ans=1
    for (int i = 0; i <= N; i++)
        dp[0][i] = 0, dp[1][i] = i; // Filling from base case as if K==0 ans=0 , K==1 ans=N, number of current floor (i)

    for (int i = 2; i < K + 1; i++){
        for (int j = 2; j < N + 1; j++){
            int l = 1, h = j, temp = 0, ans = 100000;
            while (l <= h){
                int mid = (l + h) / 2;
                int left = dp[i - 1][mid - 1]; // egg broken check for down floors of mid
                int right = dp[i][j - mid];    // not broken check for up floors of mid
                temp = 1 + max(left, right);   // store max of both
                if (left < right){                // since right is more than left and we need more in worst case
                    l = mid + 1; // so l=mid+1 to gain more temp for worst case : upward
                }
                else{ // left > right so we will go downward
                    h = mid - 1;
                }
                ans = min(ans, temp); // store minimum attempts
            }
            dp[i][j] = ans;
        }
    }
    return dp[K][N];
}

int main()
{
    int e = 2, f = 10;
    // memset(t, -1, sizeof(t));
    cout << solve(e, f);
    return 0;
}