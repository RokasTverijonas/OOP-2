#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>


class studentas {
    
    private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd;
    int egzaminas;
    double galutinisVid;
    double galutinisMed;

    public:
    //constructor
    studentas() : egzaminas(0), galutinisVid(0.0), galutinisMed(0.0) {}
    ~studentas() {}
    //getters
    const std::string& getVardas() const { return vardas; }
    const std::string& getPavarde() const { return pavarde; }
    const std::vector<int>& getNd() const { return nd; }
    int getEgzaminas() const { return egzaminas; }
    double getGalutinisVid() const { return galutinisVid; }
    double getGalutinisMed() const { return galutinisMed; }

    //setters
    void setVardas(const std::string& v) { vardas = v;}
    void setPavarde(const std::string& p) { pavarde = p; }
    void setNd(const std::vector<int>& n) { nd = n; }
    void setEgzaminas(int e) { egzaminas = e; }
    void setGalutinisVid(double galVid) { galutinisVid = galVid; }
    void setGalutinisMed(double galMed) { galutinisMed = galMed; }

    //member functions
    double vidurkis() const;
    double mediana() const;
    double galutinisVid() const;
    double galutinisMed() const;


};

#endif
