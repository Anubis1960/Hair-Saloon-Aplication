#include "Programari.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include "Oferte.h"
#include <iostream>

Programari::Programari(const std::string& filePath, const std::string& filePath1) {
    std::ifstream file(filePath);
    std::ifstream file1(filePath1);
    if (file.is_open() && file1.is_open()) {
        Load(file, file1);
        file.close();
        file1.close();
    } else {
        std::cout << "Failed to open files: " << filePath << " or " << filePath1 << std::endl;
    }
}

void Programari::Load(std::ifstream& file, std::ifstream& file1) {
    std::string name;
    std::string pret, durata;
    oferte.clear();
    appointments.clear();
    while (std::getline(file,name,',') && std::getline(file,pret,',') && std::getline(file,durata)) {
        Oferte oferta(name, std::stoi(pret), std::stoi(durata));
        oferte.push_back(oferta);
    }
    std::string utilizator, nume_oferta;
    std::string status;
    std::string pret_oferta, durata_oferta;
    std::string zi, luna, an, ora_incepere, min_incepere, ora_incheiere, minut_incheiere;
    while (std::getline(file1,utilizator,',') && std::getline(file1,nume_oferta,',') && std::getline(file1,pret_oferta,',') && std::getline(file1,durata_oferta,',') && std::getline(file1,zi,',') && std::getline(file1,luna,',') && std::getline(file1,an,',') && std::getline(file1,ora_incepere,',') && std::getline(file1,min_incepere,',') && std::getline(file1,ora_incheiere,',') && std::getline(file1,minut_incheiere,',') && std::getline(file1,status)) {
        Oferte *o = new Oferte(nume_oferta, std::stoi(pret_oferta), std::stoi(durata_oferta));
        Appointment a;
        a.nume = utilizator;
        a.offer = o;
        a.zi = std::stoi(zi);
        a.luna = std::stoi(luna);
        a.an = std::stoi(an);
        a.min_incepere = std::stoi(min_incepere);
        a.ora_incepere = std::stoi(ora_incepere);
        a.ora_incheiere = std::stoi(ora_incheiere);
        a.status = status;
        appointments.push_back(a);
    }
}

void Programari::AfiseazaOferte() const {
    std::cout << "Frizeria dispune de urmatoarele oferte: " << std::endl;
    for( int i = 0; i < oferte.size(); ++i) {
        std::cout << oferte[i];
    }
}

void Programari::SaveToFileOffer(const std::string& fileName) const{
    std::ofstream file(fileName);
    if(file.is_open()){
        for(const auto& offer : oferte)
            file << offer.GetNume() <<","<< offer.GetPret() <<","<< offer.GetDurata() << std::endl;
    file.close();
    }
    else{
        std::cout << "Error";
    }

}

void Programari::SaveToFileAppointments(const std::string& fileName)const{
    std::ofstream file(fileName);
    if(file.is_open()){
        for(const auto& appointment : appointments){
            file << appointment.nume <<","<< appointment.offer->GetNume() <<"," << appointment.offer->GetPret()<<","<< appointment.offer->GetDurata() <<","<< appointment.zi<<","<< appointment.luna <<","<< appointment.an<<","<< appointment.ora_incepere <<","<< appointment.min_incepere <<","<< appointment.ora_incheiere <<","<< appointment.min_incheiere <<","<< appointment.status << std::endl;
    }file.close();
    }
    else{
        std::cout << "Error";
    }
}

void Programari::ModificaOferta(int index, std::string NewName, int NewPrice, int NewDuration){
    oferte[index].SetNume(NewName);
    oferte[index].SetDurata(NewDuration);
    oferte[index].SetPret(NewPrice);
    SaveToFileOffer("Shared/oferte.txt");
}

void Programari::AdaugaOferta(std::string Name, int Price, int Duration){
    Oferte OfertaNoua(Name,Price, Duration);
    oferte.push_back(OfertaNoua);
    SaveToFileOffer("Shared/oferte.txt");
}

