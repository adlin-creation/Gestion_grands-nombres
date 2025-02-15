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
	Bint n(3105), m(3173);
	Bint s = n + m;
	int erreur = 0;

	if(s != 6278) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	s += n;
	if(s != 9383) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	if(n != 3105 || m != 3173) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	n += 0;
	m = m + 0;
	if(n != 3105 || m != 3173) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}
	if(n + m != m + n) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;

}
