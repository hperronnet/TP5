/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include <iostream>
#include "LectureFichierEnSections.h"

GestionnaireTables::~GestionnaireTables()
{
	for (Table* table : conteneur_)
		delete table;
}

Table * GestionnaireTables::getTable(int id) const
{
	for (Table* table : conteneur_) {
		if (table->getId() == id) {
			return table;
		}
	}
	return nullptr;
}

Table * GestionnaireTables::getMeilleureTable(int tailleGroupe) const
{
	Table* meilleureTable = new Table(-1, 1000);
	bool meilleurTableTrouvee = false;
	for (Table* table : conteneur_) {
		if ((!table->estOccupee()) && (table->getId() != ID_TABLE_LIVRAISON)) {
			if ((table->getNbPlaces() >= tailleGroupe) && (table->getNbPlaces() < meilleureTable->getNbPlaces())) {
				meilleureTable = table;
				meilleurTableTrouvee = true;
			}
		}
	}
	if (meilleurTableTrouvee)
		return meilleureTable;
	else
		return nullptr;
}

void GestionnaireTables::lireTables(const string& nomFichier)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection("-TABLES");
	while (!fichier.estFinSection()) {
		int id, nbPlaces;
		fichier >> id >> nbPlaces;
		ajouter(new Table(id, nbPlaces));
	}
}

void GestionnaireTables::afficherTables(ostream & os) const
{
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++)
		os << *(*it);
}


