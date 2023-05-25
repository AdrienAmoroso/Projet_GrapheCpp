/*****************************************************************//**
 * \file   CGraphe.h
 * \brief  Interface de la classe CGraphe.
 *		   Cette classe permet de cr�er et de g�rer des graphes.
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
	/* Constructeur par d�faut de la classe.
	E : n�ant
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le graphe est initialis�.
	*/

	CGraphe(const CGraphe& GPHParam);
	/* Constructeur de recopie de la classe.
	E : Objet CGraphe
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le graphe est initialis� � partir d'un objet CGraphe donn�.
	*/

	CGraphe(bool bOrienteParam);
	/* Constructeur de confort de la classe qui permet de construire un graphe orient� ou non.
	E : Bool�en qui indique si le graphe doit �tre orient�
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le graphe est initialis� � partir d'un bool�en indiquant si le graphe est orient� ou non.
	*/

	~CGraphe();
	/* Destructeur de la classe.
	E : n�ant
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le graphe est d�truit.
	*/

	/******** M�thodes *********/

	const unsigned int GPHLireNumSommet(unsigned int uiPosition);
	/* Cette fonction permet de consulter le num�ro du sommet � une certaine position dans la liste
	   de sommets du graphe.
	E : Position dans la liste
	N�cessite : n�ant
	S : Num�ro du sommet
	Entra�ne : Le num�ro du sommet situ� � cette position est retourn�.
	*/

	const unsigned int *GPHLirePartantSommet(unsigned int uiNumSommetParam);
	/* Cette fonction permet de consulter la liste des arcs partants du sommet � partir de son num�ro.
	E : Num�ro du sommet
	N�cessite : n�ant
	S : Liste des num�ros des arcs partants du sommet
	Entra�ne : La liste des num�ros des arcs partants du sommet est retourn�e.
	*/

	const unsigned int *GPHLireArrivantSommet(unsigned int uiNumSommetParam);
	/* Cette fonction permet de consulter la liste des arcs arrivants du sommet � partir de son num�ro.
	E : Num�ro du sommet
	N�cessite : n�ant
	S : Liste des num�ros des arcs arrivants du sommet
	Entra�ne : La liste des num�ros des arcs arrivants du sommet est retourn�e.
	*/

	const unsigned int GPHLireNbrArrivantSommet(unsigned int uiNumSommetParam);
	/* Cette fonction permet de consulter le nombre d'arcs arrivants du sommet � partir de son num�ro.
	E : Num�ro du sommet
	N�cessite : n�ant
	S : Nombre d'arcs arrivants du sommet
	Entra�ne : Le nombre d'arcs arrivants du sommet est retourn�.
	*/

	const unsigned int GPHLireNbrPartantSommet(unsigned int uiNumSommetParam);
	/* Cette fonction permet de consulter le nombre d'arcs partants du sommet � partir de son num�ro.
	E : Num�ro du sommet
	N�cessite : n�ant
	S : Nombre d'arcs partants du sommet
	Entra�ne : Le nombre d'arcs partants du sommet est retourn�.
	*/

	bool GPHEstDansGraphe(unsigned int uiNumSommetParam);
	/* Cette fonction permet de savoir si un sommet est dans le graphe � partir de son num�ro.
	E : Num�ro du sommet
	N�cessite : n�ant
	S : Bool�en
	Entra�ne : On retourne true si le sommet est dans le graphe, false sinon.
	*/

	const unsigned int GPHLireNbrSommet();
	/* Cette fonction permet de consulter le nombre de sommets du graphe.
	E : n�ant
	N�cessite : n�ant
	S : Nombre de sommets du graphe 
	Entra�ne : On retourne le nombre de sommets du graphe.
	*/

	const unsigned int GPHLireNbrArc();
	/* Cette fonction permet de consulter le nombre d'arcs du graphe.
	E : n�ant
	N�cessite : n�ant
	S : Nombre d'arcs du graphe
	Entra�ne : On retourne le nombre d'arcs du graphe.
	*/

	const bool GPHEstOriente();
	/* Cette fonction permet de savoir si un graphe est orient� ou non.
	E : n�ant
	N�cessite : n�ant
	S : Bool�en
	Entra�ne : On renvoie true si le graphe est orient�, false sinon.
	*/

	void GPHAfficherGraphe();
	/* Cette fonction permet d'afficher les caract�ristiques d'un graphe : le nombre de sommets qu'il
	   contient ainsi que les informations sur les sommets qui le composent.
	E : n�ant
	N�cessite : n�ant
	S : n�ant
	Entra�ne : On affiche � l'�cran les caract�ristiques d'un graphe d�crites pr�c�demment.
	*/

	void GPHAjouterSommet(unsigned int uiNumSommetParam);
	/* Cette fonction permet d'ajouter un sommet au graphe � partir de son num�ro.
	E : Num�ro de sommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le sommet est ajout� � la liste des sommets du graphe.
	*/

	void GPHAjouterSommet(CSommet& SOMSommetParam);
	/* Cette fonction permet d'ajouter un sommet au graphe.
	E : Objet CSommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le sommet est ajout� � la liste des sommets du graphe.
	*/

	void GPHAjouterArc(unsigned int uiNumSommetArrivant, unsigned int uiNumSommetPartant);
	/* Cette fonction permet d'ajouter un arc entre deux sommets du graphe.
	E : Num�ro du sommet de d�part, Num�ro du sommet d'arriv�e
	N�cessite : n�ant
	S : n�ant
	Entra�ne : L'arc est cr�� entre les deux sommets de num�ro pass�s en param�tre.
	*/

	void GPHSupprimerArc(unsigned int uiNumSommetArrivant, unsigned int uiNumSommetPartant);
	/* Cette fonction permet de supprimer un arc entre deux sommets du graphe.
	E : Num�ro du sommet de d�part, Num�ro du sommet d'arriv�e
	N�cessite : n�ant
	S : n�ant
	Entra�ne : L'arc est supprim� entre les deux sommets de num�ro pass� en param�tre.
	*/
	
	void GPHModifierSommet(unsigned int uiNumSommetParam, unsigned int uiNvNumSommet);
	/* Cette fonction permet de modifier un sommet du graphe � partir de son num�ro.
	E : Num�ro initial du sommet, nouveau num�ro du sommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le num�ro du sommet est modifi�, et donc les listes d'arrivants et de partants des autres sommets concern�s
			   sont �galement mises � jour.
	*/

	unsigned int GPHRechercherElement(unsigned int uiNumSommetPram);
	/* Cette fonction permet de conna�tre l'index du sommet pass� en param�tre dans la liste de sommets du graphe.
	E : Num�ro du sommet recherch�
	N�cessite : n�ant
	S : Indice du sommet dans la liste 
	Entra�ne : On retourne l'indice du sommet dans la liste de sommets du graphe.
	*/

	void GPHSupprimerSommet(unsigned int uiNumSommet);
	/* Cette fonction permet de supprimer un sommet au graphe � partir de son num�ro.
	E : Num�ro de sommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le sommet est supprim� � la liste des sommets du graphe.
	*/

	CGraphe& operator=(const CGraphe& GPHParam);
	/* Cette fonction permet de surcharger l'op�rateur =.
	E : Objet CSommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : On surcharge l'op�rateur = afin d'affecter un CGraphe � un autre.
	*/
};

#include "CGraphe.ipp"
#endif