/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.h
* Date: 4 Avril 2019
* Auteurs :  Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
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
	//Constructeur par paramètre
	GestionnairePlats(const string& nomFichier, TypeMenu type);

	//Constructeur de copie
	GestionnairePlats(GestionnairePlats* gestionnaire);

	//Destructeur
	~GestionnairePlats();

	TypeMenu getType() const;

	//Retourne un pointeur vers un nouveau plat contenant les propriétés du Plat passé en paramètre
	Plat* allouerPlat(Plat*);

	//Utilise le FoncteurPlatMoinsCher pour trouver le plat le moins cher d'un conteneur
	Plat* trouverPlatMoinsCher() const;

	//Utilise une fonction Lambda et la STL pour trouver le plat le plus cher d'un conteneur
	Plat* trouverPlatPlusCher() const;

	//Trouve un plat dans un conteneur à partir de son nom
	Plat* trouverPlat(const string& nom) const;

	//Retourne tous les plas dont les prix sont entre borneSup et borneInf
	vector<pair<string, Plat*>> getPlatsEntre(double borneInf, double borneSup);

	void lirePlats(const string& nomFichier, TypeMenu type);
	pair<string, Plat*> lirePlatDe(LectureFichierEnSections& fichier);

	void afficherPlats(ostream& os);

private:
	TypeMenu type_;
};