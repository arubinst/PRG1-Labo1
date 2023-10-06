#include "montantEnToutesLettres.h"
#include <iostream>
#include <cmath>

using namespace std;


long double roundFractional(long double montant);
long separator(long double montant, bool decimalOrFractional);


string montantEnToutesLettres(long double montant) {

  return "zero franc"s;
}



//--ROUNDING FUNCIONS ------------------------------------------------
long double roundFractional(long double montant){
    long double x = round(montant * 100) / 100;
    x = round(montant * 100) / 100;
    return x ;
}

//---------------------------------------------------------------------

//--SEPARATION OF THE DECIMAL AND FRACTIONAL --------------------------
long int separator(long double montant, bool decimalOrFractional){
    // Fractional == False,  Decimal == True
    double decimalPart;
    double fractionalPart = modf(montant, &decimalPart);

    if(decimalOrFractional){
        return decimalPart;
    }else {
        fractionalPart = roundFractional(fractionalPart);//added for fix rounding error of c++
        fractionalPart *= 100;
        return fractionalPart;
    }
}

//---------------------------------------------------------------------





