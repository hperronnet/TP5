/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
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
	type_ = gestionnaire->type_;
	conteneur_ = gestionnaire->conteneur_;
}

GestionnairePlats::~GestionnairePlats()
{
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
	pair<string, Plat*> paireMoinsChere;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		if (FoncteurPlatMoinsCher().operator()(*it, paireMoinsChere)) {
			paireMoinsChere = *it;
		}
	}

	return paireMoinsChere.second;
}

Plat * GestionnairePlats::trouverPlatPlusCher() const
{
	auto comparaison = [](const pair<string, Plat*> paire1, const pair<string, Plat*> paire2) -> bool {return paire1.second->getPrix() > paire2.second->getPrix(); };
	return max_element(conteneur_.begin(), conteneur_.end(), comparaison)->second;
}

Plat * GestionnairePlats::trouverPlat(const string & nom) const
{
	pair<string, Plat*> paireTrouvee;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
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
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		paireTrouvee = *it;
		if ((paireTrouvee.second->getPrix() > borneInf) && (paireTrouvee.second->getPrix() < borneSup)) {
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
}

