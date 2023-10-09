#include <string>
#include <cmath>

using namespace std;

// liste littéraire des unités
string unity(int number) {
    switch (number) {
        case 0:
            return "";
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

string dozenExeptions(int number) {
    switch (number) {
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

// liste littéraire des dizaines
string dozen(int number) {
    switch (number) {
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

// Fonction transformant la valeur numérique en texte
string convertSmallNumber(long double num) {
    int integerPart = (int) num;
    int quotient = integerPart / 10;
    int rest = integerPart % 10;
    string result;

    if (integerPart == 0.00) {
        result += "zero";
    } else if (integerPart < 10) {
        return result += unity(integerPart);
    } else if (integerPart < 17) {
        return result += dozenExeptions(integerPart);
    }
    if (rest == 0) {
        result += dozen(quotient);
    } else {
        if (rest == 1) {
            result += dozen(quotient) + "-et-" + unity(rest);
        } else {
            result += dozen(quotient) + "-" + unity(rest);
        }
    }
    return result;
}

string convertHundredNumber(long double num) {
    int integerPart = (int) num;
    int quotient = integerPart / 100;
    int rest = integerPart % 100;
    string result;

    if ((integerPart >= 100) && (integerPart < 1000)) {
        if ((quotient == 1) && (rest == 0)) {
            result += "cent";
        } else if ((quotient > 1) && (rest == 0)) {
            result += convertSmallNumber(quotient) + "-cents";
        } else if ((quotient == 1) && (rest < 10)) {
            result += "cent-" + convertSmallNumber(rest);
        } else if ((quotient == 1) && (rest >= 10) && (rest < 100)) {
            result += "cent-" + convertSmallNumber(rest);
        } else {
            result += convertSmallNumber(quotient) + "-cents-" + convertSmallNumber(rest);
        }
    }
    return result;
}

string convertThousandNumber(long double num) {
    int integerPart = (int) num;
    string result;
    int quotient = integerPart / 1e9;
    int rest = integerPart % 1000000000;
    if ((integerPart >= 1000) && (integerPart < 1e6)) {
        int quotient = integerPart / 1000;
        int rest = integerPart % 1000;
        if ((integerPart >= 1000) && (integerPart < 1e4)) {
            quotient = integerPart / 1000;
            rest = integerPart % 1000;
            if ((quotient == 1) && (rest == 0)) {
                result += "mille";
            } else if ((quotient == 1) && (rest < 10)) {
                result += "mille-" + convertSmallNumber(rest);
            } else if ((quotient == 1) && (rest < 100)) {
                result += "mille-" + convertSmallNumber(rest);
            } else if ((quotient == 1) && (rest < 1000)) {
                result += "mille-" + convertHundredNumber(rest);
            } else if ((quotient > 1) && (rest == 0)) {
                result += convertSmallNumber(quotient) + "-mille";
            } else {
                result += convertSmallNumber(quotient) + "-mille-" + convertHundredNumber(rest);
            }
        } else if ((integerPart >= 1e4) && (integerPart < 1e5)) {
            result += convertSmallNumber(quotient) + "-mille-" + convertHundredNumber(rest);
        } else if ((integerPart >= 1e5) && (integerPart < 1e6)) {
            result += convertHundredNumber(quotient) + "-mille-" + convertHundredNumber(rest);
        }
    } else if ((integerPart >= 1e6) && (integerPart < 1e9)) {
        int quotient = integerPart / 1e6;
        int rest = integerPart % 1000000;
        if ((integerPart >= 1e6) && (integerPart < 1e8)) {
            result += convertSmallNumber(quotient) + "-millions-" + convertThousandNumber(rest);
        } else if ((integerPart >= 1e8) && (integerPart < 1e9)) {
            result += convertHundredNumber(quotient) + "-millions-" + convertThousandNumber(rest);
        }
    } else {
        if ((integerPart >= 1e9) && (integerPart < 1e10)) {
            result += convertSmallNumber(quotient) + "-milliards-" + convertThousandNumber(rest);
        }
    }
    return result;
}

string convertDecimal(long double num) {
    int integerPart = (int) num;
    int decimalPart = floor((num - integerPart) * 100 + 0.5);
    string result;

    if (decimalPart > 0) {
        result += "et ";
        result += dozen(decimalPart / 10);
        result += unity(decimalPart % 10);
    }

    return result;
}

string montantEnToutesLettres(long double montant) {
    return convertThousandNumber(montant) + " francs";
}
