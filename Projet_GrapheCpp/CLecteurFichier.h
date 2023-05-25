/*****************************************************************//**
 * \file   CLecteurFichier.h
 * \brief  Interface de la classe CLecteurFichier.
 *		   Cette classe permet de créer des graphes à partir d'un fichier
		   texte.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Mai 2023
 *********************************************************************/

#ifndef C_LECTEUR_FICHIER_H
#define C_LECTEUR_FICHIER_H 14

#include "CGraphe.h"

class CLecteurFichier
{
public:

	/******** Méthodes *********/

	CGraphe LECCreerGrapheDepuisFichier(const char* sFichier);
	/* Cette fonction permet de créer un graphe à partir d'un fichier.
	E : Nom du fichier
	Nécessite : néant
	S : Un objet de la classe CGraphe
	Entraîne : Un graphe extraite du fichier est retourné.
	*/
};
#endif
