/*****************************************************************//**
 * \file   CArc.cpp
 * \brief  Corps de la classe CArc.
 *		   Cette classe permet de cr�er et de g�rer des arcs d'un graphe.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Mai 2023
 *********************************************************************/

 /*CLASSE CException
	 DOCUMENTATION
		 Attributs : uiEXCValeur : entier naturel, contient la valeur de l�exception.
		 Structure : Cette classe contient une m�thode de modification de la valeur
					 de l'exception, une m�thode de consultation de celle-ci et
					 une m�thode d'affichage des messages d'erreurs.
		 M�thode : n�ant
		 Modules internes:*/

// CORPS

#include "CArc.h"

// Constructeurs

/**************************************************************
Nom : CArc
***************************************************************
Constructeur par d�faut de la classe CArc qui permet
d�initialiser un objet.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : L'arc est initialis�.
***************************************************************/
CArc::CArc()
{
	uiARCDestination = 0;
}

/**************************************************************
Nom : CArc
***************************************************************
Constructeur de recopie de la classe CArc qui permet
d�initialiser un objet � partir d'un autre objet de la classe CArc.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : L'arc est initialis�.
***************************************************************/
CArc::CArc(const CArc &ARCParam)
{
	uiARCDestination = ARCParam.uiARCDestination;
}

/**************************************************************
Nom : CArc
***************************************************************
Constructeur de confort de la classe CArc qui permet
d�initialiser un objet � partir d'une destination donn�e.
***************************************************************
Entr�e : Num�ro du sommet de destination
N�cessite : n�ant
Sortie : n�ant
Entra�ne : L'arc est initialis� � partir d'une destination donn�e.
***************************************************************/
CArc::CArc(unsigned int uiDestParam)
{
	uiARCDestination = uiDestParam;
}