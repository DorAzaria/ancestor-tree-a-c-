#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;
#include <string>
using namespace std;

//1
TEST_CASE("relations") {
    family::Tree t ("Dor");
        t.addFather("Dor","Ofer")
         .addMother("Dor","Ruth")
         .addFather("Ofer","Gabriel")
         .addMother("Ofer","Naomi")
         .addFather("Ruth","Shlomo")
         .addMother("Ruth","Shushana");

        CHECK(t.relation("Dor") == "me");
        CHECK(t.relation("Do") == "Undefined");
        CHECK(t.relation("D") == "Undefined");
        CHECK(t.relation("DOR") == "Undefined");

        CHECK(t.relation("Ofer") == "father");
        CHECK(t.relation("Ofe") == "Undefined");
        CHECK(t.relation("Of") == "Undefined");
        CHECK(t.relation("O") == "Undefined");
        CHECK(t.relation("OFER") == "Undefined");

        CHECK(t.relation("Ruth") == "mother");
        CHECK(t.relation("Rut") == "Undefined");
        CHECK(t.relation("Ru") == "Undefined");
        CHECK(t.relation("R") == "Undefined");
        CHECK(t.relation("RUTH") == "Undefined");

        CHECK(t.relation("Gabriel") == "grandfather");
        CHECK(t.relation("Gabrie") == "Undefined");
        CHECK(t.relation("Gabri") == "Undefined");
        CHECK(t.relation("Gabr") == "Undefined");
        CHECK(t.relation("Gab") == "Undefined");
        CHECK(t.relation("Ga") == "Undefined");
        CHECK(t.relation("G") == "Undefined");
        CHECK(t.relation("GABRIEL") == "Undefined");

        CHECK(t.relation("Naomi") == "grandmother");
        CHECK(t.relation("Naom") == "Undefined");
        CHECK(t.relation("Nao") == "Undefined");
        CHECK(t.relation("Na") == "Undefined");
        CHECK(t.relation("N") == "Undefined");
        CHECK(t.relation("naomi") == "Undefined");
        CHECK(t.relation("NAOMI") == "Undefined");
        CHECK(t.relation("Na Omi") == "Undefined");

        CHECK(t.relation("Shlomo") == "grandfather");
        CHECK(t.relation("Shlom") == "Undefined");
        CHECK(t.relation("Shlo") == "Undefined");
        CHECK(t.relation("Shl") == "Undefined");
        CHECK(t.relation("Sh") == "Undefined");
        CHECK(t.relation("S") == "Undefined");
        CHECK(t.relation("shlomo") == "Undefined");
        CHECK(t.relation("SHLOMO") == "Undefined");

        CHECK(t.relation("Shushana") == "grandmother");
        CHECK(t.relation("Shushan") == "Undefined");
        CHECK(t.relation("Shusha") == "Undefined");
        CHECK(t.relation("Shush") == "Undefined");
        CHECK(t.relation("Shus") == "Undefined");
        CHECK(t.relation("Shu") == "Undefined");
        CHECK(t.relation("Sh") == "Undefined");
        CHECK(t.relation("S") == "Undefined");
        CHECK(t.relation("suhshana") == "Undefined");
        CHECK(t.relation("SHUSHNA") == "Undefined");
        CHECK(t.relation("SHUshaNA") == "Undefined");

    CHECK_NOTHROW(t.find("greatgreat-grandfather"));
    CHECK_NOTHROW(t.find("grandma"));
    CHECK_NOTHROW(t.find("greatgreat-"));
    CHECK_NOTHROW(t.find("-grandfather"));
    CHECK_NOTHROW(t.find("grandpa-grandfather"));
    CHECK_NOTHROW(t.find("gGRANDpa"));
    CHECK_NOTHROW(t.find("mothera"));
    CHECK_NOTHROW(t.find("motherb"));
    CHECK_NOTHROW(t.find("motherc"));
    CHECK_NOTHROW(t.find("greatgrandfather"));
    CHECK_NOTHROW(t.find("greatgreatgrandfather"));
    CHECK_NOTHROW(t.find("greatgreatgrandmother"));
    CHECK_NOTHROW(t.find("greatgrandmother"));
    CHECK_NOTHROW(t.find("ME"));
    CHECK_NOTHROW(t.find("mE"));
    CHECK_NOTHROW(t.find("Me"));
    CHECK_NOTHROW(t.find("meh"));
    CHECK_NOTHROW(t.find("fater"));
    CHECK_NOTHROW(t.find("mater"));
    CHECK_NOTHROW(t.find("mther"));
}

