#include <string>
#include <iostream>
#include "Oferte.h"

Oferte::Oferte():nume(""), pret(0),durata(0){}
Oferte::Oferte(const std::string& nume, int pret, int durata)
    : nume(nume), pret(pret), durata(durata) {}

void Oferte::SetNume(const std::string& nume) {
    this->nume = nume;
}

void Oferte::SetPret(int pret) {
    this->pret = pret;
}

void Oferte::SetDurata(int durata) {
    this->durata = durata;
}

void Oferte::AfiseazaOferta() const {
    std::cout << "Nume: " << nume << std::endl;
    std::cout << "Pret: " << pret << " ron" << std::endl;
    std::cout << "Durata: " << durata << " min" << std::endl;
}

std::string Oferte::GetNume() const {
    return nume;
}

int Oferte::GetPret() const {
    return pret;
}

int Oferte::GetDurata() const {
    return durata;
}

std::ostream& operator<<(std::ostream& os, const Oferte& oferta){
    os << "Nume: " << oferta.GetNume()<< std::endl << "Pret: " << oferta.GetPret() <<" ron" << std::endl << "Durata: " << oferta.GetDurata() << " min" << std::endl;
    return os;
}

