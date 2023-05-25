/*****************************************************************//**
 * \file   CArc.h
 * \brief  Interface de la classe CArc.
 *		   Cette classe permet de cr�er et de g�rer des arcs d'un graphe.
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
	/* Constructeur par d�faut de la classe.
	E : n�ant
	N�cessite : n�ant
	S : n�ant
	Entra�ne : L'arc est initialis�.
	*/

	CArc(const CArc &ARCParam);
	/* Constructeur de recopie de la classe.
	E : Objet CArc
	N�cessite : n�ant
	S : n�ant
	Entra�ne : L'arc est initialis� � partir d'un objet CArc donn�.
	*/

	CArc(unsigned int uiDestParam);
	/* Constructeur de confort de la classe qui cr�e un arc � partir d'une destination donn�e.
	E : Num�ro du sommet de destination
	N�cessite : n�ant
	S : n�ant
	Entra�ne : L'arc est initialis� � partir d'une destination donn�e.
	*/

	/******** M�thodes *******/

	const unsigned int ARCLireDestination();
	/* Cette fonction permet de consulter la destination d'un arc.
	E : n�ant
	N�cessite : n�ant
	S : Num�ro du sommet de destination
	Entra�ne : La destination de l'arc est retourn�e.
	*/

	void ARCModifierDestination(unsigned int uiDestParam);
	/* Cette fonction permet de modifier la destination d'un arc.
	E : Nouveau num�ro de sommet de destination
	N�cessite : n�ant
	S : n�ant
	Entra�ne : La destination de l'arc est modifi�e.
	*/

};

#include "CArc.ipp"
#endif