TEST_CASE("find names") {
    family::Tree d ("Dor");
            d.addFather("Dor","Ofer")
            .addMother("Dor","Ruth")
            .addFather("Ofer","Gabriel")
            .addMother("Ofer","Naomi")
            .addFather("Gabriel","Shaul")
            .addMother("Gabriel","Sarah");

        CHECK(d.find("father")== "Ofer");
        CHECK_NOTHROW(d.find("father"));
        CHECK_NOTHROW(d.find("mother"));
        CHECK_NOTHROW(d.find("grandfather"));
        CHECK_NOTHROW(d.find("grandmother"));
        CHECK(d.find("mother")== "Ruth");
        CHECK(d.find("grandfather")== "Gabriel");
        CHECK(d.find("grandmother")== "Naomi");
        CHECK(d.find("me")== "Dor");
        CHECK(d.find("great-grandmother")== "Sarah");
        CHECK(d.find("great-grandfather")== "Shaul");
        d.remove("Sarah");
        CHECK(d.relation("Sarah")== "Undefined");
        CHECK(d.find("great-grandmother")== "Undefined");
        d.remove("Shaul");
        CHECK(d.relation("Shaul")== "Undefined");
        CHECK(d.find("great-grandfather")== "Undefined");
        d.remove("Ofer");
        CHECK(d.relation("Gabriel")== "Undefined");
        CHECK(d.find("grandfather") == "Undefined");
        CHECK(d.relation("Naomi")== "Undefined");
        CHECK(d.find("grandmother") == "Undefined");

        CHECK(d.find("father") == "Undefined");
        CHECK(d.find("fath") == "Undefined");
        CHECK(d.find("fat") == "Undefined");
        CHECK(d.find("fa") == "Undefined");
        CHECK(d.find("f") == "Undefined");
        CHECK(d.find("FATJER") == "Undefined");
        CHECK(d.find("FATHER") == "Undefined");
        CHECK(d.find("motha") == "Undefined");
        CHECK(d.find("mothe") == "Undefined");
        CHECK(d.find("moth") == "Undefined");
        CHECK(d.find("mot") == "Undefined");
        CHECK(d.find("mo") == "Undefined");
        CHECK(d.find("m") == "Undefined");
        CHECK(d.find("MOTHER") == "Undefined");
        CHECK(d.find("MOTHA") == "Undefined");
        CHECK(d.find("GRANDFATHER") == "Undefined");
        CHECK(d.find("GRANDMOTHER") == "Undefined");
        CHECK(d.find("GREAT-GRANDMOTHER") == "Undefined");
        CHECK(d.find("great-grandmoth") == "Undefined");
        CHECK(d.find("great-grandfath") == "Undefined");
        CHECK(d.find("great") == "Undefined");
        CHECK(d.find("GREAT") == "Undefined");
        CHECK(d.find("Grea") == "Undefined");
        CHECK(d.find("grea") == "Undefined");
        CHECK(d.find("grt") == "Undefined");
        CHECK(d.find("geat") == "Undefined");
        CHECK(d.find("eat") == "Undefined");
        CHECK(d.find("grat") == "Undefined");
        CHECK(d.find("gt") == "Undefined");
        CHECK(d.find("GREat") == "Undefined");
        CHECK(d.find("grandpa") == "Undefined");
        CHECK(d.find("grandma") == "Undefined");
        CHECK(d.find("papa") == "Undefined");
        CHECK(d.find("mama") == "Undefined");
        CHECK(d.find("aunt") == "Undefined");
        CHECK(d.find("grandmotha") == "Undefined");
}
