#ifndef ZASOBY_HPP
#define ZASOBY_HPP

#include <SDL.h>
#include "Prostokat.h"
#include <SDL_image.h>

extern SDL_Window * g_Okno;
extern SDL_Renderer * g_Rys;
extern float blokipalace_x_min;
extern float blokipalace_x_max;
extern float blokipalace_y_min;
extern float blokipalace_y_max;
extern SDL_Texture* rock;
extern SDL_Rect blokDodadkowy;
extern bool blokDodadkowyState;
extern bool redWin;
extern bool blueWin;

extern float x_gracza1;
extern float y_gracza1;
extern float x_gracza2;
extern float y_gracza2;

extern float hp_gr1;
extern float hp_gr2;

// przypisane wartości sa takie aby juz w pierwszym kroku petli przypisac im nowa wartosc





void Laduj_Textury();
void Laduj_Zasoby();
void Laduj_Okno();
float Czas_Sekundy();
void Debug_Prostokat( PROSTOKAT<float> prostokat);
void Debug_Rysuj_Prostokaty();
void DodajBlokPalacy(PROSTOKAT<float> prostokat);
void koordynatyBlokowPalacych();
bool sprawdzCzyJestesWBlokuPalacym(float x, float y);
bool czyJestWBlokuDodadkowym(float x, float y);
bool Przeciwnik_po_Lewej(float x, float y,float szerokosc,float wysokosc, int id);
bool Przeciwnik_po_Prawej(float x, float y,float szerokosc,float wysokosc, int id);

#endif
