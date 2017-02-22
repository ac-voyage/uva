/* Root. Problem 1584 - Circular Sequence, by Abreto <m@abreto.net>. */
#include <stdio.h>
#include <string.h>

void doublestr(char *str)
{
  char *p = str, *q = str;
  while( *p++ != '\0' );
  while( *(++q) != '\0' ) p++;
  while(q>=str) *p-- = *q--;
}

int main(void)
{
  int T = 0;
  scanf("%d", &T);
  while (T--)
  {
    int i = 0, j = 0;
    int len = 0;
    char seq[256] = {0};
    int start = 0;

    scanf("%s", seq); len = strlen(seq);
    doublestr(seq);
    for(i = 1;i < len;++i)
      for(j = 0;j < len;++j)
        if( seq[i+j] < seq[start+j] )
        {
          start = i;
          break;
        }
        else if( seq[i+j] > seq[start+j] )
          break;
    for(i = 0;i < len;++i)
      printf("%c", seq[start+i]);
    printf("\n");
  }
  return 0;
}
