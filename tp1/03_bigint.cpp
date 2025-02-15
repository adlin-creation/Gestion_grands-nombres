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
	string s_n = "58411503416109668454505152567126127780657282", s_m = "82300683221933690901030513425225556131456408548790274", s_s = "82300683280345194317140181879730708698582536329447556";
	Bint n(s_n), m(s_m), som(s_s);
	Bint s = n + m;
	int erreur = 0;
	if(s != som || som != s) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	s += n;
	if(s != som + n || n + som != s) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	n += 0;
	m = m + 0;
	if(n + m != som || m + n != som) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	if(n + m != m + n) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}
        Bint nn("58411503416109668454505152567126127780657282"), mm("82300683221933690901030513425225556131456408548790274");
        Bint sum = nn + mm;
        if(sum != som || som != sum) {
                std::cerr << RED << "ECHEC - V" << RESET << std::endl;
                erreur++;
        }
        sum += nn;
        if(sum != som + nn || nn + som != sum) {
                std::cerr << RED << "ECHEC - VI" << RESET << std::endl;
                erreur++;
        }
        nn += 0;
        mm = mm + 0;
        if(nn + mm != som || mm + nn != som) {
                std::cerr << RED << "ECHEC - VII" << RESET << std::endl;
                erreur++;
        }
        if(nn + mm != mm + nn) {
                std::cerr << RED << "ECHEC - VIII" << RESET << std::endl;
                erreur++;
        }
        if(erreur == 0)
                std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
