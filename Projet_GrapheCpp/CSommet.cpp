/*****************************************************************//**
 * \file   CSommet.cpp
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

#include "CSommet.h"

// Constructeurs - Destructeur

/**************************************************************
Nom : CSommet
***************************************************************
Constructeur par défaut de la classe CSommet qui permet
d’initialiser un objet.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : Le sommet est initialisé.
***************************************************************/
CSommet::CSommet()
{
	uiSOMNumSommet = 0;
	uiSOMNbrArrivant = 0;
	uiSOMNbrPartant = 0;
	ppArcSOMArrivant = nullptr;
	ppArcSOMPartant = nullptr;
}

/**************************************************************
Nom : CSommet
***************************************************************
Constructeur de confort de la classe CSommet qui créé un sommet
à partir d'un numéro donné.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : Le sommet est initialisé à partir d'un numéro donné.
***************************************************************/
CSommet::CSommet(unsigned int uiNumParam)
{
	uiSOMNumSommet = uiNumParam;
	uiSOMNbrArrivant = 0;
	uiSOMNbrPartant = 0;
	ppArcSOMArrivant = nullptr;
	ppArcSOMPartant = nullptr;
}

/**************************************************************
Nom : CSommet
***************************************************************
Constructeur de recopie de la classe CSommet qui permet
d’initialiser un objet à partir d'un autre objet de la classe CSommet.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : Le sommet est initialisé à partir d'un objet CSommet donné.
***************************************************************/
CSommet::CSommet(const CSommet& SOMParam)
{
	// Copie de l'attribut uiNumSommet
	uiSOMNumSommet = SOMParam.uiSOMNumSommet;
	uiSOMNbrArrivant = SOMParam.uiSOMNbrArrivant;
	uiSOMNbrPartant = SOMParam.uiSOMNbrPartant;

	// Copie de l'attribut ppArcSOMArrivant
	ppArcSOMArrivant = new CArc *[uiSOMNbrArrivant];

	if (uiSOMNbrArrivant > 0)
	{
		for (unsigned int i = 0; i < uiSOMNbrArrivant; ++i)
		{
			if (SOMParam.ppArcSOMArrivant[i] != nullptr)
			{
				ppArcSOMArrivant[i] = new CArc(*SOMParam.ppArcSOMArrivant[i]);
			}
			else
			{
				ppArcSOMArrivant[i] = nullptr;
			}
		}
	}

	else
	{
		ppArcSOMArrivant = nullptr;
	}

	// Copie de l'attribut ppArcSOMPartant
	ppArcSOMPartant = new CArc *[uiSOMNbrPartant];

	if (uiSOMNbrPartant > 0)
	{
		for (unsigned int i = 0; i < uiSOMNbrPartant; ++i)
		{
			if (SOMParam.ppArcSOMPartant[i] != nullptr)
			{
				ppArcSOMPartant[i] = new CArc(*SOMParam.ppArcSOMPartant[i]);
			}
			else
			{
				ppArcSOMPartant[i] = nullptr;
			}
		}
	}

	else
	{
		ppArcSOMPartant = nullptr;
	}
}

/**************************************************************
Nom : CSommet
***************************************************************
Constructeur de confort de la classe CSommet qui créé un sommet
en initialisant ses attributs un à un.
***************************************************************
Entrée : Numéro du sommet, Nombre d'arcs arrivants, Nombre d'arcs
		 partants, Liste des arcs arrivants, Liste des arcs partants
Nécessite : néant
Sortie : néant
Entraîne : Le sommet est initialisé en affectant à chaque attribut
		   la valeur correspondante passée en paramètre.
***************************************************************/
CSommet::CSommet(unsigned int uiNumSommetParam, unsigned int uiNbrArrivantParam, unsigned int uiNbrPartantParam, CArc** ppArcArrivantParam, CArc** ppArcPartantParam)
{
	uiSOMNumSommet = uiNumSommetParam;
	uiSOMNbrArrivant = uiNbrArrivantParam;
	uiSOMNbrPartant = uiNbrPartantParam;

	// Initialisation de l'attribut ppArcSOMArrivant
	ppArcSOMArrivant = new CArc *[uiSOMNbrArrivant];

	for (unsigned int i = 0; i < uiSOMNbrArrivant; ++i)
	{
		if (ppArcArrivantParam[i] != nullptr)
		{
			ppArcSOMArrivant[i] = new CArc(*ppArcArrivantParam[i]);
		}

		else
		{
			ppArcSOMArrivant[i] = nullptr;
		}
	}

	// Initialisation de l'attribut ppArcSOMArrivant
	ppArcSOMPartant = new CArc *[uiSOMNbrPartant];

	for (unsigned int i = 0; i < uiSOMNbrPartant; ++i)
	{
		if (ppArcPartantParam[i] != nullptr) {
			ppArcSOMPartant[i] = new CArc(*ppArcPartantParam[i]);
		}

		else
		{
			ppArcSOMPartant[i] = nullptr;
		}
	}
}

