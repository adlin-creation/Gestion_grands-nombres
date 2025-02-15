/** 
 * Squelette pour la classe Bint.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Hiver 2025)
 * 
 *
 * IDENTIFICATION.
 *
 * 	Nom et prénom : LOUISAMA Adlin
 * 	Code permanent : LOUA20309509
 * 
 */


#ifndef __BINT_H__
#define __BINT_H__

#include "tableau.h"
#include <iostream>
// Vous devez utiliser les assertions pour vérifier les conditions
// de base de transformation des chiffres.
#include <assert.h>

using namespace std;

class Bint {
	/**************** Interface publique ****************
	* 
	* Vous ne devez pas ajouter de nouvelles fonctions 
	* publiques ni modifier les fonctions déjà présentes
	* (ne pas modifier la signature ni la valeur retournée).
	*
	*****************************************************/
	public:	
		/************ Constructeurs et destructeur ************/
		// Constructeurs par défaut
		Bint();
		Bint(long long n);
		Bint(const string & s);
		// Constructeur par copie
		Bint(const Bint & bigA);
		// Constructeur par déplacement "A expliquer"
		Bint(const Bint && bigA);
		// Destructeur
		~Bint();
		/******************************************************/
 

		/*************** Fonctions utilitaires ****************/
		int taille() const;
		/******************************************************/


		/********************* Opérateurs *********************/
		// Opérateurs de comparaison
		bool operator < (const Bint & bigA) const;
		bool operator > (const Bint & bigA) const;
		bool operator >= (const Bint & bigA) const;
		bool operator <= (const Bint & bigA) const;
		bool operator == (const Bint & bigA) const;
		bool operator != (const Bint & bigA) const;
		
		// Opérateur d'affectation par copie
		Bint & operator = (const Bint & bigA);
		Bint & operator = (const string & s);
		// Opérateur d'affectation par dépalcement
		Bint & operator = (const Bint && bigA);
		Bint & operator = (const string && s);

		// Opérateurs arithmétiques
		Bint & operator += (const Bint & bigA);
		Bint operator + (const Bint & bigA) const;
		Bint & operator *= (const Bint & bigA);
		Bint operator * (const Bint & bigA) const;

		// Opérateurs de lecture et d'écriture
		friend ostream & operator << (ostream & os, const Bint & bigA);		
		friend istream & operator >> (istream & is, Bint & bigA);
		/******************************************************/


	/**************** Représentation ********************
	* 
	* Représentation interne de la classe Bint.
	* Vous n'avez pas le droit de la modifier ni d'y ajouter 
	* des variables/attributs.
	*
	*****************************************************/
	private:
    		Tableau<int> bigint;

            // Initialise un Bint à partir d'une chaîne de caractères.
            // Découpe la chaîne en blocs de 9 chiffres et les stocke dans bigint.
            // Complexité : O(n)
		    // n est la longueur de la chaîne d'entrée `s`
			void bint_from_string(const string & s);
            static constexpr int BASE_BLOCS = 1000000000; //Base pour stocker les blocs.
    	
		/**************** Interface privée ******************
		* 
		* Vous pouvez ajouter toutes les fonctions privées
		* que vous estimez nécessaire.
		* N'oubliez pas de bien commenter vos fonctions, de 
		* bien utilisez le mot-clé const et de prendre en 
		* considération les bonnes pratiques.
		*
		*****************************************************/
};

/**************** Fonctions publiques ******************/

Bint::Bint() {
    bigint.ajouter(0);
}

Bint::Bint(long long n) {
	assert(n >= 0);
    while (n > 0) {
        bigint.ajouter(n % BASE_BLOCS);
        n /= BASE_BLOCS;
    }
}


Bint::Bint(const string & s) {
    bint_from_string(s);
}

Bint::Bint(const Bint & bigA){
    bigint = bigA.bigint;
}

Bint::Bint(const Bint && bigA) {
    bigint = bigA.bigint; 
}

Bint::~Bint() {}

int Bint::taille() const {
	if(bigint.taille() == 0){
		return 1;
	}
	int total_chiffres = 9 * (bigint.taille() - 1);
	int bloc_fin = bigint[bigint.taille() - 1];

	while(bloc_fin > 0){
		bloc_fin /= 10;
		total_chiffres++;
	}

	return total_chiffres;
}

