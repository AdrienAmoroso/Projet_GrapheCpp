# Projet C++ : Les Graphes

L'objectif de ce projet est de réaliser une librairie de classes et fonctions permettant de manipuler des graphes. 
En effet, les classes réalisées permettent : 
1. De créer des graphes orientés ou non orientés,
2. De faire des opérations "élémentaires" sur un graphe,
3. D'afficher à l'écrand un graphe

## Contraintes techniques 

Pour la réalisation de notre projet, nous avons respecté les quelques contraintes énoncées ci-dessous :
1. Les variables, types, classes, fonction et méthodes respectent les conventions de nommage,
2. Les bonnes pratiques du Génie Logiciel telles qu’elles ont pu être présentées lors des cours d’Algorithmes Orientés Objets et de Langages Orientés Objets ont été mises en œuvre.
3. Nous avons intégré la gestion des exceptions dans notre programme : nous avons utilisé pour cela la classe Cexception vue en TPs.
4. Nous avons travaillé sous Visual Studio et notre projet est une application console win32.


## Pour commencer

Voici comment fonctionne la fonction principale du projet :
1. Pour un nom de fichier passé en paramètre, lire le fichier et créer le graphe associé,
2. Afficher le graphe à l’écran,
3. Inverser tous les arcs du graphe pour obtenir un nouveau graphe,
4. Afficher ce nouveau graphe à l’écran.


Les fichiers textes passés en paramètre devront être sous la forme suivante :  
NBSommets=<Nombre_de_Sommets_du_graphe>  
	NBArcs=< Nombre_d_arcs_du_graphe >  
	Sommets=[  
Numero=<Numéro_sommet >  
	Numero=<Numéro_sommet>  
…  
	Numero=<Numéro_sommet>  
]  
Arcs=[  
Debut=<Sommet_départ_arc>, Fin=<Sommet_arrivée_arc>  
Debut=<Sommet_départ_arc>, Fin=<Sommet_arrivée_arc>  
…  
Debut=<Sommet_départ_arc>, Fin=<Sommet_arrivée_arc>  
]  

_exemple_:
NBSommets=3  
NBArcs=3  
Sommets=[  
Numero=1  
Numero=2  
Numero=3  
]  
Arcs=[  
Debut=1, Fin=2  
Debut=2, Fin=3  
Debut=3, Fin=1  
]  


De plus, il est important de noté que le programme ne gère que des graphes orientés.  

## Pré-requis

Aucun pré-requis n'est nécessaire.


## Démarrage

Une fois l'installation terminée, vous pouvez placer l'exécutable `` ProjetC++.exe`` où vous voulez.
Ensuite, pour exécuter correctement le programme, il vous faut entrer dans le terminal le nom de l'exécutable puis le nom des fichiers textes que vous souhaitez lui passer en argument (attention à bien indiquer le chemin des fichiers textes s'ils ne sont pas dans le même répertoire que l'exécutable).

_exemple_: Exécutez la commande ``ProjetC++ G1.txt G2.txt G3.txt G4.txt`` et le programme s'exécutara avec les fichiers G1, G2, G3 et G4 en argument.


## Développé avec

* [Visual Studio 2017](https://visualstudio.microsoft.com/fr/) - IDE


## Auteurs

* **Valentin DESMARES** 
* **Adrien AMOROSO** 

