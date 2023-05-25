/*****************************************************************//**
 * \file   CLecteurFichier.cpp
 * \brief  Corps de la classe CLecteurFichier.
 *		   Cette classe permet de créer des graphes à partir d'un fichier
		   texte.
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

#include "CLecteurFichier.h"

#define OUVERTURE_ECHOUEE 111
#define NOMBRE_SOMMETS_INVALIDE 112
#define NOMBRE_ARCS_INVALIDE 113
#define SYNTAXE_INVALIDE 114

// Méthodes

/**************************************************************
Nom : LECCreerGrapheDepuisFichier
***************************************************************
Cette fonction permet de créer un graphe à partir d'un fichier.
***************************************************************
Entrée : Nom du fichier
Nécessite : néant
Sortie : Un objet de la classe CGraphe
Entraîne : Un graphe extrait du fichier est retourné.
***************************************************************/
CGraphe CLecteurFichier::LECCreerGrapheDepuisFichier(const char* sFichier)
{
	ifstream ISMonFichier(sFichier);

	if (ISMonFichier.fail())
	{
		CException EXCOuvertureEchouee;
		EXCOuvertureEchouee.EXCModifierValeur(OUVERTURE_ECHOUEE);
		throw(EXCOuvertureEchouee);
	}

	unsigned int uiNbrSommets = 0;
	unsigned int uiNbrArcs = 0;

	// Récupération du nombre de sommets
	char cType[256];
	
	// Création du graphe
	CGraphe GPHGraphe(true);
	int iNbrArret = 0;


	// Ignorer les lignes vides et les caractères indésirables
	while (ISMonFichier.getline(cType, 256))
	{
		// Ignorer les espaces en début de ligne
		char* p = cType;
		while (*p == ' ') p++;

		// On saute NBSommets et NBArcs car ils ne sont pas nécessaires
		if (strncmp(cType, "NBSommets=", 10) == 0)
		{
			char* pcNumeroPos = strstr(p, "NBSommets=") + 10;
			while (*pcNumeroPos == ' ') pcNumeroPos++;
			if ((*pcNumeroPos < '0' || *pcNumeroPos > '9'))
			{
				CException EXCSyntaxeInvalide;
				EXCSyntaxeInvalide.EXCModifierValeur(SYNTAXE_INVALIDE);
				throw(EXCSyntaxeInvalide);
			}
			unsigned int uiNbrSommetResult = 0;

			while (*pcNumeroPos >= '0' && *pcNumeroPos <= '9')
			{
				uiNbrSommetResult = uiNbrSommetResult * 10 + (*pcNumeroPos - '0');
				pcNumeroPos++;
				// Ce test permet d'afficher une erreur si le format n'est pas bon
				if ((*pcNumeroPos < '0' || *pcNumeroPos > '9') && *pcNumeroPos != 32 && *pcNumeroPos != '\0')
				{
					CException EXCSyntaxeInvalide;
					EXCSyntaxeInvalide.EXCModifierValeur(SYNTAXE_INVALIDE);
					throw(EXCSyntaxeInvalide);
				}
			}

			uiNbrSommets = uiNbrSommetResult;
		}

		else if (strncmp(cType, "NBArcs=", 7) == 0)
		{
			char* pcNumeroPos = strstr(p, "NBArcs=") + 7;
			while (*pcNumeroPos == ' ') pcNumeroPos++;
			if ((*pcNumeroPos < '0' || *pcNumeroPos > '9'))
			{
				CException EXCSyntaxeInvalide;
				EXCSyntaxeInvalide.EXCModifierValeur(SYNTAXE_INVALIDE);
				throw(EXCSyntaxeInvalide);
			}
			unsigned int uiNbrArcResult = 0;

			while (*pcNumeroPos >= '0' && *pcNumeroPos <= '9')
			{
				uiNbrArcResult = uiNbrArcResult * 10 + (*pcNumeroPos - '0');
				pcNumeroPos++;
				// Ce test permet d'afficher une erreur si le format n'est pas bon
				if ((*pcNumeroPos < '0' || *pcNumeroPos > '9') && *pcNumeroPos != 32 && *pcNumeroPos != '\0')
				{
					CException EXCSyntaxeInvalide;
					EXCSyntaxeInvalide.EXCModifierValeur(SYNTAXE_INVALIDE);
					throw(EXCSyntaxeInvalide);
				}
			}

			uiNbrArcs = uiNbrArcResult;
		}
		// Vérifier le type de ligne
		else if (strncmp(p, "Numero=", 7) == 0)
		{
			char* pcNumeroPos = strstr(p, "Numero=") + 7;

			while (*pcNumeroPos == ' ') pcNumeroPos++;

			if ((*pcNumeroPos < '0' || *pcNumeroPos > '9'))
			{
				CException EXCSyntaxeInvalide;
				EXCSyntaxeInvalide.EXCModifierValeur(SYNTAXE_INVALIDE);
				throw(EXCSyntaxeInvalide);
			}
			unsigned int uiNumeroSommetResult = 0;

			while (*pcNumeroPos >= '0' && *pcNumeroPos <= '9')
			{
				uiNumeroSommetResult = uiNumeroSommetResult * 10 + (*pcNumeroPos - '0');
				pcNumeroPos++;

				// Ce test permet d'afficher une erreur si le format n'est pas bon
				if ((*pcNumeroPos < '0' || *pcNumeroPos > '9') && *pcNumeroPos != 32 && *pcNumeroPos != '\0')
				{
					CException EXCSyntaxeInvalide;
					EXCSyntaxeInvalide.EXCModifierValeur(SYNTAXE_INVALIDE);
					throw(EXCSyntaxeInvalide);
				}
			}



			GPHGraphe.GPHAjouterSommet(uiNumeroSommetResult);
		}
		else if (strncmp(p, "Debut=", 6) == 0)
		{
			char* pcDebutPos = strstr(p, "Debut=") + 6;
			char* pcFinPos = strstr(p, "Fin=") + 4;

			// Ignorer les espaces avant et après les valeurs
			while (*pcDebutPos == ' ') pcDebutPos++;
			while (*(pcFinPos - 1) == ' ') pcFinPos--;

			unsigned int uiDebut = atoi(pcDebutPos);
			unsigned int uiFin = atoi(pcFinPos);

			GPHGraphe.GPHAjouterArc(uiDebut, uiFin);
		}
		else if (strncmp(p, "Sommets=[", 9) == 0)
		{

		}

		else if (strncmp(p, "Arcs=[", 9) == 0)
		{

		}
		else if (strncmp(p, "]", 1) == 0 && iNbrArret == 0)
		{
			iNbrArret += 1;
		}
		else if (strncmp(p, "]", 1) == 0 && iNbrArret == 1)
		{
			break;
		}
		else
		{
			CException EXCSyntaxeInvalide;
			EXCSyntaxeInvalide.EXCModifierValeur(SYNTAXE_INVALIDE);
			throw(EXCSyntaxeInvalide);
		}
	}

	// Vérifier si le nombre de sommets est valide
	if (GPHGraphe.GPHLireNbrSommet() != uiNbrSommets)
	{
		CException EXCNbSommetsInvalide;
		EXCNbSommetsInvalide.EXCModifierValeur(NOMBRE_SOMMETS_INVALIDE);
		throw(EXCNbSommetsInvalide);
	}

	// Vérifier si le nombre d'arcs est valide
	if (GPHGraphe.GPHLireNbrArc() != uiNbrArcs)
	{
		CException EXCNbArcsInvalide;
		EXCNbArcsInvalide.EXCModifierValeur(NOMBRE_ARCS_INVALIDE);
		throw(EXCNbArcsInvalide);
	}

	return GPHGraphe;
}
