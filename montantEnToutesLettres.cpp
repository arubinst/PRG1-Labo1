#include <string>
#include "math.h"

using namespace std;

string checkPlurial(string sentence) {
    const string search = "cents";
    const string replace = "cent";
    if (sentence.find(search) != string::npos) {
        return sentence.replace(sentence.find(search), search.length(), replace);
    }
    return sentence;
}

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

string conversion(long long montant) {

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
        if (conversion(unite) == "un") {
            return conversion(dizaine) + "-et-" + conversion(unite);
        }
        return conversion_valeur(dizaine) + '-' + conversion(unite);
// Centaines------------------------------------------------------------------------------------------------------------
    } else if (montant < 1000) {
        long centaine = montant / 100;
        long reste = montant % 100;
        if (centaine == 1) {
            if (reste == 0) {
                return "cent";
            }
            return "cent-" + conversion(reste);
        }
        if (centaine > 1 && reste == 0) {
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
            return conversion(millier) + "-mille";
        }
        return checkPlurial(conversion(millier) + "-mille-" + conversion(reste));
    }
// Million--------------------------------------------------------------------------------------------------------------
    else if (montant < 1000000000) {
        int million = montant / 1000000;
        int reste = montant % 1000000;

        if (million == 1 && reste == 0) {
            return "un-million de ";
        }
        if (million == 1) {
            return "un-million-" + conversion(reste);
        }
        if (reste == 0) {
            return conversion(million) + "-millions" + " de";
        }
        return checkPlurial(conversion(million) + "-millions-" + conversion(reste));
    }
// Milliard-------------------------------------------------------------------------------------------------------------
    else if (montant < 1000000000000) {
        long long int milliard = montant / 1000000000;
        long long int reste = montant % 1000000000;
        if (milliard == 1 && reste == 0) {
            return "un-milliard";
        }
        if (milliard == 1) {
            return "un-milliard-" + conversion(reste);
        }
        if (reste == 0) {
            return conversion(milliard) + "-milliards";
        }
        return checkPlurial(conversion(milliard) + "-milliards-" + conversion(reste));
    }
// Valeur trop grande---------------------------------------------------------------------------------------------------

    else {
        throw "Une valeur d'argument trop grande est arrivee dans la fonction Conversion()";
    }
}

// ---------------------------------------------------------------------------------------------------------------------
string montantEnToutesLettres(long double montant) {
    // Séparation de la partie entière et décimal du montant
    long int intergerPart = static_cast<long int> (montant);
    long int valeurMil = static_cast<int>(montant * 1000);
    long int troisiemeDecimale = valeurMil % 10;
    int decimalPart = static_cast<int>((montant - floor(montant)) * 100);

    if (decimalPart != 0) {
        if ((troisiemeDecimale <= 4) && (troisiemeDecimale > 0)) {
            valeurMil -= troisiemeDecimale;
        } else if (troisiemeDecimale >= 5) {
            valeurMil += (10 - troisiemeDecimale);
            if (valeurMil == 1000) {
                decimalPart = 0;
                intergerPart++;
            } else if (valeurMil >= 1000) {
                if (decimalPart == 99) {
                    decimalPart = 0;
                    intergerPart++;
                } else {
                    decimalPart++;
                }
            }
        } else {
            decimalPart = (valeurMil / 10) % 100;
        }
    }
    //long reste_montant = (montant - entier_montant) * 100;
    if (montant < 0) {
        return "erreur : montant negatif";
    }
    if (montant > 999999999999) {
        return "erreur : montant trop grand";
    }
    if (intergerPart == 0 && decimalPart == 0) {
        return "zero franc";
    }
    string resultat;
    if (intergerPart != 0) {
        resultat += conversion(intergerPart) + (intergerPart > 1 ? " francs" : " franc");
    }
    if (decimalPart != 0) {
        if (intergerPart != 0) {
            resultat += " et ";
        }
        resultat += conversion(decimalPart) + (decimalPart > 1 ? " centimes" : " centime");
    }

    return resultat;
}
