#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    Zmogus() = default;
    Zmogus(const std::string& v, const std::string& p)
        : vardas_(v), pavarde_(p) {}
    
    virtual ~Zmogus() 
    {
        vardas_.clear();
        pavarde_.clear();     
    };
    //copy constructor
    Zmogus(const Zmogus &a)
        : vardas_(a.vardas_),
          pavarde_(a.pavarde_){}

    //copy Assignment operator
    Zmogus& operator=(const Zmogus &a)
    {
        if(this != &a)
        {
            vardas_ = a.vardas_;
            pavarde_ = a.pavarde_;
        }
        return *this;

    }

    //move constructor
    Zmogus(Zmogus&& a)
        : vardas_(std::move(a.vardas_)),
          pavarde_(std::move(a.pavarde_)){}

    //move Assignment operator
    Zmogus& operator=(Zmogus&& a)
    {
        if(this != &a)
        {
            vardas_ = std::move(a.vardas_);
            pavarde_ = std::move(a.pavarde_);
        }

        return *this;
    }
          

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