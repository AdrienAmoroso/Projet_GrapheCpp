/*****************************************************************//**
 * \file   CException.ipp
 * \brief  Corps de la classe CException.
 *		   Cette classe permet de cr�er des objets qui sont remont�s
 *		   lors de la lev�e d�exceptions dans le programme.
 * \version 1.0
 * \author Adrien AMOROSO et Valentin DESMARES
 * \date   Avril 2023
 *********************************************************************/


/**************************************************************
Nom : EXCModifierValeur
***************************************************************
Cette fonction permet de modifier la valeur de l�exception.
***************************************************************
Entr�e : La nouvelle valeur de l�exception
N�cessite : n�ant
Sortie : n�ant
Entra�ne : L�exception est modifi�e.
***************************************************************/
inline void CException::EXCModifierValeur(unsigned int uiNvValeur)
{
	uiEXCValeur = uiNvValeur;
}

/**************************************************************
Nom : EXCLireValeur
***************************************************************
Cette fonction permet de consulter la valeur de l�exception.
***************************************************************
Entr�e : n�ant
N�cessite : n�ant
Sortie : La valeur de l�exception
Entra�ne : La valeur de l'exception est retourn�e.
***************************************************************/
inline const unsigned int CException::EXCLireValeur()
{
	return(uiEXCValeur);
}