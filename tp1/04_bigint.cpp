/**
 * Tests pour la classe Bint.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2025)
 */

#include "bigint.h"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

int main() {
	Bint n = Bint("58411503416109668454505152567126127780657282"), m = Bint("82300683221933690901030513425225556131456408548790274"), som = Bint("82300683280345194317140181879730708698582536329447556");
	Bint s = n + m;
	int erreur = 0;
	if(s != som || som != s) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	m += n;
	if(s != m || m != s) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	Bint nn(n);
	if(n != nn) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	for(int i = 0; i < 5; i++)
		n += nn;	
	if(n == nn) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}
	Bint x = Bint("350469020496658010727030915402756766683943692");
	if(n != x) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	}
        if(erreur == 0)
                std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
