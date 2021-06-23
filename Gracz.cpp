#include <SDL_ttf.h>
#include "Gracz.h"
#include "Zasoby.h"

SDL_Texture *texGracz1;
SDL_Texture *czerwLewo1;
SDL_Texture *czerwLewo2;
SDL_Texture *czerwLewo3;
SDL_Texture *czerwLewo4;

SDL_Texture *czerwPrawo1;
SDL_Texture *czerwPrawo2;
SDL_Texture *czerwPrawo3;
SDL_Texture *czerwPrawo4;

SDL_Texture *czerwreceprawo1;
SDL_Texture *czerwreceprawo2;
SDL_Texture *czerwreceprawo3;

SDL_Texture *czerwrecelewo1;
SDL_Texture *czerwrecelewo2;
SDL_Texture *czerwrecelewo3;

SDL_Texture *czerwnogiprawo1;
SDL_Texture *czerwnogiprawo2;
SDL_Texture *czerwnogiprawo3;

SDL_Texture *czerwnogilewo1;
SDL_Texture *czerwnogilewo2;
SDL_Texture *czerwnogilewo3;

SDL_Texture *pasekZyciaGr1;
bool blockChanged = false;

int tickLeft = 0;
int tickRight = 0;

//https://lazyfoo.net/tutorials/SDL/14_animated_sprites_and_vsync/index.php
//https://www.youtube.com/watch?v=RqvpkZ7I1aU
Gracz::Gracz(float pozycja_x, float pozycja_y) : Aktor(pozycja_x, pozycja_y, 48, 96), m_Szybkosc(3.f), wartosc_ataku(10) {
    SDL_Surface *ludzikRedStoi = IMG_Load(
            "../img/czerw.bmp"); // <- png nie dzialalo https://discourse.libsdl.org/t/sdl2-image-fails-loading-libpng-on-latest-versions-when-cross-compiling/24494/10
    texGracz1 = SDL_CreateTextureFromSurface(g_Rys, ludzikRedStoi);
    SDL_FreeSurface(ludzikRedStoi);

    SDL_Surface *czerwLewo1surface = IMG_Load("../img/czerwLewo1.bmp");
    czerwLewo1 = SDL_CreateTextureFromSurface(g_Rys, czerwLewo1surface);
    SDL_FreeSurface(czerwLewo1surface);

    SDL_Surface *czerwLewo2surface = IMG_Load("../img/czerwLewo2.bmp");
    czerwLewo2 = SDL_CreateTextureFromSurface(g_Rys, czerwLewo2surface);
    SDL_FreeSurface(czerwLewo2surface);

    SDL_Surface *czerwLewo3surface = IMG_Load("../img/czerwLewo3.bmp");
    czerwLewo3 = SDL_CreateTextureFromSurface(g_Rys, czerwLewo3surface);
    SDL_FreeSurface(czerwLewo3surface);

    SDL_Surface *czerwLewo4surface = IMG_Load("../img/czerwLewo4.bmp");
    czerwLewo4 = SDL_CreateTextureFromSurface(g_Rys, czerwLewo4surface);
    SDL_FreeSurface(czerwLewo4surface);

    SDL_Surface *czerwPrawo1surface = IMG_Load("../img/czerwprawo1.bmp");
    czerwPrawo1 = SDL_CreateTextureFromSurface(g_Rys, czerwPrawo1surface);
    SDL_FreeSurface(czerwPrawo1surface);

    SDL_Surface *czerwPrawo2surface = IMG_Load("../img/czerwprawo2.bmp");
    czerwPrawo2 = SDL_CreateTextureFromSurface(g_Rys, czerwPrawo2surface);
    SDL_FreeSurface(czerwPrawo2surface);

    SDL_Surface *czerwPrawo3surface = IMG_Load("../img/czerwprawo3.bmp");
    czerwPrawo3 = SDL_CreateTextureFromSurface(g_Rys, czerwPrawo3surface);
    SDL_FreeSurface(czerwPrawo3surface);

    SDL_Surface *czerwPrawo4surface = IMG_Load("../img/czerwprawo4.bmp");
    czerwPrawo4 = SDL_CreateTextureFromSurface(g_Rys, czerwPrawo4surface);
    SDL_FreeSurface(czerwPrawo4surface);

    SDL_Surface *czerwreceprawo1surface = IMG_Load("../img/atak/czerwony/czerwreceprawo1.bmp");
    czerwreceprawo1 = SDL_CreateTextureFromSurface(g_Rys, czerwreceprawo1surface);
    SDL_FreeSurface(czerwreceprawo1surface);

    SDL_Surface *czerwreceprawo2surface = IMG_Load("../img/atak/czerwony/czerwreceprawo2.bmp");
    czerwreceprawo2 = SDL_CreateTextureFromSurface(g_Rys, czerwreceprawo2surface);
    SDL_FreeSurface(czerwreceprawo2surface);

    SDL_Surface *czerwreceprawo3surface = IMG_Load("../img/atak/czerwony/czerwreceprawo3.bmp");
    czerwreceprawo3 = SDL_CreateTextureFromSurface(g_Rys, czerwreceprawo3surface);
    SDL_FreeSurface(czerwreceprawo3surface);

    SDL_Surface *czerwrecelewo1surface = IMG_Load("../img/atak/czerwony/czerwrecelewo1.bmp");
    czerwrecelewo1 = SDL_CreateTextureFromSurface(g_Rys, czerwrecelewo1surface);
    SDL_FreeSurface(czerwrecelewo1surface);

    SDL_Surface *czerwrecelewo2surface = IMG_Load("../img/atak/czerwony/czerwrecelewo2.bmp");
    czerwrecelewo2 = SDL_CreateTextureFromSurface(g_Rys, czerwrecelewo2surface);
    SDL_FreeSurface(czerwrecelewo2surface);

    SDL_Surface *czerwrecelewo3surface = IMG_Load("../img/atak/czerwony/czerwrecelewo3.bmp");
    czerwrecelewo3 = SDL_CreateTextureFromSurface(g_Rys, czerwrecelewo3surface);
    SDL_FreeSurface(czerwrecelewo3surface);

    SDL_Surface *czerwnogiprawo1surface = IMG_Load("../img/atak/czerwony/czerwnogiprawo1.bmp");
    czerwnogiprawo1 = SDL_CreateTextureFromSurface(g_Rys, czerwnogiprawo1surface);
    SDL_FreeSurface(czerwnogiprawo1surface);

    SDL_Surface *czerwnogiprawo2surface = IMG_Load("../img/atak/czerwony/czerwnogiprawo2.bmp");
    czerwnogiprawo2 = SDL_CreateTextureFromSurface(g_Rys, czerwnogiprawo2surface);
    SDL_FreeSurface(czerwnogiprawo2surface);

    SDL_Surface *czerwnogiprawo3surface = IMG_Load("../img/atak/czerwony/czerwnogiprawo3.bmp");
    czerwnogiprawo3 = SDL_CreateTextureFromSurface(g_Rys, czerwnogiprawo3surface);
    SDL_FreeSurface(czerwnogiprawo3surface);

    SDL_Surface *czerwnogilewo1surface = IMG_Load("../img/atak/czerwony/czerwnogilewo1.bmp");
    czerwnogilewo1 = SDL_CreateTextureFromSurface(g_Rys, czerwnogilewo1surface);
    SDL_FreeSurface(czerwnogilewo1surface);

    SDL_Surface *czerwnogilewo2surface = IMG_Load("../img/atak/czerwony/czerwnogilewo2.bmp");
    czerwnogilewo2 = SDL_CreateTextureFromSurface(g_Rys, czerwnogilewo2surface);
    SDL_FreeSurface(czerwnogilewo2surface);

    SDL_Surface *czerwnogilewo3surface = IMG_Load("../img/atak/czerwony/czerwnogilewo3.bmp");
    czerwnogilewo3 = SDL_CreateTextureFromSurface(g_Rys, czerwnogilewo3surface);
    SDL_FreeSurface(czerwnogilewo3surface);

    SDL_Surface *pasekZyciaImg = IMG_Load("../img/brick.bmp");
    pasekZyciaGr1 = SDL_CreateTextureFromSurface(g_Rys, pasekZyciaImg);
    SDL_FreeSurface(pasekZyciaImg);

}


