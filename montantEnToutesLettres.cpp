#include "montantEnToutesLettres.h"
#include <cmath>

//# TODO : ask if okay to use English as their func are named in french
using namespace std;


long double roundFractional(long double amount);

long long separator(long double amount, bool decimalOrFractional);

string convertUnit(int unit);

string convertSpecial(int special);

string convertTens(int tens);

string tensToText(int smallInt);

string hundredsToText(int hundred, bool mille_after);

string numberToText(long long int number);

string agregator(long long int decimal, long int fractional);

string isNumberInRange(long double amount);


string convertUnit(int unit) {
    switch (unit) {
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
        default:
            return "";
    }
}

string convertSpecial(int special) {
    switch (special) {
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
        default:
            return "";
    }
}

string convertTens(int tens) {
    switch (tens) {
        case 1:
            return "dix";
        case 2:
            return "vingt";
        case 3:
            return "trente";
        case 4:
            return "quarante";
        case 5:
            return "cinquante";
        case 6:
            return "soixante";
        case 7:
            return "septante";
        case 8:
            return "huitante";
        case 9:
            return "nonante";
        default:
            return "";
    }
}

string tensToText(int smallInt) {
//    0-99
    if (smallInt < 10) {
        return convertUnit(smallInt);
    } else if (smallInt <= 16) {
        return convertSpecial(smallInt);
    }

    int quotient = smallInt / 10;
    int rest = smallInt % 10;

    if (rest == 0) {
        return convertTens(quotient);
    } else {
        string separator = (rest == 1 ? "-et-" : "-");
        return convertTens(quotient) + separator + tensToText(rest);
    }
}

string hundredsToText(int hundred, bool mille_after = false) {
//    0-999
    int quotient = hundred / 100;
    int rest = hundred % 100;

    if (quotient == 0) {
        return tensToText(hundred);
    }

    string cent = (quotient > 1 && rest == 0 && !mille_after ? "cents" : "cent");
    string tens = (rest == 0 ? "" : "-" + tensToText(rest));
    if (quotient == 1) {
        return cent + tens;
    } else {
        return convertUnit(quotient) + "-" + cent + tens;
    }
}

const int one_billion = 1e9,
        one_million = 1e6,
        one_thousand = 1e3;

string numberToText(long long int number) {
    string number_text;

    int order = number / one_billion;
    long int rest = number - order * one_billion;
    if (order >= 1) {
        number_text += hundredsToText(order) + "-milliard" + (order > 1 ? "s" : "") + (rest != 0 ? "-" : " de");
    }

    order = rest / one_million;
    rest -= order * one_million;
    if (order >= 1) {
        number_text += hundredsToText(order) + "-million" + (order > 1 ? "s" : "") + (rest != 0 ? "-" : " de");
    }

    order = rest / one_thousand;
    rest -= order * one_thousand;
    if (order == 1) {
        number_text = number_text + "mille" + (rest != 0 ? "-" : "");
    } else if (order >= 1) {
        number_text += hundredsToText(order, true) + "-mille" + (rest != 0 ? "-" : "");
    }

    if (rest >= 1 or number == 0) {
        number_text += hundredsToText(rest);
    }

    return number_text;
}

string agregator(long long int decimal, long int fractional) {

    string result;
    string beforeComma = numberToText(decimal);
    string afterComma = numberToText(fractional);

    if (fractional == 0) {
        return beforeComma + (decimal <= 1 ? " franc" : " francs");
    } else if (decimal == 0) {
        return afterComma + (fractional <= 1 ? " centime" : " centimes");
    } else {
        return beforeComma + (decimal <= 1 ? " franc et " : " francs et ") + afterComma +
               (fractional <= 1 ? " centime" : " centimes");
    }
    return "ERROR";
}

long double roundFractional(long double amount) {

    return round(amount * 100) / 100;
}


long long int separator(long double amount, bool decimalOrFractional) {
    // Fractional == False,  Decimal == True
    long double decimalPart;
    long double fractionalPart = modf(roundFractional(amount), &decimalPart);

    if (decimalOrFractional) {
        return static_cast<long long int>(decimalPart);
    } else {
        fractionalPart = roundFractional(fractionalPart);//added for fix rounding error of c++
        fractionalPart *= 100;
        return fractionalPart;
    }
}


string isNumberInRange(long double amount) {
    string flag;
    if (amount < 0) {
        flag = "erreur : amount negatif";
    } else if (amount > 999'999'999'999.99) {
        flag = "erreur : amount trop grand";
    } else {
        flag = "";
    }
    return flag;
}


string montantEnToutesLettres(long double montant) {
    if (isNumberInRange(montant) != "") {
        return isNumberInRange(montant);
    }
    return agregator(separator(montant, true), separator(montant, false));
}