#pragma once
#include "Figure.h"
#include "Triangle.h"
#include "Rectangle.h"
class ComplexFigure : public Figure {
private:
	Triangle* tr;
	rectangle* rc;
public:
	ComplexFigure(int x, int y, int a,  COLORREF w, COLORREF c, COLORREF w1, COLORREF b1);
	~ComplexFigure();
	void draw() override;
	void hide() override;
	void move(int n_x, int n_y) override;
};