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
	Tableau<int> tab;
	int erreur = 0;
	tab.ajouter(3);
	tab.ajouter(1);
	tab.ajouter(-2);
	tab.ajouter(10);
	tab.ajouter(4);
	tab.ajouter(3);
	tab.ajouter(3);
	tab.ajouter(3);
	if(tab.taille() != 8) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	if(tab[0] != 3 || tab[1] != 1 || tab[3] != 10 || tab[7] != 3) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}
	Tableau<int> sab;
	int n = 2 * 256 * 256;
	for(int i = 0; i < n; i++)
		sab.ajouter(i * 2);
	if(sab.taille() != n){
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	for(int i = 0; i < sab.taille(); i++)
		if(sab[i] != i * 2)
			erreur++;
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
