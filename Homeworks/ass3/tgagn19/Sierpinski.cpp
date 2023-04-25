/*
 * File: Sierpinski.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Sierpinski problem
 * on Assignment #3.
 * [TODO: extend the documentation]
 */

#include <iostream>
#include "gwindow.h"
#include <cmath>
#include "simpio.h"
using namespace std;

const int ang1=60;
const int ang2=-60;
const int ang3=180;
const int gwWidth=600;
const int gwHeight=600;
const double forHeight=sqrt(3.0);

void drawTriangle(GWindow& gw, double x, double y, double size, int order){
	if(order<0) return;

  GPoint ep1 =gw.drawPolarLine(x,y,size,ang1);
  GPoint ep2=gw.drawPolarLine(ep1.getX(),ep1.getY(),size,ang2);
  GPoint ep3=gw.drawPolarLine(ep2.getX(), ep2.getY(),size,ang3);

  drawTriangle(gw,ep3.getX(),ep3.getY(),size/2,order-1);
  drawTriangle(gw,ep3.getX()+size/2,ep3.getY(),size/2,order-1);
  drawTriangle(gw,ep3.getX()+size/4,ep3.getY()-(forHeight*size/4),size/2,order-1);


};

int main() {
	GWindow gw(gwWidth,gwHeight);
	double edge= getReal("please enter edge size: ");
	int order =getInteger("please enter order: ");
	drawTriangle(gw,(gw.getWidth()/2)-edge/2, (gw.getHeight()/2)+forHeight*edge/4,edge,order);
    return 0;
}
