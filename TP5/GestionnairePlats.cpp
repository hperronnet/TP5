/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.cpp
* Date: 4 Avril 2019
* Auteurs :  Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*******************************************/

#include "GestionnairePlats.h"
#include "LectureFichierEnSections.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"


GestionnairePlats::GestionnairePlats(const string & nomFichier, TypeMenu type) : type_(type)
{
	lirePlats(nomFichier,type);
}

GestionnairePlats::GestionnairePlats(GestionnairePlats * gestionnaire)
{
	for (auto it = gestionnaire->conteneur_.begin(); it != gestionnaire->conteneur_.end(); it++) { //Deep copy
		pair <string, Plat*> paire = *it;
		ajouter(paire);
	}
}

GestionnairePlats::~GestionnairePlats()
{
	for (pair<string, Plat*> paire : conteneur_) {
		delete paire.second;
	}
}

TypeMenu GestionnairePlats::getType() const
{
	return type_;
}

Plat * GestionnairePlats::allouerPlat(Plat * plat)
{
	return new Plat(*plat);
}

Plat * GestionnairePlats::trouverPlatMoinsCher() const
{
	Plat* platMoinsCher = (*(min_element(conteneur_.begin(), conteneur_.end(), FoncteurPlatMoinsCher()))).second;//Utilisation Foncteur
	return platMoinsCher;
}

Plat * GestionnairePlats::trouverPlatPlusCher() const
{
	//utilisation Fonction Lambda
	auto comparaison = [](const pair<string, Plat*> paire1, const pair<string, Plat*> paire2) -> bool {return paire1.second->getPrix() < paire2.second->getPrix(); };
	return max_element(conteneur_.begin(), conteneur_.end(), comparaison)->second;
}

Plat * GestionnairePlats::trouverPlat(const string & nom) const
{
	pair<string, Plat*> paireTrouvee;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) { //On parcours le conteneur avec un iterateur et retourne la plat qui correspond au nom
		paireTrouvee = *it;
		if (paireTrouvee.second->getNom() == nom) {				
			return paireTrouvee.second;
		}
	}
	return nullptr;
}

vector<pair<string, Plat*>> GestionnairePlats::getPlatsEntre(double borneInf, double borneSup)
{
	vector<pair<string, Plat*>> listePlats;
	pair<string, Plat*> paireTrouvee;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) { //On parcours le conteneur avec un iterateur
		paireTrouvee = *it;
		if ((paireTrouvee.second->getPrix() > borneInf) && (paireTrouvee.second->getPrix() < borneSup)) { //On ajoute le plat a la liste si il est dans les bornes
			listePlats.push_back(paireTrouvee);
		}
	}
	return listePlats;
}

void GestionnairePlats::lirePlats(const string& nomFichier, TypeMenu type)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
	while (!fichier.estFinSection())
		ajouter(lirePlatDe(fichier));
}

pair<string, Plat*> GestionnairePlats::lirePlatDe(LectureFichierEnSections& fichier)
{
	auto lectureLigne = fichier.lecteurDeLigne();
	Plat* plat;
	string nom, typeStr;
	TypePlat type;
	double prix, coutDeRevient;
	lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
	type = TypePlat(stoi(typeStr));
	double ecotaxe, vitamines, proteines, mineraux;
	switch (type) {
	case TypePlat::Bio:
		lectureLigne >> ecotaxe;
		plat = new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
		break;
	case TypePlat::BioVege:
		lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
		plat = new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
		break;
	case TypePlat::Vege:
		lectureLigne >> vitamines >> proteines >> mineraux;
		plat = new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
		break;
	default:
		plat = new Plat{ nom, prix, coutDeRevient };
	}
	return pair<string, Plat*>(plat->getNom(), plat);
}

void GestionnairePlats::afficherPlats(ostream & os)
{
	for (pair<string, Plat*> plat : conteneur_) {
		os << plat.second;
	}
}

