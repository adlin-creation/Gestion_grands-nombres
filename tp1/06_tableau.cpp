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

unsigned int compteurAffectations = 0;
class A {
	private:
		int x;
	public:
		A(int x_ = 0) : x(x_) {}
		bool operator < (const A & o) const { return x < o.x; }
		bool operator <= (const A & o) const { return x <= o.x;	}
		bool operator == (const A & o) const { return x == o.x;	}
		bool operator != (const A & o) const { return x != o.x;	}
		bool operator >= (const A & o) const { return x >= o.x;	}
		bool operator > (const A & o) const {	return x > o.x;	}
		A & operator = (const A & o) {
			compteurAffectations++;
			x = o.x;
			return *this;
		}
};

int main() {
	Tableau<A> tab;
	int erreur = 0;
	int size = 256 * 256 * 256;
	int affectations = 33554428;
	compteurAffectations = 0;
	for(int i = 0; i < size; i++)
		tab.ajouter(i);
	unsigned int affectations_tab = compteurAffectations;
	Tableau<A> sab(size + 1);
	compteurAffectations = 0;
	for(int i = 0; i < size; i++)
		sab.ajouter(i);
	unsigned int affectations_sab = compteurAffectations;
	if(affectations_sab != size) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	if(affectations_tab != affectations) {
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
		erreur++;
	}	
	if(affectations_sab >= affectations_tab) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	compteurAffectations = 0;
	Tableau<A> vab = tab;
	if(compteurAffectations != size) {
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
		erreur++;
	}
	tab.vider();
	if(tab.taille() != 0) {
		std::cerr << RED << "ECHEC - V" << RESET << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	tab.ajouter(0);
	for(int i = 0; i < 100; i++) {
		compteurAffectations = 0;
		tab.inserer(i * i, i);
		if(compteurAffectations != 2)
			erreur++;
	}
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - VI" << RESET << std::endl;
	old_erreur = erreur;
	for(int i = 0; i < 100; i++) {
		compteurAffectations = 0;
		tab.inserer(i * i);
		if(compteurAffectations != tab.taille())
			erreur++;
	}
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - VII" << RESET << std::endl;
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
