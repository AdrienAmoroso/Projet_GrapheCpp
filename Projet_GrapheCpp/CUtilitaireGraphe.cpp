/*****************************************************************//**
 * \file   CUtilitaireGraphe.cpp
 * \brief  Corps de la classe CUtilitaireGraphe.
 *		   Cette classe permet d'utiliser des fonctions avancées sur des
		   graphes.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Mai 2023
 *********************************************************************/

 /*CLASSE CException
	 DOCUMENTATION
		 Attributs : uiEXCValeur : entier naturel, contient la valeur de l’exception.
		 Structure : Cette classe contient une méthode de modification de la valeur
					 de l'exception, une méthode de consultation de celle-ci et
					 une méthode d'affichage des messages d'erreurs.
		 Méthode : néant
		 Modules internes:*/

// CORPS

#include "CUtilitaireGraphe.h"

// Méthodes

/**************************************************************
Nom : UTIInverserGraphe
***************************************************************
Cette fonction permet d'inverser un graphe orienté (i.e. inverser
le sens des arcs).
***************************************************************
Entrée : Objet CGraphe
Nécessite : néant
Sortie : Objet CGraphe inverse de celui passé en paramètre
Entraîne : On retourne le graphe inversé si le graphe en paramètre
		   est orienté, ou le même s'il ne l'est pas.
***************************************************************/
CGraphe& CUtilitaireGraphe::UTIInverserGraphe(CGraphe &GPHParam)
{
	// On renvoie le graphe d'origine si celui-ci est non orienté
	if (!GPHParam.GPHEstOriente())
	{
		return GPHParam;
	}

	// Construction d'un CGraphe vide afin d'y ajouter les sommets au fur et à mesure
	CGraphe* GPHGrapheInverse = new CGraphe();

	for (unsigned int i = 0; i < GPHParam.GPHLireNbrSommet(); i++)
	{
		// Récupération des attributs liés aux sommets d'origine pour construire le nouveau sommet
		unsigned int uiNumNvSommet = GPHParam.GPHLireNumSommet(i);
		const unsigned int* puiListeArrivantNvSommet = GPHParam.GPHLireArrivantSommet(uiNumNvSommet);
		const unsigned int* puiListePartantNvSommet = GPHParam.GPHLirePartantSommet(uiNumNvSommet);
		const unsigned int uiNbrArrivantNvSommet = GPHParam.GPHLireNbrArrivantSommet(uiNumNvSommet);
		const unsigned int uiNbrPartantNvSommet = GPHParam.GPHLireNbrPartantSommet(uiNumNvSommet);

		CArc **ppARCListeArrivantNvSommet = new CArc*[uiNbrArrivantNvSommet];
		CArc **ppARCListePartantNvSommet = new CArc*[uiNbrPartantNvSommet];

		// Contruction des listes d'arcs arrivants et partants nécessaires pour utiliser le constructeur de confort de CSommet
		for (unsigned int m = 0; m < uiNbrArrivantNvSommet; m++)
		{
			CArc* ARCArrivant = new CArc(puiListeArrivantNvSommet[m]);
			ppARCListeArrivantNvSommet[m] = ARCArrivant;
		}

		for (unsigned int m = 0; m < uiNbrPartantNvSommet; m++)
		{
			CArc* ARCArrivant = new CArc(puiListePartantNvSommet[m]);
			ppARCListePartantNvSommet[m] = ARCArrivant;
		}

		// Construction du sommet à ajouter dans le graphe en inversant ses listes d'arcs et ajout dans le graphe
		CSommet* SOMNvSommet = new CSommet(uiNumNvSommet, uiNbrPartantNvSommet, uiNbrArrivantNvSommet, ppARCListePartantNvSommet, ppARCListeArrivantNvSommet);
		GPHGrapheInverse->GPHAjouterSommet(*SOMNvSommet);
	}

	return *GPHGrapheInverse;
}