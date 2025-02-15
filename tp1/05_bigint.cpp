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
	int erreur = 0;
	string sA = "111111111111111111111111111111111111111111111";
	string sB = "999999999999999999999999999999999999999999999";
	string S = "1111111111111111111111111111111111111111111110";
	Bint bigA = sA;
	Bint bigB = sB;
	Bint bigS = S;
	if(bigA + bigB != bigS) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	} 
	bigS += bigS;
	if(bigA + bigB + bigA + bigB != bigS) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	} 
	if(bigA + bigA + bigB + bigB != bigA + bigB + bigA + bigB) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	if(bigB + bigA + bigB + bigA != bigB + bigB + bigA + bigA) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}
	if(bigB + 1 != Bint("1000000000000000000000000000000000000000000000")) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	}	
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
