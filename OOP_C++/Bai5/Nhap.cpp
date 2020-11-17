#pragma once
#include<iostream>
#include<math.h>
using namespace std;

class Point {
private:
	int x;
	int y;
	
public:
	Point() {
	};
	
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	
	void setX(int x) {
		this->x = x;
	}
	
	int getX() {
		return this->x;
	}
	
	void setY(int y) {
		this->y = y;
	}
	
	int getY() {
		return this->y;
	}
};

class Line : public Point {
private:
	Point begin;
	Point end;

public:
	Line(Point begin, Point end) {
		this->begin = begin;
		this->end = end;
	}
	
	Line(int x1, int x2, int y1, int y2) {
		this->begin = Point(x1, y1);
		this->end = Point(x2, y2);
	}
	
	void setBegin(Point begin) {
		this->begin = begin;
	}
	
	Point getBegin() {
		return this->begin;
	}
	
	void setEnd(Point end) {
		this->end = end;
	}
	
	Point getEnd() {
		return this->end;
	}
	
	double getLength() {
		return sqrt(pow(end.getX() - begin.getX(), 2) + pow(end.getY() - begin.getY(), 2));
	}
};
