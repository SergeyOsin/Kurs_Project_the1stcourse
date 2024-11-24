#pragma once
#include "Figure.h"
#include <queue>
class Queue {
private:
	queue<Figure*>fig;
public:
	void write();
	void add(Figure* f);
	~Queue();
};
