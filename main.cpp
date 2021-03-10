#include<iostream>
#include<graphics.h>
#include<windows.h>
#include<math.h>
using namespace std;
char human='0',computer='X';
struct b{
    int x1, y1,x2,y2;
    char value;
}board[9];
void credits();
void about();
void welcome();
void sintialize()
{
    board[0]={533,134,633,234,'_'};
    board[1]={633,134,733,234,'_'};
    board[2]={733,134,833,234,'_'};
    board[3]={533,234,633,334,'_'};
    board[4]={633,234,733,334,'_'};
    board[5]={733,234,833,334,'_'};
    board[6]={533,334,633,434,'_'};
    board[7]={633,334,733,434,'_'};
    board[8]={733,334,833,434,'_'};
}
int isspaceleft()
{
    for(int i=0;i<9;i++)
    if(board[i].value=='_')
    {
        return 1;
    }
    else
        return-1;
}
int winner()
{
    int flag=0;
    if(board[0].value=='X'&&board[1].value=='X'&&board[2].value=='X')
{
    return 10;
}
if(board[3].value=='X'&&board[4].value=='X'&&board[5].value=='X')
{
    return 10;
}
if(board[6].value=='X'&&board[7].value=='X'&&board[8].value=='X')
{
    return 10;
}
if(board[0].value=='X'&&board[3].value=='X'&&board[6].value=='X')
{
    return 10;
}
if(board[1].value=='X'&&board[4].value=='X'&&board[7].value=='X')
{
    return 10;
}
if(board[2].value=='X'&&board[5].value=='X'&&board[8].value=='X')
{
    return 10;
}
if(board[0].value=='X'&&board[4].value=='X'&&board[8].value=='X')
{
    return 10;
}
if(board[2].value=='X'&&board[4].value=='X'&&board[6].value=='X')
{
    return 10;
}
if(board[0].value=='0'&&board[1].value=='0'&&board[2].value=='0')
{
    return -10;
}
if(board[3].value=='0'&&board[4].value=='0'&&board[5].value=='0')
{
    return -10;
}
if(board[6].value=='0'&&board[7].value=='0'&&board[8].value=='0')
{
    return -10;
}
if(board[0].value=='0'&&board[3].value=='0'&&board[6].value=='0')
{
    return -10;
}
if(board[1].value=='0'&&board[4].value=='0'&&board[7].value=='0')
{
    return -10;
}
if(board[2].value=='0'&&board[5].value=='0'&&board[8].value=='0')
{
    return -10;
}
if(board[0].value=='0'&&board[4].value=='0'&&board[8].value=='0')
{
    return -10;
}
if(board[2].value=='0'&&board[4].value=='0'&&board[6].value=='0')
{
    return -10;
}
else
{
    for(int i=0;i<9;i++)
    {
        if(board[i].value=='_')
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        return-1+1;
    }
}
}
int minimax(int depth,bool ismaxplayer)
{
    int score,i;
    score=winner();
    if(score==10)
    {
        return (score+depth);
    }
    if(score==-10)
    {
        return (score-depth);
    }
    if(score==0)
    {
        return score;
    }
    if(ismaxplayer)
    {
        int best=-100,bestscore;
        for( i=0;i<9;i++)
        {
            if(board[i].value=='_')
        {
            board[i].value=computer;
            bestscore=minimax(depth+1,false);
            best=max(best,bestscore);
            board[i].value='_';
        }
        }

        return best;
    }
    else
    {
        int best=100,bestscore;
        for( i=0;i<9;i++)
        {
           if(board[i].value=='_')
        {
            board[i].value=human;
            bestscore=minimax(depth+1,true);
            best=min(best,bestscore);
            board[i].value='_';
        }
        }
     return best;
    }
}

void drawboard()
{
      int score;
     DWORD screenw = GetSystemMetrics(SM_CXSCREEN);
  DWORD screenh = GetSystemMetrics(SM_CYSCREEN);
  initwindow(screenw ,screenh,"TIC TAC TOE ",-3,-3,false,true);
  line(533,234,833,234);
  line(533,334,833,334);
  line(633,134,633,434);
  line(733,134,733,434);
  for(int i=0;i<9;i++)
  {if(board[i].value=='X')
  {
      setcolor(CYAN);
      line(board[i].x1+5,board[i].y1+10,board[i].x2-5,board[i].y2);
      line(board[i].x1+5,board[i].y2,board[i].x2-5,board[i].y1+10);
  }
  else if(board[i].value=='0')
  {
      setcolor(RED);
     circle(board[i].x1+50,board[i].y1+47,45);
     circle(board[i].x1+50,board[i].y1+47,44);
  }

  }
 score=winner();
   if(score==10)
   {
       delay(1000);
       outtextxy(700,500,"X is winner");
       delay(1000);
       welcome();
   }
   else if(score==-10)
   {   delay(1000);
       outtextxy(700,500,"0 is winner");
       delay(1000);
       welcome();
   }

   }
