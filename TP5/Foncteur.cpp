#include "Foncteur.h"

bool FoncteurPlatMoinsCher::operator() (const pair<string, Plat*> & plat1, const pair<string, Plat*> & plat2)
{
	return plat1.second->getPrix() < plat2.second->getPrix();
}

bool FoncteurIntervalle::operator()(const pair<string, Plat*>& plat)
{
	return (plat.second->getPrix() < borneSup_) && (plat.second->getPrix > borneInf_);
}
