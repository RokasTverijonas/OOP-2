#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

class zmogus {
private:
    std::string vardas_;
    std::string pavarde_;

public:
    zmogus() = default;
    zmogus(const std::string& v, const std::string& p)
        : vardas_(v), pavarde_(p) {}
    
    virtual ~zmogus() 
    {
        vardas_.clear();
        pavarde_.clear();     
    };

    //pure virtual
    virtual double vidurkis() const = 0;

    //getters
    const std::string& getVardas() const { return vardas_; }
    const std::string& getPavarde() const { return pavarde_; }
    //setters
    void setVardas(const std::string& v) { vardas_ = v;}
    void setPavarde(const std::string& p) { pavarde_ = p;}

};

#endif