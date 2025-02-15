/** 
 * Squelette pour classe générique Tableau<T>.
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

#ifndef __TABLEAU_H___
#define __TABLEAU_H___

// Vous devez utiliser les assertions pour vérifier les conditions
// de base sur les indices.

#include <assert.h>

template <class T>
class Tableau {
	/**************** Interface publique ****************
	* 
	* Vous ne devez pas ajouter de nouvelles fonctions 
	* publiques ni modifier les fonctions déjà présentes 
	* (ne pas modifier la signature ni la valeur retournée).
	*
	*****************************************************/
	public:		
		/************ Constructeurs et destructeur ************/
		// Constructeur par défaut 
		Tableau(int capacite_initiale = 4);
		// Constructeur par copie
		Tableau(const Tableau & autre);
		// Constructeur par déplacement
		Tableau(const Tableau && autre);
		// Destructeur
		~Tableau();
		/******************************************************/


		/*************** Fonctions utilitaires ****************/
		// Ajoute un élément e à la fin du tableau.
		// Si la taille == capacité, alors il faut doubler la 
		// capacité.
		// Complexité amortie : O(1)
		void ajouter(const T & e);

		// Retourne le nombre d'éléments dans le tableau.
		// Complexité : O(1)
		int taille() const;

		// Insère un élément e à la position i du tableau.
		// Si le tableau est vide, alors on doit avoir i == 0
		// Si le tableau n'est pas vide, alors 0 <= i < nbElements.
		// Si la taille == capacité, alors il faut doubler la 
		// capacité.
		// Complexité : O(n) 
		//	n étant la taille du tableau.
		void inserer(const T & e, int i = 0);
		
		// Enlève un élément à la position i.
		// Complexité : O(n)
		//	n étant la taille du tableau.
		void enlever(int i = 0);
		
		// Inverser les éléments du tableau, le dernier deviendra le premier,
		// l'avant dernier deviendra le deuxièm, et ainsi de suite.'
		// Complexité : O(n)
		// n étant la taille du tableau.
		void inverser();

		// Vide le tableau sans libérer la mémoire.
		// Complexité : O(1)
		void vider();
		/******************************************************/
		
		
		/********************* Opérateurs *********************/
		// Opérateurs de comparaison
		//
		// Deux tableaux sont égaux s'ils ont exactement la même taille
		// et les mêmes éléments aux mêmes indices.
		// Complexité : O(n)
		//	n étant la taille du tableau.
		bool operator == (const Tableau<T> & autre) const;
		bool operator != (const Tableau<T> & autre) const;
		// Opérateurs d'accès et de modificatiom
		const T & operator [] (int index) const;
		T & operator [] (int index);
		// Opérateurs d'affectation
		Tableau<T> & operator = (const Tableau<T> & autre);
		Tableau<T> & operator = (const Tableau<T> && autre);
		/******************************************************/
		

	/**************** Représentation ********************
	* 
	* Représentation interne de la classe Tableau<T>,
	* vous n'avez pas le droit de la modifier ni d'y 
	* ajouter des variables/attributs.
	*
	*****************************************************/
	private:
			T * elements;
			int nbElements;
			int capacite;

			//  Redimensionner le tableau dynamique lorsque sa capacité est atteinte.
			//  Double sa capacité actuelle, alloue un nouveau tableau de cette 
			//  nouvelle capacité, copie les éléments existants vers le nouveau tableau. 
			//  complexite : O(n)
			//	n étant la taille du tableau.
			void redimentionner();
		
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

/*************** Fonctions publiques ****************/

template <class T>
Tableau<T>::Tableau(int capacite_initiale) {
	capacite = capacite_initiale;
	nbElements = 0;
	elements = new T[capacite];
}

template <class T>
Tableau<T>::Tableau(const Tableau & autre) {
	capacite = autre.capacite;
	nbElements = autre.nbElements;
	elements = new T[autre.capacite];
	
	for(int i = 0; i < nbElements; ++i){
		elements[i] = autre.elements[i];
	}
}

template <class T>
Tableau<T>::Tableau(const Tableau && tab) {
	elements = tab.elements;
    nbElements = tab.nbElements;
    capacite = tab.capacite;
}

template <class T>
Tableau<T>::~Tableau() {
	delete[] elements;
	elements = nullptr;
}

template <class T>
void Tableau<T>::ajouter(const T & element) {
	if(nbElements >= capacite){
		redimentionner();
	}
	elements[nbElements++] = element;
}

template <class T>
int Tableau<T>::taille() const {
	return nbElements;
}

template <class T>
void Tableau<T>::inserer(const T & element, int index) {
	assert(index <= nbElements && index >= 0);
	if(nbElements == capacite){
		redimentionner();
	}
	for(int i = nbElements - 1; i >= index ; --i ){
		elements[i + 1] = elements[i];
	}
	elements[index] = element;
	nbElements++;
}

template <class T>
void Tableau<T>::enlever(int index) {
	assert(index < nbElements && index >= 0);
	for(int i = index; i < nbElements - 1 ; ++i ){
		elements[i] = elements[i + 1];
	}
	--nbElements;
}

template <class T>
void Tableau<T>::inverser() {
	int fin = nbElements - 1;
	for (int i = 0; i < nbElements / 2; i++) {
		T temp = elements[i];
		elements[i] = elements[fin - i];
		elements[fin - i] = temp;
	}
}

template <class T>
void Tableau<T>::vider() {
	nbElements = 0;
}

template <class T>
bool Tableau<T>::operator == (const Tableau<T> & autre) const {
	if(this == &autre){
		return true;
	}
	if(nbElements != autre.nbElements){
		return false;
	}
	for(int i = 0; i < nbElements; ++i){
		if(elements[i] != autre.elements[i]){
			return false;
		}
	}
	return true;
}

template <class T>
bool Tableau<T>::operator != (const Tableau<T> & autre) const {
	return !(*this == autre);
}

template <class T>
const T & Tableau<T>::operator [] (int index) const {
	assert(index < nbElements && index >= 0);
	return elements[index];
}

template <class T>
T & Tableau<T>::operator [] (int index) {
	assert(index < nbElements && index >= 0);
	return elements[index];
}

template <class T>
Tableau<T> & Tableau<T>::operator = (const Tableau<T> & autre) {
	if(this == &autre){
		return (*this);
	}
	nbElements = autre.nbElements;
	if(capacite < autre.nbElements){
		delete[] elements;
		capacite = autre.capacite;
		elements = new T[capacite];
	}
	for(int i = 0; i < nbElements; ++i){
		elements[i] = autre.elements[i];
	}

	return (*this);
}

template <class T>
Tableau<T> & Tableau<T>::operator = (const Tableau<T> && autre) {
    capacite = autre.capacite;
    nbElements = autre.nbElements;

    elements = new T[capacite];
    for (int i = 0; i < nbElements; ++i) {
        elements[i] = autre.elements[i];
    }
	return *this;
}

/**************** Fonctions privées *****************/

template<class T> 
void Tableau<T>::redimentionner(){
	capacite *= 2;
	T* temp = new T[capacite];
	for(int i = 0; i < nbElements; ++i){
		temp[i] = elements[i];
	}
	delete[] elements;
	elements = temp;
}

#endif
