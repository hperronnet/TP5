/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.h
* Date: 4 Avril 2019
* Auteurs :  Hugo Perronnet 1885263 - Philippe Maisonneuve 1959052
*******************************************/

#pragma once

#include "Table.h"
#include "Foncteur.h"
#include "GestionnaireGenerique.h"

#include <set>

class GestionnaireTables : public GestionnaireGenerique<Table*, set<Table*>>
{
public:
	//Constructeur
	GestionnaireTables() = default;

	//Desctructeur
	~GestionnaireTables();

	//Retourne la table ayant l'ID donnée en paramètre
	Table* getTable(int id) const;

	//Retourne la meilleure table en fonction de la taille du groupe donné en paramètre
	Table* getMeilleureTable(int tailleGroupe) const;

	void lireTables(const string& nomFichier);

	//Affiche les tables
	void afficherTables(ostream& os) const;

};