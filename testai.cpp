#include "studentas.h"
#include <cassert>
#include <iostream>
#include <string>

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