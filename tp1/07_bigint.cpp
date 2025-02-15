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
	Bint p = n * m;
	int erreur = 0;
	if(p != 9852165) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	p *= n;
	if(p != 30590972325LL) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	if(n != 3105 || m != 3173) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	n *= 0;
	m *= 1;
	if(n != 0 || m != 3173) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}
	if(p * m != m * p) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	}
	Bint nn = 4965854137, mm = 8314708674, pp("41289630466732684338");
        if(nn * mm != pp) {
                std::cerr << "ECHEC - VI" << std::endl;
                erreur++;
        }
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
} 
