/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include <iostream>
#include "LectureFichierEnSections.h"

Table * GestionnaireTables::getTable(int id) const
{
	Table* table;
	for (auto it = conteneur_.begin(); it != conteneur_.end(); it++) {
		table = *it;
		if (table->getId() == id) {
			return table;
		}
	}
	return nullptr;
}

Table * GestionnaireTables::getMeilleureTable(int tailleGroupe) const
{
	Table* meilleureTable = nullptr;
	for (Table* table : conteneur_) {
		//Possiblement une erreur ici : la premiere meilleur table n'a pas de tailleGroupe initialisé, donc peut faire bug
		if ((table->getNbPlaces() >= tailleGroupe) && (table->getNbPlaces() < meilleureTable->getNbPlaces())) {
			meilleureTable = table;
		}
	}
	return meilleureTable;
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
		os << *it;
}


