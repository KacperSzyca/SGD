#include <cstdio>
#include "Gracz2.h"
#include "Zasoby.h"

SDL_Texture* texNiebieski;
SDL_Texture* niebLewo1;
SDL_Texture* niebLewo2;
SDL_Texture* niebLewo3;
SDL_Texture* niebLewo4;

SDL_Texture* niebPrawo1;
SDL_Texture* niebPrawo2;
SDL_Texture* niebPrawo3;
SDL_Texture* niebPrawo4;


SDL_Texture* niebreceprawo1;
SDL_Texture* niebreceprawo2;
SDL_Texture* niebreceprawo3;

SDL_Texture* niebrecelewo1;
SDL_Texture* niebrecelewo2;
SDL_Texture* niebrecelewo3;

SDL_Texture* niebnogiprawo1;
SDL_Texture* niebnogiprawo2;
SDL_Texture* niebnogiprawo3;

SDL_Texture* niebnogilewo1;
SDL_Texture* niebnogilewo2;
SDL_Texture* niebnogilewo3;

SDL_Texture* pasekZyciaGr2;
int tickLeftGracz2 = 0;
int tickRightGracz2 = 0;

Gracz2::Gracz2(float pozycja_x, float pozycja_y):Aktor(pozycja_x,pozycja_y,48, 96),m_Szybkosc(3.f),wartosc_ataku(10) {
    SDL_Surface* ludzikRedStoi = IMG_Load("../img/GraczNiebieski/nieb.bmp"); // <- png nie dzialalo https://discourse.libsdl.org/t/sdl2-image-fails-loading-libpng-on-latest-versions-when-cross-compiling/24494/10
    texNiebieski = SDL_CreateTextureFromSurface(g_Rys, ludzikRedStoi);
    SDL_FreeSurface(ludzikRedStoi);

    SDL_Surface* niebLewo1surface = IMG_Load("../img/GraczNiebieski/niebLewo1.bmp");
    niebLewo1 = SDL_CreateTextureFromSurface(g_Rys, niebLewo1surface);
    SDL_FreeSurface(niebLewo1surface);

    SDL_Surface* niebLewo2surface = IMG_Load("../img/GraczNiebieski/niebLewo2.bmp");
    niebLewo2 = SDL_CreateTextureFromSurface(g_Rys, niebLewo2surface);
    SDL_FreeSurface(niebLewo2surface);

    SDL_Surface* niebLewo3surface = IMG_Load("../img/GraczNiebieski/niebLewo3.bmp");
    niebLewo3 = SDL_CreateTextureFromSurface(g_Rys, niebLewo3surface);
    SDL_FreeSurface(niebLewo3surface);

    SDL_Surface* niebLewo4surface = IMG_Load("../img/GraczNiebieski/niebLewo4.bmp");
    niebLewo4 = SDL_CreateTextureFromSurface(g_Rys, niebLewo4surface);
    SDL_FreeSurface(niebLewo4surface);

    SDL_Surface* niebPrawo1surface = IMG_Load("../img/GraczNiebieski/niebprawo1.bmp");
    niebPrawo1 = SDL_CreateTextureFromSurface(g_Rys, niebPrawo1surface);
    SDL_FreeSurface(niebPrawo1surface);

    SDL_Surface* niebPrawo2surface = IMG_Load("../img/GraczNiebieski/niebprawo2.bmp");
    niebPrawo2 = SDL_CreateTextureFromSurface(g_Rys, niebPrawo2surface);
    SDL_FreeSurface(niebPrawo2surface);

    SDL_Surface* niebPrawo3surface = IMG_Load("../img/GraczNiebieski/niebprawo3.bmp");
    niebPrawo3 = SDL_CreateTextureFromSurface(g_Rys, niebPrawo3surface);
    SDL_FreeSurface(niebPrawo3surface);

    SDL_Surface* niebPrawo4surface = IMG_Load("../img/GraczNiebieski/niebprawo4.bmp");
    niebPrawo4 = SDL_CreateTextureFromSurface(g_Rys, niebPrawo4surface);
    SDL_FreeSurface(niebPrawo4surface);

    SDL_Surface* niebreceprawo1surface = IMG_Load("../img/atak/niebieski/niebreceprawo1.bmp");
    niebreceprawo1 = SDL_CreateTextureFromSurface(g_Rys, niebreceprawo1surface);
    SDL_FreeSurface(niebreceprawo1surface);

    SDL_Surface* niebreceprawo2surface = IMG_Load("../img/atak/niebieski/niebreceprawo2.bmp");
    niebreceprawo2 = SDL_CreateTextureFromSurface(g_Rys, niebreceprawo2surface);
    SDL_FreeSurface(niebreceprawo2surface);

    SDL_Surface* niebreceprawo3surface = IMG_Load("../img/atak/niebieski/niebreceprawo3.bmp");
    niebreceprawo3 = SDL_CreateTextureFromSurface(g_Rys, niebreceprawo3surface);
    SDL_FreeSurface(niebreceprawo3surface);

    SDL_Surface* niebrecelewo1surface = IMG_Load("../img/atak/niebieski/niebrecelewo1.bmp");
    niebrecelewo1 = SDL_CreateTextureFromSurface(g_Rys, niebrecelewo1surface);
    SDL_FreeSurface(niebrecelewo1surface);

    SDL_Surface* niebrecelewo2surface = IMG_Load("../img/atak/niebieski/niebrecelewo2.bmp");
    niebrecelewo2 = SDL_CreateTextureFromSurface(g_Rys, niebrecelewo2surface);
    SDL_FreeSurface(niebrecelewo2surface);

    SDL_Surface* niebrecelewo3surface = IMG_Load("../img/atak/niebieski/niebrecelewo3.bmp");
    niebrecelewo3 = SDL_CreateTextureFromSurface(g_Rys, niebrecelewo3surface);
    SDL_FreeSurface(niebrecelewo3surface);

    SDL_Surface* niebnogiprawo1surface = IMG_Load("../img/atak/niebieski/niebnogiprawo1.bmp");
    niebnogiprawo1 = SDL_CreateTextureFromSurface(g_Rys, niebnogiprawo1surface);
    SDL_FreeSurface(niebnogiprawo1surface);

    SDL_Surface* niebnogiprawo2surface = IMG_Load("../img/atak/niebieski/niebnogiprawo2.bmp");
    niebnogiprawo2 = SDL_CreateTextureFromSurface(g_Rys, niebnogiprawo2surface);
    SDL_FreeSurface(niebnogiprawo2surface);

    SDL_Surface* niebnogiprawo3surface = IMG_Load("../img/atak/niebieski/niebnogiprawo3.bmp");
    niebnogiprawo3 = SDL_CreateTextureFromSurface(g_Rys, niebnogiprawo3surface);
    SDL_FreeSurface(niebnogiprawo3surface);

    SDL_Surface* niebnogilewo1surface = IMG_Load("../img/atak/niebieski/niebnogilewo1.bmp");
    niebnogilewo1 = SDL_CreateTextureFromSurface(g_Rys, niebnogilewo1surface);
    SDL_FreeSurface(niebnogilewo1surface);

    SDL_Surface* niebnogilewo2surface = IMG_Load("../img/atak/niebieski/niebnogilewo2.bmp");
    niebnogilewo2 = SDL_CreateTextureFromSurface(g_Rys, niebnogilewo2surface);
    SDL_FreeSurface(niebnogilewo2surface);

    SDL_Surface* niebnogilewo3surface = IMG_Load("../img/atak/niebieski/niebnogilewo3.bmp");
    niebnogilewo3 = SDL_CreateTextureFromSurface(g_Rys, niebnogilewo3surface);
    SDL_FreeSurface(niebnogilewo3surface);

    SDL_Surface* pasekZyciaImg = IMG_Load("../img/brick.bmp");
    pasekZyciaGr2 = SDL_CreateTextureFromSurface(g_Rys, pasekZyciaImg);
    SDL_FreeSurface(pasekZyciaImg);
}

