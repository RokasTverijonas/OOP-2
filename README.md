# Projekto aprašymas
Programa skirta studentų akademinių pasiekimų informacijos apdorojimui. Vartotojas gali rinktis, ar studentų informaciją įveda jis pats, ar informacija yra generuojama automatiškai. Programa leidžia generuoti, nuskaityti studentų failus bei atlikti skirtingus programos veikimo laiko testus. Programos veikimo spartos testavimui naudojami skirtingi konteineriai.

# Naudojimosi instrukcija
1. Nusiklonuokite repozitoriją:
   
   ```
   git clone https://github.com/RokasTverijonas/OOP-1.git
   ```

2. Įsidiekite CMake (Linux(Ubuntu/Debian))

   ```
   sudo apt update
   sudo apt install cmake
   ```

3. Projekto kompiliavimas su CMake
   
   ```
   cd OOP-1
   mkdir build
   cd build
   cmake ..
   make
   ```
4. Paleiskite programą
   
   ```
   ./programa1
   ```

# Kompiuterio specifikacijos:

|       CPU      |  RAM |    SSD     | 
|----------------|------|------------| 
| Intel i5-8265U | 16GB | NVMe 256GB |      
--------------------------------------

# v1.5 rezultatai

Šioje versijoje išlaikyta ta pati v1.2 versijos logika, tačiau pridėta abstrakti bazinė klasė `Zmogus` ir iš jos išvesta `Studentas` klasė.

|      Klasė     |  Tipas  |  Ką saugo                                      | 
|----------------|---------|------------------------------------------------| 
| `Zmogus`       | Abstract| vardą ir pavardę                               |   
| `Studentas`    | Derived | pažymius, egzamino balą, galutinius įvertinimus|
-----------------------------------------------------------------------------

Bandymas sukurti abstrakčios "Zmogus" klasės objektą

`Zmogus z("Vardenis", "Pavardenis")`

![alt text](image.png)

# "Rule of five"

|   Metodas                | Sintaksė                                  |Paskirtis                                     | 
| -------------------------|-------------------------------------------|----------------------------------------------| 
|Copy konstruktorius       |`studentas(const studentas& a)`            |Kuriama objekto kopija                        |
|Copy priskyrimo operatorius|`studentas& operator=(const studentas &a)`|objekto kopijos priskyrimas - b = a           |
|Move konstruktorius       |`studentas(studentas&& a)`                 |Objekto perėmimas - studentas b = std::move(a)|                                          |
|Move priskyrimo operatorius|`studentas& operator=(studentas&& a)`     |Objekto perėmimas - b = std::move(a)          |
|Destruktorius             |`~studentas()`                             |Objekto sunaikinimas (veikia automtiskai)     |
-----------------------------------------------------------------------------------------------------------------------

I/O operatoriai

|  Operatorius   |  Paskirtis                           | 
|----------------|--------------------------------------|
| `operator>>`     | nuskaito duomenis iš srauto į objektą|    
| `operator<<`    | Išveda objekto duomenis į srautą     |  
----------------------------------------------------------

Rezultatų nuotrauka

<img width="387" height="126" alt="image" src="https://github.com/user-attachments/assets/8cf09e6b-64d9-49ae-a405-f6eaa1b4422f" />