void Gracz::Rysuj(float krok) {
    ++counter;
    int x_life = 900;
    for (int i = 0; i < (int) hp_gr1 / 10; i++) {
        SDL_Rect lifeTexture = {x_life += 20, 40, 10, 10};
        SDL_RenderCopy(g_Rys, pasekZyciaGr1, NULL, &lifeTexture);
    }
    //printf("%d  ds \n", (int)counter);
    auto prostokat = Jako_SDL_Rect();
    SDL_Texture *nowTexture;
    const auto klawisze = SDL_GetKeyboardState(NULL);
    if (klawisze[SDL_SCANCODE_LEFT]) {
        if (tickLeft < 10) {
            nowTexture = czerwLewo1;
            ++tickLeft;
        } else if (tickLeft >= 10 && tickLeft < 20) {
            nowTexture = czerwLewo2;
            ++tickLeft;
        } else if (tickLeft >= 20 && tickLeft < 30) {
            nowTexture = czerwLewo3;
            ++tickLeft;
        } else if (tickLeft >= 30) {
            nowTexture = czerwLewo4;
            tickLeft = 0;
        }
    } else if (klawisze[SDL_SCANCODE_RIGHT]) {
        if (tickRight < 10) {
            nowTexture = czerwPrawo1;
            ++tickRight;
        } else if (tickRight >= 10 && tickRight < 20) {
            nowTexture = czerwPrawo2;
            ++tickRight;
        } else if (tickRight >= 20 && tickRight < 30) {
            nowTexture = czerwPrawo3;
            ++tickRight;
        } else if (tickRight >= 30) {
            nowTexture = czerwPrawo4;
            tickRight = 0;
        }
    } else if ((klawisze[SDL_SCANCODE_K] and ostatniWcisnietyKlawisz == "prawy") or animacjaWalki1) {
        if (klawisze[SDL_SCANCODE_K] and ostatniWcisnietyKlawisz == "prawy") {
            counter = 0;
        }
        if (counter < 6) {
            animacjaWalki1 = true;
            nowTexture = czerwreceprawo1;
        } else if (counter >= 6 and counter < 12) {
            nowTexture = czerwreceprawo2;
        } else if (counter >= 12 and counter < 18) {
            nowTexture = czerwreceprawo3;
        } else if (counter >= 18 and counter < 24) {
            nowTexture = czerwreceprawo2;
        } else if (counter >= 24 and counter < 30) {
            nowTexture = czerwreceprawo1;
        } else {
            //counter =0;
            nowTexture = texGracz1;
            animacjaWalki1 = false;
        }

    } else if ((klawisze[SDL_SCANCODE_K] and ostatniWcisnietyKlawisz == "lewy") or animacjaWalki2) {
        if (klawisze[SDL_SCANCODE_K] and ostatniWcisnietyKlawisz == "lewy") {
            counter = 0;
        }
        if (counter < 6) {
            animacjaWalki2 = true;
            nowTexture = czerwrecelewo1;
        } else if (counter >= 6 and counter < 12) {
            nowTexture = czerwrecelewo2;
        } else if (counter >= 12 and counter < 18) {
            nowTexture = czerwrecelewo3;
        } else if (counter >= 18 and counter < 24) {
            nowTexture = czerwrecelewo2;
        } else if (counter >= 24 and counter < 30) {
            nowTexture = czerwrecelewo1;
        } else {
            //counter =0;
            nowTexture = texGracz1;
            animacjaWalki2 = false;
        }

    } else if ((klawisze[SDL_SCANCODE_L] and ostatniWcisnietyKlawisz == "prawy") or animacjaWalki3) {
        if (klawisze[SDL_SCANCODE_L] and ostatniWcisnietyKlawisz == "prawy") {
            counter = 0;
        }

        if (counter < 6) {
            animacjaWalki3 = true;
            nowTexture = czerwnogiprawo1;
        } else if (counter >= 6 and counter < 12) {
            nowTexture = czerwnogiprawo2;
        } else if (counter >= 12 and counter < 18) {
            nowTexture = czerwnogiprawo3;
        } else if (counter >= 18 and counter < 24) {
            nowTexture = czerwnogiprawo2;
        } else if (counter >= 24 and counter < 30) {
            nowTexture = czerwnogiprawo1;
        } else {
            //counter =0;
            nowTexture = texGracz1;
            animacjaWalki3 = false;
        }


    } else if ((klawisze[SDL_SCANCODE_L] and ostatniWcisnietyKlawisz == "lewy") or animacjaWalki4) {
        if (klawisze[SDL_SCANCODE_L] and ostatniWcisnietyKlawisz == "lewy") {
            counter = 0;
        }
        if (counter < 6) {
            animacjaWalki4 = true;
            nowTexture = czerwnogilewo1;
        } else if (counter >= 6 and counter < 12) {
            nowTexture = czerwnogilewo2;
        } else if (counter >= 12 and counter < 18) {
            nowTexture = czerwnogilewo3;
        } else if (counter >= 18 and counter < 24) {
            nowTexture = czerwnogilewo2;
        } else if (counter >= 24 and counter < 30) {
            nowTexture = czerwnogilewo1;
        } else {
            //counter =0;
            nowTexture = texGracz1;
            animacjaWalki4 = false;
        }
    } else {
        nowTexture = texGracz1;
        tickRight = 0;
        tickLeft = 0;
    }
    SDL_RenderCopy(g_Rys, nowTexture, NULL, &prostokat);

}


