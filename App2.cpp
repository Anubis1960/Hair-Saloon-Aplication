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
        std::cout << "Argumente insuficiente";
        return 1;
    }
    else{
        std::string command = argv[1];
        if (command == "vizualizare_catalog"){
            if(argc != 2){
                std::cout << "Sintaxa invalida! Sintaxa corecta: app2.exe vizualizare_catalog";
                return 1;
            }
            else{
                p.AfiseazaOferte();
            }
        }
        else{
            if(command == "programare"){
                if(argc != 9){
                    std::cout << "Sintaxa invalida! Sintaxa corecta: app2.exe programare <nume utilizator> <index oferta> <zi> <luna> <an> <ora> <minut>";
                    return 1;
                }
                std::string nume = argv[2];
                nume = std::regex_replace(nume, std::regex("_"), " ");
                int index = atoi(argv[3]);
                int zi = atoi(argv[4]);
                int luna = atoi(argv[5]);
                int an = atoi(argv[6]);
                int ora = atoi(argv[7]);
                int minut = atoi(argv[8]);
                if (ora >= 21 || ora < 10 ){
                    std::cout << "Interval orar inafara programului";
                    return 1;
                }
                p.ProgramareSedinta(nume, index, zi, luna, an, ora, minut);
            }
            else{
                if(command == "vizualizare_istoric"){
                    if (argc != 3){
                        std::cout << "Sintaxa invalida! Sintaxa corecta: app2.exe vizualizare_istoric <nume utilizator>";
                        return 1;
                    }
                    std::string nume = argv[2];
                    p.IstoricProgramari(nume);
                }
            }
        }
    }

    return 0;
}
