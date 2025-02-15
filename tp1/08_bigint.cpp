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
	Bint n = Bint("58411503416109668454505152567126127780657282"), m = Bint("82300683221933690901030513425225556131456408548790274"), prod = Bint("4807306639166139460924699561035220353141037092557094588339717024466123636617961228068977688875268");
	Bint p = n * m;
	int erreur = 0;
	if(p != prod) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	m *= n;
	if(m != p) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	if(p * p != m * m) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
        if(erreur == 0)
                std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
