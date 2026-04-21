#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class studentas {
    
    private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> nd_;
    int egzaminas_;
    double galutinisVid_;
    double galutinisMed_;

    public:
    //constructor
    studentas() : egzaminas_(0), galutinisVid_(0.0), galutinisMed_(0.0) {}
    //destructor
    ~studentas() {}


    //copy constructor
    studentas(const studentas &a)
    {
        vardas_ = a.vardas_;
        pavarde_ = a.pavarde_;
        nd_ = a.nd_;
        egzaminas_ = a.egzaminas_;
        galutinisVid_ = a.galutinisVid_;
        galutinisMed_ = a.galutinisMed_;
    }

    //copy Assignment operator
    studentas& operator=(const studentas &a)
    {
        if(this != &a)
        {
            this->vardas_ = a.vardas_;
            this->pavarde_ = a.pavarde_;
            this->nd_ = a.nd_;
            this->egzaminas_ = a.egzaminas_;
            this->galutinisVid_ = a.galutinisVid_;
            this->galutinisMed_ = a.galutinisMed_;
        }
        return *this;

    }

    //move constructor
    studentas(studentas&& a)
        : vardas_(std::move(a.vardas_)),
          pavarde_(std::move(a.pavarde_)),
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
    studentas& operator=(studentas&& a)
    {
        if(this != &a)
        {
            vardas_ = std::move(a.vardas_);
            pavarde_ = std::move(a.pavarde_);
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
    friend std::ostream& operator<<(std::ostream& out, const studentas& a)
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
    friend std::istream& operator>>(std::istream& in, studentas& a)
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
    const std::string& getVardas() const { return vardas_; }
    const std::string& getPavarde() const { return pavarde_; }
    const std::vector<int>& getNd() const { return nd_; }
    int getEgzaminas() const { return egzaminas_; }
    double getGalutinisVid() const { return galutinisVid_; }
    double getGalutinisMed() const { return galutinisMed_; }

    //setters
    void setVardas(const std::string& v) { vardas_ = v;}
    void setPavarde(const std::string& p) { pavarde_ = p; }
    void setNd(const std::vector<int>& n) { nd_ = n; }
    void setEgzaminas(int e) { egzaminas_ = e; }
    void setGalutinisVid(double galVid) { galutinisVid_ = galVid; }
    void setGalutinisMed(double galMed) { galutinisMed_ = galMed; }

    //member functions
    double vidurkis() const;
    double mediana() const;
    double galutinisVid() const;
    double galutinisMed() const;


};

#endif
