/*****************************************************************//**
 * \file   CGraphe.ipp
 * \brief  Corps de la classe CGraphe.
 *		   Cette classe permet de créer de gérer des graphes.
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
Nom : GPHLireNumSommet
***************************************************************
Cette fonction permet de consulter le numéro du sommet à une certaine
position dans la liste de sommets du graphe.
***************************************************************
Entrée : Position dans la liste
Nécessite : néant
Sortie : Numéro du sommet
Entraîne : Le numéro du sommet situé à cette position est retourné.
***************************************************************/
inline const unsigned int CGraphe::GPHLireNumSommet(unsigned int uiPosition)
{
	if (uiPosition < 0 || uiPosition > uiGPHNbrSommet)
	{
		CException EXCIndexDepasse;
		EXCIndexDepasse.EXCModifierValeur(INDEX_INVALIDE);
		throw(EXCIndexDepasse);
	}

	if (ppSomGPHListeSommet == nullptr)
	{
		CException EXCListeSommetVide;
		EXCListeSommetVide.EXCModifierValeur(LISTE_SOMMET_VIDE);
		throw(EXCListeSommetVide);
	}

	return ppSomGPHListeSommet[uiPosition]->SOMLireNumSommet();
}

/**************************************************************
Nom : GPHLireArrivantSommet
***************************************************************
Cette fonction permet de consulter la liste des arcs arrivants
du sommet à partir de son numéro.
***************************************************************
Entrée : Numéro du sommet
Nécessite : néant
Sortie : Liste des numéros des arcs arrivants du sommet
Entraîne : La liste des arcs arrivants du sommet est retournée.
***************************************************************/
inline const unsigned int* CGraphe::GPHLireArrivantSommet(unsigned int uiNumSommetParam)
{
	if (!GPHEstDansGraphe(uiNumSommetParam))
	{
		CException EXCSommet_Invalide;
		EXCSommet_Invalide.EXCModifierValeur(SOMMET_INVALIDE);
		throw(EXCSommet_Invalide);
	}

	CSommet* SOMSommetTrouve = new CSommet();
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (ppSomGPHListeSommet[i]->SOMLireNumSommet() == uiNumSommetParam)
		{
			SOMSommetTrouve = ppSomGPHListeSommet[i];
			break;
		}
	}

	const unsigned int* puiListeArrivant = new unsigned int[SOMSommetTrouve->SOMLireNbrArrivant()];
	puiListeArrivant = SOMSommetTrouve->SOMLireListeArrivant();

	return puiListeArrivant;
}

/**************************************************************
Nom : GPHLirePartantSommet
***************************************************************
Cette fonction permet de consulter la liste des arcs partants
du sommet à partir de son numéro.
***************************************************************
Entrée : Numéro du sommet
Nécessite : néant
Sortie : Liste des numéros des arcs partants du sommet
Entraîne : La liste des arcs partants du sommet est retournée.
***************************************************************/
inline const unsigned int* CGraphe::GPHLirePartantSommet(unsigned int uiNumSommetParam)
{
	if (!GPHEstDansGraphe(uiNumSommetParam))
	{
		CException EXCSommet_Invalide;
		EXCSommet_Invalide.EXCModifierValeur(SOMMET_INVALIDE);
		throw(EXCSommet_Invalide);
	}

	CSommet* SOMSommetTrouve = new CSommet();
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (ppSomGPHListeSommet[i]->SOMLireNumSommet() == uiNumSommetParam)
		{
			SOMSommetTrouve = ppSomGPHListeSommet[i];
			break;
		}
	}

	const unsigned int* puiListePartant = new unsigned int[SOMSommetTrouve->SOMLireNbrPartant()];
	puiListePartant = SOMSommetTrouve->SOMLireListePartant();

	return puiListePartant;
}

/**************************************************************
Nom : GPHLireNbrArrivantSommet
***************************************************************
Cette fonction permet de consulter le nombre d'arcs arrivants
du sommet à partir de son numéro.
***************************************************************
Entrée : Numéro du sommet
Nécessite : néant
Sortie : Nombre d'arcs arrivants du sommet
Entraîne : Le nombre d'arcs arrivants du sommet est retourné.
***************************************************************/
inline const unsigned int CGraphe::GPHLireNbrArrivantSommet(unsigned int uiNumSommetParam)
{
	if (!GPHEstDansGraphe(uiNumSommetParam))
	{
		CException EXCSommet_Invalide;
		EXCSommet_Invalide.EXCModifierValeur(SOMMET_INVALIDE);
		throw(EXCSommet_Invalide);
	}

	CSommet* SOMSommetTrouve = new CSommet();
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (ppSomGPHListeSommet[i]->SOMLireNumSommet() == uiNumSommetParam)
		{
			SOMSommetTrouve = ppSomGPHListeSommet[i];
			break;
		}
	}

	unsigned int uiNbrArrivantSommet = SOMSommetTrouve->SOMLireNbrArrivant();

	return uiNbrArrivantSommet;
}

/**************************************************************
Nom : GPHLireNbrPartantSommet
***************************************************************
Cette fonction permet de consulter le nombre d'arcs partants
du sommet à partir de son numéro.
***************************************************************
Entrée : Numéro du sommet
Nécessite : néant
Sortie : Nombre d'arcs partants du sommet
Entraîne : Le nombre d'arcs partants du sommet est retourné.
***************************************************************/
inline const unsigned int CGraphe::GPHLireNbrPartantSommet(unsigned int uiNumSommetParam)
{
	if (!GPHEstDansGraphe(uiNumSommetParam))
	{
		CException EXCSommet_Invalide;
		EXCSommet_Invalide.EXCModifierValeur(SOMMET_INVALIDE);
		throw(EXCSommet_Invalide);
	}

	CSommet* SOMSommetTrouve = new CSommet();
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (ppSomGPHListeSommet[i]->SOMLireNumSommet() == uiNumSommetParam)
		{
			SOMSommetTrouve = ppSomGPHListeSommet[i];
			break;
		}
	}

	unsigned int uiNbrPartantSommet = SOMSommetTrouve->SOMLireNbrPartant();

	return uiNbrPartantSommet;
}

/**************************************************************
Nom : GPHLireNbrSommet
***************************************************************
Cette fonction permet de consulter le nombre de sommets du graphe.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : Nombre de sommets du graphe
Entraîne : On retourne le nombre de sommets du graphe.
***************************************************************/
inline const unsigned int CGraphe::GPHLireNbrSommet()
{
	return uiGPHNbrSommet;
}

/**************************************************************
Nom : GPHLireNbArc
***************************************************************
Cette fonction permet de consulter le nombre d'arcs du graphe.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : Nombre d'arcs du graphe
Entraîne : On retourne le nombre d'arcs du graphe.
***************************************************************/
inline const unsigned int CGraphe::GPHLireNbrArc()
{
	unsigned int uiCompteur = 0;

	for (unsigned int i = 0; i < uiGPHNbrSommet; i++)
	{
		uiCompteur += ppSomGPHListeSommet[i]->SOMLireNbrPartant();
	}

	if (!bGPHOriente)
	{
		uiCompteur /= 2; // Diviser par 2 pour ne compter chaque arc non orienté qu'une seule fois
	}

	return uiCompteur;
}
