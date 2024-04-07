#include <stdio.h>

int isDefective(int img[4][4], int rs, int re, int cs, int ce){
    for(int i=rs;i<=re;i++){
        for(int j=cs;j<=ce;j++){
            if(img[i][j]!=0){
                return 0;
            }
        }
    }
    return 1;
}

int isNonDefective(int img[4][4], int rs, int re, int cs, int ce){
    for(int i=rs;i<=re;i++){
        for(int j=cs;j<=ce;j++){
            if(img[i][j]!=1){
                return 0;
            }
        }
    }
    return 1;
}

void find(int img[4][4], int rs, int re, int cs, int ce){
    if(isDefective(img,rs,re,cs,ce)){
        printf("Defective region found: (%d, %d) - (%d, %d)\n", rs, cs, re, ce);
        return;
    }
    if (isNonDefective(img,rs,re,cs,ce))
        return;
    
    int rm=(rs+re)/2;
    int cm=(cs+ce)/2;
    find(img,rs,rm,cs,cm);    
    find(img,rm+1,re,cs,cm);    
    find(img,rs,rm,cm+1,ce);    
    find(img,rm+1,re,cm+1,ce);
}

int main() {
    int image[4][4] = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 1}
    };

    find(image, 0, 3, 0, 3);

    return 0;
}
