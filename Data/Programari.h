#ifndef PROGRAMARI_H
#define PROGRAMARI_H
#include <fstream>
#include <string>
#include <vector>
#include "Oferte.h"

struct Appointment{
    std::string nume;
    Oferte *offer;
    int zi;
    int luna;
    int an;
    int ora_incepere;
    int min_incepere;
    int ora_incheiere;
    int min_incheiere;
    std::string status;
};

class Programari {
private:
    std::vector<Oferte> oferte;
    std::vector<Appointment> appointments;

public:
    Programari(const std::string& filePath, const std::string& filePath1);
    void Load( std::ifstream& file, std::ifstream& file1);
    void SaveToFileOffer(const std::string& fileName) const;
    void SaveToFileAppointments(const std::string& fileName)const;
    void VizualizeazaDisponibilitate(const int zi,const int luna,const int an)const;
    void AcceptaProgramari();
    void AfiseazaOferte() const;
    void AdaugaOferta(std::string Name, int Price, int Duration);
    void ModificaOferta(int index, std::string NewName, int NewPrice, int NewDuration);
    void StergeOferta(int index);
    void ProgramareSedinta(std::string nume, int numar, int zi, int luna, int an, int ora, int minut);
    void IstoricProgramari(const std::string& nume);

};

#endif
