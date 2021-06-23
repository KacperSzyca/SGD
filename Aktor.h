#ifndef AKTOR_HPP
#define AKTOR_HPP

#include <SDL.h>
#include "Prostokat.h"
#include <string>

class SWIAT;

class Aktor {
    friend class SWIAT;
private:
    bool m_KolizjaZeScianami[int(SCIANA::_Dlugosc)];
public:
    float m_Pozycja_X, m_Pozycja_Y;
    float m_Predkosc_X, m_Predkosc_Y;
    float m_Przyspiesznie_X, m_Przyspiesznie_Y;
    float m_Szerokosc, m_wysokosc;
    float m_Sprezystosc;

    Aktor(float pozycja_X, float pozycja_Y, float szerokosc, float wysokosc);
    virtual ~Aktor(){};
    virtual void Rysuj( float krok){};
    virtual void Aktualizuj(){};
    virtual void Zdarzenie( SDL_Event & zdarzenie ){};

    inline void Impuls ( float x, float y){
        m_Przyspiesznie_X += x;
        m_Przyspiesznie_Y += y;
    }

    inline void Tarcie_X (float  wartosc){
        m_Predkosc_X *= wartosc;
    }

    inline void Tarcie_Y (float  wartosc){
        m_Predkosc_Y *= wartosc;
    }

    inline void Tarcie_XY (float  wartosc){
        m_Predkosc_X *= wartosc;
        m_Predkosc_Y *= wartosc;
    }

    void Ogranicz_Predkosc(float x_min, float x_max, float y_min, float y_max);

    bool Koliduje_ze_Sciana( SCIANA sciana );

    bool Koliduje_z_BlokiemPalacym( PROSTOKAT<float > prostokat );

    SDL_Rect Jako_SDL_Rect();
    PROSTOKAT<float> Jako_Prostokat();
};
#endif
