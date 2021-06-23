#include "Aktor.h"

#include <algorithm>
#include <cstring>

Aktor::Aktor(float pozycja_x, float pozycja_y, float szerokosc, float wysokosc)
:m_Pozycja_X(pozycja_x),m_Pozycja_Y(pozycja_y)
,m_Szerokosc(szerokosc),m_wysokosc(wysokosc)
,m_Predkosc_X(0),m_Predkosc_Y(0)
,m_Przyspiesznie_X(0),m_Przyspiesznie_Y(0)
,m_Sprezystosc(0)
{
    std::memset(m_KolizjaZeScianami,0,sizeof(m_KolizjaZeScianami));
}

SDL_Rect Aktor::Jako_SDL_Rect() {
    return SDL_Rect{
        int(m_Pozycja_X), int (m_Pozycja_Y),
        int (m_Szerokosc), int(m_wysokosc)
    };
}


void Aktor::Ogranicz_Predkosc(float x_min, float x_maks, float y_min, float y_maks) {
         m_Predkosc_X  = std::max(x_min, std::min(x_maks, m_Predkosc_X));
         m_Predkosc_Y  = std::max(y_min, std::min(y_maks, m_Predkosc_Y));
}

bool Aktor::Koliduje_ze_Sciana(SCIANA sciana) {
    return m_KolizjaZeScianami[int(sciana)];
}


PROSTOKAT<float> Aktor::Jako_Prostokat() {
    return PROSTOKAT<float>{
        m_Pozycja_X,m_Pozycja_Y,
        m_Szerokosc,m_wysokosc,
    };
}
