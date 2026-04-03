#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentas.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <deque>
#include <chrono>
#include <iomanip>


void spausdinimas(std::vector<studentas>& A);
void failoSpausdinimas(std::vector<studentas>& A);
void failoGeneravimas(int studKiekis);
void atskiriFailai(std::string failas, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai);
void tyrimasPirmas();
void tyrimasAntras(std::vector<studentas>& A, std::vector<studentas>& vargsai, std::vector<studentas>& kietekai, int kriterijus);

template<typename konteineris> 
void skaitymas(konteineris& A, std::string failas)
{
    std::ifstream input(failas);

    if(!input.is_open())
    {
        throw std::runtime_error("Pasirinkto failo nepavyko atidaryti!");
    }
    std::string eilute;

    getline(input, eilute);

    while(getline(input, eilute))
    {
        std::stringstream ss(eilute);
        studentas s;
        std::string vardas, pavarde;
        ss >> vardas >> pavarde;
        s.setVardas(vardas);
        s.setPavarde(pavarde);

        std::vector<int> pazymiai;
        int x;
        while(ss >> x)
        {
            pazymiai.push_back(x);
        }

        s.setEgzaminas(pazymiai.back());
        pazymiai.pop_back();


        s.setNd(pazymiai);
        s.setGalutinisVid(s.galutinisVid());
        s.setGalutinisMed(s.galutinisMed());

        A.push_back(s);
    }
    input.close();
}

template<typename konteineris>
void rikiavimas(konteineris& A, int kriterijus)
{
    
    auto byVardas = [](const studentas& a, const studentas& b)
    {
        return a.getVardas() < b.getVardas();
    };
    auto byPavarde = [](const studentas& a, const studentas& b)
    {
        return a.getPavarde() < b.getPavarde();
    };
    auto byGalVid = [](const studentas& a, const studentas& b)
    {
        return a.getGalutinisVid() < b.getGalutinisVid();
    };
    auto byGalMed = [](const studentas& a, const studentas& b)
    {
        return a.getGalutinisMed() < b.getGalutinisMed();
    };

    //Listo rikiavimas
    if constexpr (std::is_same_v<konteineris, std::list<studentas>>)
    {
        switch(kriterijus)
        {
            case 1: A.sort(byVardas); break;
            case 2: A.sort(byPavarde); break;
            case 3: A.sort(byGalVid); break;
            case 4: A.sort(byGalMed); break;
        }
    }
    //Vector arba deque rikiavimas
    else
    {
        switch(kriterijus)
        {
            case 1: std::sort(A.begin(), A.end(), byVardas); break;
            case 2: std::sort(A.begin(), A.end(), byPavarde); break;
            case 3: std::sort(A.begin(), A.end(), byGalVid); break;
            case 4: std::sort(A.begin(), A.end(), byGalMed); break;
        }   
    }
    

}

//1 strategija
template<typename konteineris>
void StudentuPadalinimas( konteineris& A, konteineris& vargsai, konteineris& kietekai)
{
    for(const auto& s : A)
    {
        if(s.getGalutinisVid() < 5.0)
        {
            vargsai.push_back(s);
        }
        else
        {
            kietekai.push_back(s);
        }
    }
    A.clear();

}
//2 strategija
template<typename konteineris>
void StudentuPadalinimas2(konteineris& A, konteineris& vargsai)
{
    
    if constexpr (std::is_same_v<konteineris, std::list<studentas>>)
    {
        A.sort([](const studentas& a, const studentas& b){
            return a.getGalutinisVid() > b.getGalutinisVid();
        });
    }
    else 
    {
        std::sort(A.begin(), A.end(), [](const studentas& a, const studentas& b){
            return a.getGalutinisVid() > b.getGalutinisVid();
        });
    }
    auto it = A.end();

    while(it != A.begin())
    {
        --it;
        if(it->getGalutinisVid() < 5)
        {
            vargsai.push_back(*it);
            it = A.erase(it);
        }
        else{
            break;
        }
    }
    
    /*remove_if iskelia konteinerio elementus i jo gala, ties kuriais lambda grazina true
    // it yra iteratorius kuri po remove_if rodo i pirma "netikusi" elementa, kuri reikia pasalinti
    auto it = remove_if(A.begin(), A.end(), [&vargsai](studentas& a)
    {
        if(a.galutinisVid < 5.0)
        {
            vargsai.push_back(a);
            return true;
        }
        return false;
    });
    //istrinam pagrindinio konteinerio galo elementus, kurie po remove_if buvo ten sudėti
    A.erase(it, A.end());
    */

}

//3 strategija
template<typename konteineris>
void StudentuPadalinimas3(konteineris& A, konteineris& vargsai)
{
    //grazina iteratoriu it, kuris rodo i antro bloko pirma elementa, kuris pagal partition ir musu salyga buvo false
    //konteineris lieka isdeliotas taip: pirmi elementai tie, kurie tenkina salyga, tada po ju eina visi like
    auto it = std::partition(A.begin(), A.end(), [](const studentas& a) { return a.getGalutinisVid() >= 5.0; });

    //sudeda elementus nuo konteinerio A iteratoriaus iki konteinerio pabaigos i vargsai konteineri
    vargsai.insert(vargsai.begin(), it, A.end());
    //istrina A konteinerio elementus nuo iteratoriaus iki konteinerio pabaigos
    A.erase(it, A.end());

}


template<typename konteineris>
void KonteineriuTyrimas(konteineris& A, konteineris& vargsai, konteineris& kietekai, int kriterijus, int strategija)
{
    std::vector<int> studKiekis = {1000, 10000, 100000, 1000000, 10000000};

    std::cout << std::left << std::setw(12) << "Studentai" << std::setw(15) << "Skaitymas"
    << std::setw(15) << "Rikiavimas" << std::setw(15) << "skirstymas" 
    << std::setw(15) << "Bendras laikas" << std::endl;


    for(auto x : studKiekis)
    {
        A.clear();
        vargsai.clear();
        kietekai.clear();
        
        //nuskaitymas
        auto start1 = std::chrono::high_resolution_clock::now();
        skaitymas(A, "studentai" + std::to_string(x) + ".txt");
        auto end1 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff1 = end1 - start1;

        //rikiavimas
        auto start2 = std::chrono::high_resolution_clock::now();
        rikiavimas(A, kriterijus);
        auto end2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff2 = end2 - start2;

        //padalinimas
        auto start3 = std::chrono::high_resolution_clock::now();
        if(strategija == 1)
        {
            StudentuPadalinimas(A, vargsai, kietekai);
        }
        else if(strategija == 2)
        {
            StudentuPadalinimas2(A, vargsai);
        }
        else if(strategija == 3)
        {
            StudentuPadalinimas3(A, vargsai);
        }
        auto end3 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> diff3 = end3 - start3;

        //bendras
        double visas = diff1.count() + diff2.count() + diff3.count();

        std::cout << std::left << std::setw(12) << x << std::setw(15) << diff1.count()
        << std::setw(15) << diff2.count() << std::setw(15) << diff3.count() 
        << std::setw(15) << visas << std::endl;


    }
    A.clear();
    vargsai.clear();
    kietekai.clear();
}

#endif