/* UVa Online Judge. Problem 12716 - GCD XOR, by Abreto <m@abreto.net>. */
#include <stdio.h>

#define MAXN    30000001

int ans[MAXN] = {0};
void init(void)
{
    int a = 0, i = 0, c = 0;
    for(c = 1;c <= MAXN;++c )
        for( a = 2*c;a <= MAXN;a += c )
            if( c == (a^(a-c)) )
                ans[a]++;
    for(i = 1;i < MAXN;++i)
        ans[i+1] += ans[i];
}

int main(void)
{
    int i = 0, T = 0, N = 0;

    init();
    scanf("%d", &T);
    for(i = 0;i < T;++i)
    {
        scanf("%d", &N);
        printf("Case %d: %d\n", i+1, ans[N]);
    }

    return 0;
}
