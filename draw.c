#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  printf("drawing line\n");
  int mode; //0 = Octant 1, 1 = Octant 2, 2 = Octant 3...

  if(x0>x1){   //Swap if Octant 3-6
    printf("swap used \n");
    int temp = x1;
    x1 = x0;
    x0 = temp;
    temp = y1;
    y1 = y0;
    y0 = temp;
  }

  int x = x0;
  int y = y0;
  float m = ((float)(y1-y0))/(x1-x0);
  printf("m= %f\n",m);
  if (m >= 0){
    if (m<=1){
      mode = 0;
    }
    else{
      mode = 1;
    }
  }
  else{
    if (m>=-1){
      mode = 2;
    }
    else{
      mode = 3;
    }
  }

  printf("mode: %d\n",mode);



  if (!mode){ //Octant 1
    int a = (y1-y0);
    int b = -((x1-x0));
    int d = 2*a+b;
    while (x<=x1){
      plot(s,c,x,y);
      if (d>0){
        y++;
        d+=2*b;
      }
      x++;
      d+=2*a;
    }
  }

  else if (mode == 1){  //Octant 2
    int a = (y1-y0);
    int b = -((x1-x0));
    int d = 2*b+a;
    while (y<=y1){
      plot(s,c,x,y);
      if (d<0){
        x++;
        d+=2*a;
      }
      y++;
      d+=2*b;
    }
  }

  else if (mode == 3){  //Octant 7
    int a = (y1-y0);
    int b = -((x1-x0));
    int d = a-2*b;
    while (y>=y1){
      plot(s,c,x,y);
      if (d>0){
        x++;
        d+=2*a;
      }
      y--;
      d-=2*b;
    }

  }

  else if (mode == 2){ //Octant 8
    printf("Octant 8 running \n");
    int a = (y1-y0);
    int b = -((x1-x0));
    int d = 2*a-b;
    while (x<x1){
      // printf("x:%d\n",x);
      plot(s,c,x,y);
      // printf("d:%d\n",d);
      if (d<0){
        y--;
        d-=2*b;
      }
      x++;
      d+=2*a;
    }
  }


/*  else if (mode == 7){
    int a = -(abs(y1-y0));
    int b = -(abs(x1-x0));
    int d =
  } */

}
