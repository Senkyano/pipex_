# Projet : PIPEX

## Objectif :
Ce projet consiste a reproduire le fonctionnement des pipes que l'on retrouve sur bash.
### exemple :
````
    < in_file cmd1 | cmd2 > out_file
````
## Partie bonus :
* Reproduire la même choses mais cette fois-ci pour n cmd.
* Mais aussi ajoute la fonctionnalité d'un here_doc.

### exemple :
````
n cmd       < in_file cmd1 | .. | n cmd > out_file
here_doc    cmd1 << LIMITEUR | n cmd > out_file
````
## Mini tuto :
Je vous laisse les grandes lignes.
## Les etapes :
Les choses a prendre en compte, il faut vérifier si on nous a donné assez d'arguments.

Vérifier si notre environnement est valide.

Et bien sure si vous faite la partie bonus il faut voir si notre programme doit tourner en "here_doc" ou non.
### Parsing :
Pour le parsing pour mon cas je les ai mis dans une liste chainée.

#### Env :
Il faut d'abord aller recuperer tout les chemins d'access pour trouver les commandes qui se trouve dans l'environnement, tout les chemins d'access se trouve sur la ligne ou les 5 premiers caractères commence par "PATH=".

Ensuite nous devons differencier chaque chemins. (Utilisation de la fonction ft_split que vous avez coder).

#### Commande :
Nous allons recupérer les commandes dans une structure nous aurons besoins de 3 variables :
* commande + opt
* path + cmd
* valid path_cmd

#### Fichier :
Nous allons voir si nos fichiers sont valide, esque notre fichier d'entrée est valide ou non, ou si le fichier de sortie est valide ou non.
* in_file n'existe pas = erreur.
* out_file n'existe pas = creer le fichier.


### Execution :
Avant d'exécuter les commandes assurer vous bien qu'elle soit fonctionnelle si elle ne l'est pas vous devez passer a la commande suivante sans arréter le programme.
