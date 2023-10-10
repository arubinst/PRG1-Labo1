#include <string>
using namespace std;

string conversion_valeur(int number) {
    switch (number) {
        case 0:
            return "zero";
        case 1:
            return "un";
        case 2:
            return "deux";
        case 3:
            return "trois";
        case 4:
            return "quatre";
        case 5:
            return "cinq";
        case 6:
            return "six";
        case 7:
            return "sept";
        case 8:
            return "huit";
        case 9:
            return "neuf";
        case 10:
            return "dix";
        case 11:
            return "onze";
        case 12:
            return "douze";
        case 13:
            return "treize";
        case 14:
            return "quatorze";
        case 15:
            return "quinze";
        case 16:
            return "seize";
        case 20:
            return "vingt";
        case 30:
            return "trente";
        case 40:
            return "quarante";
        case 50:
            return "cinquante";
        case 60:
            return "soixante";
        case 70:
            return "septante";
        case 80:
            return "huitante";
        case 90:
            return "nonante";
        default:
            throw "Une valeur d'argument du switch de conversion() invalide à été saisie";
    }
}

string conversion(long montant) {

// 1 à 16---------------------------------------------------------------------------------------------------------------
    if (montant <= 16) {
        return conversion_valeur(montant);
// Dizaines-------------------------------------------------------------------------------------------------------------
    } else if (montant < 100) { // Dizaine OK
        int unite = montant % 10;
        int dizaine = montant - unite;
        if (unite == 0) {
            return conversion_valeur(dizaine);
        }
        return conversion_valeur(dizaine) + '-' + conversion(unite);
// Centaines------------------------------------------------------------------------------------------------------------
    } else if (montant < 1000) {
        int centaine = montant / 100;
        int reste = montant % 100;
        if (centaine == 1) {
            if (reste == 0) {
                return "cent";
            }
            return "cent-" + conversion(reste);
        }
        if (reste == 0) {
            return conversion(centaine) + "-cents";
        }
        return conversion(centaine) + "-cent-" + conversion(reste);

    }
// Milliers-------------------------------------------------------------------------------------------------------------
    else if (montant < 1000000) {
        int millier = montant / 1000;
        int reste = montant % 1000;
        if (millier == 1) {
            if (reste == 0) {
                return "mille";
            }
            return "mille-" + conversion(reste);
        }
        if (reste == 0) {
            return conversion(millier) + "-milles";
        }
        return conversion(millier) + "-mille-" + conversion(reste);
    }
// Million--------------------------------------------------------------------------------------------------------------
    else if (montant < 1000000000) {
        int million = montant / 1000000;
        int reste = montant % 1000000;

        if (million == 1 && reste == 0) {
            return "un-millions";
        }
        if (reste == 0) {
            return conversion(million) + "-millions";
        }
        return conversion(million) + "-million-" + conversion(reste);
    }
// Milliard-------------------------------------------------------------------------------------------------------------
    else if (montant < 1000000000000) {
        int milliard = montant / 1000000000;
        int reste = montant % 1000000000;
        if (milliard == 1 && reste == 0) {
            return "un-milliard";
        }
        if (reste == 0) {
            return conversion(milliard) + "-milliards";
        }
        return conversion(milliard) + "-milliard-" + conversion(reste);
    }
// Valeur trop grande---------------------------------------------------------------------------------------------------

    else {
        return "Entrée trop grande";
    }
}
//----------------------------------------------------------------------------------------------------------------------
string montantEnToutesLettres(long double montant) {
    // Séparation de la partie entière et décimal du montant
    long entier_montant = montant;
    long reste_montant = (montant - entier_montant) * 100;
    string resultat = "";

    if (entier_montant == 0 && reste_montant == 0) {
        return "zero franc";
    }

    if (entier_montant != 0) {
        resultat += conversion(entier_montant) + (entier_montant > 1 ? " francs" : " franc");
    }

    if (reste_montant != 0) {
        if (entier_montant != 0) {
            resultat += " et ";
        }
        resultat += conversion(reste_montant) + (reste_montant > 1 ? " centimes" : " centime");
    }

    return resultat;
}


// (;,;)