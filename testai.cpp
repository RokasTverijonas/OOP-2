#include "studentas.h"
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

void testDefaultConstructor()
{
    studentas s;
    assert(s.getVardas().empty());
    assert(s.getPavarde().empty());
    assert(s.getNd().empty());
    assert(s.getEgzaminas() == 0);

    std::cout << "Default konstruktorius testą praėjo\n";
}

void testCopyConstructor()
{
    studentas s;
    std::vector<int> temp = {6,8,9}; 
    s.setVardas("vardas");
    s.setPavarde("Pavarde");
    s.setNd(temp);
    s.setEgzaminas(9);

    studentas copy(s);

    assert(s.getVardas() == copy.getVardas());
    assert(s.getPavarde() == copy.getPavarde());
    assert(s.getNd() == copy.getNd());
    assert(s.getEgzaminas() == copy.getEgzaminas());

    std::cout << "Copy konstruktorius testą praėjo\n";

}

void testCopyAssignment()
{
    studentas s;
    std::vector<int> temp = {6,8,9}; 
    s.setVardas("vardas");
    s.setPavarde("Pavarde");
    s.setNd(temp);
    s.setEgzaminas(9);

    studentas copy;
    copy = s;

    assert(s.getVardas() == copy.getVardas());
    assert(s.getPavarde() == copy.getPavarde());
    assert(s.getNd() == copy.getNd());
    assert(s.getEgzaminas() == copy.getEgzaminas());

    std::cout << "Copy assignment operatorius testą praėjo\n";

}

void testMoveConstructor()
{
    studentas s;
    std::vector<int> temp = {6,8,9}; 
    s.setVardas("vardas");
    s.setPavarde("Pavarde");
    s.setNd(temp);
    s.setEgzaminas(9);

    studentas naujas(std::move(s));

    assert(naujas.getVardas() == "vardas");
    assert(naujas.getPavarde() == "Pavarde");
    assert(naujas.getNd() == temp);
    assert(naujas.getEgzaminas() == 9);

    assert(s.getVardas().empty());
    assert(s.getPavarde().empty());
    assert(s.getNd().empty());
    assert(s.getEgzaminas() == 0);

    std::cout << "Move konstruktorius testą praėjo\n";
}

void testMoveAssignment()
{
    studentas s;
    std::vector<int> temp = {6,8,9}; 
    s.setVardas("vardas");
    s.setPavarde("Pavarde");
    s.setNd(temp);
    s.setEgzaminas(9);

    studentas naujas;

    naujas = std::move(s);

    assert(naujas.getVardas() == "vardas");
    assert(naujas.getPavarde() == "Pavarde");
    assert(naujas.getNd() == temp);
    assert(naujas.getEgzaminas() == 9);

    assert(s.getVardas().empty());
    assert(s.getPavarde().empty());
    assert(s.getNd().empty());
    assert(s.getEgzaminas() == 0);

    std::cout << "Move assignment operatorius testą praėjo\n";
}

void testDestructor()
{
    {
    studentas s;
    std::vector<int> temp = {6,8,9}; 
    s.setVardas("vardas");
    s.setPavarde("Pavarde");
    s.setNd(temp);
    s.setEgzaminas(9);
    }

    std::cout << "Destruktorius testą praėjo\n";

}

void testInputOutputOperators()
{
    studentas s;
    std::stringstream ivestis("Vardas Pavarde 1 8 9 10\n");
    ivestis >> s;
    assert(s.getVardas() == "Vardas");
    assert(s.getPavarde() == "Pavarde");
    assert(s.getNd()[0] == 1);
    assert(s.getNd()[1] == 8);
    assert(s.getNd()[2] == 9);
    assert(s.getEgzaminas() == 10);

    std::stringstream isvestis;
    isvestis << s;

    assert(isvestis.str() == "Vardas Pavarde 1 8 9 10");
    

    std::cout << "Įvesties ir išvesties operatoriai testą praėjo\n";


}