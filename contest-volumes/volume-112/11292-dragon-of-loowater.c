/* UVa Online Judge. Problem 11292 - Dragon of Loowater, by Abreto <m@abreto.net>. */
#include <stdio.h>
#include <stdlib.h>

#define MAXN    20001

int compar(const void *a, const void *b)
{
    return ((*((int*)a)) - (*((int*)b)));
}

int diameters[MAXN] = {0};
int heights[MAXN] = {0};

int main(void)
{
    int n = 0, m = 0;

    while( 2 == scanf("%d %d", &n, &m) && n && m )
    {
        int i = 0;
        int cur = 0; /* the dragon to be killed. */
        int cost = 0;

        for(i = 0;i < n;++i) scanf("%d", diameters+i);
        for(i = 0;i < m;++i) scanf("%d", heights+i);

        qsort(diameters, n, sizeof(int), compar);
        qsort(heights, m, sizeof(int), compar);

        for(i = 0;i < m;++i)
            if( heights[i] >= diameters[cur] )
            {
                cost += heights[i]; /* hire this knight */
                if( ++cur == n )    /* all the dragon is killed */
                    break;
            }
        
        if( cur < n )   printf("Loowater is doomed!\n");
        else    printf("%d\n", cost);
    }

    return 0;
}
