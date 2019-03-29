/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;


class FoncteurPlatMoinsCher : public GestionnairePlats
{ // TODO ok
	bool operator() (const pair<string, Plat*> & plat1, const pair<string, Plat*> & plat2);
};

class FoncteurIntervalle
{ // TODO ok
public:
	bool operator() (const pair<string, Plat*> & plat);

private:
	int borneSup_;
	int borneInf_;
};