/**************************************************************
Nom : ~CSommet
***************************************************************
Destructeur de la classe CSommet qui permet de détruire un objet.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : Le sommet est détruit.
***************************************************************/
CSommet::~CSommet()
{
	// Libération de la mémoire allouée pour ppArcSOMArrivant
	if (ppArcSOMArrivant != nullptr)
	{
		for (unsigned int i = 0; i < uiSOMNbrArrivant; ++i)
		{
			if (ppArcSOMArrivant[i] != nullptr)
			{
				delete ppArcSOMArrivant[i];
			}
		}

		delete[] ppArcSOMArrivant;
	}

	// Libération de la mémoire allouée pour ppArcSOMPartant
	if (ppArcSOMPartant != nullptr)
	{
		for (unsigned int i = 0; i < uiSOMNbrPartant; ++i)
		{
			if (ppArcSOMPartant[i] != nullptr)
			{
				delete ppArcSOMPartant[i];
			}
		}

		delete[] ppArcSOMPartant;
	}
}

// Méthodes

/**************************************************************
Nom : SOMEstSuccesseurDe
***************************************************************
Cette fonction permet de savoir si le sommet appelant est successeur
du sommet de numéro passé en paramètre (EX : Sommet2.EstSuccesseurDe(1)
<=> "Sommet2 est successeur du sommet de numéro 1").
***************************************************************
Entrée : Numéro du sommet dont on cherche s'il précède le sommet appelant
Nécessite : néant
Sortie : Booléen
Entraîne : On retourne vrai si le sommet appelant est successeur du
		   sommet en paramètre, faux sinon.
***************************************************************/
bool CSommet::SOMEstSuccesseurDe(unsigned int uiNumSommet)
{
	bool bTrouve = false;

	for (unsigned int i = 0; i < uiSOMNbrArrivant; ++i)
	{
		if (ppArcSOMArrivant[i] != nullptr)
		{
			if (ppArcSOMArrivant[i]->ARCLireDestination() == uiNumSommet) bTrouve = true;
		}
	}

	return bTrouve;
}

/**************************************************************
Nom : SOMEstPredecesseurDe
***************************************************************
Cette fonction permet de savoir si le sommet appelant est prédecesseur
du sommet de numéro passé en paramètre (EX : Sommet1.EstSuccesseurDe(2)
<=> "Sommet1 est prédecesseur du sommet de numéro 2").
***************************************************************
Entrée : Numéro du sommet dont on cherche s'il succède au sommet appelant
Nécessite : néant
Sortie : Booléen
Entraîne : On retourne vrai si le sommet appelant est prédecesseur du
		   sommet en paramètre, faux sinon.
***************************************************************/
bool CSommet::SOMEstPredecesseurDe(unsigned int uiNumSommet)
{
	bool bTrouve = false;

	for (unsigned int i = 0; i < uiSOMNbrPartant; ++i)
	{
		if (ppArcSOMPartant[i] != nullptr)
		{
			if (ppArcSOMPartant[i]->ARCLireDestination() == uiNumSommet) bTrouve = true;
		}
	}

	return bTrouve;
}

/**************************************************************
Nom : SOMAjouterArrivant
***************************************************************
Cette fonction permet d'ajouter un numéro de sommet dans la liste
des arrivants.
***************************************************************
Entrée : Numéro de sommet
Nécessite : néant
Sortie : néant
Entraîne : Le numéro du sommet passé en paramètre est ajouté dans
		   la liste des arrivants.
***************************************************************/
void CSommet::SOMAjouterArrivant(unsigned int uiNumParam)
{
	if (ppArcSOMArrivant == nullptr)
	{
		CArc* pNouvelArc = new CArc(uiNumParam);  // Création de l'objet CArc
		uiSOMNbrArrivant += 1;                       // Incrémentation du nombre d'arrivants

		ppArcSOMArrivant = new CArc *[uiSOMNbrArrivant]; // Création de la liste des arrivants
		ppArcSOMArrivant[0] = pNouvelArc;              // Ajout à la liste 
	}

	else
	{
		if (this->SOMEstSuccesseurDe(uiNumParam))
		{
			CException EXCEst_Successeur;
			EXCEst_Successeur.EXCModifierValeur(EST_SUCCESSEUR);
			throw(EXCEst_Successeur);
		}

		CArc* pNouvelArc = new CArc(uiNumParam);
		uiSOMNbrArrivant += 1;
		CArc** ppNouvelleListe = new CArc *[uiSOMNbrArrivant];

		for (unsigned int i = 0; i < uiSOMNbrArrivant - 1; ++i)
		{
			ppNouvelleListe[i] = ppArcSOMArrivant[i];
		}

		ppNouvelleListe[uiSOMNbrArrivant - 1] = pNouvelArc;
		delete[] ppArcSOMArrivant;
		ppArcSOMArrivant = ppNouvelleListe;
	}
}

