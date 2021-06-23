#include <SDL.h>
#include <vector>
#include <cstdio>
#include "Zasoby.h"

SDL_Window * g_Okno;
SDL_Renderer * g_Rys;
SDL_Texture* rock;
float blokipalace_x_min ;
float blokipalace_x_max;
float blokipalace_y_min;
float blokipalace_y_max ;
std::vector <PROSTOKAT<float>> g_Debug_Prostokaty;
std::vector <PROSTOKAT<float>> bloki_palace;
SDL_Rect blokDodadkowy;
bool blokDodadkowyState;
bool redWin;
bool blueWin;
float x_gracza1;
float y_gracza1;
float x_gracza2;
float y_gracza2;
float hp_gr1;
float hp_gr2 ;

void Laduj_Zasoby(){
    blokipalace_x_min = 2000;
    blokipalace_x_max = 1;
    blokipalace_y_min = 2000;
    blokipalace_y_max = 1;
    hp_gr1 = 100;
    hp_gr2 = 100;

    blokDodadkowyState = true;
    redWin = false;
    blueWin = false;

}

void Laduj_Okno(){
    const auto Okno_X = SDL_WINDOWPOS_UNDEFINED;
    const auto Okno_Y = SDL_WINDOWPOS_UNDEFINED;
    const auto Okno_Szerokosc = 1240;
    const auto Okno_Wysokosc = 895;
    const auto Okno_Flagi = 0;

    g_Okno = SDL_CreateWindow(
            "Bijatyka",
            Okno_X,Okno_Y,
            Okno_Szerokosc, Okno_Wysokosc,
            Okno_Flagi
    );

    const auto Rys_Urzadzenie = -1;
    const auto Rys_Flagi = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    g_Rys = SDL_CreateRenderer(g_Okno, Rys_Urzadzenie, Rys_Flagi);
}

float Czas_Sekundy(){
    return float (SDL_GetTicks()) / 1'000.f;
}

void Debug_Prostokat(PROSTOKAT<float> prostokat){
    g_Debug_Prostokaty.push_back(prostokat);
}

void Debug_Rysuj_Prostokaty(){
    if( g_Debug_Prostokaty.size() <= 0){
        return;
    }
    SDL_SetRenderDrawColor(g_Rys, 255,0,0,255);
    for( auto &prostokat:g_Debug_Prostokaty){
        SDL_Rect sdl_prostokat{
            int ( prostokat.X ),int ( prostokat.Y),
            int ( prostokat.S ),int ( prostokat.W),
        };
        SDL_RenderDrawRect(g_Rys, &sdl_prostokat);
    }
    g_Debug_Prostokaty.clear();
}

void DodajBlokPalacy(PROSTOKAT<float> prostokat){
    bloki_palace.push_back(prostokat);
}

void koordynatyBlokowPalacych(){
    if( bloki_palace.size() <= 0){
        return;
    }
    //najmniejszy x najmniejszy y
    //najwiekszy x najmniejszy y
    // najmniejszy x najwiekszy y
    // najwiekszy x najwiekszy y

    for(auto &prostokat:bloki_palace){
        if(blokipalace_x_min > prostokat.X){
            blokipalace_x_min = prostokat.X;
        }
        if(blokipalace_x_max < prostokat.X){
            blokipalace_x_max = prostokat.X;
        }
        if(blokipalace_y_min > prostokat.Y){
            blokipalace_y_min = prostokat.Y;
        }
        if(blokipalace_x_max < prostokat.Y){
            blokipalace_y_max = prostokat.Y;
        }
    }
    bloki_palace.clear();
}

bool sprawdzCzyJestesWBlokuPalacym(float x, float y){
    return (x+50 > blokipalace_x_min && y+100 > blokipalace_y_min
           && x-50 < blokipalace_x_max && y-40 < blokipalace_y_max);
}

bool czyJestWBlokuDodadkowym(float x, float y){
    return (x+40 > blokDodadkowy.x && y+5 > blokDodadkowy.y
           && x < blokDodadkowy.x+blokDodadkowy.w && y-5 < blokDodadkowy.y + blokDodadkowy.h);
}

bool Przeciwnik_po_Lewej(float x, float y,float szerokosc,float wysokosc, int id){
    float xPrzeciwnik;
    float yPrzeciwnik;
    if(id ==1){
        xPrzeciwnik = x_gracza2;
        yPrzeciwnik = y_gracza2;
    }else{
        xPrzeciwnik = x_gracza1;
        yPrzeciwnik = y_gracza1;
    }
    return (x-5> xPrzeciwnik && x-(szerokosc*0.65) < xPrzeciwnik && y-(wysokosc*0.6) < yPrzeciwnik  && y+(wysokosc*0.8) > yPrzeciwnik);
}

bool Przeciwnik_po_Prawej(float x, float y,float szerokosc,float wysokosc, int id){
    float xPrzeciwnik;
    float yPrzeciwnik;
    if(id ==1){
        xPrzeciwnik = x_gracza2;
        yPrzeciwnik = y_gracza2;
    }else{
        xPrzeciwnik = x_gracza1;
        yPrzeciwnik = y_gracza1;
    }
    return (x-5 < xPrzeciwnik && x+(szerokosc*0.65) > xPrzeciwnik && y-(wysokosc*0.6) < yPrzeciwnik  && y+(wysokosc*0.8) > yPrzeciwnik);
}
