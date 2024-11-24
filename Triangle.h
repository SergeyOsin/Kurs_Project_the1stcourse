#pragma once
#include "Figure.h"
class Triangle : public Figure {
public:
    Triangle(int x, int y, int a, COLORREF b, COLORREF w);
    void draw() override;
    void hide() override;
    void move(int n_x, int n_y) override;
private:
    int x1, y1;
    int x2, y2;
    COLORREF b1, w1;
};
