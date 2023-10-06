//IN 0 \n0.01 \n0.23 \n0.71 \n0.995 \n1 \n1.89 \n2.17 \n13.12 \n71.01 \n100.91 \n200.69 \n215.58 \n267 \n300.47 \n367.36 \n234.31 \n2015 \n5023.2 \n123456 \n200200 \n234567.89 \n999999.99 \n999999.995 \n200000000 \n3002001000 \n1000000000000 \n23456237532 \n123456789098.43 \n-1 \n9876543210987654 \nstop

#include <iostream>
#include <iomanip>
#include "montantEnToutesLettres.h"

using namespace std;

int main() {
   long double d;

   while (cin >> d) { // finir par EOF (Ctrl-D) ou autre chose qu'un nombre
      cout << fixed << setprecision(2)
           << d << endl
           << montantEnToutesLettres(d) << endl;
   }
}