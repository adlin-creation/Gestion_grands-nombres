/**
 * Tests unitaires pour Tableau<T>.
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
	Bint nn(9223372036854775807), mm(9223372036854775807), ss("18446744073709551614");
	if(nn + mm != ss) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	Bint nnn("966923079486372458277796550475608139378891827"), 
	     mmm("60409669243946207556163251168934130929"), 
	     sss("966923139896041702224004106638859308313022756");
	if(nnn + mmm != sss) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	Bint bigA("58411503416109668454505152567126127780657282042743951370646730920381369641346017283"),
	     bigB("13292274157728371179371628252008452869230288539864094771978374330607685530035678355"),
	     bigS("71703777573838039633876780819134580649887570582608046142625105250989055171381695638");
	if(bigA + bigB != bigS) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	} 
	Bint bA("58411503416109668454000000000000000000001370646730920300000000000000000081369641346017283"),
	     bB("132922741577283711793716282520084528692302885398640000000000000000000009477197837433060768550000000000030035678355"),
	     bS("132922741577283711793716340931587944801971339398640000000000000001370656208118137433060768550000081369671381695638");
	if(bA + bB != bS) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	} 
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
