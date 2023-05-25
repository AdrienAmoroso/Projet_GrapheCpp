/*****************************************************************//**
 * \file   CException.h
 * \brief  Interface de la classe CException.
 *		   Cette classe permet de cr�er des objets qui sont remont�s
 *		   lors de la lev�e d�exceptions dans le programme.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/

#ifndef EXCEP_H
#define EXCEP_H 11

#include <iostream>
using namespace std;

// D�finition de la valeur initiale d�une exception
#define PAS_ERREUR 0
#define ENTRER_VALEUR 106


class CException
{
	/******** Attributs *********/

private:
	unsigned int uiEXCValeur; // Variable contenant la valeur de l'exception

public:

	/******** Constructeurs - Destructeur *********/

	CException();
	/* Constructeur par d�faut de la classe CException qui permet d'initialiser un objet.
		E : n�ant
		N�cessite : n�ant
		S : n�ant
		Entra�ne : L'exception est initialis�e � PAS_ERREUR.
	*/
	~CException() {}
	/* Destructeur de la classe CException.
		E : n�ant
		N�cessite : n�ant
		S : n�ant
		Entra�ne : L'exception est d�truite.
	*/


	/******** M�thodes *********/


	const unsigned int EXCLireValeur();
	/* Cette fonction permet de consulter la valeur de l�exception.
		E : n�ant
		N�cessite : n�ant
		S : Valeur de l'exception
		Entra�ne : La valeur de l'exception est retourn�e.
	*/
	void EXCModifierValeur(unsigned int uiNvValeur);
	/* Cette fonction permet de modifier la valeur de l�exception.
		E : Nouvelle valeur
		N�cessite : n�ant
		S : n�ant
		Entra�ne : La valeur de l'exception est modifi�e.
	*/
	void EXCAfficherErreur();
	/* Cette fonction permet d'afficher un message d'erreur.
		E : n�ant
		N�cessite : n�ant
		S : n�ant
		Entra�ne : Un message d'erreur est affich�.
	*/
};
#include "CException.ipp"

#endif