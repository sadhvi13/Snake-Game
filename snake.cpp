#include<iostream>
#include<cstdlib>
#include<iostream.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y,fruitx,fruity,score;
int tailx[100],taily[100],ntail;
enum edirection{stop=0,LEFT,RIGHT,UP,DOWN
};
edirection dir;
void setup()
{
	gameover=false;
	dir=stop;
	x=width/2;
	y=height/2;
	fruitx=rand()%width;
	fruity=rand()%height;
	score=0;
}
void draw()
{
	system("cls");
	for(int i=0;i<width+1;i++)
	cout<<"#";
	cout<<endl;
	for(int i=0;i<width;i++)
	{
		for(int j=0;j<height;j++)
		{
			if( j==0||j==(height-1))
			cout<<"#";
		    if(i==y&&j==x)
			cout<<"O";
			else if(i==fruity&&j==fruitx)
			cout<<"F";
			
			else
			{
				bool print=false;
				for(int k=0;k<ntail;k++)
				{
					if(tailx[k]==j&&taily[k]==i)
					{
						cout<<"o";
						print=true;
					}
				}
				if(!print)
				cout<<" ";
			}
			
				
		}	
		cout<<endl;
	}
	for(int i=0;i<width+1;i++)
	{
		cout<<"#";
	}
	cout<<endl;
	cout<<"Score:"<<score;
}
void input()
{
	if(kbhit())
	{
		switch(getch())
		{
			case 'w':
				dir=LEFT;
				break;
			case 'e':
				dir=RIGHT;
			case 'n':
				dir=UP;
				break;
			case 's':
				dir=DOWN;
				break;
				case 'x':
					gameover=true;
					break;
		}
	}
}
void logic()
{
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<ntail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch(dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default :
			break;
	}
	if(x>width||x<0||y>height||y<0)
	gameover=true;
	if(x==fruitx&&y==fruity)
	{
		score+=10;
		fruitx=rand()/width;
		fruity=rand()/height;
		ntail++;
	}
	
}
int main()
{
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
		Sleep(50);
	}
	return 0;
}

