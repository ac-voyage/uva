/* UVa Online Judge. Problem 10820 - Send a Table, by Abreto <m@abreto.net>. */
#include <stdio.h>

#define MAXN    50001
int phi[MAXN] = {0};
int phisum[MAXN] = {0}; 
void init(void)
{
    int i = 0, j = 0;
    phi[1] = 1;
    for(i = 2;i <= MAXN;++i)
        if( !phi[i] )
            for(j = i;j <= MAXN;j+=i)
            {
                if( !phi[j] )   phi[j] = j;
                phi[j] = phi[j] / i * (i-1);
            }
    for(i = 2;i <= MAXN;++i)
        phisum[i] = phi[i] + phisum[i-1];
}

int main(void)
{
    int N = 0;

    init();
    while( scanf("%d", &N) && N )
        printf("%d\n", phisum[N]*2+1);

    return 0;
}
