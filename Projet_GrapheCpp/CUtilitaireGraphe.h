/*****************************************************************//**
 * \file   CUtilitaireGraphe.h
 * \brief  Interface de la classe CUtilitaireGraphe.
 *		   Cette classe permet d'utiliser des fonctions avanc�es sur des
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

	/******** M�thodes *********/

	static CGraphe& UTIInverserGraphe(CGraphe &GPHParam);
	/* Cette fonction permet d'inverser un graphe orient� (i.e. inverser le sens des arcs).
	E : Objet CGraphe
	N�cessite : n�ant
	S : Objet CGraphe inverse de celui pass� en param�tre
	Entra�ne : On retourne le graphe invers� si le graphe en param�tre est orient�, ou le m�me s'il ne l'est pas.
	*/
};

#endif