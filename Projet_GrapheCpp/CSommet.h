/*****************************************************************//**
 * \file   CSommet.h
 * \brief  Interface de la classe CSommet.
 *		   Cette classe permet de créer et de gérer des sommets d'un graphe.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Mai 2023
 *********************************************************************/

#ifndef C_SOMMET_H
#define C_SOMMET_H 11

#include "CArc.h"

#define NB_MAX_ARCS 20

#define EST_SUCCESSEUR 100
#define EST_PREDECESSEUR 101
#define LISTE_PARTANT_VIDE 102
#define LISTE_ARRIVANT_VIDE 103
#define ARC_INEXISTANT 104
#define INDEX_INVALIDE 105
#define LISTE_SOMMET_VIDE 108

class CSommet
{
private:

	/******** Attributs *********/

	unsigned int uiSOMNumSommet;
	unsigned int uiSOMNbrArrivant;
	unsigned int uiSOMNbrPartant;
	CArc** ppArcSOMArrivant;
	CArc** ppArcSOMPartant;
	
public:

	/******** Constructeurs - Destructeur *********/

	CSommet();
	/* Constructeur par défaut de la classe.
	E : néant
	Nécessite : néant
	S : néant
	Entraîne : Le sommet est initialisé.
	*/

	CSommet(unsigned int uiNumSommet);
	/* Constructeur de confort de la classe qui créé un sommet à partir d'un numéro donné.
	E : Numéro du sommet
	Nécessite : néant
	S : néant
	Entraîne : Le sommet est initialisé à partir d'un numéro donné.
	*/

	CSommet(const CSommet &SOMParam);
	/* Constructeur de recopie de la classe.
	E : Objet CSommet
	Nécessite : néant
	S : néant
	Entraîne : Le sommet est initialisé à partir d'un objet CSommet donné.
	*/

	CSommet(unsigned int uiNumSommet, unsigned int uiNbrArrivant, unsigned int uiNbrPartant, CArc** ppArcArrivant, CArc** ppArcPartant);
	/* Constructeur de confort de la classe qui créé un sommet en initialisant ses attributs un à un.
	E : Numéro du sommet, Nombre d'arcs arrivants, Nombre d'arcs partants, Liste des arcs arrivants, Liste des arcs partants
	Nécessite : néant
	S : néant
	Entraîne : Le sommet est initialisé en affectant à chaque attribut la valeur correspondante du paramètre.
	*/

	~CSommet();
	/* Destructeur de la classe.
	E : néant
	Nécessite : néant
	S : néant
	Entraîne : Le sommet est détruit.
	*/

	/******** Méthodes *********/

	const unsigned int SOMLireNumSommet();
	/* Cette fonction permet de consulter le numéro du sommet.
	E : néant
	Nécessite : néant
	S : Numéro du sommet
	Entraîne : Le numéro du sommet est retourné.
    */

	void SOMModifierNumSommet(unsigned int uiNvNumSommet);
	/* Cette fonction permet de modifier le numéro d'un sommet.
	E : Nouveau numéro de sommet
	Nécessite : néant
	S : néant
	Entraîne : Le numéro du sommet appelant est remplacé par celui passé en paramètre.
	*/

	const unsigned int SOMLireNbrArrivant();
	/* Cette fonction permet de consulter le nombre d'arcs dans la liste des arrivants.
	E : néant
	Nécessite : néant
	S : Nombre d'arcs arrivants
	Entraîne : Le nombre d'arcs arrivants est retourné.
    */

	const unsigned int SOMLireNbrPartant();
	/* Cette fonction permet de consulter le nombre d'arcs dans la liste des partants.
	E : néant
	Nécessite : néant
	S : Nombre d'arcs partants
	Entraîne : Le nombre d'arcs partants est retourné.
	*/

	const unsigned int SOMLirePartant(unsigned int uiPosition);
	/* Cette fonction permet de consulter le numéro d'un arc partant du sommet à une certaine
	   position de la liste.
	E : Position dans la liste
	Nécessite : néant
	S : Numéro de l'arc partant à cette position
	Entraîne : On retourne le numéro de l'arc partant à la position passée en paramètre dans la liste.
	*/

	const unsigned int SOMLireArrivant(unsigned int uiPosition);
	/* Cette fonction permet de consulter le numéro d'un arc arrivant du sommet à une certaine
	   position de la liste.
	E : Position dans la liste
	Nécessite : néant
	S : Numéro de l'arc arrivant à cette position
	Entraîne : On retourne le numéro de l'arc arrivant à la position passée en paramètre dans la liste.
	*/