void Gracz2::Rysuj(float krok) {
    auto prostokat = Jako_SDL_Rect();
    ++counter;

    int x_life = 80;
    for(int i = 0; i < (int)hp_gr2/10; i++){
        SDL_Rect lifePosition = {x_life += 20,40,10,10};
        SDL_RenderCopy( g_Rys, pasekZyciaGr2, NULL, &lifePosition);
    }

    SDL_Texture* nowTexture;
    const auto klawisze = SDL_GetKeyboardState(NULL);
    if(klawisze[SDL_SCANCODE_A]  ){
        if(tickLeftGracz2 < 10){
            nowTexture = niebLewo1;
            ++tickLeftGracz2;
        } else if (tickLeftGracz2 >= 10 && tickLeftGracz2 < 20){
            nowTexture = niebLewo2;
            ++tickLeftGracz2;
        } else if (tickLeftGracz2 >= 20 && tickLeftGracz2 < 30){
            nowTexture = niebLewo3;
            ++tickLeftGracz2;
        } else if ( tickLeftGracz2 >= 30){
            nowTexture = niebLewo4;
            tickLeftGracz2 = 0;
        }
    } else if(klawisze[SDL_SCANCODE_D] ){
        if(tickRightGracz2 < 10){
            nowTexture = niebPrawo1;
            ++tickRightGracz2;
        } else if (tickRightGracz2 >= 10 && tickRightGracz2 < 20){
            nowTexture = niebPrawo2;
            ++tickRightGracz2;
        } else if (tickRightGracz2 >= 20 && tickRightGracz2 < 30){
            nowTexture = niebPrawo3;
            ++tickRightGracz2;
        } else if ( tickRightGracz2 >= 30){
            nowTexture = niebPrawo4;
            tickRightGracz2 = 0;
        }
    }else if((klawisze[SDL_SCANCODE_C] and ostatniWcisnietyKlawisz == "prawy") or animacjaWalki1){
        if (klawisze[SDL_SCANCODE_C] and ostatniWcisnietyKlawisz == "prawy"){
            counter =0;
        }
        if(counter < 6){
            animacjaWalki1= true;
            nowTexture = niebreceprawo1;
        } else if ( counter >= 6 and counter <12){
            nowTexture = niebreceprawo2;
        }else if ( counter >=12 and counter < 18){
            nowTexture = niebreceprawo3;
        } else if ( counter >= 18 and counter < 24 ){
            nowTexture = niebreceprawo2;
        } else if ( counter >= 24 and counter < 30){
            nowTexture = niebreceprawo1;
        } else{
            //counter =0;
            nowTexture = texNiebieski;
            animacjaWalki1= false;
        }

    }else if((klawisze[SDL_SCANCODE_C] and ostatniWcisnietyKlawisz == "lewy") or animacjaWalki2) {
        if (klawisze[SDL_SCANCODE_C] and ostatniWcisnietyKlawisz == "lewy"){
            counter =0;
        }
        if(counter < 6){
            animacjaWalki2= true;
            nowTexture = niebrecelewo1;
        } else if ( counter >= 6 and counter <12){
            nowTexture = niebrecelewo2;
        }else if ( counter >=12 and counter < 18){
            nowTexture = niebrecelewo3;
        } else if ( counter >= 18 and counter < 24 ){
            nowTexture = niebrecelewo2;
        } else if ( counter >= 24 and counter < 30){
            nowTexture = niebrecelewo1;
        } else{
            //counter =0;
            nowTexture = texNiebieski;
            animacjaWalki2= false;
        }


    }else if((klawisze[SDL_SCANCODE_V] and ostatniWcisnietyKlawisz == "prawy")or animacjaWalki3){
        if (klawisze[SDL_SCANCODE_V] and ostatniWcisnietyKlawisz == "prawy"){
            counter =0;
        }

        if(counter < 6){
            animacjaWalki3= true;
            nowTexture = niebnogiprawo1;
        } else if ( counter >= 6 and counter <12){
            nowTexture = niebnogiprawo2;
        }else if ( counter >=12 and counter < 18){
            nowTexture = niebnogiprawo3;
        } else if ( counter >= 18 and counter < 24 ){
            nowTexture = niebnogiprawo2;
        } else if ( counter >= 24 and counter < 30){
            nowTexture = niebnogiprawo1;
        } else{
            //counter =0;
            nowTexture = texNiebieski;
            animacjaWalki3= false;
        }


    }else if((klawisze[SDL_SCANCODE_V] and ostatniWcisnietyKlawisz == "lewy") or animacjaWalki4) {
        if (klawisze[SDL_SCANCODE_V] and ostatniWcisnietyKlawisz == "lewy"){
            counter =0;
        }
        if(counter < 6){
            animacjaWalki4= true;
            nowTexture = niebnogilewo1;
        } else if ( counter >= 6 and counter <12){
            nowTexture = niebnogilewo2;
        }else if ( counter >=12 and counter < 18){
            nowTexture = niebnogilewo3;
        } else if ( counter >= 18 and counter < 24 ){
            nowTexture = niebnogilewo2;
        } else if ( counter >= 24 and counter < 30){
            nowTexture = niebnogilewo1;
        } else{
            //counter =0;
            nowTexture = texNiebieski;
            animacjaWalki4= false;
        }


    }else{
        nowTexture = texNiebieski;
        tickRightGracz2 =0;
        tickLeftGracz2 =0;
    }
    SDL_RenderCopy( g_Rys, nowTexture, NULL, &prostokat );


}