bool Bint::operator < (const Bint & bigA) const {
    if (taille() != bigA.taille()) {
        return taille() < bigA.taille();
    }

    if (bigint.taille() == 0 || bigA.bigint.taille() == 0) {
        return false;
    }

    for (int i = bigint.taille() - 1; i >= 0; --i) {
        if (bigint[i] != bigA.bigint[i]) {
            return bigint[i] < bigA.bigint[i];
        }
    }

    return false;
}

bool Bint::operator > (const Bint & bigA) const {
	return bigA < *this;
}

bool Bint::operator <= (const Bint & bigA) const {
	return !(bigA < *this);
}

bool Bint::operator >= (const Bint & bigA) const {
	return !(*this < bigA);
}

bool Bint::operator == (const Bint & bigA) const {
	return bigint == bigA.bigint;
}

bool Bint::operator != (const Bint & bigA) const {
	return !(*this == bigA);
}

Bint & Bint::operator = (const Bint & bigA) {
    if (this != &bigA) {
        bigint = bigA.bigint;
    }
    return *this;
}

Bint & Bint::operator = (const string & s) {
    bigint.vider();
    bint_from_string(s);
    return *this;
}

Bint & Bint::operator = (const Bint && bigA) {
	if(this != &bigA){
		bigint = bigA.bigint;
	}
	return *this;
}

Bint & Bint::operator += (const Bint & bigA) {
	int retenue = 0;
	int max_taille = max(bigint.taille(), bigA.bigint.taille());
	for(int i = 0; i < max_taille || retenue; ++i){
		if(i == bigint.taille()){
			bigint.ajouter(0);
		}
		bigint[i] += (i < bigA.bigint.taille() ? bigA.bigint[i] : 0) + retenue;
		retenue = bigint[i] / BASE_BLOCS;
		bigint[i] %= BASE_BLOCS;
	}
	return *this;
}

Bint Bint::operator + (const Bint & bigA) const {
	Bint res = *this;
	res += bigA;
    return res;
}

Bint & Bint::operator *= (const Bint & bigA) {
    Bint res = (*this * bigA);
    bigint.vider();  
    bigint = res.bigint;
    return *this;
}

Bint Bint::operator * (const Bint & bigA) const {
    if (*this == Bint(0) || bigA == Bint(0)) {
        return Bint(0);
    }
    Tableau<int> resultat;
    for (int i = 0; i < bigint.taille() + bigA.bigint.taille(); ++i) {
        resultat.ajouter(0);
    }

    for (int i = 0; i < bigint.taille(); ++i) {
        long long retenue = 0;
        for (int j = 0; j < bigA.bigint.taille(); ++j) {
            long long produit = static_cast<long long>(bigint[i]) * bigA.bigint[j] + resultat[i + j] + retenue;
            resultat[i + j] = static_cast<int>(produit % BASE_BLOCS);
            retenue = produit / BASE_BLOCS;
        }
        int k = i + bigA.bigint.taille();
        while (retenue > 0) {
            if (k >= resultat.taille()) {
                resultat.ajouter(0);
            }
            long long somme = static_cast<long long>(resultat[k]) + retenue;
            resultat[k] = static_cast<int>(somme % BASE_BLOCS);
            retenue = somme / BASE_BLOCS;
            k++;
        }
    }

    while (resultat.taille() > 1 && resultat[resultat.taille() - 1] == 0) {
        resultat.enlever(resultat.taille() - 1);
    }  
    Bint resultat_final;
    resultat_final.bigint = resultat;
    return resultat_final;
}

ostream & operator << (ostream & os, const Bint & bigA) {
    if (bigA.bigint.taille() == 0) {
        return os << "0";
    }
    if (bigA.bigint.taille() == 1 && bigA.bigint[0] == 0) {
        return os << "0";
    }

    string resultat;
    resultat += to_string(bigA.bigint[bigA.bigint.taille() - 1]);
    for (int i = bigA.bigint.taille() - 2; i >= 0; i--) {
        char buffer[10];
        snprintf(buffer, sizeof(buffer), "%09d", bigA.bigint[i]);  
        resultat += buffer;
    }
    os << resultat;
    return os;
}

std::istream &operator>>(std::istream &is, Bint &bigA) {
    string input;  
    if (!(is >> input)) { 
        bigA = Bint("0");
        return is;
    }
    bigA = input;
    return is;
}

/**************** Fonctions privées *****************/

void Bint::bint_from_string(const string & s) {
    bigint.vider();
    int len = s.size();
    for (int i = len; i > 0; i -= 9) {
        int start = max(0, i - 9);
        string block = s.substr(start, i - start);
        bigint.ajouter(stoi(block));
    }
}

#endif
