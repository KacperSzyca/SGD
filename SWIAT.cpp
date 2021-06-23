#include <cstring>
#include "SWIAT.h"
#include "Zasoby.h"

bool Jest_Solidny(BLOK blok) {
    switch (blok) {
        case BLOK::Nic :
            return false;
        default        :
            return true;
    }
}

BLOK Znak_Bloku(char znak) {
    switch (znak) {
        case 'M' :
            return BLOK::Stone;
        case 'B' :
            return BLOK::Brick;
        case 'S' :
            return BLOK::Super;
        default  :
            return BLOK::Nic;
    }
}

SWIAT::SWIAT(int szerokosc, int wysokosc) : m_Aktorzy(), m_Bloki(), m_Szerokosc(szerokosc), m_Wysokosc(wysokosc) {
    SDL_Surface *rockSurface = IMG_Load("../img/rock.bmp");
    rock = SDL_CreateTextureFromSurface(g_Rys, rockSurface);
    SDL_FreeSurface(rockSurface);

    SDL_Surface *brickSurface = IMG_Load("../img/brick.bmp");
    brick = SDL_CreateTextureFromSurface(g_Rys, brickSurface);
    SDL_FreeSurface(brickSurface);

    SDL_Surface *superSurface = IMG_Load("../img/super.bmp");
    super = SDL_CreateTextureFromSurface(g_Rys, superSurface);
    SDL_FreeSurface(superSurface);
    Alokuj_Bloki();

}

void SWIAT::Alokuj_Bloki() {
    m_Bloki.resize(m_Szerokosc * m_Wysokosc);
}

void SWIAT::Rysuj(float krok) {
    for (auto y = 0; y < m_Wysokosc; ++y) {
        for (auto x = 0; x < m_Szerokosc; ++x) {
            auto blok = Blok(x, y);

            if (blok == BLOK::Nic) {
                continue;
            }
            auto prostokat = Blok_Jako_SDL_Rect(x, y);

            // witryna nie osogalna ( https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.svgrepo.com%2Fsvg%2F192284%2Fbrick&psig=AOvVaw3lRcU_kECp6I4QG3uC12if&ust=1624442512768000&source=images&cd=vfe&ved=0CAoQjRxqFwoTCPD8pYr-qvECFQAAAAAdAAAAABAD)
            if (blok == BLOK::Brick) {
                SDL_RenderCopy(g_Rys, brick, NULL, &prostokat);
                DodajBlokPalacy(PROSTOKAT<float>{(float) prostokat.x, (float) prostokat.y});
            } else if (blok == BLOK::Super) {
                blokDodadkowy = {(int) prostokat.x, (int) prostokat.y, 32, 32};
                if (blokDodadkowyState == true) {
                    SDL_RenderCopy(g_Rys, super, NULL, &prostokat);
                } else if (blokDodadkowyState == false) {
                    SDL_RenderCopy(g_Rys, rock, NULL, &blokDodadkowy);
                }
            } else {
                //https://imgur.com/3kx8nsj
                SDL_RenderCopy(g_Rys, rock, NULL, &prostokat);
            }

        }
    }

    for (auto &aktor : m_Aktorzy) {
        aktor->Rysuj(krok);
    }
}

void SWIAT::Fizyka(Aktor *aktor) {
    aktor->m_Predkosc_X += aktor->m_Przyspiesznie_X;
    aktor->m_Predkosc_Y += aktor->m_Przyspiesznie_Y;
    aktor->m_Przyspiesznie_X = 0;
    aktor->m_Przyspiesznie_Y = 0;

    Kolizje_z_Blokami(aktor);
}

