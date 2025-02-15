/**
 * Tests pour la classe Bint.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2025)
 */

#include "bigint.h"
#include <iostream>
#include <sstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

int main() {
	string n = "3909390955393473791578227015671000958260644097114543946458701066532133971549478246266665794490171967",
	       m = "8137827280130828545527222647511351011395165403629738987471813791023206547707737533685485663347623304",
	       r = "15721577995200000000000000000000000000000000000000000000000000000000000000151457837795271",
	       s = "25165403000000000000629738987471800000000000000015145783779527100000000000000000000000000",
	       sr = "395639846045140065609900490608156179360535360000238115620988270343622069923811497525626626209308378905417862080802285857802293947662961862061010996344100000000000000000000000000",
	       nm = "31813948365497734087661737590467748995080104073661569082943304919486919130802268407532030664310394684121736616932281139648894308416008758132670790211956983323903389625081554049198717327467695696718968";
	Bint readN, readM, bigN(n), bigM(m), bigR(r), bigS(s);

	std::cin >> readN;
	std::cin >> readM;

	int erreur = 0;
	if(readN != bigN || readM != bigM) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	std::stringstream tampon;
	tampon << readN;
	if(tampon.str() != n) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	tampon.str("");
	tampon << readM;
	if(tampon.str() != m) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	Bint bigNM = bigN * bigM, bigSR = bigR * bigS;
	tampon.str("");
	tampon << bigNM;
	if(tampon.str() != nm) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	}
	tampon.str("");
	tampon << bigSR;
	if(tampon.str() != sr) {
		std::cerr << RED << "ECHEC - VI" << RESET << std::endl;
		erreur++;
	}
        if(erreur == 0)
                std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
