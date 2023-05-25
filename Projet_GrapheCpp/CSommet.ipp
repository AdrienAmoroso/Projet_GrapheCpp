/*****************************************************************//**
 * \file   CSommet.ipp
 * \brief  Corps de la classe CSommet.
 *		   Cette classe permet de créer et de gérer des sommets d'un graphe.
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
Nom : SOMLireNumSommet
***************************************************************
Cette fonction permet de consulter le numéro du sommet.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : Numéro du sommet
Entraîne : Le numéro du sommet est retourné.
***************************************************************/
inline const unsigned int CSommet::SOMLireNumSommet()
{
	return uiSOMNumSommet;
}

/**************************************************************
Nom : SOMModifierNumSommet
***************************************************************
Cette fonction permet de modifier le numéro d'un sommet.
***************************************************************
Entrée : Nouveau numéro de sommet
Nécessite : néant
Sortie : néant
Entraîne : Le numéro du sommet appelant est remplacé par celui
		   passé en paramètre.
***************************************************************/
inline void CSommet::SOMModifierNumSommet(unsigned int uiNvNumSommet)
{
	uiSOMNumSommet = uiNvNumSommet;
}

/**************************************************************
Nom : SOMLireNbrArrivant
***************************************************************
Cette fonction permet de consulter le nombre d'arcs dans la
liste des arrivants.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : Nombre d'arcs arrivants
Entraîne : Le nombre d'arcs arrivants est retourné.
***************************************************************/
inline const unsigned int CSommet::SOMLireNbrArrivant()
{
	return uiSOMNbrArrivant;
}

/**************************************************************
Nom : SOMLireNbrPartant
***************************************************************
Cette fonction permet de consulter le nombre d'arcs dans la
liste des partants.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : Nombre d'arcs partants
Entraîne : Le nombre d'arcs partants est retourné.
***************************************************************/
inline const unsigned int CSommet::SOMLireNbrPartant()
{
	return uiSOMNbrPartant;
}

/**************************************************************
Nom : SOMLirePartant
***************************************************************
Cette fonction permet de consulter le numéro d'un arc partant
du sommet à une certaine position de la liste.
***************************************************************
Entrée : Position dans la liste
Nécessite : néant
Sortie : Numéro de l'arc partant à cette position
Entraîne : On retourne le numéro de l'arc partant à la
		   position passée en paramètre dans la liste.
***************************************************************/
inline const unsigned int CSommet::SOMLirePartant(unsigned int uiPosition)
{
	if (uiPosition < 0 || uiPosition > uiSOMNbrPartant)
	{
		CException EXCIndexDepasse;
		EXCIndexDepasse.EXCModifierValeur(INDEX_INVALIDE);
		throw(EXCIndexDepasse);
	}

	if (ppArcSOMPartant == nullptr)
	{
		CException EXCListeSommetVide;
		EXCListeSommetVide.EXCModifierValeur(LISTE_SOMMET_VIDE);
		throw(EXCListeSommetVide);
	}

	return ppArcSOMPartant[uiPosition]->ARCLireDestination();
}

/**************************************************************
Nom : SOMLireArrivant
***************************************************************
Cette fonction permet de consulter le numéro d'un arc arrivant
du sommet à une certaine position de la liste.
***************************************************************
Entrée : Position dans la liste
Nécessite : néant
Sortie : Numéro de l'arc arrivant à cette position
Entraîne : On retourne le numéro de l'arc arrivant à la
		   position passée en paramètre dans la liste.
***************************************************************/
inline const unsigned int CSommet::SOMLireArrivant(unsigned int uiPosition)
{
	if (uiPosition < 0 || uiPosition > uiSOMNbrArrivant)
	{
		CException EXCIndexDepasse;
		EXCIndexDepasse.EXCModifierValeur(INDEX_INVALIDE);
		throw(EXCIndexDepasse);
	}

	if (ppArcSOMArrivant == nullptr)
	{
		CException EXCListeSommetVide;
		EXCListeSommetVide.EXCModifierValeur(LISTE_SOMMET_VIDE);
		throw(EXCListeSommetVide);
	}

	return ppArcSOMArrivant[uiPosition]->ARCLireDestination();
}

/**************************************************************
Nom : SOMLireListeArrivant
***************************************************************
Cette fonction permet de consulter la liste des arcs arrivants.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : Liste des arcs arrivants
Entraîne : La liste des arcs arrivants est retournée.
***************************************************************/
inline const unsigned int* CSommet::SOMLireListeArrivant()
{
	unsigned int* puiListe = new unsigned int[uiSOMNbrArrivant];

	if (uiSOMNbrArrivant == 0) puiListe = nullptr;

	for (unsigned int i = 0; i < uiSOMNbrArrivant; i++)
	{
		if (ppArcSOMArrivant[i] != nullptr)
		{
			puiListe[i] = ppArcSOMArrivant[i]->ARCLireDestination();
		}
	}

	return puiListe;
}

/**************************************************************
Nom : SOMLireListePartant
***************************************************************
Cette fonction permet de consulter la liste des arcs partants.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : Liste des arcs partants
Entraîne : La liste des arcs partants est retournée.
***************************************************************/
inline const unsigned int* CSommet::SOMLireListePartant()
{
	unsigned int* puiListe = new unsigned int[uiSOMNbrPartant];

	if (uiSOMNbrPartant == 0) puiListe = nullptr;

	for (unsigned int i = 0; i < uiSOMNbrPartant; i++)
	{
		if (ppArcSOMPartant[i] != nullptr)
		{
			puiListe[i] = ppArcSOMPartant[i]->ARCLireDestination();
		}
	}

	return puiListe;
}

/**************************************************************
Nom : SOMModifierListeArrivant
***************************************************************
Cette fonction permet de modifier la liste des arcs arrivants
avec celle en paramètre.
***************************************************************
Entrée : Nouvelle liste d'arcs arrivants, taille de cette liste
Nécessite : néant
Sortie : néant
Entraîne : La liste des arcs arrivants est remplacée par celle
		   en paramètre.
***************************************************************/
inline void CSommet::SOMModifierListeArrivant(CArc** ppArcArrivantParam, unsigned int uiTaille)
{
	// Supprime la liste actuelle
	for (unsigned int i = 0; i < uiSOMNbrArrivant; i++)
	{
		delete ppArcSOMArrivant[i];
	}

	delete[] ppArcSOMArrivant;

	// Affecte la nouvelle liste 
	uiSOMNbrArrivant = uiTaille;
	ppArcSOMArrivant = ppArcArrivantParam;
}

/**************************************************************
Nom : SOMModifierListePartant
***************************************************************
Cette fonction permet de modifier la liste des arcs partants
avec celle en paramètre.
***************************************************************
Entrée : Nouvelle liste d'arcs partants, taille de cette liste
Nécessite : néant
Sortie : néant
Entraîne : La liste des arcs partants est remplacée par celle
		   en paramètre.
***************************************************************/
inline void CSommet::SOMModifierListePartant(CArc** ppArcPartantParam, unsigned int uiTaille)
{
	// Supprime la liste actuelle
	for (unsigned int i = 0; i < uiSOMNbrPartant; i++)
	{
		delete ppArcSOMPartant[i];
	}

	delete[] ppArcSOMPartant;

	// Affecte la nouvelle liste 
	uiSOMNbrPartant = uiTaille;
	ppArcSOMPartant = ppArcPartantParam;
}