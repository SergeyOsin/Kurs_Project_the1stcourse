#include "Queue.h"
void Queue::add(Figure* f) {
	fig.push(f);
}
void Queue::write() {
	if (fig.empty()) {
		cout << "Queue is empty!";
		return;
	}
	while (!fig.empty()) {
		fig.front()->draw();
		fig.pop();
	}
}
Queue::~Queue() {
	while (!fig.empty())
		fig.pop();
}
