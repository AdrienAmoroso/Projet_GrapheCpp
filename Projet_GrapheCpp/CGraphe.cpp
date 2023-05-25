/*****************************************************************//**
 * \file   CGraphe.cpp
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

#include "CGraphe.h"

// Constructeurs - Destructeur

/**************************************************************
Nom : CGraphe
***************************************************************
Constructeur par défaut de la classe CGraphe qui permet
d’initialiser un objet.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : Le graphe est initialisé.
***************************************************************/
CGraphe::CGraphe()
{
	ppSomGPHListeSommet = nullptr;
	uiGPHNbrSommet = 0;
	bGPHOriente = false;
}

/**************************************************************
Nom : CGraphe
***************************************************************
Constructeur de recopie de la classe CGraphe qui permet
d’initialiser un objet à partir d'un autre objet de la classe CGraphe.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : Le graphe est initialisé à partir d'un objet CGraphe donné.
***************************************************************/
CGraphe::CGraphe(const CGraphe& GPHParam)
{
	uiGPHNbrSommet = GPHParam.uiGPHNbrSommet;
	bGPHOriente = GPHParam.bGPHOriente;

	if (uiGPHNbrSommet > 0)
	{
		ppSomGPHListeSommet = new CSommet*[uiGPHNbrSommet];

		for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
		{
			if (GPHParam.ppSomGPHListeSommet[i] != nullptr)
			{
				ppSomGPHListeSommet[i] = new CSommet(*GPHParam.ppSomGPHListeSommet[i]);
			}

			else
			{
				ppSomGPHListeSommet[i] = nullptr;
			}
		}
	}

	else
	{
		ppSomGPHListeSommet = nullptr;
	}
}

/**************************************************************
Nom : CGraphe
***************************************************************
Constructeur de confort de la classe qui permet de construire
un graphe orienté ou non.
***************************************************************
Entrée : Booléen qui indique si le graphe doit être orienté
Nécessite : néant
Sortie : néant
Entraîne : Le graphe est initialisé à partir d'un booléen indiquant
		   si le graphe est orienté ou non.
***************************************************************/
CGraphe::CGraphe(bool bOrienteParam)
{
	ppSomGPHListeSommet = nullptr;
	uiGPHNbrSommet = 0;
	bGPHOriente = bOrienteParam;
}

/**************************************************************
Nom : ~CGraphe
***************************************************************
Destructeur de la classe CGraphe qui permet de détruire un objet.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : Le sommet est détruit.
***************************************************************/
CGraphe::~CGraphe()
{
	delete[] ppSomGPHListeSommet;
}

// Méthodes

/**************************************************************
Nom : GPHEstDansGraphe
***************************************************************
Cette fonction permet de savoir si un sommet est dans le graphe
à partir de son numéro.
***************************************************************
Entrée : Numéro du sommet
Nécessite : néant
Sortie : Booléen
Entraîne : On retourne true si le sommet est dans le graphe,
		   false sinon.
***************************************************************/
bool CGraphe::GPHEstDansGraphe(unsigned int uiNumSommetParam)
{
	bool bTrouve = false;
	if (ppSomGPHListeSommet == nullptr)
	{
		bTrouve = false;
	}

	// Recherche du sommet

	for (unsigned int i = 0; i < uiGPHNbrSommet; i++)
	{
		if (ppSomGPHListeSommet[i]->SOMLireNumSommet() == uiNumSommetParam)
		{
			bTrouve = true;
			break;
		}
	}

	return bTrouve;
}

/**************************************************************
Nom : GPHEstOriente
***************************************************************
Cette fonction permet de savoir si un graphe est orienté ou non.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : Booléen
Entraîne : On retourne true si le graphe est orienté, false sinon.
***************************************************************/
const bool CGraphe::GPHEstOriente()
{
	if (!bGPHOriente) return false;

	return true;
}

