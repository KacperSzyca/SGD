//
// Created by user on 22.06.2021.
//

#ifndef SDGPROJECT_LTEXTURE_H
#define SDGPROJECT_LTEXTURE_H

#include <string>
#include "SDL.h"


class LTexture {
public:
    //Initializes variables
    LTexture();

    //Deallocates memory
    ~LTexture();

    //Loads image at specified path
    bool loadFromFile( std::string path );

    //Deallocates texture
    void free();

    //Renders texture at given point
    void render( int x, int y, SDL_Rect* clip = NULL );

    //Gets image dimensions
    int getWidth();
    int getHeight();

private:
    //The actual hardware texture
    SDL_Texture* mTexture;

    //Image dimensions
    int mWidth;
    int mHeight;
};


#endif //SDGPROJECT_LTEXTURE_H
