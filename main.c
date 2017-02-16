#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;


  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  draw_line(0,0,150,125,s,c); //Octant 1
  c.red = MAX_COLOR;
  draw_line(0,0,375,500,s,c); //Octant 2
  c.blue = MAX_COLOR;
  draw_line(150,125,300,50,s,c); //Octant 8
  c.red = 0;
  draw_line(150,125,200,0,s,c); //Octant 7
  c.green = 0;
  draw_line(500,0,125,500,s,c); //Octant 3
  c.red = MAX_COLOR;
  draw_line(500,0,350,125,s,c); //Octant 4
  c.blue = 0;
  draw_line(350,125,200,50,s,c); // Octant 5
  c.green = MAX_COLOR/2;
  draw_line(350,125,300,0,s,c); //Octant 6
  c.blue = MAX_COLOR/2;
  draw_line(250,0,250,500,s,c); //Vertical
  c.red = MAX_COLOR /2;
  draw_line(0,250,500,250,s,c); //Horizontal



  // int x = 0;
  // int y = 0;
  /*
  while (x<500){
    // printf("x^2=%d\n",x^2);
    draw_line(x,0,x,pow(x,2),s,c);
    x+=5;
  } */

  /*while(x<500){
    while(y<500){
      draw_line(x,0,y,500,s,c);
      y+=20;
    }
    x+=20;
    y=0;
  } */
  /*
  draw_line(200,200,200,300,s,c);
  draw_line(200,200,300,200,s,c);
  draw_line(200,300,300,300,s,c);
  draw_line(300,300,300,200,s,c);
  */

  display(s);
  save_extension(s, "lines.png");
}
