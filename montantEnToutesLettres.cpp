#include "montantEnToutesLettres.h"
#include <cmath>


//# TODO : ask if okay to use English as their func are named in french
using namespace std;


long double roundFractional(long double montant);

long separator(long double montant, bool decimalOrFractional);

string convertUnit(int unit);

string convertSpecial(int special);

string convertTens(int tens);

string tensToText(int smallInt);

string agregator(long int decimal, long int fractional);

string numbersToLetters(long int number);

string tensPowChecker(int number);

string numbersChunk(long int &number, long int comparator, string denominaotor);


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
            return "dix"; // FIXME : dix already in convertTen, remove one
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
    } else if (smallInt <= 17) {
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

string hundredsToText(int hundred) {
//    0-999
    int quotient = hundred / 100;
    int rest = hundred % 100;

    if (quotient == 0) {
        return tensToText(hundred);
    }

    string cent = (quotient > 1 && rest == 0 ? "cents" : "cent");
    string tens = (rest == 0 ? "" : "-" + tensToText(rest));
    if (quotient == 1) {
        return cent + tens;
    } else {
        return convertUnit(quotient) + "-" + cent + tens;
    }
}


string numbersChunk(long int &number, long int comparator, string denominaotor) {

    long int temp;
    string result;

    if (number >= comparator) {

        temp = number / comparator;
        result += tensPowChecker(temp);
        temp *= comparator;
        result += denominaotor;
        result += (temp - number == 0 ? "" : "-");
        number -= temp;
    }
    return result;
}

string numbersToLetters(long int number) {

    string result;
    result += numbersChunk(number, 1'000'000'000, "-milliard");
    result += numbersChunk(number, 1'000'000, "-million");
    result += numbersChunk(number, 1'000, "-mille");
    result += hundredsToText(number);

    return result;
}

string tensPowChecker(int number) {

    if (number <= 99)
        return tensToText(number);

    if (number <= 999)
        return hundredsToText(number);
    return "error at tensPowChecker";
}

string agregator(long int decimal, long int fractional) {

    string result;
    string beforeComma = numbersToLetters(decimal);
    string afterComma = numbersToLetters(fractional);

    if (fractional == 0) {
        return beforeComma + (decimal <= 1 ? " franc" : " francs");
    } else {
        return beforeComma + (decimal <= 1 ? " franc et " : " francs et ") + afterComma + (fractional <= 1 ? " centime" : " centimes");
    }
    return "ERROR";
}

long double roundFractional(long double montant) {

    return round(montant * 100) / 100;
}


long int separator(long double montant, bool decimalOrFractional) {
    // Fractional == False,  Decimal == True
    long double decimalPart;
    long double fractionalPart = modf(roundFractional(montant), &decimalPart);

    if (decimalOrFractional) {
        return decimalPart;
    } else {
        fractionalPart = roundFractional(fractionalPart);//added for fix rounding error of c++
        fractionalPart *= 100;
        return fractionalPart;
    }
}


//TODO CHECK IF THE VALUE INPUTED IS CORRECT


string montantEnToutesLettres(long double montant) {

    return agregator(separator(montant, true), separator(montant, false));
}