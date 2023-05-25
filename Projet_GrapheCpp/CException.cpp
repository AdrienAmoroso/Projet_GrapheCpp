/*****************************************************************//**
 * \file   CException.cpp
 * \brief  Corps de la classe CException.
 *		   Cette classe permet de créer des objets qui sont remontés
 *		   lors de la levée d’exceptions dans le programme.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

#include "CException.h"

// CORPS

/**************************************************************
Nom : CException
***************************************************************
Constructeur par défaut de la classe CException qui permet
d’initialiser un objet.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : L’exception est initialisée à PAS_ERREUR.
***************************************************************/
CException::CException()
{
	uiEXCValeur = PAS_ERREUR;
}

/**************************************************************
Nom : EXCAfficherErreur
***************************************************************
Cette fonction permet d'afficher un message d'erreur.
***************************************************************
Entrée : néant
Nécessite : néant
Sortie : néant
Entraîne : Un message d'erreur est affiché.
***************************************************************/
void CException::EXCAfficherErreur()
{
	switch (uiEXCValeur) {

	case 100:
		// EST_SUCCESSEUR
		cerr << "Erreur : Le sommet est deja successeur, l'arc ne peut etre ajoute." << endl;
		break;

	case 101:
		// EST_PREDECESSEUR
		cerr << "Erreur : Le sommet est deja predecesseur, l'arc ne peut etre ajoute." << endl;
		break;

	case 102:
		// LISTE_PARTANT_VIDE
		cerr << "Erreur : La liste des partants est vide." << endl;
		break;

	case 103:
		// LISTE_ARRIVANT_VIDE
		cerr << "Erreur : La liste des arrivants est vide." << endl;
		break;

	case 104:
		// ARC_INEXISTANT
		cerr << "Erreur : L'arc est inexistant" << endl;
		break;

	case 105:
		// INDEX_INVALIDE
		cerr << "Erreur : Index incorrect." << endl;
		break;

	case 106:
		// EXISTE_DEJA
		cerr << "Erreur : Le sommet existe deja." << endl;
		break;

	case 107:
		// SOMMET_PARTANT_INVALIDE
		cerr << "Erreur : Le sommet partant est invalide." << endl;
		break;

	case 108:
		// LISTE_SOMMET_VIDE
		cerr << "Erreur : La liste des sommets est vide." << endl;
		break;

	case 109:
		// SOMMET_ARRIVANT_INVALIDE
		cerr << "Erreur : Le sommet arrivant est invalide." << endl;
		break;

	case 110:
		// SOMMET_INVALIDE
		cerr << "Erreur : Le sommet est invalide." << endl;
		break;

	case 111:
		// OUVERTURE_ECHOUEE
		cerr << "Erreur : L'ouverture a echouee." << endl;
		break;

	case 112:
		// NOMBRE_SOMMETS_INVALIDE
		cerr << "Erreur : Le nombre de sommets est invalide." << endl;
		break;

	case 113:
		// NOMBRE_ARCS_INVALIDE
		cerr << "Erreur : Le nombre d'arcs est invalide." << endl;
		break;

	case 114:
		// SYNTAXE_INVALIDE
		cerr << "Erreur : La syntaxe est invalide." << endl;
		break;

	default:
		// ERREUR INCONNUE
		cerr << "Erreur d'origine inconnue." << endl;
	}
}