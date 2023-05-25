/*****************************************************************//**
 * \file   CGraphe.h
 * \brief  Interface de la classe CGraphe.
 *		   Cette classe permet de créer et de gérer des graphes.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Mai 2023
 *********************************************************************/

#ifndef C_GRAPHE_H
#define C_GRAPHE_H 12

#include "CSommet.h"

#define EXISTE_DEJA 106
#define SOMMET_PARTANT_INVALIDE 107
#define SOMMET_ARRIVANT_INVALIDE 109
#define SOMMET_INVALIDE 110

class CGraphe
{
private:

	/******** Attributs *********/

	CSommet** ppSomGPHListeSommet;
	unsigned int uiGPHNbrSommet;
	bool bGPHOriente;

public:

	/******** Constructeurs - Destructeur *********/

	CGraphe();
	/* Constructeur par défaut de la classe.
	E : néant
	Nécessite : néant
	S : néant
	Entraîne : Le graphe est initialisé.
	*/

	CGraphe(const CGraphe& GPHParam);
	/* Constructeur de recopie de la classe.
	E : Objet CGraphe
	Nécessite : néant
	S : néant
	Entraîne : Le graphe est initialisé à partir d'un objet CGraphe donné.
	*/

	CGraphe(bool bOrienteParam);
	/* Constructeur de confort de la classe qui permet de construire un graphe orienté ou non.
	E : Booléen qui indique si le graphe doit être orienté
	Nécessite : néant
	S : néant
	Entraîne : Le graphe est initialisé à partir d'un booléen indiquant si le graphe est orienté ou non.
	*/

	~CGraphe();
	/* Destructeur de la classe.
	E : néant
	Nécessite : néant
	S : néant
	Entraîne : Le graphe est détruit.
	*/

	/******** Méthodes *********/

	const unsigned int GPHLireNumSommet(unsigned int uiPosition);
	/* Cette fonction permet de consulter le numéro du sommet à une certaine position dans la liste
	   de sommets du graphe.
	E : Position dans la liste
	Nécessite : néant
	S : Numéro du sommet
	Entraîne : Le numéro du sommet situé à cette position est retourné.
	*/

	const unsigned int *GPHLirePartantSommet(unsigned int uiNumSommetParam);
	/* Cette fonction permet de consulter la liste des arcs partants du sommet à partir de son numéro.
	E : Numéro du sommet
	Nécessite : néant
	S : Liste des numéros des arcs partants du sommet
	Entraîne : La liste des numéros des arcs partants du sommet est retournée.
	*/

	const unsigned int *GPHLireArrivantSommet(unsigned int uiNumSommetParam);
	/* Cette fonction permet de consulter la liste des arcs arrivants du sommet à partir de son numéro.
	E : Numéro du sommet
	Nécessite : néant
	S : Liste des numéros des arcs arrivants du sommet
	Entraîne : La liste des numéros des arcs arrivants du sommet est retournée.
	*/

	const unsigned int GPHLireNbrArrivantSommet(unsigned int uiNumSommetParam);
	/* Cette fonction permet de consulter le nombre d'arcs arrivants du sommet à partir de son numéro.
	E : Numéro du sommet
	Nécessite : néant
	S : Nombre d'arcs arrivants du sommet
	Entraîne : Le nombre d'arcs arrivants du sommet est retourné.
	*/

	const unsigned int GPHLireNbrPartantSommet(unsigned int uiNumSommetParam);
	/* Cette fonction permet de consulter le nombre d'arcs partants du sommet à partir de son numéro.
	E : Numéro du sommet
	Nécessite : néant
	S : Nombre d'arcs partants du sommet
	Entraîne : Le nombre d'arcs partants du sommet est retourné.
	*/

	bool GPHEstDansGraphe(unsigned int uiNumSommetParam);
	/* Cette fonction permet de savoir si un sommet est dans le graphe à partir de son numéro.
	E : Numéro du sommet
	Nécessite : néant
	S : Booléen
	Entraîne : On retourne true si le sommet est dans le graphe, false sinon.
	*/

