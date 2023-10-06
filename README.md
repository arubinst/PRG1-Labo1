# Laboratoire de PRG1 - Montant en toutes lettres 

# OBJECTIFS PÉDAGOGIQUES

* Conception et mise en oeuvre de fonctions
* Approfondissement de la notion de tests et décision

# DESCRIPTION DU PROBLÈME

Le but de ce laboratoire est de créer une fonction qui reçoit en entrée un nombre réel au format double, et retourne une chaine de caractères au format string contenant le montant correspondant exprimé en francs et centimes. Le français utilisé est celui utilisé dans le canton de Vaud, donc septante, huitante et nonante pour 70, 80 et 90.

La fonction doit traiter correctement toutes les valeurs entre 0 franc et neuf-cent-nonante-neuf-milliards-neuf-cent-nonante-neuf-millions-neuf-cent-nonante-neuf-mille-neuf-cent-nonante-neuf francs et nonante-neuf centimes, en respectant les règles de la grammaire française. Cependant, n'utilisez pas les accents. Ecrivez donc zero et pas zéro.

EXEMPLES

    0.00
    zero franc
    0.01
    un centime
    0.71
    septante-et-un centimes
    1.89
    un franc et huitante-neuf centimes
    2.90
    deux francs et nonante centimes
    16.56
    seize francs et cinquante-six centimes
    100.00
    cent francs
    200.34
    deux-cents francs et trente-quatre centimes
    567.89
    cinq-cent-soixante-sept francs et huitante-neuf centimes
    234567.89
    deux-cent-trente-quatre-mille-cinq-cent-soixante-sept francs et huitante-neuf centimes
    500500.00
    cinq-cent-mille-cinq-cents francs
    123456789012.34
    cent-vingt-trois-milliards-quatre-cent-cinquante-six-millions-sept-cent-huitante-neuf-mille-douze francs et trente-quatre centimes

# INSTRUCTIONS

Il faut que votre fonction `montantEnToutesLettres` passe tous les tests 

Vous devez découper votre code en plusieurs fonctions, de manière à éviter toute duplication de code.
Vous n'avez pas le droit d'utiliser de tableau ou de structures similaires. Utilisez une fonction contenant 
un switch pour un résultat similaire.

# Rendu

Le rendu doit être fait avant le jeudi 12.10.2023 au soir, à 23:59. Sur votre repo github, indiquez une 'release' en cliquant sur 'Create a new release' dans la barre de navigation droite du repo. Utilisez le tag `rendu` qui pointe sur votre dernier commit - c'est celui-ci qui sera corrigé. Les commits effectués après celui-ci seront ignorés.