/**************************************************************
Nom : SOMAjouterPartant
***************************************************************
Cette fonction permet d'ajouter un numéro de sommet dans la liste
des partants.
***************************************************************
Entrée : Numéro de sommet
Nécessite : néant
Sortie : néant
Entraîne : Le numéro du sommet passé en paramètre est ajouté dans
		   la liste des partants.
***************************************************************/
void CSommet::SOMAjouterPartant(unsigned int uiNumParam)
{
	if (ppArcSOMPartant == nullptr)
	{
		CArc* pNouvelArc = new CArc(uiNumParam);  // Création de l'objet Arc
		uiSOMNbrPartant += 1;                       // Incrémentation du nombre d'arrivants

		ppArcSOMPartant = new CArc *[uiSOMNbrPartant]; // Création de la liste des arrivants
		ppArcSOMPartant[0] = pNouvelArc;              // Ajout à la liste 
	}

	else
	{
		if (this->SOMEstPredecesseurDe(uiNumParam))
		{
			CException EXCEst_Predecesseur;
			EXCEst_Predecesseur.EXCModifierValeur(EST_PREDECESSEUR);
			throw(EXCEst_Predecesseur);
		}

		CArc* pNouvelArc = new CArc(uiNumParam);
		uiSOMNbrPartant += 1;
		CArc** ppNouvelleListe = new CArc *[uiSOMNbrPartant];

		for (unsigned int i = 0; i < uiSOMNbrPartant - 1; ++i)
		{
			ppNouvelleListe[i] = ppArcSOMPartant[i];
		}

		ppNouvelleListe[uiSOMNbrPartant - 1] = pNouvelArc;
		delete[] ppArcSOMPartant;
		ppArcSOMPartant = ppNouvelleListe;
	}
}

/**************************************************************
Nom : SOMSupprimerPartant
***************************************************************
Cette fonction permet de supprimer un numéro de sommet dans la
liste des partants.
***************************************************************
Entrée : Numéro de sommet
Nécessite : néant
Sortie : néant
Entraîne : Le numéro du sommet passé en paramètre est supprimé de
		   la liste des partants.
***************************************************************/
void CSommet::SOMSupprimerPartant(unsigned int uiNumParam)
{
	if (ppArcSOMPartant == nullptr)
	{
		CException EXCListePartantVide;
		EXCListePartantVide.EXCModifierValeur(LISTE_PARTANT_VIDE);
		throw(EXCListePartantVide);
	}

	bool bTrouve = false;
	unsigned int uiIndexSupprimer = 0;

	for (unsigned int i = 0; i < uiSOMNbrPartant; ++i)
	{
		if (ppArcSOMPartant[i] != nullptr && ppArcSOMPartant[i]->ARCLireDestination() == uiNumParam)
		{
			bTrouve = true;
			uiIndexSupprimer = i;
			break;
		}
	}

	if (!bTrouve)
	{
		CException EXCArc_Inexistant;
		EXCArc_Inexistant.EXCModifierValeur(ARC_INEXISTANT);
		throw(EXCArc_Inexistant);
	}

	delete ppArcSOMPartant[uiIndexSupprimer];
	ppArcSOMPartant[uiIndexSupprimer] = nullptr;

	// Réarranger la liste des arcs partants
	for (unsigned int i = uiIndexSupprimer; i < uiSOMNbrPartant - 1; ++i)
	{
		ppArcSOMPartant[i] = ppArcSOMPartant[i + 1];
	}

	ppArcSOMPartant[uiSOMNbrPartant - 1] = nullptr;
	uiSOMNbrPartant -= 1;
}

