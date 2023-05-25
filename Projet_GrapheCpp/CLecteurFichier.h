/*****************************************************************//**
 * \file   CLecteurFichier.h
 * \brief  Interface de la classe CLecteurFichier.
 *		   Cette classe permet de cr�er des graphes � partir d'un fichier
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

	/******** M�thodes *********/

	CGraphe LECCreerGrapheDepuisFichier(const char* sFichier);
	/* Cette fonction permet de cr�er un graphe � partir d'un fichier.
	E : Nom du fichier
	N�cessite : n�ant
	S : Un objet de la classe CGraphe
	Entra�ne : Un graphe extraite du fichier est retourn�.
	*/
};
#endif
