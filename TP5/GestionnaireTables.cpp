/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include <iostream>
#include "LectureFichierEnSections.h"

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

Table* getTable(int id) const: {
	for (auto it = c.begin(); it != c.end(); it++)
	{
		if (it->id == id)
			return it;
	}
}

Table* getMeilleureTable(int tailleGroupe) {
	Table* meilleureTable = new Table;
	for (auto it = c.begin(); it != c.end(); it++)
		if (it->nbPlaces_ < meilleureTable->nbPlaces_)
			meilleureTable = it;
	return it;
}

void  afficherTables(ostream&  os)  const {
	for (auto it = c.begin(); it != c.end(); it++)
		cout << *it;
	}

