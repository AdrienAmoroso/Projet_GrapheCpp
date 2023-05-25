// main.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "CLecteurFichier.h"
#include "CUtilitaireGraphe.h"
#define MAX_NB_GRAPHES 100


int main(int argc, char* argv[])
{
	cout << "Debut du Programme!\n\n";

	if (argc < 2) {
		cerr << "Aucun nom de fichier n'a ete passe en parametre." << endl;
		return 1;
	}

	// Création des graphes à partir des fichiers 
	unsigned int iTailleListe = argc - 1;
	CGraphe* pGPHListeGraphes[MAX_NB_GRAPHES];
	int iNbGraphe = 0;

	try
	{
		for (int i = 1; i < argc; i++)
		{
			cout << "Fichier : " << argv[i] << endl;

			CLecteurFichier LECGraphe;
			CGraphe GPHGrapheCree = LECGraphe.LECCreerGrapheDepuisFichier(argv[i]);
			pGPHListeGraphes[iNbGraphe++] = new CGraphe(GPHGrapheCree);
		}
	}
	catch (CException EXCErreurFichier)
	{
		EXCErreurFichier.EXCAfficherErreur();
		exit(1);
	}

	// Affichage des graphes
	cout << "Affichage des Graphes : " << endl << endl;
	for (int i = 0; i < iNbGraphe; i++)
	{
		cout << "Graphe numero " << i + 1 << endl;
		pGPHListeGraphes[i]->GPHAfficherGraphe();
	}

	// Affichage des graphes inversés
	cout << "Affichage des Graphes une fois Inverses : " << endl << endl;

	try
	{
		for (int i = 0; i < iNbGraphe; i++)
		{
			cout << "Graphe numero " << i + 1 << endl;
			CUtilitaireGraphe UTIGraphe;
			CGraphe& GPHGrapheInverse = UTIGraphe.UTIInverserGraphe(*pGPHListeGraphes[i]);
			GPHGrapheInverse.GPHAfficherGraphe();
		}
	}
	catch (CException EXCErreurInversion)
	{
		EXCErreurInversion.EXCAfficherErreur();
		exit(1);
	}
}
