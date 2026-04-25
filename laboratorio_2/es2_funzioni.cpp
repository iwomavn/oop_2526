#include "persona.h"

string Persona::getInformation() {
	return nome.substr(0, 1) + ". " + cognome + ", " + to_string(anni);
}