/**************************************************************
Nom : GPHRechercherElement
***************************************************************
Cette fonction permet de connaître l'index du sommet passé en
paramètre dans la liste de sommets du graphe.
***************************************************************
Entrée : Numéro du sommet recherché
Nécessite : néant
Sortie : Indice du sommet dans la liste
Entraîne : On retourne l'indice du sommet dans la liste de sommets
		   du graphe.
***************************************************************/
unsigned int CGraphe::GPHRechercherElement(unsigned int uiNumSommetParam)
{
	if (ppSomGPHListeSommet == nullptr)
	{
		CException EXCListeSommetVide;
		EXCListeSommetVide.EXCModifierValeur(LISTE_SOMMET_VIDE);
		throw(EXCListeSommetVide);
	}

	// Recherche du sommet 
	int index = -1;

	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (ppSomGPHListeSommet[i]->SOMLireNumSommet() == uiNumSommetParam)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		CException EXCSommet_Invalide;
		EXCSommet_Invalide.EXCModifierValeur(SOMMET_INVALIDE);
		throw(EXCSommet_Invalide);
	}

	return index;
}

/**************************************************************
Nom : GPHAjouterSommet
***************************************************************
Cette fonction permet d'ajouter un sommet au graphe à partir de
son numéro.
***************************************************************
Entrée : Numéro de sommet
Nécessite : néant
Sortie : néant
Entraîne : Le sommet est ajouté à la liste des sommets du graphe.
***************************************************************/
void CGraphe::GPHAjouterSommet(unsigned int uiNumSommetParam)
{
	// Vérifie si le graphe est vide
	if (ppSomGPHListeSommet == nullptr)
	{
		// Création d'un nouveau tableau avec un seul sommet
		uiGPHNbrSommet += 1;
		ppSomGPHListeSommet = new CSommet *[uiGPHNbrSommet];
		ppSomGPHListeSommet[0] = new CSommet(uiNumSommetParam);

		return;
	}

	// Vérifie si le sommet existe déjà dans le graphe
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (ppSomGPHListeSommet[i]->SOMLireNumSommet() == uiNumSommetParam)
		{
			CException EXCExiste_Deja;
			EXCExiste_Deja.EXCModifierValeur(EXISTE_DEJA);
			throw(EXCExiste_Deja);
		}
	}

	// Création d'un nouveau tableau de pointeurs vers CSommet avec une taille augmentée de 1
	CSommet** pNouveauTableau = new CSommet *[uiGPHNbrSommet + 1];

	// Copie des pointeurs des sommets existants dans le nouveau tableau
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		pNouveauTableau[i] = ppSomGPHListeSommet[i];
	}

	// Ajout du nouveau sommet à la dernière position du tableau
	pNouveauTableau[uiGPHNbrSommet] = new CSommet(uiNumSommetParam);

	// Suppression de l'ancien tableau de pointeurs vers CSommet
	delete[] ppSomGPHListeSommet;

	// Mettre à jour le tableau de pointeurs avec le nouveau tableau
	ppSomGPHListeSommet = pNouveauTableau;

	// Mettre à jour le nombre de sommets
	++uiGPHNbrSommet;
}

/**************************************************************
Nom : GPHAjouterSommet
***************************************************************
Cette fonction permet d'ajouter un sommet au graphe.
***************************************************************
Entrée : Objet CSommet
Nécessite : néant
Sortie : néant
Entraîne : Le sommet est ajouté à la liste des sommets du graphe.
***************************************************************/
void CGraphe::GPHAjouterSommet(CSommet& SOMSommetParam)
{
	// Vérifie si le graphe est vide
	if (ppSomGPHListeSommet == nullptr)
	{
		// Création d'un nouveau tableau avec un seul sommet
		uiGPHNbrSommet += 1;
		ppSomGPHListeSommet = new CSommet *[uiGPHNbrSommet];
		ppSomGPHListeSommet[0] = new CSommet(SOMSommetParam);

		return;
	}

	// Vérifie si le sommet existe déjà dans le graphe
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (ppSomGPHListeSommet[i]->SOMLireNumSommet() == SOMSommetParam.SOMLireNumSommet())
		{
			CException EXCExiste_Deja;
			EXCExiste_Deja.EXCModifierValeur(EXISTE_DEJA);
			throw(EXCExiste_Deja);
		}
	}

	// Création d'un nouveau tableau de pointeurs vers CSommet avec une taille augmentée de 1
	CSommet** pNouveauTableau = new CSommet *[uiGPHNbrSommet + 1];

	// Copie des pointeurs des sommets existants dans le nouveau tableau
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		pNouveauTableau[i] = ppSomGPHListeSommet[i];
	}

	// Ajout du nouveau sommet à la dernière position du tableau
	pNouveauTableau[uiGPHNbrSommet] = new CSommet(SOMSommetParam);

	// Suppression de l'ancien tableau de pointeurs vers CSommet
	delete[] ppSomGPHListeSommet;

	// Mettre à jour le tableau de pointeurs avec le nouveau tableau
	ppSomGPHListeSommet = pNouveauTableau;

	// Mettre à jour le nombre de sommets
	++uiGPHNbrSommet;
}

