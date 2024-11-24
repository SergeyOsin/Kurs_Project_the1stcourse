#include "Rectangle.h"
#include "Triangle.h"
#include "Queue.h"
#include "ComplexFigure.h"
#include "Figure.h"
#include <iostream>
using namespace std;
const int NU = system("color F0");
int main() {
	Figure* s[2];
	s[0] = new rectangle(350, 150, 90, RGB(0,0,0), RGB(255, 255, 255));
	s[1] = new Triangle(250, 100, 50, RGB(100, 100, 100), RGB(0, 100, 200));
	Queue deq;
	cout << "Figures: \n ";
	try {
		for (auto& i : s)
			deq.add(i);
		deq.write();
		Sleep(3000);
		s[0]->move(450, 200);
		Sleep(3000);
	}
	catch (Figure::Border br) {
		br.err();
	}
	catch (Figure::InvalCoor ic) {
		ic.cr();
	}
	Sleep(5000);
	system("pause");
	return 0;
}
