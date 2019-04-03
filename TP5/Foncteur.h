/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"
//#include "GestionnairePlats.h"

using namespace std;


class FoncteurPlatMoinsCher
{ // TODO ok
public:
	FoncteurPlatMoinsCher() {};
	bool operator() (const pair<string, Plat*> & plat1, const pair<string, Plat*> & plat2)
	{
		return plat1.second->getPrix() < plat2.second->getPrix();
	}

};

class FoncteurIntervalle
{ // TODO ok
public:

	FoncteurIntervalle(int borneInf, int borneSup) : borneInf_(borneInf), borneSup_(borneSup){}

	bool operator()(const pair<string, Plat*>& plat)
	{
		return (plat.second->getPrix() < borneSup_) && (plat.second->getPrix() > borneInf_);
	}
private:
	int borneSup_;
	int borneInf_;
};

