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
	     m = Bint("10000000000000000000000000000000000000000000000000000000000"); 
	int erreur = 0;
	if(n == m || m == n) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	if(n > m || m < n) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	if(n >= m || m <= n) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	n *= 10;
	if(n != m || m != n) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}
	if(n > m || m < n || m > n || n < m) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	}
	m += 1;
	if(n == m || m == n) {
		std::cerr << RED << "ECHEC - VI" << RESET << std::endl;
		erreur++;
	}
	if(n > m || m < n) {
		std::cerr << RED << "ECHEC - VII" << RESET << std::endl;
		erreur++;
	}
	if(n >= m || m <= n) {
		std::cerr << RED << "ECHEC - VIII" << RESET << std::endl;
		erreur++;
	}
        if(erreur == 0)
                std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
