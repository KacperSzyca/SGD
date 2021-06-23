#include <iostream>
#include "Zasoby.h"
#include "SWIAT.h"
#include "Gracz.h"
#include "Gracz2.h"

void nowa_gra();

void kolejna_gra();

using namespace std;

//https://www.youtube.com/watch?v=1VulZJw353I
int main(int ilosc_argumentow_konsoli, char **argumenty_konsoli) {
    Laduj_Okno();
    nowa_gra();

    return 0;
}

void nowa_gra() {
    Laduj_Zasoby();

    SWIAT swiat(39, 19);
    swiat.Laduj(vector<const char *>{
            "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
            "M                                     M",
            "M                                     M",
            "M                  S                  M",
            "M                                     M",
            "M                                     M",
            "M                                     M",
            "M                                     M",
            "M                  M                  M",
            "M                                     M",
            "M            M           M            M",
            "M                         M           M",
            "M     M                         M     M",
            "M                                     M",
            "MM                                   MM",
            "M                                     M",
            "M         BBBBBBBBBBBBBBBBBBB         M",
            "M     M                         M     M",
            "M                                     M",
            "MM                                   MM",
            "M                                     M",
            "M                                     M",
            "MMMMMM                           MMMMMM",
            "M                                     M",
            "M        M                   M        M",
            "M       MMMMMMMMMMMMMMMMMMMMMMM       M",
            "M    MMMMMMMMMMMMMMMMMMMMMMMMMMMMM    M",
            "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM",
    });

    swiat.Przywolaj(new Gracz(1145, 848));
    swiat.Przywolaj(new Gracz2(64, 848));

    constexpr auto CzestotliwoscAktualizacji = 60.f;
    constexpr auto SekundyNaAktualizaje = 1.f / CzestotliwoscAktualizacji;
    SDL_Event wydarzenie;
    bool gra_wlaczona = true;
    auto czas_stary = Czas_Sekundy();
    auto czas_opoznienie = 0.f;
    bool koordynatyPobrane = false;


    while (gra_wlaczona) {

        auto czas_nowy = Czas_Sekundy();
        auto czas_delta = czas_nowy - czas_stary;
        czas_stary = czas_nowy;
        czas_opoznienie += czas_delta;

        //Proces wydarzen
        while (SDL_PollEvent(&wydarzenie)) {
            switch (wydarzenie.type) {
                case SDL_QUIT:
                    gra_wlaczona = false;
                    //SDL_DestroyTexture(SDL_Texture * texture);
                    SDL_Quit();
                    break;
            }

            swiat.Zdarzenie(wydarzenie);
        }

        //Proces rysowania(fuzyka itp)
        while (czas_opoznienie > SekundyNaAktualizaje) {
            swiat.Aktualizuj();
            czas_opoznienie -= SekundyNaAktualizaje;
        }


        // Proces rysowania
        SDL_SetRenderDrawColor(g_Rys, 0, 0, 0, 255);
        SDL_RenderClear(g_Rys);

        //uwtorzenie swiata
        const auto krok = czas_opoznienie / SekundyNaAktualizaje;
        swiat.Rysuj(krok);
        if (!koordynatyPobrane) {
            koordynatyBlokowPalacych();
            koordynatyPobrane = true;
        }


        if (blueWin == true) {
            gra_wlaczona = false;
            SDL_Surface *bluewinsurface = IMG_Load("../img/bluewin.bmp");
            SDL_Texture *bluewin = SDL_CreateTextureFromSurface(g_Rys, bluewinsurface);
            SDL_FreeSurface(bluewinsurface);
            SDL_Rect rect = {0, 0, 1240, 895};
            SDL_RenderCopy(g_Rys, bluewin, NULL, &rect);
        }
        if (redWin == true) {
            gra_wlaczona = false;
            SDL_Surface *redwinsurface = IMG_Load("../img/redwin.bmp");
            SDL_Texture *redewin = SDL_CreateTextureFromSurface(g_Rys, redwinsurface);
            SDL_FreeSurface(redwinsurface);
            SDL_Rect rect = {0, 0, 1240, 895};
            SDL_RenderCopy(g_Rys, redewin, NULL, &rect);
        }
        SDL_RenderPresent(g_Rys);
    }
    kolejna_gra();
}

void kolejna_gra() {
    SDL_Event event;
    bool graczNieWybral = true;
    const auto klawisze = SDL_GetKeyboardState(NULL);
    while (graczNieWybral) {
        if (SDL_WaitEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    graczNieWybral = false;
                    break;
            }
            if (klawisze[SDL_SCANCODE_Q]) {
                graczNieWybral = false;
                SDL_Quit();
            }
            if (klawisze[SDL_SCANCODE_R]) {
                graczNieWybral = false;
                nowa_gra();
            }
        }
    }

}





