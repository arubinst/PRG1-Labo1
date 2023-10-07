#include "montantEnToutesLettres.h"
using namespace std;

const string pluriel = "s";
const string zero = "zero";
const string un = "un";
const string deux = "deux";
const string trois = "trois";
const string quatre = "quatre";
const string cinq = "cinq";
const string six = "six";
const string sept = "sept";
const string huit = "huit";
const string neuf = "neuf";
const string dix = "dix";
const string onze = "onze";
const string douze = "douze";
const string treize = "treize";
const string quatorze = "quatorze";
const string quinze = "quinze";
const string seize = "seize";
const string vingt = "vingt";
const string trente = "trente";
const string quarante = "quarante";
const string soixante = "soixante";
const string nonante = "nonante";
const string cent = "cent";
const string mille = "mille";
const string million = "million";
const string milliard = "milliard";


// Checker nombre
bool montantEnToutesLettres(const string &entree) {
    for (char c : entree) {
        if (c < '0' || c > '9') {
            return false; // Ce n'est pas un chiffre
        }
    }
    return true; // Tous les caractères étaient des chiffres
}

// Compter les digits
int nombre_de_chiffres = to_string(n).length();

/* Fonction qui va regarder si le montant contient une '.' et
 => si oui va le splitter par 3 (XXX XXX XXX XXX .XX) avant la virgule et après
 */



string montantEnToutesLettres(long double montant) {
    string result = to_string(montant);
    for (int i = 0; i < result.length(); ++i) {
        if (result[i] == '.') {
        } else {

        }
    }
    return result;
}



