#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  draw_line(0,0,150,150,s,c); //Octant 1
  draw_line(0,0,375,500,s,c); //Octant 2
  draw_line(150,150,300,50,s,c); //Octant 8
  draw_line(150,150,300,0,s,c); //Octant 7
  draw_line(500,0,125,500,s,c); //Octant 3
  draw_line(500,0,350,150,s,c); //Octant 4
  draw_line(350,150,200,50,s,c); // Octant 5
  draw_line(350,150,200,0,s,c); //Octant 6

  display(s);
  save_extension(s, "lines.png");
}
