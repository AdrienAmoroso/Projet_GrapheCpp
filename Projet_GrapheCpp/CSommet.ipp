/*****************************************************************//**
 * \file   CSommet.ipp
 * \brief  Corps de la classe CSommet.
 *		   Cette classe permet de cr�er et de g�rer des sommets d'un graphe.
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
Nom : SOMLireNumSommet
***************************************************************
Cette fonction permet de consulter le num�ro du sommet.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : Num�ro du sommet
Entra�ne : Le num�ro du sommet est retourn�.
***************************************************************/
inline const unsigned int CSommet::SOMLireNumSommet()
{
	return uiSOMNumSommet;
}

/**************************************************************
Nom : SOMModifierNumSommet
***************************************************************
Cette fonction permet de modifier le num�ro d'un sommet.
***************************************************************
Entr�e : Nouveau num�ro de sommet
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Le num�ro du sommet appelant est remplac� par celui
		   pass� en param�tre.
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
Entr�e : n�ant
N�cessite : n�ant
Sortie : Nombre d'arcs arrivants
Entra�ne : Le nombre d'arcs arrivants est retourn�.
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
Entr�e : n�ant
N�cessite : n�ant
Sortie : Nombre d'arcs partants
Entra�ne : Le nombre d'arcs partants est retourn�.
***************************************************************/
inline const unsigned int CSommet::SOMLireNbrPartant()
{
	return uiSOMNbrPartant;
}

/**************************************************************
Nom : SOMLirePartant
***************************************************************
Cette fonction permet de consulter le num�ro d'un arc partant
du sommet � une certaine position de la liste.
***************************************************************
Entr�e : Position dans la liste
N�cessite : n�ant
Sortie : Num�ro de l'arc partant � cette position
Entra�ne : On retourne le num�ro de l'arc partant � la
		   position pass�e en param�tre dans la liste.
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
Cette fonction permet de consulter le num�ro d'un arc arrivant
du sommet � une certaine position de la liste.
***************************************************************
Entr�e : Position dans la liste
N�cessite : n�ant
Sortie : Num�ro de l'arc arrivant � cette position
Entra�ne : On retourne le num�ro de l'arc arrivant � la
		   position pass�e en param�tre dans la liste.
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
Entr�e : n�ant
N�cessite : n�ant
Sortie : Liste des arcs arrivants
Entra�ne : La liste des arcs arrivants est retourn�e.
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
Entr�e : n�ant
N�cessite : n�ant
Sortie : Liste des arcs partants
Entra�ne : La liste des arcs partants est retourn�e.
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
avec celle en param�tre.
***************************************************************
Entr�e : Nouvelle liste d'arcs arrivants, taille de cette liste
N�cessite : n�ant
Sortie : n�ant
Entra�ne : La liste des arcs arrivants est remplac�e par celle
		   en param�tre.
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
avec celle en param�tre.
***************************************************************
Entr�e : Nouvelle liste d'arcs partants, taille de cette liste
N�cessite : n�ant
Sortie : n�ant
Entra�ne : La liste des arcs partants est remplac�e par celle
		   en param�tre.
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