using namespace std;

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> 

#include "link.h"
#include "queue.h"
#include "es5-LQueueTest.h"


int main() {
	LQueue<Item> Q1, Q2;
	Item temp;

	Q1.enqueue(Item(1));
	Q1.enqueue(Item(2));
	Q1.enqueue(Item(3));
	Q1.enqueue(Item(4));

	Q2.enqueue(Item(1));
	Q2.enqueue(Item(2));
	Q2.enqueue(Item(3));
	Q2.enqueue(Item(7));

	if (equal_queues(Q1, Q2)) {
		cout << "Le due code sono uguali" << endl;
	}
	else {
		cout << "Le due code sono diverse" << endl;
	}
	
	return 0;
}