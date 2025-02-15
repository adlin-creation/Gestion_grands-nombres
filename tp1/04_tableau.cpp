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
	int n = 1024;
        Tableau<int> sab(n);
        for(int i = 0; i < n; i++)
                sab.inserer(i * 2);
	Tableau<int> tab = Tableau<int>(sab);
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
	for(int i = 0; i < n; i++)
		sab[i] = -2 * i - 1;
	old_erreur = erreur;
	for(int i = 0; i < n; i++)
		if(sab[i] == tab[i])
			erreur++;
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
