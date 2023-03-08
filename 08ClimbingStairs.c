#include <stdio.h>
#include <string.h>
int climbStairs(int n);
int main() {
    int n;
    printf("Enter the number of stairs: ");
    scanf("%d", &n);

    int ways = climbStairs(n);

    printf("Number of distinct ways to climb %d stairs: %d\n", n, ways);

    return 0;
}
int climbStairs(int n){
    if (n == 0 || n == 1){
            return 1;
        }
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