void Programari::StergeOferta(int index){
    if (index < 0 || index > oferte.size())
        std::cout << "Index invalid";
    else{
        oferte.erase(oferte.begin()+index);
        SaveToFileOffer("Shared/oferte.txt");
    }
}

void Programari::AcceptaProgramari(){
    for(auto& appointment : appointments){
        appointment.status = "ACCEPTED";
    }
    SaveToFileAppointments("Shared/programari.txt");
    std::cout << "Programari acceptate cu succes." << std::endl;
}

void Programari::VizualizeazaDisponibilitate(const int zi,const int luna,const int an)const {
    std::cout << "Disponibilitatea frizeriei in data de: " << zi << "/" << luna << "/" << an << std::endl;
    std::cout << "Intervalele ocupate sunt:" << std::endl;
    for( auto& appointment : appointments){
        if ( appointment.an == an && appointment.luna == luna && appointment.zi == zi ){
            std::cout << appointment.ora_incepere << ":" << appointment.min_incepere <<" - " << appointment.ora_incheiere << ":" << appointment.min_incheiere << std::endl;
        }
    }
}

void Programari::IstoricProgramari(const std::string& nume){
    std::cout << "Istoricul utilizatorului " << nume << " este:" << std::endl;
    for( auto& appointment : appointments ){
        if ( appointment.nume == nume ){
            std::string nume = appointment.offer->GetNume();
            int pret = appointment.offer->GetPret();
            int durata = appointment.offer->GetDurata();
            std::cout << "Oferta aleasa: " << nume << " " << pret << " ron " << durata << " min" << std::endl;
            std::cout << "Data: " << appointment.zi <<"/" << appointment.luna << "/" << appointment.an << " " << appointment.ora_incepere << ":" << appointment.min_incepere << std::endl;
            std::cout << "Status: " << appointment.status << std::endl;

        }
    }
}

void Programari::ProgramareSedinta(std::string nume, int numar, int zi, int luna, int an, int ora, int minut){

    Oferte *oferta_aleasa = new Oferte(oferte[numar-1].GetNume(),oferte[numar-1].GetPret(),oferte[numar-1].GetDurata());
    int ora_terminarii, min_terminarii;
    if(minut+oferta_aleasa->GetDurata() >= 60){
        min_terminarii = minut+oferta_aleasa->GetDurata()-60;
        ora_terminarii = ora+1;
    }
    else{
        ora_terminarii = ora;
        min_terminarii = minut+oferta_aleasa->GetDurata();
    }
    int ok = 1;
    for( auto& appointment : appointments){
        if (appointment.an == an && appointment.zi == zi && appointment.luna == luna){
            if(appointment.ora_incepere == ora){
                if(appointment.ora_incheiere == appointment.ora_incepere){
                    if((minut > appointment.min_incepere && minut < appointment.min_incheiere)||(min_terminarii > appointment.min_incepere && min_terminarii < appointment.min_incheiere ))
                        ok = 0;
                }
                else{
                    if((minut > appointment.min_incepere || minut < appointment.min_incheiere)||(min_terminarii > appointment.min_incepere || min_terminarii < appointment.min_incheiere ))
                        ok = 0;
                }
            }
        }
    }
    if( ok == 0 )
        std::cout << "Programarea nu s-a putut realiza. Intervalul ales este indisponibil." << std::endl;
    else{
        Appointment a;
        a.nume = nume;
        a.offer = oferta_aleasa;
        a.an = an;
        a.zi = zi;
        a.luna = luna;
        a.min_incepere = minut;
        a.ora_incepere = ora;
        a.min_incheiere = min_terminarii;
        a.ora_incheiere = ora_terminarii;
        a.status = "PENDING";
        appointments.push_back(a);
        SaveToFileAppointments("Shared/programari.txt");
        std::cout << "Programare realizata cu succes" << std::endl;
    }

}
