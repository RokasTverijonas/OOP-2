#include "studentas.h"
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <gtest/gtest.h>

TEST(StudentasClassTest, DefaultConstructor)
{
    Studentas s;
    EXPECT_TRUE(s.getVardas().empty());
    EXPECT_TRUE(s.getPavarde().empty());
    EXPECT_TRUE(s.getNd().empty());
    EXPECT_EQ(s.getEgzaminas(), 0);
}

TEST(SudentasClassTest, CopyConstructor)
{
    Studentas s;
    std::vector<int> temp = {6,8,9}; 
    s.setVardas("vardas");
    s.setPavarde("Pavarde");
    s.setNd(temp);
    s.setEgzaminas(9);

    Studentas copy(s);

    EXPECT_EQ(s.getVardas(), copy.getVardas());
    EXPECT_EQ(s.getPavarde(), copy.getPavarde());
    EXPECT_EQ(s.getNd(), copy.getNd());
    EXPECT_EQ(s.getEgzaminas(), copy.getEgzaminas());

}

TEST(StudentasClassTest, CopyAssignment)
{
    Studentas s;
    std::vector<int> temp = {6,8,9}; 
    s.setVardas("vardas");
    s.setPavarde("Pavarde");
    s.setNd(temp);
    s.setEgzaminas(9);

    Studentas copy;
    copy = s;

    EXPECT_EQ(s.getVardas(),copy.getVardas());
    EXPECT_EQ(s.getPavarde(), copy.getPavarde());
    EXPECT_EQ(s.getNd(), copy.getNd());
    EXPECT_EQ(s.getEgzaminas(), copy.getEgzaminas());

}

TEST(StudentasClassTest, MoveConstructor)
{
    Studentas s;
    std::vector<int> temp = {6,8,9}; 
    s.setVardas("vardas");
    s.setPavarde("Pavarde");
    s.setNd(temp);
    s.setEgzaminas(9);

    Studentas naujas(std::move(s));

    EXPECT_EQ(naujas.getVardas(), "vardas");
    EXPECT_EQ(naujas.getPavarde(), "Pavarde");
    EXPECT_EQ(naujas.getNd(), temp);
    EXPECT_EQ(naujas.getEgzaminas(), 9);

    EXPECT_TRUE(s.getVardas().empty());
    EXPECT_TRUE(s.getPavarde().empty());
    EXPECT_TRUE(s.getNd().empty());
    EXPECT_EQ(s.getEgzaminas(), 0);
}

TEST(StudentasClassTest, MoveAssignment)
{
    Studentas s;
    std::vector<int> temp = {6,8,9}; 
    s.setVardas("vardas");
    s.setPavarde("Pavarde");
    s.setNd(temp);
    s.setEgzaminas(9);

    Studentas naujas;

    naujas = std::move(s);

    EXPECT_EQ(naujas.getVardas(), "vardas");
    EXPECT_EQ(naujas.getPavarde(), "Pavarde");
    EXPECT_EQ(naujas.getNd(), temp);
    EXPECT_EQ(naujas.getEgzaminas(), 9);

    EXPECT_TRUE(s.getVardas().empty());
    EXPECT_TRUE(s.getPavarde().empty());
    EXPECT_TRUE(s.getNd().empty());
    EXPECT_EQ(s.getEgzaminas(), 0);
}

TEST(StudentasClassTest, Destructor)
{
    {
    Studentas s;
    std::vector<int> temp = {6,8,9}; 
    s.setVardas("vardas");
    s.setPavarde("Pavarde");
    s.setNd(temp);
    s.setEgzaminas(9);
    //s.~studentas();
    //std::cout << "Getinamas egzaminas po destruktoriaus" << std::endl;
    //std::cout << s.getEgzaminas() << std::endl;
    }

}

TEST(StudentasClassTest, InputOutputOperators)
{
    Studentas s;
    std::stringstream ivestis("Vardas Pavarde 1 8 9 10\n");
    ivestis >> s;
    EXPECT_EQ(s.getVardas(), "Vardas");
    EXPECT_EQ(s.getPavarde(), "Pavarde");
    EXPECT_EQ(s.getNd()[0], 1);
    EXPECT_EQ(s.getNd()[1], 8);
    EXPECT_EQ(s.getNd()[2], 9);
    EXPECT_EQ(s.getEgzaminas(), 10);

    std::stringstream isvestis;
    isvestis << s;

    EXPECT_EQ(isvestis.str(), "Vardas Pavarde 1 8 9 10");
}