void Gracz2::Aktualizuj() {
    const float Predkosc = 1.0;
    const auto klawisze = SDL_GetKeyboardState(NULL);

    x_gracza2 = m_Pozycja_X;
    y_gracza2 = m_Pozycja_Y;

    if(klawisze[SDL_SCANCODE_A]){
        Impuls(-m_Szybkosc, 0);
        ostatniWcisnietyKlawisz = "lewy";
    }
    if(klawisze[SDL_SCANCODE_D]){
        Impuls(+m_Szybkosc, 0);
        ostatniWcisnietyKlawisz = "prawy";
    }
    Impuls(0,0.3f);
    Tarcie_X(0.4f);
    if(m_Pozycja_Y < 300){
        Tarcie_X(0.3f);
    }

    if(sprawdzCzyJestesWBlokuPalacym(m_Pozycja_X,m_Pozycja_Y)){
        hp_gr2 -= 0.5;
    }

    if(czyJestWBlokuDodadkowym(m_Pozycja_X,m_Pozycja_Y) && blokDodadkowyState){
        hp_gr2 += 50;
        blokDodadkowyState =false;
    }

    if(hp_gr2 <=0){
        redWin = true;
    }
}

void Gracz2::Zdarzenie(SDL_Event &zdarzenie) {
    if(zdarzenie.type == SDL_KEYDOWN and not zdarzenie.key.repeat){
        if (zdarzenie.key.keysym.scancode == SDL_SCANCODE_W and Koliduje_ze_Sciana(SCIANA::Grona)){
            Impuls(0,-8.f);
        }

        if ( zdarzenie.key.keysym.scancode == SDL_SCANCODE_C and Przeciwnik_po_Prawej(m_Pozycja_X,m_Pozycja_Y,m_Szerokosc,m_wysokosc,2) and ostatniWcisnietyKlawisz == "prawy"){
            hp_gr1 -= wartosc_ataku;
        }
        if ( zdarzenie.key.keysym.scancode == SDL_SCANCODE_C and Przeciwnik_po_Lewej(m_Pozycja_X,m_Pozycja_Y,m_Szerokosc,m_wysokosc,2) and ostatniWcisnietyKlawisz == "lewy"){
            hp_gr1 -= wartosc_ataku;
        }
        if ( zdarzenie.key.keysym.scancode == SDL_SCANCODE_V and Przeciwnik_po_Prawej(m_Pozycja_X,m_Pozycja_Y,m_Szerokosc,m_wysokosc,2) and ostatniWcisnietyKlawisz == "prawy"){
            hp_gr1 -= wartosc_ataku;
        }
        if ( zdarzenie.key.keysym.scancode == SDL_SCANCODE_V and Przeciwnik_po_Lewej(m_Pozycja_X,m_Pozycja_Y,m_Szerokosc,m_wysokosc,2) and ostatniWcisnietyKlawisz == "lewy"){
            hp_gr1 -= wartosc_ataku;
        }
    }
}
