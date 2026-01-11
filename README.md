RAPPORT TRAVAUX PRATIQUES: CMAKE



Réalisé par: Cédric NTCHOUERE LEBANI 
Date de réalisation: 11/01/2026 
Tuteur référent: Aymard DJASRABE




1. INTRODUCTION

Le TP7 a pour objectif de découvrir et d'utiliser CMake, l'un des systèmes de build les plus utilisés pour des projets C et C++.
L'exercise ici consiste à :
- créer un premier projet minimal avec CMake (HelloWorld)
- reconstruire entièrement le TP6(librairies statiques et dynamiques + exécutable)
- remplacer la compilation manuelle et le Makefile par une configuration CMake complète
- produire une structure du projet, propre et modulaire
- expliquer clairement le fonctionnement de CMake et des fichiers CMakeLists.txt

En resumé, ce rapport présente la structure du projet, les choix technique, les fichiers CMake utilisés, ainsi que les étapes de compilation et d'exécution.
L'objectif final est donc de démontrer une compréhension solide de CMake et de produire un projet conforme aux pratiques professionnelles.



2. STRUCTURE DU PROJET

Le projet TP7 est organisé en deux sous-projets distincts :

- `helloworld/` : projet minimal pour valider l’utilisation de CMake  
- `calculatrice/` : projet complet basé sur le TP6, avec librairies statiques et dynamiques

Arborescence du projet `calculatrice/` :

