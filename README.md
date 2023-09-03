# QR code augmenté

![Language](https://img.shields.io/badge/Language-C++-blue.svg)
![Librairies](https://img.shields.io/badge/Librairies-OpenCV-green.svg)
![IDE](https://img.shields.io/badge/IDE-Visual%20Studio%202022-red.svg)

## Description

Le but du projet est de générer un code QR augmenté qui regroupe 4 codes QR. Il s’agit d’insérer dans un code QR (code porteur) 3 autres codes QR invisibles. Après l’étape d’insertion, l’image obtenue est un code QR augmenté qui peut être décodé.

Pour le détail des méthodes d'insertion et de décodage, voir le [pdf](assets/Projet.pdf).

## Démonstration

Dans la vidéo, on peut voir le code porteur, les 3 codes invisibles et le code augmenté. Le code augmenté est décodé et les 3 codes invisibles dont le porteur sont affichés.

![Démonstration](demo.gif)

## Installation

Dans les paramètres du projet :

C/C++ > Général > Autres répertoires include : Ajouter le chemin vers le dossier include de la bibliothèque OpenCV

Éditeur de liens > Général > Répertoires de bibliothèques supplémentaires : Ajouter le chemin vers le dossier lib de la bibliothèque OpenCV

Éditeur de liens > Entrée > Dépendances supplémentaires : Ajouter les librairies suivantes :

opencv_world460d.lib
opencv_world460.lib

Pour lancer le projet, il suffit de mettre dans le dossier "input" 4 QR Codes de même taille avec les noms suivants :
 - qr1
 - qr2
 - qr3
 - qrPorteur
 
 Tous au format PNG.