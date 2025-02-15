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
        int n = 2 * 512;
	Tableau<int> sab(n);
        for(int i = 0; i < n; i++)
                sab.inserer(i);
	Tableau<int> tab(sab);
	int erreur = 0;
	if(tab != sab) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	for(int i = 0; i < n/4; i++)
		sab[i * 2] = i * 4;
		
	if(tab == sab) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	for(int i = 0; i < n; i++)
		tab.inserer(-i,i);
	int old_erreur = erreur;
	for(int i = 0; i < n; i++)
		if(tab[i] != -i || tab[tab.taille() - 1 - i] != i) 
			erreur++;
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
