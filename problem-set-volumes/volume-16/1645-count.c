/* UVa Online Judge :: Problem Set Volumes :: Volume 16. Problem 1645 - Count, by Abreto <m@abreto.net>. */
#include <stdio.h>

#define MOD 1000000007

int main(void)
{
    int i = 0, j = 0;
    int n = 0;
    int dp[1024] = {0};

    dp[1] = 1;
    for(i = 1;i < 1024;++i)
        for(j = i;j < 1024;j += i)
            dp[j+1] = (dp[j+1] + dp[i]) % MOD;
    
    i = 0;
    while(EOF != scanf("%d", &n))
        printf("Case %d: %d\n", ++i, dp[n]);

    return 0;
}
