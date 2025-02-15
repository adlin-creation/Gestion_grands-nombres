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
	string s = "82300683280345194317140181879730708698582536329447556";
	Bint n(s);

	int erreur = 0;
	if(n.taille() != s.length()) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	Bint m(0);
	if(m.taille() != 1) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	m = n + n;
	if(m.taille() != n.taille() + 1) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
        if(erreur == 0)
                std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