/**************************************************************
Nom : GPHAjouterArc
***************************************************************
Cette fonction permet d'ajouter un arc au graphe à partir de
son numéro.
***************************************************************
Entrée : Numéro de sommet
Nécessite : néant
Sortie : néant
Entraîne : Le sommet est ajouté à la liste des sommets du graphe.
***************************************************************/
void CGraphe::GPHAjouterArc(unsigned int uiNumSommetPartant, unsigned int uiNumSommetArrivant)
{
	unsigned int indexPartant = GPHRechercherElement(uiNumSommetPartant);
	unsigned int indexArrivant = GPHRechercherElement(uiNumSommetArrivant);

	ppSomGPHListeSommet[indexPartant]->SOMAjouterPartant(uiNumSommetArrivant);
	ppSomGPHListeSommet[indexArrivant]->SOMAjouterArrivant(uiNumSommetPartant);

	// Teste si le graphe est orienté ou non 
	if (!bGPHOriente)
	{
		ppSomGPHListeSommet[indexPartant]->SOMAjouterArrivant(uiNumSommetArrivant);
		ppSomGPHListeSommet[indexArrivant]->SOMAjouterPartant(uiNumSommetPartant);
	}
}

/**************************************************************
Nom : GPHModifierSommet
***************************************************************
Cette fonction permet de modifier un sommet du graphe à partir
de son numéro.
***************************************************************
Entrée : Numéro initial du sommet, nouveau numéro du sommet
Nécessite : néant
Sortie : néant
Entraîne : Le numéro du sommet est modifié, et donc les listes
		   d'arrivants et de partants des autres sommets concernés
		   sont également mises à jour.
***************************************************************/
void CGraphe::GPHModifierSommet(unsigned int uiNumSommetParam, unsigned int uiNvNumSommet)
{
	// Vérifier si le sommet existe dans le graphe
	unsigned int uiIndexParam = GPHRechercherElement(uiNumSommetParam);

	// Verifie que le nouveau sommet n'est pas dans le graphe
	if (unsigned int uiIndexNouveauSommet = GPHEstDansGraphe(uiNvNumSommet))
	{
		CException EXCNumeroSommetInvalide;
		EXCNumeroSommetInvalide.EXCModifierValeur(SOMMET_INVALIDE);
		throw(EXCNumeroSommetInvalide);
	}

	// Modifier le numéro du sommet
	ppSomGPHListeSommet[uiNumSommetParam - 1]->SOMModifierNumSommet(uiNvNumSommet);

	// Mettre à jour les numéros dans la liste des partants et arrivants des autres sommets
	for (unsigned int i = 0; i < uiGPHNbrSommet; i++)
	{
		// Mettre à jour les partants
		CSommet* SOMSommet = ppSomGPHListeSommet[i];
		for (unsigned int j = 0; j < SOMSommet->SOMLireNbrPartant(); j++)
		{
			if (SOMSommet->SOMLirePartant(j) == uiNumSommetParam)
			{
				SOMSommet->SOMSupprimerPartant(uiNumSommetParam);
				SOMSommet->SOMAjouterPartant(uiNvNumSommet);
			}
		}

		// Mettre à jour les arrivants
		for (unsigned int j = 0; j < SOMSommet->SOMLireNbrArrivant(); j++)
		{
			if (SOMSommet->SOMLireArrivant(j) == uiNumSommetParam)
			{
				SOMSommet->SOMSupprimerArrivant(uiNumSommetParam);
				SOMSommet->SOMAjouterArrivant(uiNvNumSommet);
			}
		}
	}

}

