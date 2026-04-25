#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "zmogus.h"

class Studentas : public Zmogus{

private:
    std::vector<int> nd_;
    int egzaminas_;
    double galutinisVid_;
    double galutinisMed_;

public:
    //constructor
    Studentas() 
        : Zmogus(), egzaminas_(0), galutinisVid_(0.0), galutinisMed_(0.0) {}

    Studentas(const std::string& v, const std::string& p)
        : Zmogus(v, p), egzaminas_(0), galutinisVid_(0.0), galutinisMed_(0.0) {}

    //destructor
    ~Studentas() override
    {
        vardas_.clear();
        pavarde_.clear();
        nd_.clear();
        egzaminas_ = 0;
        galutinisVid_ = 0.0;
        galutinisMed_ = 0.0;
    }


    //copy constructor
    Studentas(const Studentas &a)
        : Zmogus(a),
          nd_(a.nd_),
          egzaminas_(a.egzaminas_),
          galutinisVid_(a.galutinisVid_),
          galutinisMed_(a.galutinisMed_) {}


    //copy Assignment operator
    Studentas& operator=(const Studentas &a)
    {
        if(this != &a)
        {
            Zmogus::operator=(a);
            nd_ = a.nd_;
            egzaminas_ = a.egzaminas_;
            galutinisVid_ = a.galutinisVid_;
            galutinisMed_ = a.galutinisMed_;
        }
        return *this;

    }

    //move constructor
    Studentas(Studentas&& a)
        : Zmogus(std::move(a)),
          nd_(std::move(a.nd_)),
          egzaminas_(std::move(a.egzaminas_)),
          galutinisVid_(std::move(a.galutinisVid_)),
          galutinisMed_(std::move(a.galutinisMed_)) 
          {
            a.egzaminas_ = 0;
            a.galutinisVid_ = 0.0;
            a.galutinisMed_ = 0.0;
          }

    //move Assignment operator
    Studentas& operator=(Studentas&& a)
    {
        if(this != &a)
        {
            Zmogus::operator=(std::move(a));
            nd_ = std::move(a.nd_);
            egzaminas_ = std::move(a.egzaminas_);
            galutinisVid_ = std::move(a.galutinisVid_);
            galutinisMed_ = std::move(a.galutinisMed_);

            a.egzaminas_ = 0;
            a.galutinisVid_ = 0.0;
            a.galutinisMed_ = 0.0;

        }

        return *this;
    }
    //isvedimo operatorius
    friend std::ostream& operator<<(std::ostream& out, const Studentas& a)
    {
        out << a.vardas_ << " " << a.pavarde_ << " ";
        for(int i : a.nd_)
        {
            out << i << " ";
        }
        out << a.egzaminas_;
        return out;
    }
    //ivedimo operatorius
    friend std::istream& operator>>(std::istream& in, Studentas& a)
    {
        std::string eilute;
        std::getline(in, eilute);
        std::stringstream ss(eilute);
        ss >> a.vardas_ >> a.pavarde_;

        int skaicius;
        std::vector<int> visi;

        while(ss >> skaicius)
        {
            visi.push_back(skaicius);
        }
        a.egzaminas_  = visi.back();
        visi.pop_back();
        a.nd_ = visi;

        return in;
    }
    //getters
    const std::vector<int>& getNd() const { return nd_; }
    int getEgzaminas() const { return egzaminas_; }
    double getGalutinisVid() const { return galutinisVid_; }
    double getGalutinisMed() const { return galutinisMed_; }

    //setters
    void setNd(const std::vector<int>& n) { nd_ = n; }
    void setEgzaminas(int e) { egzaminas_ = e; }
    void setGalutinisVid(double galVid) { galutinisVid_ = galVid; }
    void setGalutinisMed(double galMed) { galutinisMed_ = galMed; }

    //member functions
    double vidurkis() const override;

    double mediana() const;
    double galutinisVid() const;
    double galutinisMed() const;


};

#endif
