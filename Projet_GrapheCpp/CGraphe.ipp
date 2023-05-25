/*****************************************************************//**
 * \file   CGraphe.ipp
 * \brief  Corps de la classe CGraphe.
 *		   Cette classe permet de cr�er de g�rer des graphes.
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
Nom : GPHLireNumSommet
***************************************************************
Cette fonction permet de consulter le num�ro du sommet � une certaine
position dans la liste de sommets du graphe.
***************************************************************
Entr�e : Position dans la liste
N�cessite : n�ant
Sortie : Num�ro du sommet
Entra�ne : Le num�ro du sommet situ� � cette position est retourn�.
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
du sommet � partir de son num�ro.
***************************************************************
Entr�e : Num�ro du sommet
N�cessite : n�ant
Sortie : Liste des num�ros des arcs arrivants du sommet
Entra�ne : La liste des arcs arrivants du sommet est retourn�e.
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
du sommet � partir de son num�ro.
***************************************************************
Entr�e : Num�ro du sommet
N�cessite : n�ant
Sortie : Liste des num�ros des arcs partants du sommet
Entra�ne : La liste des arcs partants du sommet est retourn�e.
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
du sommet � partir de son num�ro.
***************************************************************
Entr�e : Num�ro du sommet
N�cessite : n�ant
Sortie : Nombre d'arcs arrivants du sommet
Entra�ne : Le nombre d'arcs arrivants du sommet est retourn�.
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
du sommet � partir de son num�ro.
***************************************************************
Entr�e : Num�ro du sommet
N�cessite : n�ant
Sortie : Nombre d'arcs partants du sommet
Entra�ne : Le nombre d'arcs partants du sommet est retourn�.
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
Entr�e : n�ant
N�cessite : n�ant
Sortie : Nombre de sommets du graphe
Entra�ne : On retourne le nombre de sommets du graphe.
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
Entr�e : n�ant
N�cessite : n�ant
Sortie : Nombre d'arcs du graphe
Entra�ne : On retourne le nombre d'arcs du graphe.
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
		uiCompteur /= 2; // Diviser par 2 pour ne compter chaque arc non orient� qu'une seule fois
	}

	return uiCompteur;
}
