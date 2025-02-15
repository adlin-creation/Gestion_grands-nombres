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
	int n = 256 * 256;
	for(int i = 0; i < n; i++)
		tab.ajouter(i);
	Tableau<A> sab = tab;
	compteurAffectations = 0;
	Tableau<A> vab = Tableau<A>(sab);
	if(compteurAffectations != n) {
		std::cerr << RED << "ECHEC - I" << RESET << std::endl;
		erreur++;
	}
	int old_erreur = erreur;
	for(int i = 0; i < 100; i++) {
		compteurAffectations = 0;
		tab.enlever();
		if(compteurAffectations != n - i - 1)
			erreur++;
	}
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - II" << RESET << std::endl;
	compteurAffectations = 0;
	vab.inverser();
	if(compteurAffectations > 99000) {
		std::cerr << RED << "ECHEC - III" << RESET << std::endl;
		erreur++;
	}
	old_erreur = erreur;
	for(int i = n - 1; i > 0; i--) {
		compteurAffectations = 0;
		sab.enlever(i - 1);
		if(compteurAffectations != 1)
			erreur++;
	}
	if(old_erreur != erreur)
		std::cerr << RED << "ECHEC - IV" << RESET << std::endl;
	if(erreur == 0)
		std::cout << GREEN << "\t==> OK" << RESET << std::endl;
	return erreur;
}
