#ifndef SDGPROJECT_PROSTOKAT_H
#define SDGPROJECT_PROSTOKAT_H

template <typename T>
struct PROSTOKAT{
    T X,Y,S,W; // X , Y , SZEROKOSC , WYSOKOSC

    inline T Lewa(){
        return X;
    }

    inline T Prawa(){
        return X+S;
    }

    inline T Gorna(){
        return Y;
    }

    inline T Dolna(){
        return Y+W;
    }

    inline bool Koliduje_z( PROSTOKAT<T> inny){
        return Lewa() < inny.Prawa() and inny.Lewa() < Prawa() and
            Gorna() < inny.Dolna() and inny.Gorna() < Dolna();
    }


};

enum class SCIANA{
    Prawa,
    Dolna,
    Lewa,
    Grona,
    _Dlugosc,
};


#endif //SDGPROJECT_PROSTOKAT_H