	const unsigned int GPHLireNbrSommet();
	/* Cette fonction permet de consulter le nombre de sommets du graphe.
	E : néant
	Nécessite : néant
	S : Nombre de sommets du graphe 
	Entraîne : On retourne le nombre de sommets du graphe.
	*/

	const unsigned int GPHLireNbrArc();
	/* Cette fonction permet de consulter le nombre d'arcs du graphe.
	E : néant
	Nécessite : néant
	S : Nombre d'arcs du graphe
	Entraîne : On retourne le nombre d'arcs du graphe.
	*/

	const bool GPHEstOriente();
	/* Cette fonction permet de savoir si un graphe est orienté ou non.
	E : néant
	Nécessite : néant
	S : Booléen
	Entraîne : On renvoie true si le graphe est orienté, false sinon.
	*/

	void GPHAfficherGraphe();
	/* Cette fonction permet d'afficher les caractéristiques d'un graphe : le nombre de sommets qu'il
	   contient ainsi que les informations sur les sommets qui le composent.
	E : néant
	Nécessite : néant
	S : néant
	Entraîne : On affiche à l'écran les caractéristiques d'un graphe décrites précédemment.
	*/

	void GPHAjouterSommet(unsigned int uiNumSommetParam);
	/* Cette fonction permet d'ajouter un sommet au graphe à partir de son numéro.
	E : Numéro de sommet
	Nécessite : néant
	S : néant
	Entraîne : Le sommet est ajouté à la liste des sommets du graphe.
	*/

	void GPHAjouterSommet(CSommet& SOMSommetParam);
	/* Cette fonction permet d'ajouter un sommet au graphe.
	E : Objet CSommet
	Nécessite : néant
	S : néant
	Entraîne : Le sommet est ajouté à la liste des sommets du graphe.
	*/

	void GPHAjouterArc(unsigned int uiNumSommetArrivant, unsigned int uiNumSommetPartant);
	/* Cette fonction permet d'ajouter un arc entre deux sommets du graphe.
	E : Numéro du sommet de départ, Numéro du sommet d'arrivée
	Nécessite : néant
	S : néant
	Entraîne : L'arc est créé entre les deux sommets de numéro passés en paramètre.
	*/

	void GPHSupprimerArc(unsigned int uiNumSommetArrivant, unsigned int uiNumSommetPartant);
	/* Cette fonction permet de supprimer un arc entre deux sommets du graphe.
	E : Numéro du sommet de départ, Numéro du sommet d'arrivée
	Nécessite : néant
	S : néant
	Entraîne : L'arc est supprimé entre les deux sommets de numéro passé en paramètre.
	*/
	
	void GPHModifierSommet(unsigned int uiNumSommetParam, unsigned int uiNvNumSommet);
	/* Cette fonction permet de modifier un sommet du graphe à partir de son numéro.
	E : Numéro initial du sommet, nouveau numéro du sommet
	Nécessite : néant
	S : néant
	Entraîne : Le numéro du sommet est modifié, et donc les listes d'arrivants et de partants des autres sommets concernés
			   sont également mises à jour.
	*/

	unsigned int GPHRechercherElement(unsigned int uiNumSommetPram);
	/* Cette fonction permet de connaître l'index du sommet passé en paramètre dans la liste de sommets du graphe.
	E : Numéro du sommet recherché
	Nécessite : néant
	S : Indice du sommet dans la liste 
	Entraîne : On retourne l'indice du sommet dans la liste de sommets du graphe.
	*/

	void GPHSupprimerSommet(unsigned int uiNumSommet);
	/* Cette fonction permet de supprimer un sommet au graphe à partir de son numéro.
	E : Numéro de sommet
	Nécessite : néant
	S : néant
	Entraîne : Le sommet est supprimé à la liste des sommets du graphe.
	*/

	CGraphe& operator=(const CGraphe& GPHParam);
	/* Cette fonction permet de surcharger l'opérateur =.
	E : Objet CSommet
	Nécessite : néant
	S : néant
	Entraîne : On surcharge l'opérateur = afin d'affecter un CGraphe à un autre.
	*/
};

#include "CGraphe.ipp"
#endif