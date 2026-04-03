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

# v1.1 Tyrimo rezultatai:

-Tyrimas atliekamas su vector konteineriu, pannaudojant 3-ją strategiją, kuri buvo sukurta v1.0 versijoje.

-Tyrimo tkslas palyginti struct ir class efektyvumą, saugant studentų duomenis.


100000 studentų failas

|   Veikimo laikas (class) |  Veikimo laikas (struct)  | Vėliava | Vykdomojo failo dydis (class) | Vykdomojo failo dydis (struct)   |
| -------------------------|---------------------------| --------| ------------------------------| ---------------------------------| 
|     0.277439 s           |          0.241432 s       | -01     |             206.5 KB          |               210.1 KB           | 
|     0.305582 s           |          0.251457 s       | -O2     |             189.6 KB          |               183.8 KB           |
|     0.28994 s            |          0.239646 s       | -O3     |             191.2 KB          |               190.2 KB           |
-------------------------------------------------------------------------------------------------------------------------------------

1000000 studentų failas

|   Veikimo laikas (class) |  Veikimo laikas (struct)  | Vėliava | Vykdomojo failo dydis (class) | Vykdomojo failo dydis (struct)   |
| -------------------------|---------------------------| --------| ------------------------------| ---------------------------------| 
|     2.64364 s            |          2.25808 s        | -01     |             206.5 KB          |               210.1 KB           | 
|     2.75745 s            |          2.28378 s        | -O2     |             189.6 KB          |               183.8 KB           |
|     2.66723 s            |          2.14807 s        | -O3     |             191.2 KB          |               190.2 KB           |
-------------------------------------------------------------------------------------------------------------------------------------

