/*****************************************************************//**
 * \file   CArc.ipp
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

// M�thodes

/**************************************************************
Nom : ARCLireDestination
***************************************************************
Cette fonction permet de consulter la destination d'un arc.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : Num�ro du sommet de destination
Entra�ne : La destination de l'arc est retourn�e.
***************************************************************/
inline const unsigned int CArc::ARCLireDestination()
{
	return uiARCDestination;
}

/**************************************************************
Nom : ARCModifierDestination
***************************************************************
Cette fonction permet de modifier la destination d'un arc.
***************************************************************
Entr�e : Nouveau num�ro de sommet de destination
N�cessite : n�ant
Sortie : n�ant
Entra�ne : La destination de l'arc est modifi�e.
***************************************************************/
inline void CArc::ARCModifierDestination(unsigned int uiDestParam)
{
	uiARCDestination = uiDestParam;
}