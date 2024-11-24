#pragma once
#include "Figure.h"
class rectangle : public Figure {
public:
	rectangle(int x, int y, int a, COLORREF b, COLORREF);
	void draw() override;
	void hide() override;
	void move(int n_x, int n_y) override;
private:
	int x3, y3;
	int x4, y4;
	COLORREF bc, wc;
};
