#ifndef SWIAT_HPP
#define SWIAT_HPP

#include "Aktor.h"
#include <vector>
#include "Prostokat.h"
#include "SDL.h"


using namespace std;

enum class BLOK {
    Nic,
    Brick,
    Super,
    Stone,
};

bool Jest_Solidny(BLOK blok);

BLOK Znak_Bloku(char znak);

class SWIAT {
private:
    vector<Aktor *> m_Aktorzy;
    vector<BLOK> m_Bloki;
    int m_Szerokosc, m_Wysokosc;
    SDL_Texture *brick;
    SDL_Texture *super;

    // przypisane wartości sa takie aby juz w pierwszym kroku petli przypisac im nowa wartosc
    float blokipalace_x_min = 2000;
    float blokipalace_x_max = 1;
    float blokipalace_y_min = 2000;
    float blokipalace_y_max = 1;


    void Alokuj_Bloki();

    void Fizyka(Aktor *aktor);

    void Kolizje_z_Blokami(Aktor *aktor);

public:
    const static auto Szerokosc_Bloku = 32;
    const static auto Wysokosc_Bloku = 32;

    SWIAT(int szerokosc, int wysokosc);

    void Rysuj(float krok);

    void Aktualizuj();

    void Zdarzenie(SDL_Event &zdarzenie);

    vector<Aktor *> &Lista_Aktorow();

    void Przywolaj(Aktor *aktor);

    int Szerokosc();

    int Wysokosc();

    BLOK Blok(int pozycja_x, int pozycja_y);

    void UstawBlok(int pozycja_x, int pozycja_y, BLOK blok);

    SDL_Rect Blok_Jako_SDL_Rect(int pozycja_x, int pozycja_y);

    PROSTOKAT<float> Blok_Jako_Prostokat(int pozycja_x, int pozycja_y);

    PROSTOKAT<int> Prostokat_Wyrowany_Do_Blokow(PROSTOKAT<float> prostokat);


    void Laduj(vector<const char *> rzedy);
};

#endif

