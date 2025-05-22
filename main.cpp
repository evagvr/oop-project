#include <iostream>
#include <string>
#include "gameplay.h"
#include "inputHandler.h"

int main() {
    InputHandler verifInput;
    auto g = std::make_shared<Gameplay>();
    g->start();
    g->setup();
    g->incrementeazaAn();

    while (true) {
        g->afisareDate();
        g->meniu();
        std::string opt = verifInput.getStringInput({"1", "2", "3", "4", "5", "6", "7", "r", "n"});

        if (opt == "n") {
            g->incrementeazaAn();
        }
        else if (opt == "1") {
            g->repetitii();
        }
        else if (opt == "2") {
            g->inregistreazaAlbum();
        }
        else if (opt == "3") {
            g->modificaTrupa();
        }
        else if (opt == "4") {
            g->afiseazaStatusTrupa();
        }
        else if (opt == "5") {
            g->help();
        }
        else if (opt == "6") {
            g->concert();
        }
        else if (opt == "7") {
            g->turneu();
        }
        else if (opt == "r") {
            if (g->reset()) {
                g->start();
                g->setup();
                g->incrementeazaAn();
            }
        }

        if (g->terminareJoc()) {
            g->raportFinal();
            break;
        }
    }
}