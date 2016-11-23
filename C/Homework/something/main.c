#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m[8][8];
    int i,j;
    int a=0;
    for (i=0;i<8;i++){
        for(j=0;j<8;j++){
            a++;
            m[i][j]=a;
        }
    }
    printf("%d",m[7][7]);
    return 0;
}
