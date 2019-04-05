/********************************************
* Titre: Travail pratique #5 - GestionnaireGenerique.h
* Date: 4 Avril 2019
* Auteurs :  Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*******************************************/

#pragma once

#include <algorithm>
#include "Foncteur.h"
#include "debogageMemoire.hpp"

using namespace  std;

//              T   = pair<string, Plat*> ou Table*; 
//              C   = map<string, Plat*> ou set<Table*>; 
template<typename T, typename C>
class GestionnaireGenerique
{
public:
	/**
	* Fonction getConteneur()
	* Retourne une copie du conteneur_.
	*/
	C getConteneur() const;

	/** 
	* Fonction ajouter(T t)
	* Ajoute un élément dans le conteneur_
	*/
	void ajouter(T t);

	/**
	* Fonction getNombreElements()
	* retourne le nombre d'élements dans conteneur_
	*/
	int getNombreElements() const;

protected:
	C conteneur_;
};




template<typename T, typename C>
C GestionnaireGenerique<T, C>::getConteneur() const
{
	return conteneur_;
}

template<typename T, typename C>
void GestionnaireGenerique<T, C>::ajouter(T t) 
{
	conteneur_.insert(t);
}

template<typename T, typename C>
int GestionnaireGenerique<T, C>::getNombreElements() const
{
	return conteneur_.size();
}

