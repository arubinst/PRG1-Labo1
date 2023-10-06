#include "montantEnToutesLettres.h"

using namespace std;

string convertUnit(int unit);

string convertSpecial(int special);

string convertTens(int tens);

string tensToText(int smallInt);


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
        case 10: return "dix"; // FIXME : dix already in convertTen, remove one
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

string tensToText(int smallInt) {
//    1-99
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
        string separator = (rest == 1 ? " et " : "-");
        return convertTens(quotient) + separator + tensToText(rest);
    }
}

string montantEnToutesLettres(long double montant) {
    return tensToText(montant);
    return "zero franc"s;
}