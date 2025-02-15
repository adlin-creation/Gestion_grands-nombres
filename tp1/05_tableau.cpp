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
	Tableau<int> lab;
	for(int i = 0; i < n; i++)
		lab.inserer(i * 100);
	Tableau<int> tab = Tableau<int>(lab);
	Tableau<int> sab = tab;
	int erreur = 0;
	if(tab != sab) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	for(int i = 0; i < n; i += 2)
		tab.enlever();
	if(tab.taille() != n/2 || sab.taille() != n) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;	
	}
	int old_erreur = erreur;
	for(int i = 0; i < tab.taille(); i++)
		if(tab[i] != sab[n/2 + i]) 
			erreur++;
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
	for(int i = tab.taille() - 1; i >= 0; i--)
		sab.enlever(i);
	if(tab != sab) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
