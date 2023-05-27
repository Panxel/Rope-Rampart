# Rope-Rampart

![Image de jeu](Images/jeu.png)

Code source du jeu Rope Rampart, un jeu de défense d'un château avec 2 personnages liés par une corde !

## Pré-requis

* C++
* SFML

### Installation de SFML

Pour installer la bibliothèque SFML, tapez cette commande sur votre terminal : 

 ```sudo apt install libsfml-dev```


## Compilation et exécution

Une fois que vous avez mis le repository sur votre pc notamment grâce à la commande :

```git clone https://github.com/Panxel/Rope-Rampart.git```

Vous pouvez commencer à jouer au jeu !

* Pour compiler le programme, tapez la commande

```make ```

* Pour lancer le programme, tapez la commande

```./main```

## But du jeu

Le jeu est le suivant :

C'est un jeu à deux joueurs dont le but est de défendre le château des vagues de robots. Le jeu se termine si le château est détruit ou si un des deux joueurs meurt. Bien sûr, pour rendre le jeu plus original et plus difficile, les deux joueurs sont attachés par une corde empêchant de s'éloigner l'un de l'autre.
 
Le jeu se déroule dans une carte 2D vue de dessus avec dans le coin à droite une minimap pour voir l'arrivée des robots.

## Controle du jeu

Chaque joueur se déplace en utilisant 4 touches du clavier :

* Le 1er joueur se contrôle avec les flèches directionnelles et attaque avec la barre d'espace

![touches directionnels](Images/joueur1.jpg)

* Le 2eme joueur se contrôle avec les touches ZQSD et attaque avec la touche A

![image](Images/joueur2.jpg)


## Remarque

Le jeu devient de plus en plus dur au fil des vagues avec plus de robots et de "Bombot".


## Documentation

La documentation du code se trouve dans le dossier Documentation