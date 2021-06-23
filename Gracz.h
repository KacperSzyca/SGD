#ifndef SDGPROJECT_GRACZ_H
#define SDGPROJECT_GRACZ_H

#include "Aktor.h"

class Gracz : public Aktor {
private:
    int wartosc_ataku;
    std::string ostatniWcisnietyKlawisz;
    int counter;
    bool animacjaWalki1;
    bool animacjaWalki2;
    bool animacjaWalki3;
    bool animacjaWalki4;
public:
    float m_Szybkosc;


    Gracz(float pozycja_x, float pozycja_y);

    virtual ~Gracz() {};

    void Rysuj(float krok) override;

    void Aktualizuj() override;

    void Zdarzenie(SDL_Event &zdarzenie) override;
};


#endif //SDGPROJECT_GRACZ_H
