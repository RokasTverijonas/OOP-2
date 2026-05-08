#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>
#include <iostream>

/**
 * @class Zmogus
 * @brief Abstrakti klasė sauganti vardą ir pavardę
 */

class Zmogus {
protected:
    std::string vardas_; ///< Žmogaus vardas
    std::string pavarde_; ///<Žmogaus pavardė

public:
    /**
     * @brief Default konstruktorius
     */
    Zmogus() = default;
    /**
     * @brief konstruktorius su parametrais
     * @param v Vardas
     * @param p Pavardė
     */
    Zmogus(const std::string& v, const std::string& p)
        : vardas_(v), pavarde_(p) {}

    /**
     * @brief Virtualus destruktorius
     */
    virtual ~Zmogus() 
    {
        vardas_.clear();
        pavarde_.clear();     
    };
    /**
     * @brief Kopijos konstruktorius
     * @param a Kopijuojamas objektas
     */
    Zmogus(const Zmogus &a)
        : vardas_(a.vardas_),
          pavarde_(a.pavarde_){}

    /**
     * @brief Kopijos priskyrimo operatorius
     * @param a Priskiriamas objektas
     * @return Nuoroda į objektą
     */
    Zmogus& operator=(const Zmogus &a)
    {
        if(this != &a)
        {
            vardas_ = a.vardas_;
            pavarde_ = a.pavarde_;
        }
        return *this;

    }

    /**
     * @brief Perkėlimo konstruktorius
     * @param a Priskiriamas objektas
     */
    Zmogus(Zmogus&& a)
        : vardas_(std::move(a.vardas_)),
          pavarde_(std::move(a.pavarde_)){}

    /**
     * @brief Perkėlimo priskyrimo operatorius
     * @param a Perkeliamas objektas
     * @return nuoroda į objektą
     */
    Zmogus& operator=(Zmogus&& a)
    {
        if(this != &a)
        {
            vardas_ = std::move(a.vardas_);
            pavarde_ = std::move(a.pavarde_);
        }

        return *this;
    }
          

    /**
     * @brief Grynai virtualus vidurkio metodas
     * Paveldinčios klasės privalo realizuoti šį metodą
     */
    virtual double vidurkis() const = 0;


    /**
     * @brief Grąžina vardą
     */
    const std::string& getVardas() const { return vardas_; }
    /**
     * @brief Grąžina pavardę
     */
    const std::string& getPavarde() const { return pavarde_; }
    
    /**
     * @brief Nustato vardą
     * @param v Vardas
     */
    void setVardas(const std::string& v) { vardas_ = v;}
    /**
     * @brief Nustato pavardę
     * @param p Pavardė
     */
    void setPavarde(const std::string& p) { pavarde_ = p;}

};

#endif