#include <bits/stdc++.h>
using namespace std;
 
// Stores the overlapping state
int dp[1001][3001];
 
// Recursive function to find the maximum
// number of bananas that can be transferred
// to A distance using memoization
int recBananaCnt(int A, int B, int C)
{
    // Base Case where count of bananas
    // is less that the given distance
    if (B <= A) {
        return 0;
    }
 
    // Base Case where count of bananas
    // is less that camel's capacity
    if (B <= C) {
        return B - A;
    }
 
    // Base Case where distance = 0
    if (A == 0) {
        return B;
    }
 
    // If the current state is already
    // calculated
    if (dp[A][B] != -1) {
        return dp[A][B];
    }
 
    // Stores the maximum count of bananas
    int maxCount = INT_MIN;
 
    // Stores the number of trips to transfer
    // B bananas using a camel of capacity C
    int tripCount = B % C == 0 ? ((2 * B) / C) - 1
                               : ((2 * B) / C) + 1;
 
    // Loop to iterate over all the
    // breakpoints in range [1, A]
    for (int i = 1; i <= A; i++) {
 
        // Recursive call over the
        // remaining path
        int curCount
            = recBananaCnt(A - i,
                           B - tripCount * i, C);
 
        // Update the maxCount
        if (curCount > maxCount) {
            maxCount = curCount;
 
            // Memoize the current value
            dp[A][B] = maxCount;
        }
    }
 
    // Return answer
    return maxCount;
}
 
// Function to find the maximum number of
// bananas that can be transferred
int maxBananaCnt(int A, int B, int C)
{
    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));
 
    // Function Call
    return recBananaCnt(A, B, C);
}
 
// Driver Code
int main()
{
    int A = 1000;
    int B = 3000;
    int C = 1000;
    cout << maxBananaCnt(A, B, C);
 
    return 0;
}