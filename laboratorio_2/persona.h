#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream> 
#include <fstream>

using namespace std;
class Persona {
	private:
		string nome;
		string cognome;
		int anni;
	public:
		Persona(string n = "", string c = "", int a = 0) {
			nome = n;
			cognome = c;
			anni = a;
		}
		
		bool operator != (Persona p2) {
			if (nome != p2.nome || cognome != p2.cognome || anni != p2.anni) {
				return true;
			}
			else {
				return false;
			}
		}

		string getInformation();

		void setCognome(string c) {
			cognome = c;
		} 
};

#endif