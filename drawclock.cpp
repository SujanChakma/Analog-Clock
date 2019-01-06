//#include <cstdlib>
#include <iostream>
#include "graphics.h"

using namespace std;

//Make first page
void page()
{
      int i;

    setfillstyle(1,2);
     bar(0,0,getmaxx(),getmaxy());

    setcolor(11);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(7,100,"WELCOME TO OUR PROJECT ( ANALOG CLOCK )");
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    outtextxy(45,150,"DESIGNED BY,");
     outtextxy(200,200,"SUJAN CHAKMA");

    setcolor(3);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
     outtextxy(280,300,"Loading.....");

 for( i=0;i<690;i++)
 {
  setcolor(4);
  rectangle(50,400,50+i,410);
  delay(10);
 }

}

//design the clock
void design()
{
    int x, y, i, j, l;

    int hour, minute, second;
    float  p, q, r;
    struct tm *t;
    time_t rawtime;

    x=getmaxx()/2;
    int array[20];
    setfillstyle(1,2);
    bar(0,0,getmaxx(),getmaxy());

    setfillstyle(1,9);
    bar(100,145,700,490);

    setcolor(12);

    for(i = 1;i<=5;i++)
          circle(400,315,170-i);


       setcolor(2);
    for(l=1;l<31;l++)
            circle(400,315,134+l);

     setcolor(3);
     settextstyle(1,0,2);
     outtextxy(388,156,"12");
     outtextxy(310,180,"11");
     outtextxy(250,242,"10");
     outtextxy(243,310,"9");
     outtextxy(265,381,"8");
     outtextxy(325,435,"7");
     outtextxy(400,452,"6");
     outtextxy(475,424,"5");
     outtextxy(520,369,"4");
     outtextxy(537,302,"3");
     outtextxy(515,235,"2");
     outtextxy(462,182,"1");

     rawtime =time(NULL);
           t=localtime(&rawtime);

            hour = t->tm_hour;
             minute = t->tm_min;
              second = t->tm_sec;

               r = 90 - hour * 30;
               q = 90 - minute * 6;
               p = 90 - second * 6;

              setcolor(2);
                        sector(400, 315, p, p+1, 127, 127);//second
                        sector(400, 315, q, q+2, 110, 110);// minute
                        sector(400, 315, r, r+5, 80, 80);//hour

}

void show()
{
     int k, count = 0, hour, minute, second;

    int cir[300]={288,245,287,245,289,243,289,242,290,241,291,240,291,239,292,238,293,237,294,235,303,225,308,220,313,215,319,210,326,205,334,200,
    355,190,360,188,365,187,370,186,375,185,380,184,385,184,390,183,395,183,400,183,405,183,410,183,415,184,420,184,425,185,430,186,435,187,440,
    189,445,190,450,192,455,194,455,194,460,197,465,199,470,202,475,205,480,209,485,214,490,218,495,222,500,227,505,233,510,239,515,248,520,259,
    525,268,530,286,532,300,533,322,532,330,531,340,527,355,525,360,523,365,519,375,507,395,499,405,482,420,468,430,459,435,451,439,431,445,419,
    448,400,448,390,447,370,445,355,440,353,440,348,438,343,436,338,433,333,431,328,427,323,424,318,420,313,416,308,412,303,407,298,401,293,395,
    288,389,283,381,278,373,272,358,271,355,270,350,268,340,267,335,265,320,267,300,269,285,285,245};

    float p , q, r;
    struct tm *t;
    time_t rawtime;

    setfillstyle(1,9);
    fillpoly(98,cir);

    design();

    while(1)
    {
           rawtime =time(NULL);
           t=localtime(&rawtime);

            hour = t->tm_hour;
             minute = t->tm_min;
              second = t->tm_sec;

        r = 90 - hour * 30;
        for(k=1;k<=60;k++)
        {
                delay(1000);
                 q = 90 - minute * 6;

            for(int j=1;j<=60;j++)
            {
                     delay(1000);
                     p = 90 - second * 6;
                for(int i=1;i<=60;i++)
                {

                        delay(1000);

                        setfillstyle(1,9);
                        fillpoly(98,cir);

                        setcolor(2);
                        sector(400, 315, p, p+1, 127, 127);//second
                        sector(400, 315, q, q+2, 110, 110);// minute
                        sector(400, 315, r, r+5, 80, 80);// hour
                        printf("\a");
                        p = p - 6;
                }

                q = q - 6;
                r = r - 0.5;
            }

            for(int h=0;h<12;h++)
            {
                    delay(5);
                    printf("\a");
            }

        }
    }
}



int main(int argc, char *argv[])
{
    initwindow(800,600);
     page();
     show();

    //system("PAUSE");
    return EXIT_SUCCESS;
}
