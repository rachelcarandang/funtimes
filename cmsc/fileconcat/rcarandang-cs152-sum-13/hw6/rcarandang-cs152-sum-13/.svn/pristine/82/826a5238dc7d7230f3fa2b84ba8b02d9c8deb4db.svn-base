/* Rachel Carandang, rcarandang */
/* CMSC2 Summer 2013 */
/* Lab 3 */

#include <stdio.h>
#include <stdlib.h>
#include "checkit.h"

#define PI 3.14159

struct point {
	float x;
	float y;
	};

struct square {
	float s;
	struct point* position; 
	};

struct rectangle {
	float width;	
	float height;
	struct point* position; 
	};

struct circle {
	float radius;
	struct point* position; 
	};

typedef struct point* Point;
typedef struct square* Square;
typedef struct rectangle* Rect;
typedef struct circle* Circle;

Point mkPoint(float x, float y);
Square mkSquare(float s, Point position);
float squarePerimeter(Square mySquare);
float squareArea(Square mySquare);
Rect mkRect(float width, float height, Point position);
float rectPerimeter(Rect myRect);
float rectArea(Rect myRect);
Circle mkCircle(float radius, Point position);
float circlePerimeter(Circle myCircle);
float circleArea(Circle myCircle);

int main(void) {
	Point testPoint=mkPoint(2, 3);
	Square testSquare=mkSquare(4, testPoint);
	Rect testRect=mkRect(4, 5, testPoint);
	Circle testCircle=mkCircle(3, testPoint);
	checkit_float(squarePerimeter(testSquare), 16.0f);
	checkit_float(squareArea(testSquare), 16.0f);
	checkit_float(rectPerimeter(testRect), 18.0f);
	checkit_float(rectArea(testRect), 20.0f);
	checkit_float(circlePerimeter(testCircle), 6.0f*PI);
	checkit_float(circleArea(testCircle), PI*9.0f);
	return 0;
}


Point mkPoint(float x, float y){
	Point point1=(Point)malloc(sizeof(struct point));
	point1->x=x;
	point1->y=y;
	return point1;
};

// Square functions 

Square mkSquare(float s, Point position) {
	Square square1;
	square1 = (Square)malloc(sizeof(struct square)); 
	square1->s=s;
	square1->position=position;
	return square1;
};
float squarePerimeter(Square mySquare){ 
	return 4*(mySquare->s);
	};

float squareArea(Square mySquare){
	return (mySquare->s)*(mySquare->s);
	};


// Rectangle functions

Rect mkRect(float width, float height, Point position) {
	Rect rect1;
	rect1 = (Rect)malloc(sizeof(struct rectangle)); 
	rect1->width=width;
	rect1->height=height;
	rect1->position=position;
	return rect1;
};

float rectPerimeter(Rect myRect){
	return 2*(myRect->width) + 2*(myRect->height);
	};

float rectArea(Rect myRect){
	return (myRect->width)*(myRect->height);
	};

// Circle functions

Circle mkCircle(float radius, Point position) {
	Circle circle1;
	circle1 = (Circle)malloc(sizeof(struct circle)); 
	circle1->radius=radius;
	circle1->position=position;
	return circle1;
};
float circlePerimeter(Circle myCircle) {
	return 2*PI*(myCircle->radius);
	};

float circleArea(Circle myCircle){
	return PI*(myCircle->radius)*(myCircle->radius);
	};




