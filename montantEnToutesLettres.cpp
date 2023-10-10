#include "montantEnToutesLettres.h"
#include <cmath>

using namespace std;


long double roundFractional(long double amount);

long long separator(long double amount, bool isDecimal);

string convertUnit(int unit);

string convertSpecial(int special);

string convertTens(int tens);

string tensToText(int tens);

string hundredsToText(int hundreds, bool isBeforeThousand);

string numberToText(long long int number);

string agregator(long long int decimal, long int fractional);

string isNumberInRange(long double amount);


string convertUnit(int unit) {
    switch (unit) {
        case 0:return "zero";
        case 1:return "un";
        case 2:return "deux";
        case 3:return "trois";
        case 4:return "quatre";
        case 5:return "cinq";
        case 6:return "six";
        case 7:return "sept";
        case 8:return "huit";
        case 9:return "neuf";
        default:return "";
    }
}

string convertSpecial(int special) {
    switch (special) {
        case 10:return "dix";
        case 11:return "onze";
        case 12:return "douze";
        case 13:return "treize";
        case 14:return "quatorze";
        case 15:return "quinze";
        case 16:return "seize";
        default:return "";
    }
}

string convertTens(int tens) {
    switch (tens) {
        case 1:return "dix";
        case 2:return "vingt";
        case 3:return "trente";
        case 4:return "quarante";
        case 5:return "cinquante";
        case 6:return "soixante";
        case 7:return "septante";
        case 8:return "huitante";
        case 9:return "nonante";
        default:return "";
    }
}

string tensToText(int tens) {
//    0-99
    if (tens < 10) {
        return convertUnit(tens);
    } else if (tens <= 16) {
        return convertSpecial(tens);
    }

    int quotient = tens / 10;
    int rest = tens % 10;

    if (rest == 0) {
        return convertTens(quotient);
    } else {
        string separator = (rest == 1 ? "-et-" : "-");
        return convertTens(quotient) + separator + tensToText(rest);
    }
}

string hundredsToText(int hundreds, bool isBeforeThousand = false) {
//    0-999
    int quotient = hundreds / 100;
    int rest = hundreds % 100;

    if (quotient == 0) {
        return tensToText(hundreds);
    }

    string cent = (quotient > 1 && rest == 0 && !isBeforeThousand ? "cents" : "cent");
    string tens = (rest == 0 ? "" : "-" + tensToText(rest));
    if (quotient == 1) {
        return cent + tens;
    } else {
        return convertUnit(quotient) + "-" + cent + tens;
    }
}

const int oneBillion = 1e9,
        oneMillion = 1e6,
        oneThousand = 1e3;

string numberToText(long long int number) {
//    0-999'999'999'999
    string numberText;

    int order = number / oneBillion;
    long int rest = number - order * oneBillion;
    if (order >= 1) {
        numberText += hundredsToText(order) + "-milliard" + (order > 1 ? "s" : "") + (rest != 0 ? "-" : " de");
    }

    order = rest / oneMillion;
    rest -= order * oneMillion;
    if (order >= 1) {
        numberText += hundredsToText(order) + "-million" + (order > 1 ? "s" : "") + (rest != 0 ? "-" : " de");
    }

    order = rest / oneThousand;
    rest -= order * oneThousand;
    if (order == 1) {
        numberText = numberText + "mille" + (rest != 0 ? "-" : "");
    } else if (order >= 1) {
        numberText += hundredsToText(order, true) + "-mille" + (rest != 0 ? "-" : "");
    }

    if (rest >= 1 or number == 0) {
        numberText += hundredsToText(rest);
    }

    return numberText;
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
}

long double roundFractional(long double amount) {
    return round(amount * 100) / 100;
}


long long int separator(long double amount, bool isDecimal) {
    long double decimalPart;
    long double fractionalPart = modf(roundFractional(amount), &decimalPart);

    if (isDecimal) {
        return static_cast<long long int>(decimalPart);
    } else {
        fractionalPart = roundFractional(fractionalPart);  // added to fix rounding error of c++
        fractionalPart *= 100;
        return fractionalPart;
    }
}


string isNumberInRange(long double amount) {
    string flag;
    if (amount < 0) {
        flag = "erreur : montant negatif";
    } else if (amount > 999'999'999'999.99) {
        flag = "erreur : montant trop grand";
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