/*****************************************************************//**
 * \file   CGraphe.cpp
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

#include "CGraphe.h"

// Constructeurs - Destructeur

/**************************************************************
Nom : CGraphe
***************************************************************
Constructeur par d�faut de la classe CGraphe qui permet
d�initialiser un objet.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Le graphe est initialis�.
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
d�initialiser un objet � partir d'un autre objet de la classe CGraphe.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Le graphe est initialis� � partir d'un objet CGraphe donn�.
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
un graphe orient� ou non.
***************************************************************
Entr�e : Bool�en qui indique si le graphe doit �tre orient�
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Le graphe est initialis� � partir d'un bool�en indiquant
		   si le graphe est orient� ou non.
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
Destructeur de la classe CGraphe qui permet de d�truire un objet.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Le sommet est d�truit.
***************************************************************/
CGraphe::~CGraphe()
{
	delete[] ppSomGPHListeSommet;
}

// M�thodes

/**************************************************************
Nom : GPHEstDansGraphe
***************************************************************
Cette fonction permet de savoir si un sommet est dans le graphe
� partir de son num�ro.
***************************************************************
Entr�e : Num�ro du sommet
N�cessite : n�ant
Sortie : Bool�en
Entra�ne : On retourne true si le sommet est dans le graphe,
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
Cette fonction permet de savoir si un graphe est orient� ou non.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : Bool�en
Entra�ne : On retourne true si le graphe est orient�, false sinon.
***************************************************************/
const bool CGraphe::GPHEstOriente()
{
	if (!bGPHOriente) return false;

	return true;
}

/**************************************************************
Nom : GPHRechercherElement
***************************************************************
Cette fonction permet de conna�tre l'index du sommet pass� en
param�tre dans la liste de sommets du graphe.
***************************************************************
Entr�e : Num�ro du sommet recherch�
N�cessite : n�ant
Sortie : Indice du sommet dans la liste
Entra�ne : On retourne l'indice du sommet dans la liste de sommets
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
Cette fonction permet d'ajouter un sommet au graphe � partir de
son num�ro.
***************************************************************
Entr�e : Num�ro de sommet
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Le sommet est ajout� � la liste des sommets du graphe.
***************************************************************/
void CGraphe::GPHAjouterSommet(unsigned int uiNumSommetParam)
{
	// V�rifie si le graphe est vide
	if (ppSomGPHListeSommet == nullptr)
	{
		// Cr�ation d'un nouveau tableau avec un seul sommet
		uiGPHNbrSommet += 1;
		ppSomGPHListeSommet = new CSommet *[uiGPHNbrSommet];
		ppSomGPHListeSommet[0] = new CSommet(uiNumSommetParam);

		return;
	}

	// V�rifie si le sommet existe d�j� dans le graphe
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (ppSomGPHListeSommet[i]->SOMLireNumSommet() == uiNumSommetParam)
		{
			CException EXCExiste_Deja;
			EXCExiste_Deja.EXCModifierValeur(EXISTE_DEJA);
			throw(EXCExiste_Deja);
		}
	}

	// Cr�ation d'un nouveau tableau de pointeurs vers CSommet avec une taille augment�e de 1
	CSommet** pNouveauTableau = new CSommet *[uiGPHNbrSommet + 1];

	// Copie des pointeurs des sommets existants dans le nouveau tableau
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		pNouveauTableau[i] = ppSomGPHListeSommet[i];
	}

	// Ajout du nouveau sommet � la derni�re position du tableau
	pNouveauTableau[uiGPHNbrSommet] = new CSommet(uiNumSommetParam);

	// Suppression de l'ancien tableau de pointeurs vers CSommet
	delete[] ppSomGPHListeSommet;

	// Mettre � jour le tableau de pointeurs avec le nouveau tableau
	ppSomGPHListeSommet = pNouveauTableau;

	// Mettre � jour le nombre de sommets
	++uiGPHNbrSommet;
}

/**************************************************************
Nom : GPHAjouterSommet
***************************************************************
Cette fonction permet d'ajouter un sommet au graphe.
***************************************************************
Entr�e : Objet CSommet
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Le sommet est ajout� � la liste des sommets du graphe.
***************************************************************/
void CGraphe::GPHAjouterSommet(CSommet& SOMSommetParam)
{
	// V�rifie si le graphe est vide
	if (ppSomGPHListeSommet == nullptr)
	{
		// Cr�ation d'un nouveau tableau avec un seul sommet
		uiGPHNbrSommet += 1;
		ppSomGPHListeSommet = new CSommet *[uiGPHNbrSommet];
		ppSomGPHListeSommet[0] = new CSommet(SOMSommetParam);

		return;
	}

	// V�rifie si le sommet existe d�j� dans le graphe
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		if (ppSomGPHListeSommet[i]->SOMLireNumSommet() == SOMSommetParam.SOMLireNumSommet())
		{
			CException EXCExiste_Deja;
			EXCExiste_Deja.EXCModifierValeur(EXISTE_DEJA);
			throw(EXCExiste_Deja);
		}
	}

	// Cr�ation d'un nouveau tableau de pointeurs vers CSommet avec une taille augment�e de 1
	CSommet** pNouveauTableau = new CSommet *[uiGPHNbrSommet + 1];

	// Copie des pointeurs des sommets existants dans le nouveau tableau
	for (unsigned int i = 0; i < uiGPHNbrSommet; ++i)
	{
		pNouveauTableau[i] = ppSomGPHListeSommet[i];
	}

	// Ajout du nouveau sommet � la derni�re position du tableau
	pNouveauTableau[uiGPHNbrSommet] = new CSommet(SOMSommetParam);

	// Suppression de l'ancien tableau de pointeurs vers CSommet
	delete[] ppSomGPHListeSommet;

	// Mettre � jour le tableau de pointeurs avec le nouveau tableau
	ppSomGPHListeSommet = pNouveauTableau;

	// Mettre � jour le nombre de sommets
	++uiGPHNbrSommet;
}

