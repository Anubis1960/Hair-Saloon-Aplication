#ifndef OFERTE_H
#define OFERTE_H

#include <string>

class Oferte {
private:
    std::string nume;
    int pret;
    int durata;

public:
    Oferte();
    Oferte(const std::string& nume, int pret, int durata);

    void SetNume(const std::string& nume);
    void SetPret(int pret);
    void SetDurata(int durata);
    std::string GetNume() const;
    int GetPret() const;
    int GetDurata() const;
    void AfiseazaOferta() const;
    friend std::ostream& operator << (std::ostream& os, const Oferte& oferta);
};

#endif
