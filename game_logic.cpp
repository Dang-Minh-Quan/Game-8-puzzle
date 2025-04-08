#include "include/game_logic.h"
#include "include/sdl_utils.h"
#include<map>
#include <ctime>
#include <iostream>
#include<SDL_mixer.h>
using namespace std;

int cansolve(int PuzzleState[],int n)//Kiểm tra tính giải được của bảng
{
    int t=0;
    for(int i=1;i<9;i++)
    {
        for(int j=i+1;j<=9;j++)
        {
            if(i!=n&&j!=n)
            {
                if(PuzzleState[i]>PuzzleState[j])
                    t++;
            }
        }
    }
    return t;
}

void random(int PuzzleState[],int TargetState[])//Tạo 2 bảng trạng thái
{
    int r;
    srand(time(NULL));
    map<int, bool> table1;
    map<int, bool> table2;
    for(int i = 1; i < 9; i++)
    {
    r = 1 + rand()%8;
    while(table1.find(r) != table1.end())
    {
        r = 1 + rand()%8;
    }
    PuzzleState[i]=r;
    table1[r] = true;
    }
    PuzzleState[9]=0;

    if(cansolve(PuzzleState,9)%2==0)
        swap(PuzzleState[8],PuzzleState[7]);

    for(int i = 1; i <=9; i++)
    {
        if(i!=5)
        {
            r = 1 + rand()%8;
            while(table2.find(r) != table2.end())
            {
                r = 1 + rand()%8;
            }
            TargetState[i]=r;
            table2[r] = true;
        }
        else
        {
            TargetState[i]=0;
        }
    }
    if(cansolve(TargetState,5)%2==0)
        swap(TargetState[8],TargetState[9]);
}

void Gameplay(bool &check,int *PuzzleState,int *TargetState,SDL_Event press,int &t,bool &keyPress)//Vận hành game
{
    Mix_Chunk* moveMusic = Mix_LoadWAV("music/move block.wav");
    if(press.type==SDL_KEYDOWN)//Nhận phím từ người chơi,thực hiện di chuyển ô số
    {
        if(press.key.keysym.sym == SDLK_s&&t>3)
        {
            Mix_PlayChannel(-1, moveMusic, 0);
            swap(PuzzleState[t],PuzzleState[t-3]);
            t=t-3;
        }
        if(press.key.keysym.sym == SDLK_w&&t<7)
        {
            Mix_PlayChannel(-1, moveMusic, 0);
            swap(PuzzleState[t],PuzzleState[t+3]);
            t=t+3;
        }
        if(press.key.keysym.sym == SDLK_d&&t%3!=1)
        {
            Mix_PlayChannel(-1, moveMusic, 0);
            swap(PuzzleState[t],PuzzleState[t-1]);
            t=t-1;
        }
        if(press.key.keysym.sym == SDLK_a&&t%3!=0)
        {
            Mix_PlayChannel(-1, moveMusic, 0);
            swap(PuzzleState[t],PuzzleState[t+1]);
            t=t+1;
        }
        keyPress=false;
    }
    for(int i=1;i<=9;i++)//Kiểm tra complete game
    {
        if(PuzzleState[i]!=TargetState[i])
        {
            check=false;
            break;
        }
    }
    if(check)
    {
        Mix_Chunk* WinMusic = Mix_LoadWAV("music/Win.wav");
        Mix_PlayChannel(-1, WinMusic, 0);
    }
}

