#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>


void main()
{ int gd=DETECT,gm,errorcode,i,c,j,b,a,r,l;
static int k=300,s=0;
int i1[4],j1[4],i2[4],j2[4];
char ch;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
setcolor(RED);
outtextxy(320,225,"Press any key to start");
getch();
setbkcolor(RED);
while(1)
{
while(1)
{
i=random(465);
if(i>100)
break;
}
c=i;
i=0;
r=random(2);
if(r==0)
l=random(2);
for(j=0;j<=560;j+=5)
{
cleardevice();

printf("Score=%d\r",s);
setcolor(WHITE);
line(100,0,100,500);
line(101,0,101,500);
line(500,0,500,500);
line(501,0,501,500);
fflush(stdin);


if(kbhit())
{
ch=getch();
if(ch==',' && k>=110)
k-=5;
if(ch=='.' && k<=455)
k+=5;
}
setcolor(WHITE);
rectangle(k,400,k+35,435);
i2[0]=k;
i2[1]=k;
i2[2]=k+35;
i2[3]=k+35;      //moving rectangle

j2[0]=400;
j2[1]=435;
j2[2]=435;
j2[3]=400;

switch(r)
{

case 1:setcolor(WHITE);
rectangle(c,j-35,c+35,j);

i1[0]=c;
i1[1]=c;
i1[2]=c+35;      //falling rectangle
i1[3]=c+35;

j1[0]=j-35;
j1[1]=j;
j1[2]=j;
j1[3]=j-35;

b=i2[0]%5;
a=i1[3]%5;

if( ((i1[2]>i2[0] && i1[2]<i2[3]) || (i1[1]>i2[0] && i1[1]<i2[3]))  && j1[2]==j2[0] )
{
goto b;
}
else if( ((j1[2]>j2[0] && j1[2]<j2[1]) || (j1[3]>j2[0] && j1[3]<j2[1]))  && i2[0]+a==i1[3] )
{
goto b;
}
else if(((j1[1]>j2[3] && j1[1]<j2[2]) || (j1[0]>j2[3] && j1[0]<j2[2]))  && i1[0]-b==i2[3] )
{
goto b;
}delay(40);break;

case 0: switch(l)
	{case 1:setcolor(WHITE);
		line(101,j,245,j);
		if((i2[0]>=101 && i2[0]<=245) && j2[0]==j)
		goto b; break;
	 case 0:setcolor(WHITE);
		line(355,j,500,j);
		if((i2[3]>=355 && i2[0]<=500) && j2[0]==j)
		goto b; break;
	}
delay(40); break;
}
}
s++;


}
b:

getch();
closegraph();
}