```
calculatrice/
├── CMakeLists.txt
├── .gitignore
└── src/
    ├── app/
    │   └── main.c
    └── lib/
        ├── staticCalculatrice/
        │   ├── static_calculatrice.c
        │   └── static_calculatrice.h
        └── dynamicCalculatrice/
            ├── dynamic_calculatrice.c
            └── dynamic_calculatrice.h
````

Cette structure respecte les bonnes pratiques de modularisation :

- chaque librairie est isolée dans son propre dossier  
- les headers sont placés avec les sources pour simplifier l’inclusion  
- le dossier `app/` contient uniquement le point d’entrée (`main.c`)  
- le fichier `CMakeLists.txt` principal orchestre la compilation de l’ensemble  
- le fichier `.gitignore` empêche les fichiers générés de polluer le dépôt

Ce découpage permet une compilation propre, une maintenance facilitée, et une extension future du projet.




3. COMPRENDRE CMAKE

CMake est un système de build moderne utilisé pour configurer, générer et organiser la compilation de projets C et C++.  
Contrairement à un Makefile écrit manuellement, CMake :

- détecte automatiquement l’environnement de compilation  
- génère un système de build adapté (Makefile, Ninja, Visual Studio…)  
- gère les dépendances entre fichiers  
- facilite la création de projets modulaires  
- simplifie la gestion des librairies statiques et dynamiques  

3.1. Deux étapes distinctes : configuration et compilation

CMake fonctionne toujours en deux phases :

1. Configuration 
   CMake lit les fichiers `CMakeLists.txt` et génère un système de build.  
   Exemple :

   ```
   cmake ..
   ```

2. Compilation 
   Le système de build généré compile réellement le projet.  
   Exemple :

   ```
   cmake --build .
   ```

Cette séparation permet une compilation propre, reproductible et indépendante du code source.

3.2. Le rôle du fichier `CMakeLists.txt`

Chaque dossier important du projet contient un fichier `CMakeLists.txt` qui décrit :

- le nom du projet  
- les fichiers sources  
- les librairies à créer  
- les dépendances  
- les options de compilation  
- les chemins des headers  

CMake lit ces fichiers de manière hiérarchique, ce qui permet une organisation modulaire du projet.

3.3. Avantages de CMake dans ce TP

L’utilisation de CMake dans ce TP apporte plusieurs bénéfices :

- compilation automatique des librairies statiques (`.a`) et dynamiques (`.so`)  
- gestion propre des dépendances entre modules  
- structure claire et extensible  
- possibilité de compiler sur n’importe quel système (Linux, Windows, macOS)  
- séparation nette entre code source et fichiers générés (`build/`)  

CMake remplace donc efficacement le Makefile du TP6 et prépare le projet à une organisation professionnelle.





4. EXPLICATION DETAILLEE DES FICHIERS CMakeLists.txt

Le projet `calculatrice/` repose sur trois fichiers `CMakeLists.txt` distincts.  
Chaque fichier joue un rôle précis dans la configuration, la compilation et l’assemblage du projet.  
Cette architecture modulaire est typique des projets professionnels utilisant CMake.



4.1. Le CMakeLists principal (racine du projet)**

Ce fichier est le **point d’entrée** de CMake.  
Il définit la configuration globale et orchestre la compilation de l’ensemble du projet.

Son rôle :

- définir la version minimale de CMake  
- déclarer le projet (`project(Calculatrice C)`)  
- ajouter les sous-dossiers contenant les librairies  
- créer l’exécutable principal  
- définir les chemins d’inclusion  
- lier l’exécutable aux librairies statique et dynamique  

 Pourquoi c’est important ?

Ce fichier ne compile rien directement.  
Il décrit la structure logique du projet et dit à CMake :

- où sont les modules  
- comment ils doivent être compilés  
- comment ils doivent être liés ensemble  

C’est l’équivalent d’un *Makefile maître*, mais beaucoup plus flexible.



4.2. CMakeLists de la librairie statique

Ce fichier déclare une librairie statique avec :

```
add_library(staticCalculatrice STATIC ...)
```

 Son rôle :

- compiler les fichiers `.c` en objets `.o`  
- assembler ces objets dans une archive `.a`  
- exposer le dossier comme chemin d’inclusion (`target_include_directories`)  

 Pourquoi c’est important ?

Une librairie statique :

- est intégrée directement dans l’exécutable final  
- ne nécessite pas de chargement dynamique  
- garantit que le code est embarqué dans le binaire  

C’est idéal pour les fonctions simples, stables, et peu susceptibles de changer.


4.3. CMakeLists de la librairie dynamique

Ce fichier déclare une librairie dynamique avec :

```
add_library(dynamicCalculatrice SHARED ...)
```

 Son rôle :

- compiler les sources en objets  
- générer un fichier `.so` (shared object)  
- exposer le dossier comme chemin d’inclusion  

 Pourquoi c’est important ?

Une librairie dynamique :

- est chargée au moment de l’exécution  
- peut être mise à jour sans recompiler l’exécutable  
- permet une modularité avancée  
- réduit la taille du binaire final  

C’est typiquement utilisé pour des modules évolutifs ou interchangeables.



4.4. Comment CMake assemble le projet

Voici le processus complet :

1. Le CMakeLists principal appelle les sous-dossiers :  
   ```
   add_subdirectory(staticCalculatrice)
   add_subdirectory(dynamicCalculatrice)
   ```

2. Chaque sous-dossier compile **sa propre librairie** :
   - `libstaticCalculatrice.a`
   - `libdynamicCalculatrice.so`

3. CMake compile ensuite l’exécutable `calculatrice`.

4. L’exécutable est lié aux deux librairies via :  
   ```
   target_link_libraries(calculatrice PRIVATE staticCalculatrice dynamicCalculatrice)
   ```

5. Le dossier `build/` contient alors :
   - les librairies compilées  
   - l’exécutable final  
   - les fichiers générés par CMake  



4.5. Pourquoi cette architecture est professionnelle

Cette organisation :

- sépare clairement les responsabilités  
- permet de réutiliser les librairies dans d’autres projets  
- facilite les tests unitaires  
- rend le projet extensible (ajout d’autres modules, options, flags…)  
- respecte les standards de l’industrie logicielle  

C’est exactement la structure utilisée dans les projets C/C++ modernes.





5. COMPILATION ET EXECUTION DU PROJET

Le projet utilise CMake pour générer un système de build propre et indépendant du code source.  
Toutes les étapes se déroulent dans un dossier séparé appelé `build/`, conformément aux bonnes pratiques.



5.1. Génération du dossier de build

Depuis la racine du projet `calculatrice/` :

```
mkdir build
cd build
```

Ce dossier contiendra tous les fichiers générés par CMake (Makefile, objets, librairies, exécutable…).


5.2. Configuration du projet

```
cmake ..
```

Cette commande :

- lit les fichiers `CMakeLists.txt`  
- détecte l’environnement de compilation  
- génère un système de build adapté (Makefile dans ce TP)  
- configure la compilation des librairies et de l’exécutable  



5.3. Compilation du projet

```
cmake --build .
```

CMake compile alors :

- la librairie statique → `libstaticCalculatrice.a`  
- la librairie dynamique → `libdynamicCalculatrice.so`  
- l’exécutable → `calculatrice`  

Tous ces fichiers apparaissent dans le dossier `build/`.



5.4. Exécution du programme

Comme l’exécutable dépend d’une librairie dynamique (`.so`), il faut indiquer à Linux où la trouver :

```
LD_LIBRARY_PATH=src/lib/dynamicCalculatrice ./calculatrice
```

Le programme s’exécute alors normalement et affiche :

- le résultat via la librairie statique  
- le résultat via la librairie dynamique  



5.5. Pourquoi ce workflow est propre

- le code source reste dans `src/`  
- les fichiers générés restent dans `build/`  
- aucune pollution du dépôt Git  
- compilation reproductible  
- structure conforme aux standards professionnels  






6. CONCLUSION

Ce TP7 a permis de mettre en place une structure de projet, disons-le , professionnelle en utilisant CMake, un outil largement adopté pour la gestion de projets C et C++.  
L’ensemble du travail réalisé démontre :

- la capacité à organiser un projet en modules cohérents  
- la maîtrise de la création et de l’intégration de librairies statiques et dynamiques  
- la compréhension du rôle des fichiers `CMakeLists.txt`  
- la mise en place d’un workflow de compilation propre et reproductible  
- l’utilisation correcte d’un dossier `build/` pour isoler les fichiers générés  
- la gestion d’un dépôt Git structuré et lisible  

Le passage du Makefile du TP6 à une configuration CMake moderne constitue une étape importante vers des pratiques de développement plus robustes, plus maintenables et plus proches des standards professionnels.

Ce projet fournit désormais une base solide pour aller plus loin comme : ajout de tests unitaires, options de compilation, documentation automatisée, ou intégration continue.  
CMake ouvre la voie à des projets plus complexes et mieux structurés.




NTCHOUERE LEBANI Cedric
Aspirant développeur systèmes et réseaux
Email: cedriclebani@gmail.com Tel:+241077710608