/**************************************************************
Nom : SOMSupprimerArrivant
***************************************************************
Cette fonction permet de supprimer un numéro de sommet dans la 
liste des arrivants.
***************************************************************
Entrée : Numéro de sommet
Nécessite : néant
Sortie : néant
Entraîne : Le numéro du sommet passé en paramètre est supprimé de
		   la liste des arrivants.
***************************************************************/
void CSommet::SOMSupprimerArrivant(unsigned int uiNumParam)
{
	if (ppArcSOMArrivant == nullptr)
	{
		CException EXCListeArrivantVide;
		EXCListeArrivantVide.EXCModifierValeur(LISTE_ARRIVANT_VIDE);
		throw(EXCListeArrivantVide);
	}

	bool bTrouve = false;
	unsigned int uiIndexSupprimer = 0;

	for (unsigned int i = 0; i < uiSOMNbrArrivant; ++i)
	{
		if (ppArcSOMArrivant[i] != nullptr && ppArcSOMArrivant[i]->ARCLireDestination() == uiNumParam)
		{
			bTrouve = true;
			uiIndexSupprimer = i;
			break;
		}
	}

	if (!bTrouve)
	{
		CException EXCArc_Inexistant;
		EXCArc_Inexistant.EXCModifierValeur(ARC_INEXISTANT);
		throw(EXCArc_Inexistant);
	}

	delete ppArcSOMArrivant[uiIndexSupprimer];
	ppArcSOMArrivant[uiIndexSupprimer] = nullptr;

	// Réarranger la liste des arcs partants
	for (unsigned int i = uiIndexSupprimer; i < uiSOMNbrArrivant - 1; ++i)
	{
		ppArcSOMArrivant[i] = ppArcSOMArrivant[i + 1];
	}

	ppArcSOMArrivant[uiSOMNbrArrivant - 1] = nullptr;
	uiSOMNbrArrivant -= 1;
}

/**************************************************************
Nom : SOMAfficherSommet
***************************************************************
Cette fonction permet d'afficher les caractéristiques d'un sommet :
son numéro, sa liste d'arrivants et de partants.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : On affiche à l'écran les caractéristiques d'un sommet :
		   son numéro, sa liste d'arrivants et de partants.
***************************************************************/
void CSommet::SOMAfficherSommet()
{
	cout << "Sommet " << uiSOMNumSommet << " :\n";

	// Liste des arcs entrants
	cout << "  Arrivants :\n";

	if (uiSOMNbrArrivant == 0)
	{
		cout << "    Aucun\n";
	}

	else
	{
		for (unsigned int i = 0; i < uiSOMNbrArrivant; ++i)
		{
			if (ppArcSOMArrivant[i] != nullptr)
			{
				cout << "    . " << ppArcSOMArrivant[i]->ARCLireDestination() << "\n";
			}
		}
	}

	// Liste des arcs sortants
	cout << "  Partants :\n";

	if (uiSOMNbrPartant == 0)
	{
		cout << "    Aucun\n";
	}

	else
	{
		for (unsigned int i = 0; i < uiSOMNbrPartant; ++i)
		{
			if (ppArcSOMPartant[i] != nullptr)
			{
				cout << "    . " << ppArcSOMPartant[i]->ARCLireDestination() << "\n";
			}
		}
	}
}

/**************************************************************
Nom : operator=
***************************************************************
Cette fonction permet de surcharger l'opérateur =.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : On surcharge l'opérateur = afin d'affecter un CSommet
		   à un autre.
***************************************************************/
CSommet& CSommet::operator=(const CSommet& SOMParam)
{
	if (this == &SOMParam)
	{
		return *this; // Vérification de l'auto-attribution
	}

	// Suppression des anciens arcs arrivants
	for (unsigned int i = 0; i < uiSOMNbrArrivant; ++i)
	{
		delete ppArcSOMArrivant[i];
	}

	delete[] ppArcSOMArrivant;

	// Suppression des anciens arcs partants
	for (unsigned int i = 0; i < uiSOMNbrPartant; ++i)
	{
		delete ppArcSOMPartant[i];
	}

	delete[] ppArcSOMPartant;

	// Copie des attributs
	uiSOMNumSommet = SOMParam.uiSOMNumSommet;
	uiSOMNbrArrivant = SOMParam.uiSOMNbrArrivant;
	uiSOMNbrPartant = SOMParam.uiSOMNbrPartant;

	// Copie des arcs arrivants
	ppArcSOMArrivant = new CArc *[uiSOMNbrArrivant];

	for (unsigned int i = 0; i < uiSOMNbrArrivant; ++i)
	{
		if (SOMParam.ppArcSOMArrivant[i] != nullptr)
		{
			ppArcSOMArrivant[i] = new CArc(*SOMParam.ppArcSOMArrivant[i]);
		}

		else
		{
			ppArcSOMArrivant[i] = nullptr;
		}
	}

	// Copie des arcs partants
	ppArcSOMPartant = new CArc *[uiSOMNbrPartant];

	for (unsigned int i = 0; i < uiSOMNbrPartant; ++i)
	{
		if (SOMParam.ppArcSOMPartant[i] != nullptr)
		{
			ppArcSOMPartant[i] = new CArc(*SOMParam.ppArcSOMPartant[i]);
		}

		else
		{
			ppArcSOMPartant[i] = nullptr;
		}
	}

	return *this;
}