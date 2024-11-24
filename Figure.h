#pragma once
#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include <string>
using namespace std;
class Figure {
protected:
	int x, y;
	int a;
	HWND h;
	HDC hd;
	RECT rt;
	COLORREF black;
	COLORREF white;
public:
	Figure() :a(0), x(0), y(0), h(NULL), hd(NULL), black(0), white(0) {};
	Figure(int _x, int _y, int sh, COLORREF b, COLORREF w) : x(_x), y(_y), a(sh), black(b), white(w){
		h = GetConsoleWindow();
		hd = GetDC(h);
		GetClientRect(h, &rt);
	}
	~Figure() {
		ReleaseDC(h, hd);
	}
	virtual void draw();
	virtual void hide();
	virtual void move(int n_x, int n_y) {
		hide();
		x = n_x;
		y = n_y;
		draw();
	}
	class Border {
	private:
		string error;
	public:
		Border() : error("\nBreaking Window border\n") {};
		void err() {
			cout << error << '\n';
		}
	};
	class InvalCoor {
	private:
		string coor;
	public:
		InvalCoor() : coor("\nCoordinates or sides are less than 0\n") {};
		void cr() {
			cout << coor << '\n';
		}
	};
};




