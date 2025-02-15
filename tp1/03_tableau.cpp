/**
 * Tests pour la classe Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2025)
 */

#include "tableau.h"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

int main() {
	int n = 2 * 256 * 256;
	Tableau<int> sab(n);
        for(int i = 0; i < n; i++)
                sab.ajouter(i * 2);
	Tableau<int> tab(sab);
	int erreur = 0;
	if(tab.taille() != n) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	for(int i = 0; i < n; i++)
		if(sab[i] != tab[i])
			erreur++;
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
	tab.inverser();
	old_erreur = erreur;
	for(int i = 0; i < n; i++)
		if(sab[i] != tab[n - 1 - i])
			erreur++;
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
	old_erreur = erreur;
	tab.inverser();
	for(int i = 0; i < n; i++)
		if(sab[i] != tab[i])
			erreur++;
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
	sab.vider();
	if(sab.taille() != 0) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
