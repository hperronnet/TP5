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



Plat * GestionnairePlats::trouverPlat(const string & nom) const
{
	return nullptr;
}

vector<pair<string, Plat*>> GestionnairePlats::getPlatsEntre(double borneInf, double borneSup)
{
	return vector<pair<string, Plat*>>();
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
	pair<string, Plat*> platMoinsCher;
	FoncteurPlatMoinsCher f();
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		f(it, platMoinsCher);												//Marche pas, a refaire
 	}

	return platMoinsCher.second;
}

Plat * GestionnairePlats::trouverPlatPlusCher() const
{
	return nullptr;
}