/**************************************************************
Nom : GPHSupprimerSommet
***************************************************************
Cette fonction permet de supprimer un sommet du graphe à partir de
son numéro.
***************************************************************
Entrée : Numéro de sommet
Nécessite : néant
Sortie : néant
Entraîne : Le sommet est supprimé de la liste des sommets du graphe.
***************************************************************/
void CGraphe::GPHSupprimerSommet(unsigned int uiNumSommet)
{
	unsigned int uiIndex = GPHRechercherElement(uiGPHNbrSommet);

	// Suppression des arcs liés au sommet à supprimer
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (i != uiIndex)
		{
			try
			{
				ppSomGPHListeSommet[i]->SOMSupprimerArrivant(uiNumSommet);
				ppSomGPHListeSommet[i]->SOMSupprimerPartant(uiNumSommet);
			}
			catch (const CException&)
			{
				// Ne rien faire en cas d'exception
			}
		}
	}

	// Suppression du sommet du graphe
	delete ppSomGPHListeSommet[uiIndex];
	ppSomGPHListeSommet[uiIndex] = nullptr;

	for (unsigned int i = uiIndex; i < uiGPHNbrSommet - 1; ++i)
	{
		ppSomGPHListeSommet[i] = ppSomGPHListeSommet[i + 1];
	}

	ppSomGPHListeSommet[uiGPHNbrSommet - 1] = nullptr;
	uiGPHNbrSommet -= 1;
}

/**************************************************************
Nom : GPHSupprimerArc
***************************************************************
Cette fonction permet de supprimer un arc entre deux sommets du
graphe.
***************************************************************
Entrée : Numéro du sommet de départ, Numéro du sommet d'arrivée
Nécessite : néant
Sortie : néant
Entraîne : L'arc est supprimé entre les deux sommets de numéro
passé en paramètre.
***************************************************************/
void CGraphe::GPHSupprimerArc(unsigned int uiNumSommetPartant, unsigned int uiNumSommetArrivant)
{
	unsigned int indexPartant = GPHRechercherElement(uiNumSommetPartant);
	unsigned int indexArrivant = GPHRechercherElement(uiNumSommetArrivant);

	ppSomGPHListeSommet[indexPartant]->SOMSupprimerPartant(uiNumSommetArrivant);
	ppSomGPHListeSommet[indexArrivant]->SOMSupprimerArrivant(uiNumSommetPartant);

	// Teste si le graphe est non orienté
	if (!bGPHOriente)
	{
		ppSomGPHListeSommet[indexPartant]->SOMSupprimerArrivant(uiNumSommetArrivant);
		ppSomGPHListeSommet[indexArrivant]->SOMSupprimerPartant(uiNumSommetPartant);
	}
}

/**************************************************************
Nom : SOMAfficherGraphe
***************************************************************
Cette fonction permet d'afficher les caractéristiques d'un graphe :
le nombre de sommets qu'il contient, ainsi que les informations 
sur les sommets qui le composent.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : On affiche à l'écran les caractéristiques d'un graphe
		   décrites précédemment.
***************************************************************/
void CGraphe::GPHAfficherGraphe()
{
	cout << "Nombre de sommets dans le graphe";

	if (bGPHOriente)
	{
		cout << " oriente";
	}

	else
	{
		cout << " non oriente";
	}

	cout << " : " << uiGPHNbrSommet << endl;
	cout << "Liste des sommets :" << endl;

	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		ppSomGPHListeSommet[i]->SOMAfficherSommet();
		cout << endl;
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
Entraîne : On surcharge l'opérateur = afin d'affecter un CGraphe
		   à un autre.
***************************************************************/
CGraphe& CGraphe::operator=(const CGraphe& GPHParam)
{
	if (this == &GPHParam) {
		return *this; // Vérification de l'auto-attribution
	}

	// Suppression des anciens sommets
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		delete ppSomGPHListeSommet[i];
	}
	delete[] ppSomGPHListeSommet;

	// Copie des attributs
	uiGPHNbrSommet = GPHParam.uiGPHNbrSommet;
	bGPHOriente = GPHParam.bGPHOriente;

	// Copie des sommets
	ppSomGPHListeSommet = new CSommet *[uiGPHNbrSommet];
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (GPHParam.ppSomGPHListeSommet[i] != nullptr)
		{
			ppSomGPHListeSommet[i] = new CSommet(*GPHParam.ppSomGPHListeSommet[i]);
		}
		else
		{
			ppSomGPHListeSommet[i] = nullptr;
		}
	}

	return *this;
}