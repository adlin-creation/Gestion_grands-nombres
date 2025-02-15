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
	Bint n = Bint("1000000000000000000000000000000000000000000000000000000000"),
	     m = Bint("100000000000000000000000000000000000000000000000000000000000000"), 
	     prod = Bint("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	Bint p = n * m;
	int erreur = 0;
	if(p != prod) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	p *= p;
	if(p != prod * prod) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	if(p != n * m * n * m) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	Bint v("22222222222222222222222222222222222222222222222222222222222222222222"),
	     w("111111111111111111111111111111111111111111111111111111111111111111110");
	if(v * 5 != w) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}	
        if(erreur == 0)
                std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