void SWIAT::Kolizje_z_Blokami(Aktor *aktor) {
    PROSTOKAT<float> hitbox_aktora;
    PROSTOKAT<int> zasieg_aktora;

    memset(aktor->m_KolizjaZeScianami, 0, sizeof(aktor->m_KolizjaZeScianami));

    aktor->m_Pozycja_X += aktor->m_Predkosc_X;
    hitbox_aktora = aktor->Jako_Prostokat();
    zasieg_aktora = Prostokat_Wyrowany_Do_Blokow(hitbox_aktora);

    for (auto y = zasieg_aktora.Gorna(); y <= zasieg_aktora.Dolna(); ++y) {
        for (auto x = zasieg_aktora.Lewa(); x <= zasieg_aktora.Prawa(); ++x) {
            if (not Jest_Solidny(Blok(x, y))) {
                continue;
            }
            auto hitbox_bloku = Blok_Jako_Prostokat(x, y);
            if (aktor->m_Predkosc_X > +0.001 and not Jest_Solidny(Blok(x - 1, y))) {
                auto sciana = PROSTOKAT<float>{
                        hitbox_bloku.Lewa(), hitbox_bloku.Gorna() + 1,
                        aktor->m_Predkosc_X, hitbox_bloku.W - 2,
                };
                if (hitbox_aktora.Koliduje_z(sciana)) {
                    aktor->m_Predkosc_X *= -aktor->m_Sprezystosc;
                    aktor->m_Pozycja_X = hitbox_bloku.Lewa() - hitbox_aktora.S;
                    aktor->m_KolizjaZeScianami[int(SCIANA::Lewa)] = true;
                }
            }
            if (aktor->m_Predkosc_X < -0.001 and not Jest_Solidny(Blok(x + 1, y))) {
                auto sciana = PROSTOKAT<float>{
                        hitbox_bloku.Prawa() + aktor->m_Predkosc_X, hitbox_bloku.Gorna() + 1,
                        -aktor->m_Predkosc_X, hitbox_bloku.W - 2,
                };
                if (hitbox_aktora.Koliduje_z(sciana)) {
                    aktor->m_Predkosc_X *= -aktor->m_Sprezystosc;
                    aktor->m_Pozycja_X = hitbox_bloku.Prawa();
                    aktor->m_KolizjaZeScianami[int(SCIANA::Prawa)] = true;
                }
            }
        }
    }


    aktor->m_Pozycja_Y += aktor->m_Predkosc_Y;
    hitbox_aktora = aktor->Jako_Prostokat();
    zasieg_aktora = Prostokat_Wyrowany_Do_Blokow(hitbox_aktora);

    for (auto y = zasieg_aktora.Gorna(); y <= zasieg_aktora.Dolna(); ++y) {
        for (auto x = zasieg_aktora.Lewa(); x <= zasieg_aktora.Prawa(); ++x) {
            if (not Jest_Solidny(Blok(x, y))) {
                continue;
            }
            auto hitbox_bloku = Blok_Jako_Prostokat(x, y);
            if (aktor->m_Predkosc_Y > +0.001 and not Jest_Solidny(Blok(x, y - 1))) {
                auto sciana = PROSTOKAT<float>{
                        hitbox_bloku.Lewa() + 1, hitbox_bloku.Gorna(),
                        hitbox_bloku.S - 2, aktor->m_Predkosc_Y,
                };
                if (hitbox_aktora.Koliduje_z(sciana)) {
                    aktor->m_Predkosc_Y *= -aktor->m_Sprezystosc;
                    aktor->m_Pozycja_Y = hitbox_bloku.Gorna() - hitbox_aktora.W;
                    aktor->m_KolizjaZeScianami[int(SCIANA::Grona)] = true;
                }
            }
            if (aktor->m_Predkosc_Y < -0.001 and not Jest_Solidny(Blok(x, y + 1))) {
                auto sciana = PROSTOKAT<float>{
                        hitbox_bloku.Lewa() + 1, hitbox_bloku.Dolna() + aktor->m_Predkosc_Y,
                        hitbox_bloku.S - 2, -aktor->m_Predkosc_Y,
                };
                if (hitbox_aktora.Koliduje_z(sciana)) {
                    aktor->m_Predkosc_Y *= -aktor->m_Sprezystosc;
                    aktor->m_Pozycja_Y = hitbox_bloku.Dolna();
                    aktor->m_KolizjaZeScianami[int(SCIANA::Dolna)] = true;

                }
            }
        }
    }

}

void SWIAT::Aktualizuj() {
    for (auto &aktor : m_Aktorzy) {
        aktor->Aktualizuj();

        Fizyka(aktor);
    }
}

void SWIAT::Zdarzenie(SDL_Event &zdarzenie) {
    for (auto aktor:m_Aktorzy) {
        aktor->Zdarzenie(zdarzenie);
    }
}

vector<Aktor *> &SWIAT::Lista_Aktorow() {
    return m_Aktorzy;
}

void SWIAT::Przywolaj(Aktor *aktor) {
    m_Aktorzy.push_back(aktor);
}

int SWIAT::Szerokosc() {
    return m_Szerokosc;
}

int SWIAT::Wysokosc() {
    return m_Wysokosc;
}

BLOK SWIAT::Blok(int pozycja_x, int pozycja_y) {
    if (pozycja_x >= 0 and pozycja_x < m_Szerokosc and
        pozycja_y >= 0 and pozycja_y < m_Wysokosc) {
        return m_Bloki.at(pozycja_x + pozycja_y * m_Szerokosc);
    } else {
        return BLOK::Nic;
    }
}

void SWIAT::UstawBlok(int pozycja_x, int pozycja_y, BLOK blok) {
    if (pozycja_x >= 0 and pozycja_x < m_Szerokosc and
        pozycja_y >= 0 and pozycja_y < m_Wysokosc) {
        m_Bloki.at(pozycja_x + pozycja_y * m_Szerokosc) = blok;
    }

}

SDL_Rect SWIAT::Blok_Jako_SDL_Rect(int pozycja_x, int pozycja_y) {
    return SDL_Rect{
            pozycja_x * Szerokosc_Bloku, pozycja_y * Wysokosc_Bloku,
            Szerokosc_Bloku, Wysokosc_Bloku,
    };
}

PROSTOKAT<float> SWIAT::Blok_Jako_Prostokat(int pozycja_x, int pozycja_y) {
    return PROSTOKAT<float>{
            float(pozycja_x * Szerokosc_Bloku), float(pozycja_y * Wysokosc_Bloku),
            Szerokosc_Bloku, Wysokosc_Bloku,
    };
}

PROSTOKAT<int> SWIAT::Prostokat_Wyrowany_Do_Blokow(PROSTOKAT<float> prostokat) {
    auto lewa = int(prostokat.Lewa() / float(Szerokosc_Bloku));
    auto prawa = int(prostokat.Prawa() / float(Szerokosc_Bloku));
    auto gorna = int(prostokat.Gorna() / float(Wysokosc_Bloku));
    auto dolna = int(prostokat.Dolna() / float(Wysokosc_Bloku));

    return PROSTOKAT<int>{
            lewa, gorna,
            prawa - lewa, dolna - gorna,
    };
}

void SWIAT::Laduj(vector<const char *> rzedy) {
    m_Wysokosc = rzedy.size();
    m_Szerokosc = strlen(rzedy[0]);
    Alokuj_Bloki();

    auto y = 0;
    for (auto rzad:rzedy) {
        for (auto x = 0; x < m_Szerokosc; ++x) {
            UstawBlok(x, y, Znak_Bloku(rzad[x]));
        }
        ++y;
    }
}