void Gracz::Aktualizuj() {

    const auto klawisze = SDL_GetKeyboardState(NULL);
    // SDL_FreeSurface(surfaceMessage);
    //SDL_DestroyTexture(Message);

    x_gracza1 = m_Pozycja_X;
    y_gracza1 = m_Pozycja_Y;

    if (klawisze[SDL_SCANCODE_LEFT]) {
        Impuls(-m_Szybkosc, 0);
        ostatniWcisnietyKlawisz = "lewy";
    }
    if (klawisze[SDL_SCANCODE_RIGHT]) {
        Impuls(+m_Szybkosc, 0);
        ostatniWcisnietyKlawisz = "prawy";
    }
    //grawitacja
    Impuls(0, 0.3f);
    Tarcie_X(0.4f);

    if (m_Pozycja_Y < 300) {
        Tarcie_X(0.3f);
    }

    if (sprawdzCzyJestesWBlokuPalacym(m_Pozycja_X, m_Pozycja_Y)) {
        hp_gr1 -= 0.5;
    }

    if (czyJestWBlokuDodadkowym(m_Pozycja_X, m_Pozycja_Y) && blokDodadkowyState) {
        hp_gr1 += 50;
        wartosc_ataku +=20;
        blokDodadkowyState = false;
    }

    if (hp_gr1 <= 0) {
        blueWin = true;
    }
}

