/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include "Plat.h"
#include "Vege.h"
#include "gestionnaireGenerique.h"
#include "Foncteur.h"

#include <utility>
#include <map>
#include <algorithm>
#include <functional>
//#include <iterator>

using namespace std;

class GestionnairePlats : public GestionnaireGenerique<pair<string, Plat*>, map<string, Plat*>>
{
public:
	GestionnairePlats(const string& nomFichier, TypeMenu type); //TODO ok
	GestionnairePlats(GestionnairePlats* gestionnaire); // TODO ok

	~GestionnairePlats(); // TODO ok

	TypeMenu getType() const; // TODO ok

	Plat* allouerPlat(Plat*); // TODO ok

	Plat* trouverPlatMoinsCher() const; // TODO ok
	Plat* trouverPlatPlusCher() const; // TODO ok

	Plat* trouverPlat(const string& nom) const; // TODO ok
	vector<pair<string, Plat*>> getPlatsEntre(double borneInf, double borneSup); // TODO ok
	void lirePlats(const string& nomFichier, TypeMenu type);
	pair<string, Plat*> lirePlatDe(LectureFichierEnSections& fichier);

	void afficherPlats(ostream& os);

private:
	TypeMenu type_;
};