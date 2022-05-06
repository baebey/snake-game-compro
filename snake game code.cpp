#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;


int main()
{
	
	bool running = true;
	int a,b;
	char start[100] = "PRESS X TO START";
	char end[100] = "PRESS E TO EXIT";
	char gameover[100] = "GameOver";
	char yourscore[100] = "Your Score : ";
	srand(time(NULL));
	detectgraph(&b,&a);
	initgraph(&b,&a,NULL);
	while(1)
		{
			settextstyle(0, HORIZ_DIR, 3);
			outtextxy(100,200,start);
			outtextxy(100,300,end);
			if(GetAsyncKeyState(88) < 0)
			{
				setcolor(0);
				outtextxy(100,200,start);
				outtextxy(100,300,end);
				break;
			}
			if(GetAsyncKeyState(69) < 0)
			{
				exit(0);
				break;
			}
		}

  	while (running)
  	{
		int baegae,i,X[100],Y[100],rx,ry,a,b,snake,check=2,num=16;
		char score[10];
		srand(time(NULL));
		detectgraph(&b,&a);
		initgraph(&b,&a,NULL);
		setfillstyle(1,2); 
		
		bar(num-num/2,num-num/2,(num/2)+num*(635/num),num+num/2);
		bar(num-num/2,(-num/2)+num*(470/num),(num/2)+num*(635/num),(num/2)+num*(470/num));
		bar(num-num/2,num-num/2,num+num/2,(num/2)+num*(470/num));
		bar((-num/2)+num*(635/num),num-num/2,(num/2)+num*(635/num),(num/2)+num*(470/num));
		X[0]=num*(635/(2*num)); Y[0]=num*(470/(2*num));
    	bar(X[0]-num/2,Y[0]-num/2,X[0]+num/2,Y[0]+num/2);
    	snake=5;
    	for(i=1;i<snake;i++)
    	{
    	    X[i]=X[0]-(i*num);
    	    Y[i]=Y[0];
    	    bar(X[i]-num/2,Y[i]-num/2,X[i]+num/2,Y[i]+num/2);
    	}
    	rx=num; ry=num;
    	baegae = (rand() % 12) +3;
    	setfillstyle(1,baegae);
    	while(getpixel(rx,ry)!=0)
		{
			rx=num*(1+rand()%(620/num-1));
			ry=num*(1+rand()%(460/num-1));
		}
		bar(rx-num/2,ry-num/2,rx+num/2,ry+num/2);
    	delay(1000);
		while(1)
		{
    		setfillstyle(0,0);
			bar(X[snake-1]-num/2,Y[snake-1]-num/2,X[snake-1]+num/2,Y[snake-1]+num/2);
			for(i=snake-1;i>0;i--)
    		{
    			X[i]=X[i-1];
	    		Y[i]=Y[i-1];
			}
    		if(check==0)
				X[0]=X[0]-num;
			if(check==1)
				Y[0]=Y[0]-num;	
    		else if(check==2)
				X[0]=X[0]+num;
			else if(check==3)
				Y[0]=Y[0]+num;
			if(getpixel(X[0],Y[0])==2)
				break;
			if((GetAsyncKeyState(VK_RIGHT))&&(check!=0))
				check=2;
			else if((GetAsyncKeyState(VK_UP))&&(check!=3))
				check=1;
			else if((GetAsyncKeyState(VK_LEFT))&&(check!=2))
				check=0;
			else if((GetAsyncKeyState(VK_DOWN))&&(check!=1))
				check=3;
			if(getpixel(X[0],Y[0])==baegae)
			{
				rx=num; ry=num;
				setfillstyle(1,baegae);
				while(getpixel(rx,ry)!=0)
				{
					rx=num*(1+rand()%(635/num-1));
					ry=num*(1+rand()%(470/num-1));
				}
				bar(rx-num/2,ry-num/2,rx+num/2,ry+num/2);
				snake=snake+1;
				itoa(snake-5, score, 10);
				settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);
				setcolor(15);
				outtextxy(100,100,score);
			}
			setfillstyle(1,2);
			for(i=0;i<snake;i++)
    	   		bar(X[i]-num/2,Y[i]-num/2,X[i]+num/2,Y[i]+num/2);	
			delay(100);
    	}
    	printf("score : %d",snake-5); 
	    settextstyle(0, HORIZ_DIR, 2);
		outtextxy(200,200,gameover);
		outtextxy(200,250,yourscore);
		outtextxy(425,250,score);
		delay(2000);
		closegraph();
		cout << "\nWant to play again? (y/n): ";
    	char answer;
    	cin >> answer;
    	if (answer == 'y') {
    		running = answer == 'y';
    		closegraph();
		}
    	else if (answer == 'n') {
    		running = answer == 'n';
    		exit(0);
		}   	
	}
	return 0;	
}

