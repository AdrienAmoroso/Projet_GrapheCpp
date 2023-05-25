/*****************************************************************//**
 * \file   CArc.ipp
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

// Méthodes

/**************************************************************
Nom : ARCLireDestination
***************************************************************
Cette fonction permet de consulter la destination d'un arc.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : Numéro du sommet de destination
Entraîne : La destination de l'arc est retournée.
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
Entrée : Nouveau numéro de sommet de destination
Nécessite : néant
Sortie : néant
Entraîne : La destination de l'arc est modifiée.
***************************************************************/
inline void CArc::ARCModifierDestination(unsigned int uiDestParam)
{
	uiARCDestination = uiDestParam;
}