#ifndef SDGPROJECT_GRACZ2_H
#define SDGPROJECT_GRACZ2_H

#include "Aktor.h"

class Gracz2 : public Aktor {
private:
    int wartosc_ataku;
    int counter;
    bool animacjaWalki1;
    bool animacjaWalki2;
    bool animacjaWalki3;
    bool animacjaWalki4;
    int prevHp;
    int counterForFireBlock;
    int attack1counter;
    int attack2counter;
public:
    float m_Szybkosc;

    Gracz2(float pozycja_x, float pozycja_y);

    virtual ~Gracz2() {};

    void Rysuj(float krok) override;

    void Aktualizuj() override;

    void Zdarzenie(SDL_Event &zdarzenie) override;

};


#endif //SDGPROJECT_GRACZ2_H
