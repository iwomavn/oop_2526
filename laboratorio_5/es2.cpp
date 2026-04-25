using namespace std;

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h> 

#include "link.h"
#include "es2-lqueue.h"
#include "lQueueTest.h"

int main() {
	LQueue<Item> myQueue;
	myQueue.enqueue(Item(1));
	myQueue.enqueue(Item(2));
	myQueue.enqueue(Item(3));
	myQueue.enqueue(Item(4));
	cout << "Ecco la coda originale: ";
	Lqueueprint(myQueue);

	myQueue.reverse();
	cout << "Ecco la coda reversed: ";
	Lqueueprint(myQueue);

	return 0;
}