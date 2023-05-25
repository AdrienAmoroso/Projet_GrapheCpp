/*****************************************************************//**
 * \file   CArc.cpp
 * \brief  Corps de la classe CArc.
 *		   Cette classe permet de créer et de gérer des arcs d'un graphe.
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

#include "CArc.h"

// Constructeurs

/**************************************************************
Nom : CArc
***************************************************************
Constructeur par défaut de la classe CArc qui permet
d’initialiser un objet.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : L'arc est initialisé.
***************************************************************/
CArc::CArc()
{
	uiARCDestination = 0;
}

/**************************************************************
Nom : CArc
***************************************************************
Constructeur de recopie de la classe CArc qui permet
d’initialiser un objet à partir d'un autre objet de la classe CArc.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : L'arc est initialisé.
***************************************************************/
CArc::CArc(const CArc &ARCParam)
{
	uiARCDestination = ARCParam.uiARCDestination;
}

/**************************************************************
Nom : CArc
***************************************************************
Constructeur de confort de la classe CArc qui permet
d’initialiser un objet à partir d'une destination donnée.
***************************************************************
Entrée : Numéro du sommet de destination
Nécessite : néant
Sortie : néant
Entraîne : L'arc est initialisé à partir d'une destination donnée.
***************************************************************/
CArc::CArc(unsigned int uiDestParam)
{
	uiARCDestination = uiDestParam;
}