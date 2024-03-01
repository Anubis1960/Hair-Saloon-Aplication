#include <iostream>
#include "Data/Programari.h"
#include <string>
#include <fstream>
#include <fstream>
#include <cstring>
#include <regex>
int main(int argc, char* argv[]) {
    std::string filePath = "Shared/oferte.txt";
    std::string filePath1 = "Shared/programari.txt";
    Programari p(filePath, filePath1);
    if (argc < 2){
        return 1;
        std::cout << "Argumente insuficiente";
    }
    else{

        std::string command = argv[1];
        if (command == "stergere_oferta"){
            if (argc != 3){
                std::cout << "Sintaxa invalida! Sintaxa corecta: app1.exe stergere_oferta <index>";
                return 1;
            }
            int index = atoi(argv[2]);
            p.StergeOferta(index);
            std::cout << "Stergere realizata cu succes";
        }
        else{
            if(command == "acceptare_programare")
                if(argc != 2){
                    std::cout << "Sintaxa invalida! Sintaxa corecta: app1.exe acceptare_programare";
                    return 1;
                }
                else{
                    p.AcceptaProgramari();
                }
            else{
                if(command == "vizualizare_disponibilitate"){
                    if (argc != 5){
                        std::cout << "Sintaxa invalida! Sintaxa corecta: app1.exe vizualizare_disponibilitate <zi> <luna> <an>";
                        return 1;
                    }
                    int zi = atoi(argv[2]);
                    int luna = atoi(argv[3]);
                    int an = atoi(argv[4]);
                    p.VizualizeazaDisponibilitate(zi,luna,an);
                }
                else{
                    if(command == "adauga_oferta"){
                        if(argc != 5){
                            std::cout << "Sintaxa invalida! Sintaxa corecta: app1.exe adauga_oferta <nume oferta> <pret> <durata>";
                            return 1;
                        }
                        std::string numa = argv[2];
                        numa = std::regex_replace(numa, std::regex("_"), " ");
                        int pret = atoi(argv[3]);
                        int durata = atoi(argv[4]);
                        p.AdaugaOferta(numa, pret, durata);
                        std::cout << "Oferta adaugata cu succes";
                    }
                    else{
                        if(command == "modifica_oferta"){
                            if(argc != 6){
                                std::cout << "Sintaxa invalida! Sintaxa corecta: app1.exe modifica_oferta <nume nou oferta> <pret nou> <durata noua> <index>";
                                return 1;
                            }
                            std::string nume = argv[2];
                            nume = std::regex_replace(nume, std::regex("_"), " ");
                            int pret = atoi(argv[3]);
                            int durata = atoi(argv[4]);
                            int index = atoi(argv[5]);
                            p.ModificaOferta(index, nume, pret, durata);
                            std::cout << "Oferta modificata cu succes";
                        }
                    }
                }
            }
        }
    }

    return 0;
}
