#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>


class studentas {
    
    private:
    std::string vardas1;
    std::string pavarde1;
    std::vector<int> nd1;
    int egzaminas1;
    double galutinisVid1;
    double galutinisMed1;

    public:
    //constructor
    studentas() : egzaminas1(0), galutinisVid1(0.0), galutinisMed1(0.0) {}
    ~studentas() {}
    //getters
    const std::string& getVardas() const { return vardas1; }
    const std::string& getPavarde() const { return pavarde1; }
    const std::vector<int>& getNd() const { return nd1; }
    int getEgzaminas() const { return egzaminas1; }
    double getGalutinisVid() const { return galutinisVid1; }
    double getGalutinisMed() const { return galutinisMed1; }

    //setters
    void setVardas(const std::string& v) { vardas1 = v;}
    void setPavarde(const std::string& p) { pavarde1 = p; }
    void setNd(const std::vector<int>& n) { nd1 = n; }
    void setEgzaminas(int e) { egzaminas1 = e; }
    void setGalutinisVid(double galVid) { galutinisVid1 = galVid; }
    void setGalutinisMed(double galMed) { galutinisMed1 = galMed; }

    //member functions
    double vidurkis() const;
    double mediana() const;
    double galutinisVid() const;
    double galutinisMed() const;


};

#endif
