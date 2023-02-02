#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
int t1=300,t2=100;
int c1=0,c2=0; // c1=up/down , c2=left/right

void car()
{
    setcolor(12);
   rectangle(305+c2,350-c1,325+c2,330-c1);
  rectangle(300+c2,350-c1,330+c2,390-c1);
  ellipse(298+c2,357-c1,0,360,2,6);
  ellipse(332+c2,357-c1,0,360,2,6);
  ellipse(298+c2,382-c1,0,360,2,6);
  ellipse(332+c2,382-c1,0,360,2,6);
}
void control()
{
    char ch;
    ch=getch();

  switch(ch)
  {
    case 'w':
  {
    c1=c1+5;
    break;
  }
  case 's':
  {
    c1=c1-5;
    break;
  }
  case 'd':
  {
    c2=c2+5;
    break;
  }
  case 'a':
  {
    c2=c2-5;
    break;
  }
  case 'e' :
  {
   exit(0);
  }
 }
}
void traffic(int t1,int t2)
{
   setcolor(2);
  rectangle(t1,t2,t1+30,t2+40);
  rectangle(t1+5,t2,t1+25,t2+60);
  ellipse(t1-1,t2+7,0,360,2,6);
  ellipse(t1+32,t2+7,0,360,2,6);
  ellipse(t1-1,t2+30,0,360,2,6);
  ellipse(t1+32,t2+30,0,360,2,6);
}
void road(int r,int d,int tc,int tc2)
{
static int count=0;
  do
  {
    gotoxy(45,2);
    printf("Cars no:%d" ,count);
    line(10,10,10,600); // end of road1
    line(440,10,440,600); // end of road2

    car();
    if(tc==480) // traffic car control
    {
    //randomize();
      tc=0;
      tc2=random(330); //traffic car position
      count=count+2;
    }
    traffic(tc2+14,10+tc);
    traffic(tc2+100,tc2+tc);
    tc=tc+10;
    setcolor(11);
    line(300,100+r,300,200+r); //middle road line 1
    line(150,100+r,150,200+r); //middle road
   r=r+8;
   d=d+8;
   line(300,300+d,300,400+d); //middle road line 2
   line(150,300+d,150,400+d); // middle road
   if(r==400)
   r=0;
   if(d==200)
       d=-200;
   delay(30);
  clearviewport();
 }while(!kbhit());
}

void main()
{
  int gd=DETECT,gm;
  int r=0,d=0; //road
  int tc=0,tc2=0; // traffic cars control
  initgraph(&gd,&gm,"C:\\turboc3\\bgi");
  do
  {
     road(r,d,tc,tc2);
    control();
  }while(1);
  getch();
  closegraph();
}
