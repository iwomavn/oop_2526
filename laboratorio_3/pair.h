#ifndef PAIR_H
#define PAIR_H

#include <iostream>
using namespace std;

template<class T>
class Pair {
	T first;
	T second;
public:
	Pair(T f, T s) {
		first = f;
		second = s;
	}

	void set_element(int position, T value) {
		if (position == 1) {
			first = value;
		}
		else if (position == 2) {
			second = value;
		}
		else {
			cout << "Illegal position" << endl;
		}
	}

	T get_element(int position) const {
		if (position == 1) {
			return first;
		}
		else if (position == 2) {
			return second;
		}
		else {
			cout << "Illegal position" << endl;
		}
	}
	void add_up(const Pair<T>& the_pair) {
		first = first + the_pair.first
		second = second + the_pair.second;
	}

};
	


#endif
