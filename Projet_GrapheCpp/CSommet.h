/*****************************************************************//**
 * \file   CSommet.h
 * \brief  Interface de la classe CSommet.
 *		   Cette classe permet de cr�er et de g�rer des sommets d'un graphe.
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
	/* Constructeur par d�faut de la classe.
	E : n�ant
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le sommet est initialis�.
	*/

	CSommet(unsigned int uiNumSommet);
	/* Constructeur de confort de la classe qui cr�� un sommet � partir d'un num�ro donn�.
	E : Num�ro du sommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le sommet est initialis� � partir d'un num�ro donn�.
	*/

	CSommet(const CSommet &SOMParam);
	/* Constructeur de recopie de la classe.
	E : Objet CSommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le sommet est initialis� � partir d'un objet CSommet donn�.
	*/

	CSommet(unsigned int uiNumSommet, unsigned int uiNbrArrivant, unsigned int uiNbrPartant, CArc** ppArcArrivant, CArc** ppArcPartant);
	/* Constructeur de confort de la classe qui cr�� un sommet en initialisant ses attributs un � un.
	E : Num�ro du sommet, Nombre d'arcs arrivants, Nombre d'arcs partants, Liste des arcs arrivants, Liste des arcs partants
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le sommet est initialis� en affectant � chaque attribut la valeur correspondante du param�tre.
	*/

	~CSommet();
	/* Destructeur de la classe.
	E : n�ant
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le sommet est d�truit.
	*/

	/******** M�thodes *********/

	const unsigned int SOMLireNumSommet();
	/* Cette fonction permet de consulter le num�ro du sommet.
	E : n�ant
	N�cessite : n�ant
	S : Num�ro du sommet
	Entra�ne : Le num�ro du sommet est retourn�.
    */

	void SOMModifierNumSommet(unsigned int uiNvNumSommet);
	/* Cette fonction permet de modifier le num�ro d'un sommet.
	E : Nouveau num�ro de sommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le num�ro du sommet appelant est remplac� par celui pass� en param�tre.
	*/

	const unsigned int SOMLireNbrArrivant();
	/* Cette fonction permet de consulter le nombre d'arcs dans la liste des arrivants.
	E : n�ant
	N�cessite : n�ant
	S : Nombre d'arcs arrivants
	Entra�ne : Le nombre d'arcs arrivants est retourn�.
    */

	const unsigned int SOMLireNbrPartant();
	/* Cette fonction permet de consulter le nombre d'arcs dans la liste des partants.
	E : n�ant
	N�cessite : n�ant
	S : Nombre d'arcs partants
	Entra�ne : Le nombre d'arcs partants est retourn�.
	*/

	const unsigned int SOMLirePartant(unsigned int uiPosition);
	/* Cette fonction permet de consulter le num�ro d'un arc partant du sommet � une certaine
	   position de la liste.
	E : Position dans la liste
	N�cessite : n�ant
	S : Num�ro de l'arc partant � cette position
	Entra�ne : On retourne le num�ro de l'arc partant � la position pass�e en param�tre dans la liste.
	*/

	const unsigned int SOMLireArrivant(unsigned int uiPosition);
	/* Cette fonction permet de consulter le num�ro d'un arc arrivant du sommet � une certaine
	   position de la liste.
	E : Position dans la liste
	N�cessite : n�ant
	S : Num�ro de l'arc arrivant � cette position
	Entra�ne : On retourne le num�ro de l'arc arrivant � la position pass�e en param�tre dans la liste.
	*/

	bool SOMEstSuccesseurDe(unsigned int uiNumSommet);
	/* Cette fonction permet de savoir si le sommet appelant est successeur du sommet de num�ro pass� en param�tre
	   (EX : Sommet2.EstSuccesseurDe(1) <=> "Sommet2 est successeur du sommet de num�ro 1").
	E : Num�ro du sommet dont on cherche s'il pr�c�de le sommet appelant
	N�cessite : n�ant
	S : Bool�en
	Entra�ne : On retourne vrai si le sommet appelant est successeur du sommet en param�tre, faux sinon.
	*/

	bool SOMEstPredecesseurDe(unsigned int uiNumSommet);
	/* Cette fonction permet de savoir si le sommet appelant est pr�decesseur du sommet de num�ro pass� en param�tre
	   (EX : Sommet1.EstPredecesseurDe(2) <=> "Sommet1 est pr�decesseur du sommet de num�ro 2").
	E : Num�ro du sommet dont on cherche s'il succ�de au sommet appelant
	N�cessite : n�ant
	S : Bool�en
	Entra�ne : On retourne vrai si le sommet appelant est pr�decesseur du sommet en param�tre, faux sinon.
	*/

	const unsigned int* SOMLireListeArrivant();
	/* Cette fonction permet de consulter la liste des arcs arrivants.
	E : n�ant
	N�cessite : n�ant
	S : Liste des arcs arrivants
	Entra�ne : La liste des arcs arrivants est retourn�e.
	*/

	const unsigned int* SOMLireListePartant();
	/* Cette fonction permet de consulter la liste des arcs partants.
	E : n�ant
	N�cessite : n�ant
	S : Liste des arcs partants
	Entra�ne : La liste des arcs partants est retourn�e.
	*/

	void SOMModifierListeArrivant(CArc** ppArcArrivantParam, unsigned int uiTaille);
	/* Cette fonction permet de modifier la liste des arcs arrivants avec celle en param�tre.
	E : Nouvelle liste d'arcs arrivants, taille de cette liste
	N�cessite : n�ant
	S : n�ant
	Entra�ne : La liste des arcs arrivants est remplac�e par celle en param�tre.
	*/

	void SOMModifierListePartant(CArc** ppArcPartantParam, unsigned int uiTaille);
	/* Cette fonction permet de modifier la liste des arcs partants avec celle en param�tre.
	E : Nouvelle liste d'arcs partants, taille de cette liste
	N�cessite : n�ant
	S : n�ant
	Entra�ne : La liste des arcs partants est remplac�e par celle en param�tre.
	*/

	void SOMAjouterArrivant(unsigned int uiNumParam);
	/* Cette fonction permet d'ajouter un num�ro de sommet dans la liste des arrivants.
	E : Num�ro de sommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le num�ro du sommet pass� en param�tre est ajout� dans la liste des arrivants.
	*/

	void SOMAjouterPartant(unsigned int uiNumParam);
	/* Cette fonction permet d'ajouter un num�ro de sommet dans la liste des partants.
	E : Num�ro de sommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le num�ro du sommet pass� en param�tre est ajout� dans la liste des partants.
	*/

	void SOMSupprimerPartant(unsigned int uiNumParam);
	/* Cette fonction permet de supprimer un num�ro de sommet de la liste des partants.
	E : Num�ro de sommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le num�ro du sommet pass� en param�tre est supprim� de la liste des partants.
	*/

	void SOMSupprimerArrivant(unsigned int uiNumParam);
	/* Cette fonction permet de supprimer un num�ro de sommet de la liste des arrivants.
	E : Num�ro de sommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : Le num�ro du sommet pass� en param�tre est supprim� de la liste des arrivants.
	*/

	void SOMAfficherSommet();
	/* Cette fonction permet d'afficher les caract�ristiques d'un sommet : son num�ro, sa liste d'arrivants et de partants.
	E : n�ant
	N�cessite : n�ant
	S : n�ant
	Entra�ne : On affiche � l'�cran les caract�ristiques d'un sommet : son num�ro, sa liste d'arrivants et de partants.
	*/

	CSommet& operator=(const CSommet& SOMParam);
	/* Cette fonction permet de surcharger l'op�rateur =.
	E : Objet CSommet
	N�cessite : n�ant
	S : n�ant
	Entra�ne : On surcharge l'op�rateur = afin d'affecter un CSommet � un autre.
	*/
};

#include "CSommet.ipp"
#endif