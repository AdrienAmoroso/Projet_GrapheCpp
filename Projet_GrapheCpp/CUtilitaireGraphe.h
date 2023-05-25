/*****************************************************************//**
 * \file   CUtilitaireGraphe.h
 * \brief  Interface de la classe CUtilitaireGraphe.
 *		   Cette classe permet d'utiliser des fonctions avancées sur des
		   graphes.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Mai 2023
 *********************************************************************/

#ifndef C_UTILITAIRE_GRAPHE_H
#define C_UTILITAIRE_GRAPHE_H 13

#include "CGraphe.h"

class CUtilitaireGraphe
{
public:

	/******** Méthodes *********/

	static CGraphe& UTIInverserGraphe(CGraphe &GPHParam);
	/* Cette fonction permet d'inverser un graphe orienté (i.e. inverser le sens des arcs).
	E : Objet CGraphe
	Nécessite : néant
	S : Objet CGraphe inverse de celui passé en paramètre
	Entraîne : On retourne le graphe inversé si le graphe en paramètre est orienté, ou le même s'il ne l'est pas.
	*/
};

#endif