/**************************************************************
Nom : GPHAjouterArc
***************************************************************
Cette fonction permet d'ajouter un arc au graphe � partir de
son num�ro.
***************************************************************
Entr�e : Num�ro de sommet
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Le sommet est ajout� � la liste des sommets du graphe.
***************************************************************/
void CGraphe::GPHAjouterArc(unsigned int uiNumSommetPartant, unsigned int uiNumSommetArrivant)
{
	unsigned int indexPartant = GPHRechercherElement(uiNumSommetPartant);
	unsigned int indexArrivant = GPHRechercherElement(uiNumSommetArrivant);

	ppSomGPHListeSommet[indexPartant]->SOMAjouterPartant(uiNumSommetArrivant);
	ppSomGPHListeSommet[indexArrivant]->SOMAjouterArrivant(uiNumSommetPartant);

	// Teste si le graphe est orient� ou non 
	if (!bGPHOriente)
	{
		ppSomGPHListeSommet[indexPartant]->SOMAjouterArrivant(uiNumSommetArrivant);
		ppSomGPHListeSommet[indexArrivant]->SOMAjouterPartant(uiNumSommetPartant);
	}
}

/**************************************************************
Nom : GPHModifierSommet
***************************************************************
Cette fonction permet de modifier un sommet du graphe � partir
de son num�ro.
***************************************************************
Entr�e : Num�ro initial du sommet, nouveau num�ro du sommet
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Le num�ro du sommet est modifi�, et donc les listes
		   d'arrivants et de partants des autres sommets concern�s
		   sont �galement mises � jour.
***************************************************************/
void CGraphe::GPHModifierSommet(unsigned int uiNumSommetParam, unsigned int uiNvNumSommet)
{
	// V�rifier si le sommet existe dans le graphe
	unsigned int uiIndexParam = GPHRechercherElement(uiNumSommetParam);

	// Verifie que le nouveau sommet n'est pas dans le graphe
	if (unsigned int uiIndexNouveauSommet = GPHEstDansGraphe(uiNvNumSommet))
	{
		CException EXCNumeroSommetInvalide;
		EXCNumeroSommetInvalide.EXCModifierValeur(SOMMET_INVALIDE);
		throw(EXCNumeroSommetInvalide);
	}

	// Modifier le num�ro du sommet
	ppSomGPHListeSommet[uiNumSommetParam - 1]->SOMModifierNumSommet(uiNvNumSommet);

	// Mettre � jour les num�ros dans la liste des partants et arrivants des autres sommets
	for (unsigned int i = 0; i < uiGPHNbrSommet; i++)
	{
		// Mettre � jour les partants
		CSommet* SOMSommet = ppSomGPHListeSommet[i];
		for (unsigned int j = 0; j < SOMSommet->SOMLireNbrPartant(); j++)
		{
			if (SOMSommet->SOMLirePartant(j) == uiNumSommetParam)
			{
				SOMSommet->SOMSupprimerPartant(uiNumSommetParam);
				SOMSommet->SOMAjouterPartant(uiNvNumSommet);
			}
		}

		// Mettre � jour les arrivants
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
Cette fonction permet de supprimer un sommet du graphe � partir de
son num�ro.
***************************************************************
Entr�e : Num�ro de sommet
N�cessite : n�ant
Sortie : n�ant
Entra�ne : Le sommet est supprim� de la liste des sommets du graphe.
***************************************************************/
void CGraphe::GPHSupprimerSommet(unsigned int uiNumSommet)
{
	unsigned int uiIndex = GPHRechercherElement(uiGPHNbrSommet);

	// Suppression des arcs li�s au sommet � supprimer
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
Entr�e : Num�ro du sommet de d�part, Num�ro du sommet d'arriv�e
N�cessite : n�ant
Sortie : n�ant
Entra�ne : L'arc est supprim� entre les deux sommets de num�ro
pass� en param�tre.
***************************************************************/
void CGraphe::GPHSupprimerArc(unsigned int uiNumSommetPartant, unsigned int uiNumSommetArrivant)
{
	unsigned int indexPartant = GPHRechercherElement(uiNumSommetPartant);
	unsigned int indexArrivant = GPHRechercherElement(uiNumSommetArrivant);

	ppSomGPHListeSommet[indexPartant]->SOMSupprimerPartant(uiNumSommetArrivant);
	ppSomGPHListeSommet[indexArrivant]->SOMSupprimerArrivant(uiNumSommetPartant);

	// Teste si le graphe est non orient�
	if (!bGPHOriente)
	{
		ppSomGPHListeSommet[indexPartant]->SOMSupprimerArrivant(uiNumSommetArrivant);
		ppSomGPHListeSommet[indexArrivant]->SOMSupprimerPartant(uiNumSommetPartant);
	}
}

/**************************************************************
Nom : SOMAfficherGraphe
***************************************************************
Cette fonction permet d'afficher les caract�ristiques d'un graphe :
le nombre de sommets qu'il contient, ainsi que les informations 
sur les sommets qui le composent.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : On affiche � l'�cran les caract�ristiques d'un graphe
		   d�crites pr�c�demment.
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
Cette fonction permet de surcharger l'op�rateur =.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : n�ant
Entra�ne : On surcharge l'op�rateur = afin d'affecter un CGraphe
		   � un autre.
***************************************************************/
CGraphe& CGraphe::operator=(const CGraphe& GPHParam)
{
	if (this == &GPHParam) {
		return *this; // V�rification de l'auto-attribution
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