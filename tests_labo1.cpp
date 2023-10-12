#define CATCH_CONFIG_FAST_COMPILE

#include <catch2/catch_test_macros.hpp>
#include "montantEnToutesLettres.h"
#include <utility>
#include <array>

using namespace std;

array testValues { make_pair(0.00,"zero franc"s) ,
                   make_pair(0.01,"un centime"s),
                   make_pair(0.23,"vingt-trois centimes"s) ,
                   make_pair(0.71,"septante-et-un centimes"s) ,
                   make_pair(0.994,"nonante-neuf centimes"s) ,
                   make_pair(0.996,"un franc"s) ,
                   make_pair(1.00,"un franc"s) ,
                   make_pair(1.89,"un franc et huitante-neuf centimes"s) ,
                   make_pair(2.17,"deux francs et dix-sept centimes"s) ,
                   make_pair(13.12,"treize francs et douze centimes"s) ,
                   make_pair(71.01,"septante-et-un francs et un centime"s) ,
                   make_pair(100.91,"cent francs et nonante-et-un centimes"s) ,
                   make_pair(200.69,"deux-cents francs et soixante-neuf centimes"s) ,
                   make_pair(215.58,"deux-cent-quinze francs et cinquante-huit centimes"s) ,
                   make_pair(267.00,"deux-cent-soixante-sept francs"s) ,
                   make_pair(300.47,"trois-cents francs et quarante-sept centimes"s) ,
                   make_pair(367.36,"trois-cent-soixante-sept francs et trente-six centimes"s) ,
                   make_pair(234.31,"deux-cent-trente-quatre francs et trente-et-un centimes"s) ,
                   make_pair(2015.00,"deux-mille-quinze francs"s) ,
                   make_pair(5023.20,"cinq-mille-vingt-trois francs et vingt centimes"s) ,
                   make_pair(123456.00,"cent-vingt-trois-mille-quatre-cent-cinquante-six francs"s) ,
                   make_pair(200200.00,"deux-cent-mille-deux-cents francs"s) ,
                   make_pair(234567.89,"deux-cent-trente-quatre-mille-cinq-cent-soixante-sept francs et huitante-neuf centimes"s) ,
                   make_pair(999999.99,"neuf-cent-nonante-neuf-mille-neuf-cent-nonante-neuf francs et nonante-neuf centimes"s) ,
                   make_pair(200000000.00,"deux-cents-millions de francs"s) ,
                   make_pair(3002001000.00,"trois-milliards-deux-millions-mille francs"s) ,
                   make_pair(1000000000000.00,"erreur : montant trop grand"s) ,
                   make_pair(23456234657532.00, "erreur : montant trop grand"s) ,
                   make_pair(123456789098765.44, "erreur : montant trop grand"s) ,
                   make_pair(-1.00,"erreur : montant negatif"s) ,
                   make_pair(9876543210987654.00,"erreur : montant trop grand"s) };

TEST_CASE( "Tests fournis aux etudiants", "TestValues") {
    for(auto& p : testValues) {
        SECTION(to_string(p.first) + " == " + p.second) {
            REQUIRE(montantEnToutesLettres(p.first) == p.second);
        }
    }
}