int playermove()
{
    drawboard();
     POINT p;
    int mx,my;
    bool moved=true;
    while(moved)
    {
        GetCursorPos(&p);
        mx=p.x;
        my=p.y;
         setcolor(RED);
         outtextxy(650,500,"Human turn");
        delay(500);
    if(GetAsyncKeyState(VK_LBUTTON))
    {
        for(int i=0;i<9;i++)
        {
           if((mx>=board[i].x1&&my>=board[i].y1)&&(mx<=board[i].x2&&my<=board[i].y2))
        {
            if(board[i].value=='X'||board[i].value=='0')
            {
                outtextxy(650,500,"Space occupied Try another place");
                moved=false;
                 return -1;
            }
            else
            {
                board[i].value=human;
                drawboard();
                moved=false;
                return 1;
            }
        }
        }
    }
    }
    drawboard();
}
int findbestmove()
{
    int bestmove=-100,moveval=0,mov;
    for(int i=0;i<9;i++)
    {
        if(board[i].value=='X'||board[i].value=='0')
            continue;
        else
        {

                board[i].value=computer;
                moveval=minimax(0,false);
                board[i].value='_';
                if(moveval>bestmove)
                {
                    bestmove=moveval;
                    mov=i;
                }

            }

        }
return mov;
}
void computermove()
{
    int score;
    int mov=findbestmove();
    board[mov].value=computer;
    for(int i=0;i<9;i++)
    {
        if(board[i].value=='_')
        {
            board[i].value=human;
            score=winner();
            board[i].value='_';
            if(score==-10)
            {
                board[mov].value='_';
                board[i].value=computer;
                return ;
            }
        }
    }
}
void turn()
{
    int i;
    for(i=1;i<=9;i++)
    {
        int value=0;
        if(isspaceleft())
        {
            if((i)%2!=0)
            {
                value=playermove();
                delay(1000);
                if(i==9)
    {
        outtextxy(650,500,"TIE");
        delay(1000);
        welcome();
    }
                if(value==-1)
                i--;
            }
            else if(i%2==0)
            {
                setcolor(CYAN);
                outtextxy(650,500,"Computer is making move");
                delay(1000);
                computermove();
            }

        }

    }

}

void welcome()
{

    bool click=true;
    DWORD screenw = GetSystemMetrics(SM_CXSCREEN);
  DWORD screenh = GetSystemMetrics(SM_CYSCREEN);
  initwindow(screenw ,screenh,"TIC TAC TOE ",-3,-3,false,true);
       POINT e;
    int mx,my;
     sintialize();
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    outtextxy(653,250,"Tic Tac Toe");
    settextstyle(SIMPLEX_FONT,HORIZ_DIR,1);
  outtextxy(683,450,"1. Play");
  outtextxy(683,500,"2. Credits");
  outtextxy(683,550,"3. About");
  outtextxy(683,600,"4. Exit");
    while(click)
    {
        GetCursorPos(&e);
        mx=e.x;
        my=e.y;
    if(GetAsyncKeyState(VK_LBUTTON))
  {
if((mx>=683&&my>=450)&&(mx<=750&&my<=499))
{
    click=false;
    turn();
}
if((mx>=683&&my>=500)&&(mx<=750&&my<=549))
{
    click=false;
    credits();
}
if((mx>=683&&my>=550)&&(mx<=750&&my<=599))
{
    click=false;
    about();
}
if((mx>=683&&my>=600)&&(mx<=750&&my<=650))
{
    click=false;
    exit(0);
}
  }
  }

}

void credits()
{
    POINT e;
    int mx,my;
    bool click=true;
    DWORD screenw = GetSystemMetrics(SM_CXSCREEN);
  DWORD screenh = GetSystemMetrics(SM_CYSCREEN);
  initwindow(screenw ,screenh,"TIC TAC TOE ",-3,-3,false,true);
    settextstyle(BOLD_FONT,HORIZ_DIR,4);
    outtextxy(603,300,"Created by Rohan Jain(Btech-CSE)");
    outtextxy(603,350,"   College:HMRITM");
     while(click)
    {
        delay(1000);
    if(GetAsyncKeyState(VK_LBUTTON))
    {
        click=false;

        welcome();
    }
    }
}
void about()
{
    POINT e;
    int mx,my;
    bool click=true;
    DWORD screenw = GetSystemMetrics(SM_CXSCREEN);
  DWORD screenh = GetSystemMetrics(SM_CYSCREEN);
  initwindow(screenw ,screenh,"TIC TAC TOE ",-3,-3,false,true);
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(593,330,"1. Tic Tac Toe is a two player board game");
    outtextxy(593,350,"2.If either of player make three consecutive move ");
    outtextxy(593,370,"in row ,column or in diagonal ");
     while(click)
    {
        delay(1000);
    if(GetAsyncKeyState(VK_LBUTTON))
    {
        click=false;

        welcome();
    }
    }
}
int main()
{


    welcome();
    return 0;

}
