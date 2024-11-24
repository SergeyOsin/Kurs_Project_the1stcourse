#include "Rectangle.h"
#include "Figure.h"
rectangle::rectangle(int x, int y, int a, COLORREF b, COLORREF w) : bc(b), wc(w),
    Figure(x, y, a, b, w) {
    x3 = x, y3 = y;
    x4 = x + a, y4 = y + a;
}

void rectangle::hide() {
    cout << "Rectangle is hidden: " << x3 << " " << y3 << " " << x4 << " " << y4 << '\n';
    HPEN p = CreatePen(PS_SOLID, 2, RGB(255,255,255));
    HBRUSH b = CreateSolidBrush(RGB(255,255,255));
    SelectObject(hd, p);
    SelectObject(hd, b);
    Rectangle(hd, x3, y3, x4, y4);
    DeleteObject(p);
    DeleteObject(b);
}

void rectangle::draw() {
    
    if (x + a > rt.right || x - a < rt.left || y + a > rt.bottom || y - a < rt.top) {
        throw Border();
    }       
    if (x3 < 0 || y3 < 0 || x4 < 0 || y4 < 0)
        throw InvalCoor();
    if (x < 0 || y < 0 || a <= 0) {
        throw InvalCoor();
    }
    cout << "Rectangle: " << x3 << " " << y3 << " " << x4 << " " << y4 << '\n';
    HPEN p = CreatePen(PS_SOLID, 2, bc); 
    HBRUSH b = CreateSolidBrush(wc); 
    GetClientRect(h, &rt);
    SelectObject(hd, p); 
    SelectObject(hd, b);
    Rectangle(hd, x3, y3, x4, y4);
    DeleteObject(p); 
    DeleteObject(b); 
}

void rectangle::move(int n_x, int n_y) {
    this->hide();
    x = n_x, y = n_y;
    x3 = x, y3 = y;
    x4 = x + a, y4 = y + a;
    this->draw();
}


