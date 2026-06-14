#include <iostream>
#include <cstdlib>
#include <string>

#include <sstream>
#include <fstream>

using namespace std;

#include <map>
#include <set>

bool Find_terno(map<string, set<int>>& lotto, string ruota, int n1, int n2, int n3) {
	map<string, set<int>>::iterator it = lotto.find(ruota); // la ruota è la chiave 
	if (it == lotto.end())
		return false;

	if ((*it).second.find(n1) != (*it).second.end() &&
		(*it).second.find(n2) != (*it).second.end() &&
		(*it).second.find(n3) != (*it).second.end()) {
		return true;
	}
	else
		return false;
}

int main(int argc, char* argv[]) {
	map<string, set<int>> lotto;

	ifstream myfile("lotto.txt");

	string ruota;
	int n1, n2, n3, n4, n5;

	if (myfile.is_open()) {
		while (myfile >> ruota >> n1 >> n2 >> n3 >> n4 >> n5) {

			set<int> numeri_estratti;

			numeri_estratti.insert(n1);
			numeri_estratti.insert(n2);
			numeri_estratti.insert(n3);
			numeri_estratti.insert(n4);
			numeri_estratti.insert(n5);

			lotto.insert(std::pair<string, set<int>>(ruota, numeri_estratti));
		}
	}
	else {
		cout << "Errore di apertura del file" << endl;
	}
	myfile.close();

	cout << "Terno (11, 12, 13) su ruota Firenze: " << Find_terno(lotto, "Firenze", 11, 12, 13) << endl;
	cout << "Terno (46, 84, 3) su ruota Milano: " << Find_terno(lotto, "Milano", 46, 84, 3) << endl;

	return 0;
}