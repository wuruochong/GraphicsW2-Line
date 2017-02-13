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
  int a = abs(y1-y0);
  int b = -(abs(x1-x0));
  int d = 2*a+b;


  if (!mode){    //Octant 1
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
    int a = abs(y1-y0);
    int b = -(abs(x1-x0));
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


/*  else if (mode == 7){
    int a = -(abs(y1-y0));
    int b = -(abs(x1-x0));
    int d =
  } */

}
