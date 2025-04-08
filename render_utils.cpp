#include "include/render_utils.h"

void renderBlock(SDL_Texture* Block[],SDL_Rect block[],SDL_Rect block2[],SDL_Renderer* renderer,int *A,int *B)//In ra các ô số
{
    int i,j;
    for(j=1;j<=9;j++)
        if(A[j]!=0)
            SDL_RenderCopy(renderer, Block[A[j]-1], NULL, &block2[j-1]);
    for(j=1;j<=9;j++)
        if(B[j]!=0)
            SDL_RenderCopy(renderer, Block[B[j]-1], NULL, &block[j-1]);
}