void Gracz::Zdarzenie(SDL_Event &zdarzenie) {

    if (zdarzenie.type == SDL_KEYDOWN and not zdarzenie.key.repeat) {
        if (zdarzenie.key.keysym.scancode == SDL_SCANCODE_UP and Koliduje_ze_Sciana(SCIANA::Grona)) {
            //skok
            Impuls(0, -8.f);
        }
        if (zdarzenie.key.keysym.scancode == SDL_SCANCODE_K and
            Przeciwnik_po_Prawej(m_Pozycja_X, m_Pozycja_Y, m_Szerokosc, m_wysokosc, 1) and
            ostatniWcisnietyKlawisz == "prawy") {
            hp_gr2 -= wartosc_ataku;
        }
        if (zdarzenie.key.keysym.scancode == SDL_SCANCODE_K and
            Przeciwnik_po_Lewej(m_Pozycja_X, m_Pozycja_Y, m_Szerokosc, m_wysokosc, 1) and
            ostatniWcisnietyKlawisz == "lewy") {
            hp_gr2 -= wartosc_ataku;
        }
        if (zdarzenie.key.keysym.scancode == SDL_SCANCODE_L and
            Przeciwnik_po_Prawej(m_Pozycja_X, m_Pozycja_Y, m_Szerokosc, m_wysokosc, 1) and
            ostatniWcisnietyKlawisz == "prawy") {
            hp_gr2 -= wartosc_ataku;
        }
        if (zdarzenie.key.keysym.scancode == SDL_SCANCODE_L and
            Przeciwnik_po_Lewej(m_Pozycja_X, m_Pozycja_Y, m_Szerokosc, m_wysokosc, 1) and
            ostatniWcisnietyKlawisz == "lewy") {
            hp_gr2 -= wartosc_ataku;
        }

    }

}