	bool SOMEstSuccesseurDe(unsigned int uiNumSommet);
	/* Cette fonction permet de savoir si le sommet appelant est successeur du sommet de numéro passé en paramètre
	   (EX : Sommet2.EstSuccesseurDe(1) <=> "Sommet2 est successeur du sommet de numéro 1").
	E : Numéro du sommet dont on cherche s'il précède le sommet appelant
	Nécessite : néant
	S : Booléen
	Entraîne : On retourne vrai si le sommet appelant est successeur du sommet en paramètre, faux sinon.
	*/

	bool SOMEstPredecesseurDe(unsigned int uiNumSommet);
	/* Cette fonction permet de savoir si le sommet appelant est prédecesseur du sommet de numéro passé en paramètre
	   (EX : Sommet1.EstPredecesseurDe(2) <=> "Sommet1 est prédecesseur du sommet de numéro 2").
	E : Numéro du sommet dont on cherche s'il succède au sommet appelant
	Nécessite : néant
	S : Booléen
	Entraîne : On retourne vrai si le sommet appelant est prédecesseur du sommet en paramètre, faux sinon.
	*/

	const unsigned int* SOMLireListeArrivant();
	/* Cette fonction permet de consulter la liste des arcs arrivants.
	E : néant
	Nécessite : néant
	S : Liste des arcs arrivants
	Entraîne : La liste des arcs arrivants est retournée.
	*/

	const unsigned int* SOMLireListePartant();
	/* Cette fonction permet de consulter la liste des arcs partants.
	E : néant
	Nécessite : néant
	S : Liste des arcs partants
	Entraîne : La liste des arcs partants est retournée.
	*/

	void SOMModifierListeArrivant(CArc** ppArcArrivantParam, unsigned int uiTaille);
	/* Cette fonction permet de modifier la liste des arcs arrivants avec celle en paramètre.
	E : Nouvelle liste d'arcs arrivants, taille de cette liste
	Nécessite : néant
	S : néant
	Entraîne : La liste des arcs arrivants est remplacée par celle en paramètre.
	*/

	void SOMModifierListePartant(CArc** ppArcPartantParam, unsigned int uiTaille);
	/* Cette fonction permet de modifier la liste des arcs partants avec celle en paramètre.
	E : Nouvelle liste d'arcs partants, taille de cette liste
	Nécessite : néant
	S : néant
	Entraîne : La liste des arcs partants est remplacée par celle en paramètre.
	*/

	void SOMAjouterArrivant(unsigned int uiNumParam);
	/* Cette fonction permet d'ajouter un numéro de sommet dans la liste des arrivants.
	E : Numéro de sommet
	Nécessite : néant
	S : néant
	Entraîne : Le numéro du sommet passé en paramètre est ajouté dans la liste des arrivants.
	*/

	void SOMAjouterPartant(unsigned int uiNumParam);
	/* Cette fonction permet d'ajouter un numéro de sommet dans la liste des partants.
	E : Numéro de sommet
	Nécessite : néant
	S : néant
	Entraîne : Le numéro du sommet passé en paramètre est ajouté dans la liste des partants.
	*/

	void SOMSupprimerPartant(unsigned int uiNumParam);
	/* Cette fonction permet de supprimer un numéro de sommet de la liste des partants.
	E : Numéro de sommet
	Nécessite : néant
	S : néant
	Entraîne : Le numéro du sommet passé en paramètre est supprimé de la liste des partants.
	*/

	void SOMSupprimerArrivant(unsigned int uiNumParam);
	/* Cette fonction permet de supprimer un numéro de sommet de la liste des arrivants.
	E : Numéro de sommet
	Nécessite : néant
	S : néant
	Entraîne : Le numéro du sommet passé en paramètre est supprimé de la liste des arrivants.
	*/

	void SOMAfficherSommet();
	/* Cette fonction permet d'afficher les caractéristiques d'un sommet : son numéro, sa liste d'arrivants et de partants.
	E : néant
	Nécessite : néant
	S : néant
	Entraîne : On affiche à l'écran les caractéristiques d'un sommet : son numéro, sa liste d'arrivants et de partants.
	*/

	CSommet& operator=(const CSommet& SOMParam);
	/* Cette fonction permet de surcharger l'opérateur =.
	E : Objet CSommet
	Nécessite : néant
	S : néant
	Entraîne : On surcharge l'opérateur = afin d'affecter un CSommet à un autre.
	*/
};

#include "CSommet.ipp"
#endif