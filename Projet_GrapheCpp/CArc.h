/*****************************************************************//**
 * \file   CArc.h
 * \brief  Interface de la classe CArc.
 *		   Cette classe permet de créer et de gérer des arcs d'un graphe.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Mai 2023
 *********************************************************************/

#ifndef C_ARC_H
#define C_ARC_H 10

#include <iostream>
#include <fstream>
#include "CException.h"
using namespace std;

class CArc
{
private:

	/******** Attributs *********/

	unsigned int uiARCDestination;


public:

	/******** Constructeur *******/

	CArc();
	/* Constructeur par défaut de la classe.
	E : néant
	Nécessite : néant
	S : néant
	Entraîne : L'arc est initialisé.
	*/

	CArc(const CArc &ARCParam);
	/* Constructeur de recopie de la classe.
	E : Objet CArc
	Nécessite : néant
	S : néant
	Entraîne : L'arc est initialisé à partir d'un objet CArc donné.
	*/

	CArc(unsigned int uiDestParam);
	/* Constructeur de confort de la classe qui crée un arc à partir d'une destination donnée.
	E : Numéro du sommet de destination
	Nécessite : néant
	S : néant
	Entraîne : L'arc est initialisé à partir d'une destination donnée.
	*/

	/******** Méthodes *******/

	const unsigned int ARCLireDestination();
	/* Cette fonction permet de consulter la destination d'un arc.
	E : néant
	Nécessite : néant
	S : Numéro du sommet de destination
	Entraîne : La destination de l'arc est retournée.
	*/

	void ARCModifierDestination(unsigned int uiDestParam);
	/* Cette fonction permet de modifier la destination d'un arc.
	E : Nouveau numéro de sommet de destination
	Nécessite : néant
	S : néant
	Entraîne : La destination de l'arc est modifiée.
	*/

};

#include "CArc.ipp"
#endif