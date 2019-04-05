/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 4 Avril 2019
* Auteurs :  Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052 
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"
//#include "GestionnairePlats.h"

using namespace std;


class FoncteurPlatMoinsCher
{
public:
	/**
	* operateur()  de FoncteurPlatMoinscher : prend deux paires de <strin,Plat*> et retourne le moins cher des deux
	*/
	bool operator() (const pair<string, Plat*> & plat1, const pair<string, Plat*> & plat2)
	{
		return plat1.second->getPrix() < plat2.second->getPrix();
	}

};

class FoncteurIntervalle
{
public:
	// Constructeur qui prend en paramètre les bornes inférieures et supérieures
	FoncteurIntervalle(int borneInf, int borneSup) : borneInf_(borneInf), borneSup_(borneSup){}

	//Opérateur () qui retorune VRAI si le plat entré en paramètre si situe dans l'intervalle, FALSE sinon.
	bool operator()(const pair<string, Plat*>& plat)
	{
		return (plat.second->getPrix() < borneSup_) && (plat.second->getPrix() > borneInf_);
	}
private:
	int borneSup_;
	int borneInf_;
};

