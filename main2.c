#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280, 720, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

    // creates a surface to load an image into the main memory 
    SDL_Surface* surface;

    // please provide a path for your image 
    surface = IMG_Load("img/up.bmp");

    // loads image to our graphics hardware memory. 
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

    // clears main-memory 
    SDL_FreeSurface(surface);

    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;

    // connects our texture with dest to control position 
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

    // adjust height and width of our image box. 
    dest.w /= 3;
    dest.h /= 3;

    // sets initial x-position of object 
    dest.x = (1280 - dest.w) / 2;

    // sets initial y-position of object 
    dest.y = (720 - dest.h) / 2;

    // controls annimation loop 
    int close = 0;

    // speed of box 
    int speed = 300;

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    dest.y -= speed / 30;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    dest.x -= speed / 30;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    dest.y += speed / 30;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    dest.x += speed / 30;
                    break;
                }
            }
        }

        // right boundary 
        if (dest.x + dest.w > 1280)
            dest.x = 1280 - dest.w;

        // left boundary 
        if (dest.x < 0)
            dest.x = 0;

        // bottom boundary 
        if (dest.y + dest.h > 720)
            dest.y = 720 - dest.h;

        // upper boundary 
        if (dest.y < 0)
            dest.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex, NULL, &dest);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 30);
    }

    // destroy texture 
    SDL_DestroyTexture(tex);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}






SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
        SDL_RenderClear(rend);









#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rendSea = SDL_CreateRenderer(win, -1, render_flags);
    SDL_Renderer* rendGrass = SDL_CreateRenderer(win, -1, render_flags);
    SDL_Renderer* rendRoad = SDL_CreateRenderer(win, -1, render_flags);
    SDL_Renderer* rendStop = SDL_CreateRenderer(win, -1, render_flags);

    // creates a surface to load an image into the main memory 
    SDL_Surface* sea;
    SDL_Surface* grass;
    SDL_Surface* road;
    SDL_Surface* stop;

    // please provide a path for your image 
    sea = IMG_Load("img/sea.bmp");
    grass = IMG_Load("img/grass.bmp");
    road = IMG_Load("img/road.bmp");
    stop = IMG_Load("img/stop.bmp");

    // loads image to our graphics hardware memory. 
    SDL_Texture* texSea = SDL_CreateTextureFromSurface(rendSea, sea);
    SDL_Texture* texGrass = SDL_CreateTextureFromSurface(rendGrass, grass);
    SDL_Texture* texRoad = SDL_CreateTextureFromSurface(rendRoad, road);
    SDL_Texture* texStop = SDL_CreateTextureFromSurface(rendStop, stop);

    // clears main-memory 
    //SDL_FreeSurface(surface);

    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;

    // connects our texture with dest to control position 
    SDL_QueryTexture(texSea, NULL, NULL, &dest.w, &dest.h);

    // sets initial x-position of object 
    dest.x = 0;

    // sets initial y-position of object 
    dest.y = 0;

    SDL_QueryTexture(texGrass, NULL, NULL, &dest.w, &dest.h);

    // sets initial x-position of object 
    dest.x = 100;

    // sets initial y-position of object 
    dest.y = 0;

    SDL_QueryTexture(texRoad, NULL, NULL, &dest.w, &dest.h);

    // sets initial x-position of object 
    dest.x = 200;

    // sets initial y-position of object 
    dest.y = 0;

    SDL_QueryTexture(texStop, NULL, NULL, &dest.w, &dest.h);

    // sets initial x-position of object 
    dest.x = 300;

    // sets initial y-position of object 
    dest.y = 0;

    // controls annimation loop 
    int close = 0;

    // annimation loop 
    while (!close) {
        
       

        // clears the screen 
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex, NULL, &dest);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 30);
    }

    // destroy texture 
    SDL_DestroyTexture(tex);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}












#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280, 720, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    // loads image to our graphics hardware memory. 
    SDL_Texture* tex;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);

    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 3;
    dest4.h /= 3;
    dest4.x = (1280 - dest4.w) / 2;
    dest4.y = (720 - dest4.h) / 2;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;



    // controls annimation loop 
    int close = 0;
    int speed = 300;

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    dest4.y -= speed / 30;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    dest4.x -= speed / 30;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    dest4.y += speed / 30;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    dest4.x += speed / 30;
                    break;
                }
            }
        }

        // right boundary 
        if (dest4.x + dest4.w > 1280)
            dest4.x = 1280 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 720)
            dest4.y = 720 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        for (int u = 0; u < 2; u++) {
            for (int y = 1; y <= 3; y++) {
                if (u == 0) {
                    dest.x = 0; 
                    dest.y = 0;

                    if (y == 1) {
                        SDL_RenderCopy(rend, tex1, NULL, &dest);
                    } else if (y == 2) {
                        dest.x += 100; 
                        SDL_RenderCopy(rend, tex2, NULL, &dest);
                    } else if (y == 3) {
                        dest.x += 200; 
                        SDL_RenderCopy(rend, tex3, NULL, &dest);
                    }
                } else {
                    dest.x = 100 * u + 200; 
                    dest.y = 0;

                    if (y == 1) {
                        SDL_RenderCopy(rend, tex1, NULL, &dest);
                    } else if (y == 2) {
                        dest.x += 100;
                        SDL_RenderCopy(rend, tex2, NULL, &dest);
                    } else if (y == 3) {
                        dest.x += 200;
                        SDL_RenderCopy(rend, tex3, NULL, &dest);
                    }
                }

                


                
            }
        }

        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 30);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    SDL_DestroyTexture(tex2);
    SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}






















#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);

    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 3;
    dest4.h /= 3;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 300;

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    dest4.y -= speed / 30;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    dest4.x -= speed / 30;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    dest4.y += speed / 30;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    dest4.x += speed / 30;
                    break;
                }
            }
        }

        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        texBottpm = tex4;


        for (int u = 0; u < 20; u++) {


            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 100 * u; 
            }

            

            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 100 * y;
                }


                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 30);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}





























#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 60;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 300;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    dest4.y -= speed / 30;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    dest4.x -= speed / 30;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    dest4.y += speed / 30;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    dest4.x += speed / 30;
                    break;
                }
            }
        }


        int testX, testY;
        testX = dest4.x/10;
        testY = dest4.y/10;

        if (masTex[testY][testX] == 2) {
             // right boundary 
            if (dest4.x + dest4.w > ((50*testX)+50))
                dest4.x = ((50*testX)+50) - dest4.w;

            // left boundary 
            if (dest4.x < 0)
                dest4.x = 0;

            // bottom boundary 
            if (dest4.y + dest4.h > 1000)
                dest4.y = 1000 - dest4.h;

            // upper boundary 
            if (dest4.y < 0)
                dest4.y = 0;
        }

        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 30);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}



































#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 60;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 300;
    int testX, testY;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    dest4.y -= speed / 30;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    dest4.x -= speed / 30;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    dest4.y += speed / 30;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    dest4.x += speed / 30;
                    break;
                }
            }
        }

        //dest4.w /= 4;
        //dest4.h /= 4;
        int testXR, testYR, testXL, testYL, top, bot, rig, lef;
        testXR = dest4.x/50;
        testYR = dest4.y/50;

        testXL = (dest4.x+25)/50;
        testYL = (dest4.y+25)/50;

        top = masTex[testYR][testXR];
        bot = masTex[testYR][testXR];
        rig = masTex[testYR][testXR];
        lef = masTex[testYR][testXR];
        

        if (masTex[testYR][testXR] == 2) {
             // right boundary 
            if (dest4.x + dest4.w > ((50*testXR)+50))
                dest4.x = ((50*testXR)+50) - dest4.w;

        }

        if (masTex[testYL][testXL] == 2) {

            // left boundary 
            if (dest4.x < (50*testXL))
                dest4.x = (50*testXL);

        }



        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 30);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}













#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 60;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 300;
    int testX, testY;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    dest4.y -= speed / 30;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    dest4.x -= speed / 30;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    dest4.y += speed / 30;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    dest4.x += speed / 30;
                    break;
                }
            }
        }

        //dest4.w /= 4;
        //dest4.h /= 4;
        int testXR, testYR, testXL, testYL, top, bot, rig, lef, XRig, XLef;
        testXR = dest4.x/50;
        testYR = dest4.y/50;

        testXL = (dest4.x+24)/50;
        testYL = (dest4.y+24)/50;

        top = masTex[testYL-1][testXL];

        bot = masTex[testYR+1][testXR];

        rig = masTex[testYR][testXR+1];
        
        lef = masTex[testYL][testXL-1];
        

        if (rig != 2) {
             // right boundary 
            if (dest4.x + dest4.w > ((50*testXR)+50))
                dest4.x = ((50*testXR)+50) - dest4.w;

        }

        if (lef != 2) {
             // right boundary 
            if (dest4.x < 50*testXL)
                dest4.x = 50*testXL;

        }

        if (bot != 2) {
             // right boundary 
            if (dest4.y + dest4.h > ((50*testYR)+50))
                dest4.y = ((50*testYR)+50) - dest4.h;

        }

        if (top != 2) {
             // right boundary 
            if (dest4.y < 50*testYL)
                dest4.y = 50*testYL;

        }





        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 30);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}












































17.03.2020



#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 60;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 300;
    int testX, testY;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    dest4.y -= speed / 30;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    dest4.x -= speed / 30;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    dest4.y += speed / 30;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    dest4.x += speed / 30;
                    break;
                }
            }
        }

        //dest4.w /= 4;
        //dest4.h /= 4;
        int testXR, testYR, testXL, testYL, top, bot, rig, lef, XRig, XLef;
        testXR = dest4.x/50;
        testYR = dest4.y/50;

        testXL = (dest4.x+24)/50;
        testYL = (dest4.y+24)/50;

        top = masTex[testYL-1][testXL];

        bot = masTex[testYR+1][testXR];

        rig = masTex[testYR][testXR+1];
        
        lef = masTex[testYL][testXL-1];
        

        if (rig != 2) {
             // right boundary 
            if (dest4.x + dest4.w > ((50*testXR)+50))
                dest4.x = ((50*testXR)+50) - dest4.w;

        }

        if (lef != 2) {
             // right boundary 
            if (dest4.x < 50*testXL)
                dest4.x = 50*testXL;

        }

        if (bot != 2) {
             // right boundary 
            if (dest4.y + dest4.h > ((50*testYR)+50))
                dest4.y = ((50*testYR)+50) - dest4.h;

        }

        if (top != 2) {
             // right boundary 
            if (dest4.y < 50*testYL)
                dest4.y = 50*testYL;

        }





        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 30);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}


























#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 60;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 300;
    int testX, testY;
    int go = 1;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_W:
                    case SDL_SCANCODE_UP:

                        switch (event.key.keysym.scancode) {
                            case SDL_SCANCODE_A:
                            case SDL_SCANCODE_LEFT:
                                go--;
                                if (go == 0) {
                                    go = 4;
                                }
                            case SDL_SCANCODE_D:
                            case SDL_SCANCODE_RIGHT:
                                go++;
                                if (go == 4) {
                                    go = 1;
                                }
                        }

                        if (go == 1) {
                            dest4.y -= speed / 30;
                        } else if (go == 2) {
                            dest4.x += speed / 30;
                        } else if (go == 3) {
                            dest4.y += speed / 30;
                        } else if (go == 4) {
                            dest4.x -= speed / 30;
                        }

                        break;
                }
            }
        }


        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        

        //генерация карты
        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }
        //генерация карты





        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}


































#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 60;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 300;
    int testX, testY;
    int go = 2, move = 0;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_W:
                        move = 1;
                        break;
                    case SDL_SCANCODE_A:
                        go--;
                        if (go == 0) {
                            go = 4;
                        }
                        break;
                    case SDL_SCANCODE_D:
                        go++;
                        if (go == 4) {
                            go = 1;
                        }
                        break;
                }

            case SDL_KEYUP:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_W:
                        move = 0;
                        break;
                }
            }
        }

        if (go == 1 && move == 1) {
            dest4.y -= speed / 30;
        } else if (go == 2 && move == 1) {
            dest4.x += speed / 30;
        } else if (go == 3 && move == 1) {
            dest4.y += speed / 30;
        } else if (go == 4 && move == 1) {
            dest4.x -= speed / 30;
        }

        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        

        //генерация карты
        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }
        //генерация карты





        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}












#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {
    
    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;

    dest4.x = 60;
    dest4.y = 60;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);


    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);


    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);




    // controls annimation loop 
    int close = 0;
    int speed = 300;
    int testX, testY;
    int go = 2, move = 0;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_W:
                        move = 1;
                        break;
                    case SDL_SCANCODE_A:
                        go--;
                        if (go == 0) {
                            go = 4;
                        }
                        break;
                    case SDL_SCANCODE_D:
                        go++;
                        if (go == 5) {
                            go = 1;
                        }
                        break;
                }
            }
        }

        if (go == 1 && move == 1) {
            dest4.y -= speed / 30;
        } else if (go == 2 && move == 1) {
            dest4.x += speed / 30;
        } else if (go == 3 && move == 1) {
            dest4.y += speed / 30;
        } else if (go == 4 && move == 1) {
            dest4.x -= speed / 30;
        }

        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        printf("%d -- ", dest4.x);

        //генерация карты
        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }
        //генерация карты





        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 30);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}


























































#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 60;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 300/60;
    int testX, testY;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {
            switch (event.type) {

            case SDL_QUIT:
                // handling of close button 
                close = 1;
                break;

            case SDL_KEYDOWN:
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_W:
                case SDL_SCANCODE_UP:
                    dest4.y -= speed;
                    break;
                case SDL_SCANCODE_A:
                case SDL_SCANCODE_LEFT:
                    dest4.x -= speed;
                    break;
                case SDL_SCANCODE_S:
                case SDL_SCANCODE_DOWN:
                    dest4.y += speed;
                    break;
                case SDL_SCANCODE_D:
                case SDL_SCANCODE_RIGHT:
                    dest4.x += speed;
                    break;
                }
            }
        }

if (event.type = SDL_QUIT) {
    close = 1;
    break;
} else if (event.type = SDL_KEYDOWN) {
    if (event.key.keysym.scancode = SDL_SCANCODE_W) {
        muve = 1;
    } else if (event.key.keysym.scancode = SDL_SCANCODE_A) {
        muveRight = 1;
    }
} else if (event.type = SDL_KEYUP) {
    if (event.key.keysym.scancode = SDL_SCANCODE_W) {
        muve = 0;
    } else if (event.key.keysym.scancode = SDL_SCANCODE_A) {
        muveRight = 0;
    }
}




        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}










































#include <stdio.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 60;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 300/60;
    int testX, testY, muveIn, muveOut, cut = 1, direction;
    double angleRad, cos, sqrt, c, a, b=5, posX, posY, desX, desY, aUR, bUR;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    cut += 1;
                    if (cut == 4) {
                        cut = 0;
                    }
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    cut -= 1;
                    if (cut == -1) {
                        cut = 3;
                    }
                }
            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }
            }


        }



        if (muveIn == 1 && cut == 0) {
            dest4.y -= speed;
        } else if (muveIn == 1 && cut == 1) {
            dest4.x += speed;
        } else if (muveIn == 1 && cut == 2) {
            dest4.y += speed;
        } else if (muveIn == 1 && cut == 3) {
             dest4.x -= speed;
        }

        if (muveOut == 1 && cut == 0) {
            dest4.y += speed;
        } else if (muveOut == 1 && cut == 1) {
            dest4.x -= speed;
        } else if (muveOut == 1 && cut == 2) {
            dest4.y -= speed;
        } else if (muveOut == 1 && cut == 3) {
             dest4.x += speed;
        }


        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}









\











        if (cut > 0 && cut <=89) {
            cut = 90 - cut;

            angleRad = cut * 3.14/180;
            c = b/cos(angleRad);
            a = sqrt((c * c) - (b * b));

            desX = posX + b;
            desY = posY - a;
            direction = 1;
        }

        if (direction == 2 || direction == 1) {
            aUR = (desY-posY)/(desX-posX);
            bUR = posY-posX*aUR;
            speedMath=b/(c/speed);
        } else if (direction != 0 && (direction == 3 || direction == 4 || direction == 5 || direction == 6)) {
            speedMath = speed;
        }

        if (muveIn == 1) {
            dest4.x +=speedMath;
            dest4.y =aUR*posX+bUR;
        }











































        #include <stdio.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 940;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3;
    int testX, testY, muveIn, muveOut, cut = 10, cutGo, direction = 0, posX, posY;
    float angleRad, c, a, b=30, desX, desY, aUR, bUR, speedMath;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    cut += 2;
                    if (cut > 89) {
                        cut = 1;
                    }
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    cut -= 2;
                    if (cut < 0) {
                        cut = 89;
                    }
                }
            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }
            }


        }
        posX = dest4.x;
        posY = dest4.y;

        

            cutGo = 90 - cut;
            
            angleRad = cutGo * M_PI/180;
            c = b/cos(angleRad);
            a = sqrt((c * c) - (b * b));
            printf ("ac=%f---ca=%f---", a, c);
            desX = posX + b;
            desY = posY - a;

            aUR = (desY-posY)/(desX-posX);
            bUR = posY-posX*aUR;
            speedMath=b/(c/speed);

        if (muveIn == 1) {
            dest4.x +=speedMath;
            dest4.y =aUR*posX+bUR;
        }

        



        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        SDL_RenderCopy(rend, tex4, NULL, &dest4);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}



























































#include <stdio.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 940;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 2;
    int testX, testY, muveIn, muveOut, direction = 0;
    float angleRad, cut = 80, cutGo, c, a, b=30, aUR, bUR, posX, posY, desX, desY, test1, test2, speedMath;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    cut += 2;
                    if (cut > 89) {
                        cut = 1;
                    }
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    cut -= 2;
                    if (cut < 0) {
                        cut = 89;
                    }
                }
            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }
            }


        }
        posX = dest4.x;
        posY = dest4.y;
        test1 = dest4.x;
        test2 = dest4.y;
        cutGo = 90 - cut;
        angleRad = cutGo * M_PI/180;
        c = b/cos(angleRad);
        a = sqrt((c * c) - (b * b));
        desX = posX + b;
        desY = posY - a;
        //printf ("aUR=(%f-%f)/(%f-%f)", desY, posY, desX, posX);
        aUR = (desY-posY)/(desX-posX);
        bUR = posY-posX*aUR;
        speedMath=b/(c/speed);
        //printf ("aUR=%f---bUR=%f---", aUR, bUR);
        //printf ("speedMath=%f---", round(speedMath));

        if (muveIn == 1) {
            test1 += speedMath;
            test2 = aUR*test1+bUR;
printf ("test1=%f---test2=%f---\naUR=%f---bUR=%f---\n", test1, test2, aUR, bUR);

            dest4.x = round(test1);
            dest4.y = round(test2);
            printf ("dest4.x=%d---dest4.y=%d---\n\n", dest4.x, dest4.y);
        }

        



        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                //SDL_RenderCopyEx(renderer, tex, 0, &dst_rect, 45, 0, SDL_FLIP_NONE);
            }

        }

        SDL_RenderCopyEx(rend, tex4, NULL, &dest4, 45, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}

















































#include <stdio.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 500;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3;
    int speed2 = 2;
    int testX, testY, muveIn, muveOut, cut = 0, cutDeg=0, direction;
    double angleRad, cos, sqrt, c, a, b=5, posX, posY, desX, desY, aUR, bUR;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    if (muveIn==1 && muveOut==0) {
                        cut += 1;
                        if (cut == 8) {
                            cut = 0;
                        }
                    } else if (muveIn==0 && muveOut==1) {
                        cut -= 1;
                        if (cut == -1) {
                            cut = 7;
                        }
                    }
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    if (muveIn==1 && muveOut==0) {
                        cut -= 1;
                        if (cut == -1) {
                            cut = 7;
                        }
                    } else if (muveIn==0 && muveOut==1) {
                        cut += 1;
                        if (cut == 8) {
                            cut = 0;
                        }
                    }
                }
            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }
            }


        }

        if (muveIn==1 && muveOut==1) {
            muveIn = 0;
            muveOut = 0;
        }

        if (cut == 0) {
            cutDeg = 0;
        } else if (cut == 1) {
            cutDeg = 45;
        } else if (cut == 2) {
            cutDeg = 90;
        } else if (cut == 3) {
            cutDeg = 135;
        } else if (cut == 4) {
            cutDeg = 180;
        } else if (cut == 5) {
            cutDeg = 225;
        } else if (cut == 6) {
            cutDeg = 270;
        } else if (cut == 7) {
            cutDeg = 315;
        }



        if (muveIn == 1 && cut == 0) {
            dest4.y -= speed;
        } else if (muveIn == 1 && cut == 1) {
            dest4.x += speed2;
            dest4.y -= speed2;
        } else if (muveIn == 1 && cut == 2) {
            dest4.x += speed;
        } else if (muveIn == 1 && cut == 3) {
             dest4.x += speed2;
             dest4.y += speed2;
        } else if (muveIn == 1 && cut == 4) {
            dest4.y += speed;
        } else if (muveIn == 1 && cut == 5) {
            dest4.x -= speed2;
            dest4.y += speed2;
        } else if (muveIn == 1 && cut == 6) {
            dest4.x -= speed;
        } else if (muveIn == 1 && cut == 7) {
             dest4.x -= speed2;
             dest4.y -= speed2;
        }


        if (muveOut == 1 && cut == 0) {
            dest4.y += speed;
        } else if (muveOut == 1 && cut == 1) {
            dest4.x -= speed2;
            dest4.y += speed2;
        } else if (muveOut == 1 && cut == 2) {
            dest4.x -= speed;
        } else if (muveOut == 1 && cut == 3) {
             dest4.x -= speed2;
             dest4.y -= speed2;
        } else if (muveOut == 1 && cut == 4) {
            dest4.y -= speed;
        } else if (muveOut == 1 && cut == 5) {
            dest4.x += speed2;
            dest4.y -= speed2;
        } else if (muveOut == 1 && cut == 6) {
            dest4.x += speed;
        } else if (muveOut == 1 && cut == 7) {
             dest4.x += speed2;
             dest4.y += speed2;
        }







        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        //SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cutDeg, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}








































#include <stdio.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 500;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3;
    int speed2 = 2;
    int testX, testY, muveIn=0, muveOut=0, bust=0, cut = 0, cutDeg=0, direction;
    double angleRad, cos, sqrt, c, a, b=5, posX, posY, desX, desY, aUR, bUR;

    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 1;               
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    if (muveIn==1) {
                        cut += 1;
                        if (cut == 8) {
                            cut = 0;
                        }
                    } else if (muveOut==1) {
                        cut -= 1;
                        if (cut == -1) {
                            cut = 7;
                        }
                    }
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    if (muveIn==1) {
                        cut -= 1;
                        if (cut == -1) {
                            cut = 7;
                        }
                    } else if (muveOut==1) {
                        cut += 1;
                        if (cut == 8) {
                            cut = 0;
                        }
                    }
                }
            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }
                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 0;               
                }
            }
        }

        if (bust == 0) {
            speed = 3;
            speed2 = 2;
        } else {
            speed = 6;
            speed2 = 4; 
        }

        if (cut == 0) {
            cutDeg = 0;
        } else if (cut == 1) {
            cutDeg = 45;
        } else if (cut == 2) {
            cutDeg = 90;
        } else if (cut == 3) {
            cutDeg = 135;
        } else if (cut == 4) {
            cutDeg = 180;
        } else if (cut == 5) {
            cutDeg = 225;
        } else if (cut == 6) {
            cutDeg = 270;
        } else if (cut == 7) {
            cutDeg = 315;
        }



        if (muveIn == 1 && cut == 0) {
            dest4.y -= speed;
        } else if (muveIn == 1 && cut == 1) {
            dest4.x += speed2;
            dest4.y -= speed2;
        } else if (muveIn == 1 && cut == 2) {
            dest4.x += speed;
        } else if (muveIn == 1 && cut == 3) {
             dest4.x += speed2;
             dest4.y += speed2;
        } else if (muveIn == 1 && cut == 4) {
            dest4.y += speed;
        } else if (muveIn == 1 && cut == 5) {
            dest4.x -= speed2;
            dest4.y += speed2;
        } else if (muveIn == 1 && cut == 6) {
            dest4.x -= speed;
        } else if (muveIn == 1 && cut == 7) {
             dest4.x -= speed2;
             dest4.y -= speed2;
        }


        if (muveOut == 1 && cut == 0) {
            dest4.y += speed;
        } else if (muveOut == 1 && cut == 1) {
            dest4.x -= speed2;
            dest4.y += speed2;
        } else if (muveOut == 1 && cut == 2) {
            dest4.x -= speed;
        } else if (muveOut == 1 && cut == 3) {
             dest4.x -= speed2;
             dest4.y -= speed2;
        } else if (muveOut == 1 && cut == 4) {
            dest4.y -= speed;
        } else if (muveOut == 1 && cut == 5) {
            dest4.x += speed2;
            dest4.y -= speed2;
        } else if (muveOut == 1 && cut == 6) {
            dest4.x += speed;
        } else if (muveOut == 1 && cut == 7) {
             dest4.x += speed2;
             dest4.y += speed2;
        }







        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        //SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cutDeg, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}




























































// мой вариант с треугольником

#include <stdio.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 450;
    dest4.y = 450;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3;
    int speed2 = 2;
    int testX, testY, muveIn=0, muveOut=0, bust=0, cut = 45, cutDeg=0, direction;
    float posX1=dest4.x, posY1=dest4.y, posX2, posY2, aDes, bDes=3, cDes, tanAlfa, radAlfa, aUR, bUR;


    cutDeg = 90 - cut;

    radAlfa=cutDeg * M_PI/180;
    //tanAlfa=tan(radAlfa);
    cDes = bDes/cos(radAlfa);
    aDes = sqrt((cDes * cDes) - (bDes * bDes));
    posX2 = posX1 + bDes;
    posY2 = posY1 - aDes;

    aUR = (posY2-posY1)/(posX2-posX1);
    bUR = posY1-posX1*aUR;

    printf ("aUR=%f---bUR=%f---\n", aUR, bUR);
    printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
    printf ("posX2=%f---posY2=%f---\n", posX2, posY2);
    printf ("cDes=%f---aDes=%f---\n", cDes, aDes);
    printf ("radAlfa=%f---\n\n\n", radAlfa);



    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 1;               
                }

                

            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 0;               
                }

            }
        }

        if (bust == 0) {
            speed = 3;
            speed2 = 2;
        } else {
            speed = 6;
            speed2 = 4; 
        }





        if (muveIn == 1) {
            printf ("posX1=%f---posY1=%f---\n\n\n", posX1, posY1);
            posX1 += 6;
            posY1 = aUR*posX1+bUR;
            printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
            dest4.x=round(posX1);
            dest4.y=round(posY1);
            printf ("dest4.x=%d---dest4.y=%d---\n\n", dest4.x, dest4.y);
        } 
        if (muveOut == 1) {
            printf ("posX1=%f---posY1=%f---\n\n\n", posX1, posY1);
            posX1 -= 6;
            posY1 = aUR*posX1+bUR;
            printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
            dest4.x=round(posX1);
            dest4.y=round(posY1);
            printf ("dest4.x=%d---dest4.y=%d---\n\n", dest4.x, dest4.y);
        } 









        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        //SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}













#include <stdio.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    //dest4.x = 475;
    //dest4.y = 475;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3;
    int speed2 = 2;
    int muveIn=0, muveOut=0, bust=0, cut = 45, cutDeg=0, muveLeft=0, muveRight=0;
    float posX1=dest4.x, posY1=dest4.y, posX2, posY2, aDes, bDes=3, cDes, tanAlfa, radAlfa, aUR, bUR, speedMath;


    cutDeg = 90 - cut;
    radAlfa=cutDeg * M_PI/180;
    cDes = bDes/cos(radAlfa);
    aDes = sqrt((cDes * cDes) - (bDes * bDes));
    posX2 = posX1 + bDes;
    posY2 = posY1 - aDes;
    aUR = (posY2-posY1)/(posX2-posX1);
    bUR = posY1-posX1*aUR;
    speedMath=bDes/(cDes/speed);

    printf ("aUR=%f---bUR=%f---\n", aUR, bUR);
    printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
    printf ("posX2=%f---posY2=%f---\n", posX2, posY2);
    printf ("cDes=%f---aDes=%f---\n", cDes, aDes);
    printf ("radAlfa=%f---\n\n\n", radAlfa);



    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    bust = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    bust = 1;               
                }

                

            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    bust = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    bust = 0;               
                }

            }
        }


        if () {

        }

        if (bust == 0) {
            speed = 3;
            speed2 = 2;
        } else {
            speed = 6;
            speed2 = 4; 
        }





        if (muveIn == 1) {
            posX1 += speedMath;
            posY1 = aUR*posX1+bUR;
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 
        if (muveOut == 1) {
            posX1 -= speedMath;
            posY1 = aUR*posX1+bUR;
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 









        // right boundary 
        if (dest4.x + dest4.w > 1000)
            dest4.x = 1000 - dest4.w;

        // left boundary 
        if (dest4.x < 0)
            dest4.x = 0;

        // bottom boundary 
        if (dest4.y + dest4.h > 1000)
            dest4.y = 1000 - dest4.h;

        // upper boundary 
        if (dest4.y < 0)
            dest4.y = 0;

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        //SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}



















//posCarX, posCarY, numRectX, numRectY, top, bot, lef, rig;
        //    dest4.w /= 4;

        halfCar = dest4.w;
        posCarX = dest4.x+halfCar;
        posCarY = dest4.y+halfCar;
        numRectX = posCarX/50;
        numRectY = posCarY/50;

        top = masTex[numRectY-1][numRectX];
        bot = masTex[numRectY+1][numRectX];
        rig = masTex[numRectY][numRectX+1];
        lef = masTex[numRectY][numRectX-1];
        
        if (top != 2) {
            if (posCarY < 50*numRectY)
                dest4.y = 50*numRectY-halfCar;
                posY1 = dest4.y;
        }











        #include <stdio.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0,255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* surface2;
    surface2 = IMG_Load("img/road.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/stop2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* tex2;
    tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 500;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex2, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    //dest.w /= 2;
    //dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3;
    int muveIn=0, muveOut=0, bust=0, cut = 0, cutDeg=0, muveLeft=0, muveRight=0, direction=0, degLeftRight=5;
    float posX1=dest4.x, posY1=dest4.y, posX2, posY2, aDes, bDes=3, cDes, tanAlfa, radAlfa, aUR, bUR, speedMath;

    int posCarX, posCarY, numRectX, numRectY, top, bot, lef, rig, halfCar;


    cutDeg = 90 - cut;
    radAlfa=cutDeg * M_PI/180;
    cDes = bDes/cos(radAlfa);
    aDes = sqrt((cDes * cDes) - (bDes * bDes));
    posX2 = posX1 + bDes;
    posY2 = posY1 - aDes;
    aUR = (posY2-posY1)/(posX2-posX1);
    bUR = posY1-posX1*aUR;
    speedMath=bDes/(cDes/speed);

    printf ("aUR=%f---bUR=%f---\n", aUR, bUR);
    printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
    printf ("posX2=%f---posY2=%f---\n", posX2, posY2);
    printf ("cDes=%f---aDes=%f---\n", cDes, aDes);
    printf ("radAlfa=%f---\n\n\n", radAlfa);



    int masTex[20][20] = {  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
                            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 1, 
                            1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 
                            1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 1, 1, 1, 1, 
                            1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 2, 2, 1, 1, 1, 1,
                            1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 3, 3, 3, 1, 1, 2, 2, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 3, 1, 2, 1, 3, 3, 3, 3, 1, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 1, 1, 3, 3, 1, 2, 1, 1, 
                            1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 2, 1, 1, 
                            1, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 
                            1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 
                            1, 3, 3, 3, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 2, 1, 
                            1, 3, 3, 1, 2, 1, 1, 2, 2, 2, 2, 2, 3, 3, 1, 2, 1, 1, 2, 1, 
                            3, 3, 3, 1, 2, 2, 2, 2, 2, 1, 1, 1, 3, 3, 1, 2, 2, 2, 2, 1, 
                            3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 1, 1, 1, 1, };

    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 1;               
                }

                

            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 0;               
                }

            }
        }

        if (bust == 0) {
            speed = 3;
        } else {
            speed = 6;
        }


        if (muveIn==1) {
            if (muveLeft==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
            if (muveRight==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
        }


        if (muveOut==1) {
            if (muveLeft==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
            if (muveRight==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
        }


        if (cut > 0 && cut <=89) {
            cutDeg = 90 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 90 && cut <=179) {
            cutDeg = 90 - (180 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 180 && cut <=269) {
            cutDeg = 270 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut > 270 && cut <=359) {
            cutDeg = 90 - (360 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut == 0 || cut == 360) {
            direction = 3;
            speedMath = speed;
        } else if (cut == 90) {
            direction = 4;
            speedMath = speed;
        } else if (cut == 180) {
            direction = 5;
            speedMath = speed;
        } else if (cut == 270) {
            direction = 6;
            speedMath = speed;
        }




        if (muveIn == 1) {
            if (direction == 1) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 -= speedMath;
            } else if (direction == 4) {
                posX1 += speedMath;
            } else if (direction == 5) {
                posY1 += speedMath;
            } else if (direction == 6) {
                posX1 -= speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 


        if (muveOut == 1) {
            if (direction == 1) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 += speedMath;
            } else if (direction == 4) {
                posX1 -= speedMath;
            } else if (direction == 5) {
                posY1 -= speedMath;
            } else if (direction == 6) {
                posX1 += speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 




        // right boundary 
        if (dest4.x + dest4.w > 1000) {
            dest4.x = 1000 - dest4.w;
            posX1 = dest4.x;
        }


        // left boundary 
        if (dest4.x < 0) {
            dest4.x = 0;
            posX1 = dest4.x;
        }


        // bottom boundary 
        if (dest4.y + dest4.h > 1000) {
            dest4.y = 1000 - dest4.h;
            posY1 = dest4.y;
        }
        

        // upper boundary 
        if (dest4.y < 0){
            dest4.y = 0;
            posY1 = dest4.y;
        }

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        


        for (int u = 0; u < 20; u++) {

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 1) {
                    texBottpm = tex1;
                } else if (masTex[u][y] == 2) {
                    texBottpm = tex2;
                } else if (masTex[u][y] == 3) {
                    texBottpm = tex3;
                } else if (masTex[u][y] == 4) {
                    texBottpm = tex4;
                }


                
                SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                
            }

        }

        //SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}





























#include <stdio.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* road1;
    road1 = IMG_Load("img/road.bmp");

    SDL_Surface* road2;
    road2 = IMG_Load("img/road2.bmp");

    SDL_Surface* road3;
    road3 = IMG_Load("img/road3.bmp");

    SDL_Surface* road4;
    road4 = IMG_Load("img/road4.bmp");

    SDL_Surface* roadStart;
    roadStart = IMG_Load("img/roadStart.bmp");

    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/car2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* roadTex1;
    roadTex1 = SDL_CreateTextureFromSurface(rend, road1);
    SDL_FreeSurface(road1);

    SDL_Texture* roadTex2;
    roadTex2 = SDL_CreateTextureFromSurface(rend, road2);
    SDL_FreeSurface(road2);

    SDL_Texture* roadTex3;
    roadTex3 = SDL_CreateTextureFromSurface(rend, road3);
    SDL_FreeSurface(road3);

    SDL_Texture* roadTex4;
    roadTex4 = SDL_CreateTextureFromSurface(rend, road4);
    SDL_FreeSurface(road4);

    SDL_Texture* roadStart1;
    roadStart1 = SDL_CreateTextureFromSurface(rend, roadStart);
    SDL_FreeSurface(roadStart);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 500;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;

    SDL_QueryTexture(roadTex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 2;
    //dest.h /= 2;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    dest.w /= 2;
    dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3;
    int muveIn=0, muveOut=0, bust=0, cut = 0, cutDeg=0, muveLeft=0, muveRight=0, direction=0, degLeftRight=5;
    float posX1=dest4.x, posY1=dest4.y, posX2, posY2, aDes, bDes=3, cDes, tanAlfa, radAlfa, aUR, bUR, speedMath;

    int posCarX, posCarY, numRectX, numRectY, top, bot, lef, rig, halfCar;


    cutDeg = 90 - cut;
    radAlfa=cutDeg * M_PI/180;
    cDes = bDes/cos(radAlfa);
    aDes = sqrt((cDes * cDes) - (bDes * bDes));
    posX2 = posX1 + bDes;
    posY2 = posY1 - aDes;
    aUR = (posY2-posY1)/(posX2-posX1);
    bUR = posY1-posX1*aUR;
    speedMath=bDes/(cDes/speed);

    printf ("aUR=%f---bUR=%f---\n", aUR, bUR);
    printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
    printf ("posX2=%f---posY2=%f---\n", posX2, posY2);
    printf ("cDes=%f---aDes=%f---\n", cDes, aDes);
    printf ("radAlfa=%f---\n\n\n", radAlfa);



    int masTex[20][20] = {  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 

                            10, 81, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 82, 10, 10, 81, 72, 72, 82, 10,

                            10, 71, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 71, 10, 81, 83, 10, 10, 71, 10,

                            10, 71, 10, 81, 72, 72, 72, 72, 72, 72, 82, 10, 84, 72, 83, 10, 10, 81, 83, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 81, 72, 82, 10, 71, 10, 10, 

                            10, 71, 10, 71, 10, 81, 72, 72, 72, 72, 94, 72, 72, 93, 10, 71, 10, 71, 10, 10,

                            10, 91, 72, 50, 72, 93, 10, 10, 10, 10, 10, 10, 10, 71, 10, 84, 72, 83, 10, 10,

                            10, 71, 10, 71, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 10, 10, 10, 10,

                            10, 61, 10, 71, 10, 84, 72, 72, 72, 82, 30, 30, 10, 84, 72, 82, 10, 10, 10, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 71, 30, 30, 30, 10, 10, 84, 72, 82, 10, 10,

                            10, 71, 10, 71, 10, 30, 30, 30, 10, 71, 10, 30, 30, 30, 30, 10, 10, 71, 10, 10,

                            10, 71, 10, 71, 10, 30, 30, 10, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10,

                            10, 71, 10, 71, 10, 10, 10, 81, 72, 94, 72, 92, 72, 82, 30, 30, 10, 71, 10, 10,

                            10, 84, 72, 94, 72, 82, 10, 71, 10, 10, 10, 71, 10, 71, 10, 10, 10, 71, 10, 10,

                            10, 10, 10, 10, 10, 91, 72, 83, 10, 10, 10, 71, 10, 84, 72, 82, 10, 71, 10, 10,

                            10, 30, 30, 30, 81, 83, 10, 10, 10, 10, 10, 71, 10, 10, 10, 71, 10, 84, 82, 10,

                            10, 30, 30, 10, 71, 10, 10, 81, 92, 72, 72, 83, 30, 30, 10, 71, 10, 10, 71, 10,

                            30, 30, 30, 10, 84, 72, 72, 94, 83, 10, 10, 10, 30, 30, 10, 84, 72, 72, 83, 10,

                            30, 30, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 30, 30, 30, 10, 10, 10, 10, 10, };

    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 1;               
                }

                

            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 0;               
                }

            }
        }

        if (bust == 0) {
            speed = 3;
        } else {
            speed = 6;
        }


        if (muveIn==1) {
            if (muveLeft==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
            if (muveRight==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
        }


        if (muveOut==1) {
            if (muveLeft==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
            if (muveRight==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
        }


        if (cut > 0 && cut <=89) {
            cutDeg = 90 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 90 && cut <=179) {
            cutDeg = 90 - (180 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 180 && cut <=269) {
            cutDeg = 270 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut > 270 && cut <=359) {
            cutDeg = 90 - (360 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut == 0 || cut == 360) {
            direction = 3;
            speedMath = speed;
        } else if (cut == 90) {
            direction = 4;
            speedMath = speed;
        } else if (cut == 180) {
            direction = 5;
            speedMath = speed;
        } else if (cut == 270) {
            direction = 6;
            speedMath = speed;
        }




        if (muveIn == 1) {
            if (direction == 1) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 -= speedMath;
            } else if (direction == 4) {
                posX1 += speedMath;
            } else if (direction == 5) {
                posY1 += speedMath;
            } else if (direction == 6) {
                posX1 -= speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 


        if (muveOut == 1) {
            if (direction == 1) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 += speedMath;
            } else if (direction == 4) {
                posX1 -= speedMath;
            } else if (direction == 5) {
                posY1 -= speedMath;
            } else if (direction == 6) {
                posX1 += speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 




        // right boundary 
        if (dest4.x + dest4.w > 1000) {
            dest4.x = 1000 - dest4.w;
            posX1 = dest4.x;
        }


        // left boundary 
        if (dest4.x < 0) {
            dest4.x = 0;
            posX1 = dest4.x;
        }


        // bottom boundary 
        if (dest4.y + dest4.h > 1000) {
            dest4.y = 1000 - dest4.h;
            posY1 = dest4.y;
        }
        

        // upper boundary 
        if (dest4.y < 0){
            dest4.y = 0;
            posY1 = dest4.y;
        }

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        

        int cutRoad = 0;
        for (int u = 0; u < 20; u++) {
            cutRoad = 0;

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 20; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 10) {
                    texBottpm = tex1;
                    cutRoad = 0;
                } else if (masTex[u][y] == 50) {
                    texBottpm = roadTex4;
                    cutRoad = 0;
                } else if (masTex[u][y] == 60 || masTex[u][y] == 61 || masTex[u][y] == 62) {
                    texBottpm = roadStart1;
                    if (masTex[u][y] == 60) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 61) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 62) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 70 || masTex[u][y] == 71 || masTex[u][y] == 72) {
                    texBottpm = roadTex1;
                    if (masTex[u][y] == 70) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 71) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 72) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 80 || masTex[u][y] == 81 || masTex[u][y] == 82 || masTex[u][y] == 83 || masTex[u][y] == 84) {
                    texBottpm = roadTex2;
                    if (masTex[u][y] == 80) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 81) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 82) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 83) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 84) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 90 || masTex[u][y] == 91 || masTex[u][y] == 92 || masTex[u][y] == 93 || masTex[u][y] == 94) {
                    texBottpm = roadTex3;
                    if (masTex[u][y] == 90) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 91) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 92) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 93) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 94) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 30) {
                    texBottpm = tex3;
                    cutRoad = 0;
                } else if (masTex[u][y] == 40) {
                    texBottpm = tex4;
                    cutRoad = 0;
                }

//roadStart1
                
                //SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                SDL_RenderCopyEx(rend, texBottpm, NULL, &dest, cutRoad, NULL, SDL_FLIP_NONE);
                
            }

        }

        //SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}












































//gcc main.c -o main -lmingw32 -lSDL2main -lSDL2_image -lSDL2

//printf ("aUR=---bUR=");


#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1600, 900, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* star;
    star = IMG_Load("img/star.bmp");



    SDL_Surface* road1;
    road1 = IMG_Load("img/road1.bmp");

    SDL_Surface* road2;
    road2 = IMG_Load("img/road2.bmp");

    SDL_Surface* road3;
    road3 = IMG_Load("img/road3.bmp");

    SDL_Surface* road4;
    road4 = IMG_Load("img/road4.bmp");

    SDL_Surface* roadStart;
    roadStart = IMG_Load("img/roadStart.bmp");



    SDL_Surface* road1star;
    road1star = IMG_Load("img/road1star.bmp");

    SDL_Surface* road2star;
    road2star = IMG_Load("img/road2star.bmp");

    SDL_Surface* road3star;
    road3star = IMG_Load("img/road3star.bmp");

    SDL_Surface* road4star;
    road4star = IMG_Load("img/road4star.bmp");

    SDL_Surface* roadStartstar;
    roadStartstar = IMG_Load("img/roadStartstar.bmp");



    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* send;
    send = IMG_Load("img/send.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/car2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* starTex;
    starTex = SDL_CreateTextureFromSurface(rend, star);
    SDL_FreeSurface(star);



    SDL_Texture* roadTex1;
    roadTex1 = SDL_CreateTextureFromSurface(rend, road1);
    SDL_FreeSurface(road1);

    SDL_Texture* roadTex2;
    roadTex2 = SDL_CreateTextureFromSurface(rend, road2);
    SDL_FreeSurface(road2);

    SDL_Texture* roadTex3;
    roadTex3 = SDL_CreateTextureFromSurface(rend, road3);
    SDL_FreeSurface(road3);

    SDL_Texture* roadTex4;
    roadTex4 = SDL_CreateTextureFromSurface(rend, road4);
    SDL_FreeSurface(road4);

    SDL_Texture* roadStart1;
    roadStart1 = SDL_CreateTextureFromSurface(rend, roadStart);
    SDL_FreeSurface(roadStart);



    SDL_Texture* roadTex1star;
    roadTex1star = SDL_CreateTextureFromSurface(rend, road1star);
    SDL_FreeSurface(road1star);

    SDL_Texture* roadTex2star;
    roadTex2star = SDL_CreateTextureFromSurface(rend, road2star);
    SDL_FreeSurface(road2star);

    SDL_Texture* roadTex3star;
    roadTex3star = SDL_CreateTextureFromSurface(rend, road3star);
    SDL_FreeSurface(road3star);

    SDL_Texture* roadTex4star;
    roadTex4star = SDL_CreateTextureFromSurface(rend, road4star);
    SDL_FreeSurface(road4star);

    SDL_Texture* roadStart1star;
    roadStart1star = SDL_CreateTextureFromSurface(rend, roadStartstar);
    SDL_FreeSurface(roadStartstar);




    SDL_Texture* tex3send;
    tex3send = SDL_CreateTextureFromSurface(rend, send);
    SDL_FreeSurface(send);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;
    SDL_Rect destStar;
    


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 500;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(starTex, NULL, NULL, &destStar.w, &destStar.h);
    //dest.w /= 3;
    //dest.h /= 3;

    destStar.w /= 4;
    destStar.h /= 4;

    SDL_QueryTexture(roadTex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1, NULL, NULL, &dest.w, &dest.h);


    SDL_QueryTexture(roadTex1star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1star, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 2;
    //dest.h /= 2;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    SDL_QueryTexture(tex3send, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    dest.w /= 2;
    dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3;
    int muveIn=0, muveOut=0, bust=0, cut = 0, cutDeg=0, muveLeft=0, muveRight=0, direction=0, degLeftRight=5;
    float posX1=dest4.x, posY1=dest4.y, posX2, posY2, aDes, bDes=3, cDes, tanAlfa, radAlfa, aUR, bUR, speedMath;

    int rightX, leftX, tobY, bottomY;
    int masPosX, masPosY;
    int top, bot, lef, rig;


    cutDeg = 90 - cut;
    radAlfa=cutDeg * M_PI/180;
    cDes = bDes/cos(radAlfa);
    aDes = sqrt((cDes * cDes) - (bDes * bDes));
    posX2 = posX1 + bDes;
    posY2 = posY1 - aDes;
    aUR = (posY2-posY1)/(posX2-posX1);
    bUR = posY1-posX1*aUR;
    speedMath=bDes/(cDes/speed);

    printf ("aUR=%f---bUR=%f---\n", aUR, bUR);
    printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
    printf ("posX2=%f---posY2=%f---\n", posX2, posY2);
    printf ("cDes=%f---aDes=%f---\n", cDes, aDes);
    printf ("radAlfa=%f---\n\n\n", radAlfa);



    int masTex[18][32] = {  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 

                            10, 81, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 82, 10, 10, 81, 72, 72, 92, 72, 92, 72, 72, 72, 62, 72, 72, 72, 72, 72, 82, 10,

                            10, 71, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 71, 10, 81, 83, 10, 10, 71, 10, 71, 20, 20, 20, 20, 20, 20, 20, 20, 20, 61, 10,

                            10, 71, 10, 81, 72, 72, 72, 72, 72, 72, 82, 10, 84, 72, 83, 10, 10, 81, 83, 10, 71, 20, 20, 20, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 71, 20, 20, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 81, 72, 82, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10, 

                            10, 71, 10, 71, 10, 81, 72, 72, 62, 72, 94, 72, 72, 93, 10, 71, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 91, 72, 50, 72, 93, 10, 10, 10, 10, 10, 10, 10, 71, 10, 84, 62, 83, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 20, 20, 71, 10,

                            10, 71, 10, 71, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 10, 10, 10, 10, 71, 20, 30, 30, 30, 30, 30, 20, 20, 20, 71, 20,

                            10, 61, 10, 71, 10, 84, 72, 72, 72, 82, 30, 30, 10, 84, 72, 82, 10, 10, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 20, 20, 71, 20,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 71, 30, 30, 30, 10, 10, 84, 72, 82, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 30, 30, 30, 10, 71, 10, 30, 30, 30, 30, 10, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 30, 30, 10, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 81, 72, 94, 72, 92, 72, 82, 30, 30, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 20,

                            10, 84, 72, 94, 72, 82, 10, 71, 10, 10, 10, 71, 10, 71, 10, 10, 10, 71, 10, 10, 71, 20, 20, 30, 30, 20, 30, 30, 30, 20, 71, 20,

                            10, 10, 10, 10, 10, 91, 72, 93, 10, 10, 10, 91, 72, 94, 72, 82, 10, 71, 10, 10, 71, 20, 20, 20, 20, 20, 20, 20, 20, 20, 61, 10,

                            10, 30, 30, 10, 10, 84, 72, 83, 10, 10, 10, 84, 72, 62, 72, 94, 72, 94, 72, 72, 94, 72, 72, 72, 72, 72, 72, 72, 72, 72, 83, 10,

                            10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 20, 20, 10, 10, 10, 10, 10,

                            };

    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 1;               
                }

                

            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 0;               
                }

            }
        }

        if (bust == 0) {
            speed = 3;
        } else {
            speed = 6;
        }

        if (muveIn==0 && muveOut==0) {
           if (muveLeft==1) {
                cut-=2;
                if (cut<=0) {
                    cut=360;
                }
            }
            if (muveRight==1) {
                cut+=2;
                if (cut>=360) {
                    cut=0;
                }
            } 
        }


        if (muveIn==1) {
            if (muveLeft==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
            if (muveRight==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
        }


        if (muveOut==1) {
            if (muveLeft==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
            if (muveRight==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
        }


        if (cut > 0 && cut <=89) {
            cutDeg = 90 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 90 && cut <=179) {
            cutDeg = 90 - (180 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 180 && cut <=269) {
            cutDeg = 270 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut > 270 && cut <=359) {
            cutDeg = 90 - (360 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut == 0 || cut == 360) {
            direction = 3;
            speedMath = speed;
        } else if (cut == 90) {
            direction = 4;
            speedMath = speed;
        } else if (cut == 180) {
            direction = 5;
            speedMath = speed;
        } else if (cut == 270) {
            direction = 6;
            speedMath = speed;
        }




        if (muveIn == 1) {
            if (direction == 1) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 -= speedMath;
            } else if (direction == 4) {
                posX1 += speedMath;
            } else if (direction == 5) {
                posY1 += speedMath;
            } else if (direction == 6) {
                posX1 -= speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 


        if (muveOut == 1) {
            if (direction == 1) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 += speedMath;
            } else if (direction == 4) {
                posX1 -= speedMath;
            } else if (direction == 5) {
                posY1 -= speedMath;
            } else if (direction == 6) {
                posX1 += speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 



    
        rightX=1600; 
        leftX=0;
        tobY=0; 
        bottomY=900;
        masPosX=round(posX1);
        masPosY=round(posY1);

        masPosY=(masPosY+12)/50;
        masPosX=(masPosX+12)/50;
        top = masTex[masPosY-1][masPosX];
        bot = masTex[masPosY+1][masPosX];
        rig = masTex[masPosY][masPosX+1];
        lef = masTex[masPosY][masPosX-1];
        int r1=0, r2=0, iNumRand=0, stopRand=0;

        if (masTex[masPosY][masPosX] == 501 || masTex[masPosY][masPosX] == 601 || masTex[masPosY][masPosX] == 6011 || masTex[masPosY][masPosX] == 621 || masTex[masPosY][masPosX] == 701 || masTex[masPosY][masPosX] == 711 || masTex[masPosY][masPosX] == 721 || masTex[masPosY][masPosX] == 801 || masTex[masPosY][masPosX] == 811 || masTex[masPosY][masPosX] == 821 || masTex[masPosY][masPosX] == 831 || masTex[masPosY][masPosX] == 841 || masTex[masPosY][masPosX] == 901 || masTex[masPosY][masPosX] == 911 || masTex[masPosY][masPosX] == 921 || masTex[masPosY][masPosX] == 931 || masTex[masPosY][masPosX] == 941) {
            if (masTex[masPosY][masPosX] == 501) {
                masTex[masPosY][masPosX] = 50;
            } else if (masTex[masPosY][masPosX] == 701) {
                masTex[masPosY][masPosX] = 70;
            } else if (masTex[masPosY][masPosX] == 711) {
                masTex[masPosY][masPosX] = 71;
            } else if (masTex[masPosY][masPosX] == 721) {
                masTex[masPosY][masPosX] = 72;
            } else if (masTex[masPosY][masPosX] == 601) {
                masTex[masPosY][masPosX] = 60;
            } else if (masTex[masPosY][masPosX] == 611) {
                masTex[masPosY][masPosX] = 61;
            } else if (masTex[masPosY][masPosX] == 621) {
                masTex[masPosY][masPosX] = 62;
            } else if (masTex[masPosY][masPosX] == 801) {
                masTex[masPosY][masPosX] = 80;
            } else if (masTex[masPosY][masPosX] == 811) {
                masTex[masPosY][masPosX] = 81;
            } else if (masTex[masPosY][masPosX] == 821) {
                masTex[masPosY][masPosX] = 82;
            } else if (masTex[masPosY][masPosX] == 831) {
                masTex[masPosY][masPosX] = 83;
            } else if (masTex[masPosY][masPosX] == 841) {
                masTex[masPosY][masPosX] = 84;
            } else if (masTex[masPosY][masPosX] == 901) {
                masTex[masPosY][masPosX] = 90;
            } else if (masTex[masPosY][masPosX] == 911) {
                masTex[masPosY][masPosX] = 91;
            } else if (masTex[masPosY][masPosX] == 921) {
                masTex[masPosY][masPosX] = 92;
            } else if (masTex[masPosY][masPosX] == 931) {
                masTex[masPosY][masPosX] = 93;
            } else if (masTex[masPosY][masPosX] == 941) {
                masTex[masPosY][masPosX] = 94;
            }

            stopRand=1;
            srand(time(NULL));            

            while (stopRand==1) {
                r1 = rand() % 17;
                r2 = rand() % 31;

                if (masTex[r1][r2] == 50) {
                    masTex[r1][r2] = 501;
                    stopRand=0;
                } else if (masTex[r1][r2] == 70) {
                    masTex[r1][r2] = 701;
                    stopRand=0;
                } else if (masTex[r1][r2]== 71) {
                    masTex[r1][r2] = 711;
                    stopRand=0;
                } else if (masTex[r1][r2] == 72) {
                    masTex[r1][r2] = 721;
                    stopRand=0;
                } else if (masTex[r1][r2] == 60) {
                    masTex[r1][r2] = 601;
                    stopRand=0;
                } else if (masTex[r1][r2] == 61) {
                    masTex[r1][r2] = 611;
                    stopRand=0;
                } else if (masTex[r1][r2] == 62) {
                    masTex[r1][r2] = 621;
                    stopRand=0;
                } else if (masTex[r1][r2] == 80) {
                    masTex[r1][r2] = 801;
                    stopRand=0;
                } else if (masTex[r1][r2] == 81) {
                    masTex[r1][r2] = 811;
                    stopRand=0;
                } else if (masTex[r1][r2] == 82) {
                    masTex[r1][r2] = 821;
                    stopRand=0;
                } else if (masTex[r1][r2] == 83) {
                    masTex[r1][r2] = 831;
                    stopRand=0;
                } else if (masTex[r1][r2] == 84) {
                    masTex[r1][r2] = 841;
                    stopRand=0;
                } else if (masTex[r1][r2] == 90) {
                    masTex[r1][r2] = 901;
                    stopRand=0;
                } else if (masTex[r1][r2] == 91) {
                    masTex[r1][r2] = 911;
                    stopRand=0;
                } else if (masTex[r1][r2] == 92) {
                    masTex[r1][r2] = 921;
                    stopRand=0;
                } else if (masTex[r1][r2] == 93) {
                    masTex[r1][r2] = 931;
                    stopRand=0;
                } else if (masTex[r1][r2] == 94) {
                    masTex[r1][r2] = 941;
                    stopRand=0;
                }
            }
        }


        if (top < 50 || top > 1000) {
            tobY=(50*masPosY)+2; 
        }

        if (bot < 50 || bot > 1000) {
            bottomY=(50*(masPosY+1))-2; 
        }

        if (rig < 50 || rig > 1000) {
            rightX=(50*(masPosX+1))-7; 
        }

        if (lef < 50 || lef > 1000) {
            leftX=(50*masPosX)+7; 
        }

        // right boundary 
        if (dest4.x + dest4.w > rightX) {
            dest4.x = rightX - dest4.w;
            posX1 = dest4.x;
        }


        // left boundary 
        if (dest4.x < leftX) {
            dest4.x = leftX;
            posX1 = dest4.x;
        }


        // bottom boundary 
        if (dest4.y + dest4.h > bottomY) {
            dest4.y = bottomY - dest4.h;
            posY1 = dest4.y;
        }
        

        // upper boundary 
        if (dest4.y < tobY){
            dest4.y = tobY;
            posY1 = dest4.y;
        }

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        

        int cutRoad = 0;
        for (int u = 0; u < 18; u++) {
            cutRoad = 0;

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 32; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 10) {
                    texBottpm = tex1;
                    cutRoad = 0;
                } else if (masTex[u][y] == 50) {
                    texBottpm = roadTex4;
                    cutRoad = 0;
                } else if (masTex[u][y] == 60 || masTex[u][y] == 61 || masTex[u][y] == 62) {
                    texBottpm = roadStart1;
                    if (masTex[u][y] == 60) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 61) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 62) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 70 || masTex[u][y] == 71 || masTex[u][y] == 72) {
                    texBottpm = roadTex1;
                    if (masTex[u][y] == 70) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 71) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 72) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 80 || masTex[u][y] == 81 || masTex[u][y] == 82 || masTex[u][y] == 83 || masTex[u][y] == 84) {
                    texBottpm = roadTex2;
                    if (masTex[u][y] == 80) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 81) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 82) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 83) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 84) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 90 || masTex[u][y] == 91 || masTex[u][y] == 92 || masTex[u][y] == 93 || masTex[u][y] == 94) {
                    texBottpm = roadTex3;
                    if (masTex[u][y] == 90) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 91) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 92) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 93) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 94) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 501) {
                    texBottpm = roadTex4star;
                    cutRoad = 0;
                } else if (masTex[u][y] == 601 || masTex[u][y] == 611 || masTex[u][y] == 621) {
                    texBottpm = roadStart1star;
                    if (masTex[u][y] == 601) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 611) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 621) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 701 || masTex[u][y] == 711 || masTex[u][y] == 721) {
                    texBottpm = roadTex1star;
                    if (masTex[u][y] == 701) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 711) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 721) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 801 || masTex[u][y] == 811 || masTex[u][y] == 821 || masTex[u][y] == 831 || masTex[u][y] == 841) {
                    texBottpm = roadTex2star;
                    if (masTex[u][y] == 801) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 811) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 821) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 831) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 841) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 901 || masTex[u][y] == 911 || masTex[u][y] == 921 || masTex[u][y] == 931 || masTex[u][y] == 941) {
                    texBottpm = roadTex3star;
                    if (masTex[u][y] == 901) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 911) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 921) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 931) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 941) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 20) {
                    texBottpm = tex3send;
                    cutRoad = 0;
                } else if (masTex[u][y] == 30) {
                    texBottpm = tex3;
                    cutRoad = 0;
                } else if (masTex[u][y] == 40) {
                    texBottpm = tex4;
                    cutRoad = 0;
                }

//roadStart1
                
                //SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                SDL_RenderCopyEx(rend, texBottpm, NULL, &dest, cutRoad, NULL, SDL_FLIP_NONE);
                
            }

        }

        //SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
        SDL_Delay(1000 / 60);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}

























































//gcc main.c -o main -lmingw32 -lSDL2main -lSDL2_image -lSDL2

//printf ("aUR=---bUR=");


//#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {
    srand(time(NULL)); 
    //printf ("hello gamer");

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1600, 900, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* star;
    star = IMG_Load("img/star.bmp");



    SDL_Surface* road1;
    road1 = IMG_Load("img/road1.bmp");

    SDL_Surface* road2;
    road2 = IMG_Load("img/road2.bmp");

    SDL_Surface* road3;
    road3 = IMG_Load("img/road3.bmp");

    SDL_Surface* road4;
    road4 = IMG_Load("img/road4.bmp");

    SDL_Surface* roadStart;
    roadStart = IMG_Load("img/roadStart.bmp");



    SDL_Surface* road1star;
    road1star = IMG_Load("img/road1star.bmp");

    SDL_Surface* road2star;
    road2star = IMG_Load("img/road2star.bmp");

    SDL_Surface* road3star;
    road3star = IMG_Load("img/road3star.bmp");

    SDL_Surface* road4star;
    road4star = IMG_Load("img/road4star.bmp");

    SDL_Surface* roadStartstar;
    roadStartstar = IMG_Load("img/roadStartstar.bmp");



    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* send;
    send = IMG_Load("img/send.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/car2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* starTex;
    starTex = SDL_CreateTextureFromSurface(rend, star);
    SDL_FreeSurface(star);



    SDL_Texture* roadTex1;
    roadTex1 = SDL_CreateTextureFromSurface(rend, road1);
    SDL_FreeSurface(road1);

    SDL_Texture* roadTex2;
    roadTex2 = SDL_CreateTextureFromSurface(rend, road2);
    SDL_FreeSurface(road2);

    SDL_Texture* roadTex3;
    roadTex3 = SDL_CreateTextureFromSurface(rend, road3);
    SDL_FreeSurface(road3);

    SDL_Texture* roadTex4;
    roadTex4 = SDL_CreateTextureFromSurface(rend, road4);
    SDL_FreeSurface(road4);

    SDL_Texture* roadStart1;
    roadStart1 = SDL_CreateTextureFromSurface(rend, roadStart);
    SDL_FreeSurface(roadStart);



    SDL_Texture* roadTex1star;
    roadTex1star = SDL_CreateTextureFromSurface(rend, road1star);
    SDL_FreeSurface(road1star);

    SDL_Texture* roadTex2star;
    roadTex2star = SDL_CreateTextureFromSurface(rend, road2star);
    SDL_FreeSurface(road2star);

    SDL_Texture* roadTex3star;
    roadTex3star = SDL_CreateTextureFromSurface(rend, road3star);
    SDL_FreeSurface(road3star);

    SDL_Texture* roadTex4star;
    roadTex4star = SDL_CreateTextureFromSurface(rend, road4star);
    SDL_FreeSurface(road4star);

    SDL_Texture* roadStart1star;
    roadStart1star = SDL_CreateTextureFromSurface(rend, roadStartstar);
    SDL_FreeSurface(roadStartstar);




    SDL_Texture* tex3send;
    tex3send = SDL_CreateTextureFromSurface(rend, send);
    SDL_FreeSurface(send);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;
    SDL_Rect destStar;
    


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;

    dest4.x = 60;
    dest4.y = 500;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(starTex, NULL, NULL, &destStar.w, &destStar.h);
    //dest.w /= 3;
    //dest.h /= 3;

    destStar.w /= 4;
    destStar.h /= 4;

    SDL_QueryTexture(roadTex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1, NULL, NULL, &dest.w, &dest.h);


    SDL_QueryTexture(roadTex1star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1star, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 2;
    //dest.h /= 2;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    SDL_QueryTexture(tex3send, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    dest.w /= 2;
    dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3;
    int muveIn=0, muveOut=0, bust=0, cut = 0, cutDeg=0, muveLeft=0, muveRight=0, direction=0, degLeftRight=5;
    float posX1=dest4.x, posY1=dest4.y, posX2, posY2, aDes, bDes=3, cDes, tanAlfa, radAlfa, aUR, bUR, speedMath, firstStart=0;

    int rightX, leftX, tobY, bottomY;
    int masPosX, masPosY;
    int top, bot, lef, rig;
    int rendTreck=0, iMas=0, jMas=0;


    cutDeg = 90 - cut;
    radAlfa=cutDeg * M_PI/180;
    cDes = bDes/cos(radAlfa);
    aDes = sqrt((cDes * cDes) - (bDes * bDes));
    posX2 = posX1 + bDes;
    posY2 = posY1 - aDes;
    aUR = (posY2-posY1)/(posX2-posX1);
    bUR = posY1-posX1*aUR;
    speedMath=bDes/(cDes/speed);

    //printf ("aUR=%f---bUR=%f---\n", aUR, bUR);
    //printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
    //printf ("posX2=%f---posY2=%f---\n", posX2, posY2);
    //printf ("cDes=%f---aDes=%f---\n", cDes, aDes);
    //printf ("radAlfa=%f---\n\n\n", radAlfa);



    int masTex[18][32] = {  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 

                            10, 81, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 82, 10, 10, 81, 72, 72, 92, 72, 92, 72, 72, 72, 62, 72, 72, 72, 72, 72, 82, 10,

                            10, 71, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 71, 10, 81, 83, 10, 10, 71, 10, 71, 20, 20, 20, 20, 20, 20, 20, 20, 20, 61, 10,

                            10, 71, 10, 81, 72, 72, 72, 72, 72, 72, 82, 10, 84, 72, 83, 10, 10, 81, 83, 10, 71, 20, 20, 20, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 71, 20, 20, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 81, 72, 82, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10, 

                            10, 71, 10, 71, 10, 81, 72, 72, 62, 72, 94, 72, 72, 93, 10, 71, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 91, 72, 50, 72, 93, 10, 10, 10, 10, 10, 10, 10, 71, 10, 84, 62, 83, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 20, 20, 71, 10,

                            10, 71, 10, 71, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 10, 10, 10, 10, 71, 20, 30, 30, 30, 30, 30, 20, 20, 20, 71, 20,

                            10, 61, 10, 71, 10, 84, 72, 72, 72, 82, 30, 30, 10, 84, 72, 82, 10, 10, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 20, 20, 71, 20,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 71, 30, 30, 30, 10, 10, 84, 72, 82, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 30, 30, 30, 10, 71, 10, 30, 30, 30, 30, 10, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 30, 30, 10, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 81, 72, 94, 72, 92, 72, 82, 30, 30, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 20,

                            10, 84, 72, 94, 72, 82, 10, 71, 10, 10, 10, 71, 10, 71, 10, 10, 10, 71, 10, 10, 71, 20, 20, 30, 30, 20, 30, 30, 30, 20, 71, 20,

                            10, 10, 10, 10, 10, 91, 72, 93, 10, 10, 10, 91, 72, 94, 72, 82, 10, 71, 10, 10, 71, 20, 20, 20, 20, 20, 20, 20, 20, 20, 61, 10,

                            10, 30, 30, 10, 10, 84, 72, 83, 10, 10, 10, 84, 72, 62, 72, 94, 72, 94, 72, 72, 94, 72, 72, 72, 72, 72, 72, 72, 72, 72, 83, 10,

                            10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 20, 20, 10, 10, 10, 10, 10,

                            };


    // annimation loop 
    while (!close) {
        SDL_Event event;




        // Events mangement 
        while (SDL_PollEvent(&event)) {



            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 1;               
                }

                

            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 0;               
                }

            }
        }



        if (rendTreck==1) {
            //магия генерации трека
            srand(time(NULL)); 
            int whileTest=1, rendStartTest=1;  

            while (whileTest == 1) {
                if (rendStartTest == 1) {
                    //up = 0; rg = 0; dw = 0; lf = 0; colRect = 0;

                    for (int i = 0; i < 18; i++) {
                        for (int j = 0; j < 32; j++){
                            masTex[i][j] = 71;
                        }
                    }

                    rendTreck = 0;
                    rendStartTest = 0;
                    whileTest=0;
                } else {

                }
            }


        } else {

            

            if (bust == 0) {
                speed = 3;
            } else {
                speed = 6;
            }

            if (muveIn==0 && muveOut==0) {
               if (muveLeft==1) {
                    cut-=2;
                    if (cut<=0) {
                        cut=360;
                    }
                }
                if (muveRight==1) {
                    cut+=2;
                    if (cut>=360) {
                        cut=0;
                    }
                } 
            }


            if (muveIn==1) {
                if (muveLeft==1) {
                    cut-=degLeftRight;
                    if (cut<=0) {
                        cut=360;
                    }
                }
                if (muveRight==1) {
                    cut+=degLeftRight;
                    if (cut>=360) {
                        cut=0;
                    }
                }
            }


            if (muveOut==1) {
                if (muveLeft==1) {
                    cut+=degLeftRight;
                    if (cut>=360) {
                        cut=0;
                    }
                }
                if (muveRight==1) {
                    cut-=degLeftRight;
                    if (cut<=0) {
                        cut=360;
                    }
                }
            }


            if (cut > 0 && cut <=89) {
                cutDeg = 90 - cut;
                radAlfa=cutDeg * M_PI/180;
                cDes = bDes/cos(radAlfa);
                aDes = sqrt((cDes * cDes) - (bDes * bDes));
                posX2 = posX1 + bDes;
                posY2 = posY1 - aDes;
                aUR = (posY2-posY1)/(posX2-posX1);
                bUR = posY1-posX1*aUR;
                speedMath=bDes/(cDes/speed);
                direction = 1;
            } else if (cut > 90 && cut <=179) {
                cutDeg = 90 - (180 - cut);
                radAlfa=cutDeg * M_PI/180;
                cDes = bDes/cos(radAlfa);
                aDes = sqrt((cDes * cDes) - (bDes * bDes));
                posX2 = posX1 + bDes;
                posY2 = posY1 + aDes;
                aUR = (posY2-posY1)/(posX2-posX1);
                bUR = posY1-posX1*aUR;
                speedMath=bDes/(cDes/speed);
                direction = 1;
            } else if (cut > 180 && cut <=269) {
                cutDeg = 270 - cut;
                radAlfa=cutDeg * M_PI/180;
                cDes = bDes/cos(radAlfa);
                aDes = sqrt((cDes * cDes) - (bDes * bDes));
                posX2 = posX1 - bDes;
                posY2 = posY1 + aDes;
                aUR = (posY2-posY1)/(posX2-posX1);
                bUR = posY1-posX1*aUR;
                speedMath=bDes/(cDes/speed);
                direction = 2;
            } else if (cut > 270 && cut <=359) {
                cutDeg = 90 - (360 - cut);
                radAlfa=cutDeg * M_PI/180;
                cDes = bDes/cos(radAlfa);
                aDes = sqrt((cDes * cDes) - (bDes * bDes));
                posX2 = posX1 - bDes;
                posY2 = posY1 - aDes;
                aUR = (posY2-posY1)/(posX2-posX1);
                bUR = posY1-posX1*aUR;
                speedMath=bDes/(cDes/speed);
                direction = 2;
            } else if (cut == 0 || cut == 360) {
                direction = 3;
                speedMath = speed;
            } else if (cut == 90) {
                direction = 4;
                speedMath = speed;
            } else if (cut == 180) {
                direction = 5;
                speedMath = speed;
            } else if (cut == 270) {
                direction = 6;
                speedMath = speed;
            }




            if (muveIn == 1) {
                if (direction == 1) {
                    posX1 += speedMath;
                    posY1 = aUR*posX1+bUR;
                } else if (direction == 2) {
                    posX1 -= speedMath;
                    posY1 = aUR*posX1+bUR;
                } else if (direction == 3) {
                    posY1 -= speedMath;
                } else if (direction == 4) {
                    posX1 += speedMath;
                } else if (direction == 5) {
                    posY1 += speedMath;
                } else if (direction == 6) {
                    posX1 -= speedMath;
                }
                dest4.x=round(posX1);
                dest4.y=round(posY1);
            } 


            if (muveOut == 1) {
                if (direction == 1) {
                    posX1 -= speedMath;
                    posY1 = aUR*posX1+bUR;
                } else if (direction == 2) {
                    posX1 += speedMath;
                    posY1 = aUR*posX1+bUR;
                } else if (direction == 3) {
                    posY1 += speedMath;
                } else if (direction == 4) {
                    posX1 -= speedMath;
                } else if (direction == 5) {
                    posY1 -= speedMath;
                } else if (direction == 6) {
                    posX1 += speedMath;
                }
                dest4.x=round(posX1);
                dest4.y=round(posY1);
            } 



        
            rightX=1600; 
            leftX=0;
            tobY=0; 
            bottomY=900;
            masPosX=round(posX1);
            masPosY=round(posY1);

            masPosY=(masPosY+12)/50;
            masPosX=(masPosX+12)/50;
            top = masTex[masPosY-1][masPosX];
            bot = masTex[masPosY+1][masPosX];
            rig = masTex[masPosY][masPosX+1];
            lef = masTex[masPosY][masPosX-1];
            int r1=0, r2=0, iNumRand=0, stopRand=0;

            if (firstStart==0) {
                for (int i = 0; i < 6; i++) {
                    stopRand=1;
                    srand(time(NULL));            

                    while (stopRand==1) {
                        r1 = rand() % 17;
                        r2 = rand() % 31;

                        if (masTex[r1][r2] == 50) {
                            masTex[r1][r2] = 501;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 70) {
                            masTex[r1][r2] = 701;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 71) {
                            masTex[r1][r2] = 711;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 72) {
                            masTex[r1][r2] = 721;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 60) {
                            masTex[r1][r2] = 601;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 61) {
                            masTex[r1][r2] = 611;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 62) {
                            masTex[r1][r2] = 621;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 80) {
                            masTex[r1][r2] = 801;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 81) {
                            masTex[r1][r2] = 811;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 82) {
                            masTex[r1][r2] = 821;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 83) {
                            masTex[r1][r2] = 831;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 84) {
                            masTex[r1][r2] = 841;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 90) {
                            masTex[r1][r2] = 901;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 91) {
                            masTex[r1][r2] = 911;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 92) {
                            masTex[r1][r2] = 921;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 93) {
                            masTex[r1][r2] = 931;
                            stopRand=0;
                        } else if (masTex[r1][r2] == 94) {
                            masTex[r1][r2] = 941;
                            stopRand=0;
                        }
                    }
                    stopRand=1;
                }
                firstStart=1;
            }
            

            if (masTex[masPosY][masPosX] == 501 || masTex[masPosY][masPosX] == 601 || masTex[masPosY][masPosX] == 611 || masTex[masPosY][masPosX] == 621 || masTex[masPosY][masPosX] == 701 || masTex[masPosY][masPosX] == 711 || masTex[masPosY][masPosX] == 721 || masTex[masPosY][masPosX] == 801 || masTex[masPosY][masPosX] == 811 || masTex[masPosY][masPosX] == 821 || masTex[masPosY][masPosX] == 831 || masTex[masPosY][masPosX] == 841 || masTex[masPosY][masPosX] == 901 || masTex[masPosY][masPosX] == 911 || masTex[masPosY][masPosX] == 921 || masTex[masPosY][masPosX] == 931 || masTex[masPosY][masPosX] == 941) {
                if (masTex[masPosY][masPosX] == 501) {
                    masTex[masPosY][masPosX] = 50;
                } else if (masTex[masPosY][masPosX] == 701) {
                    masTex[masPosY][masPosX] = 70;
                } else if (masTex[masPosY][masPosX] == 711) {
                    masTex[masPosY][masPosX] = 71;
                } else if (masTex[masPosY][masPosX] == 721) {
                    masTex[masPosY][masPosX] = 72;
                } else if (masTex[masPosY][masPosX] == 601) {
                    masTex[masPosY][masPosX] = 60;
                } else if (masTex[masPosY][masPosX] == 611) {
                    masTex[masPosY][masPosX] = 61;
                } else if (masTex[masPosY][masPosX] == 621) {
                    masTex[masPosY][masPosX] = 62;
                } else if (masTex[masPosY][masPosX] == 801) {
                    masTex[masPosY][masPosX] = 80;
                } else if (masTex[masPosY][masPosX] == 811) {
                    masTex[masPosY][masPosX] = 81;
                } else if (masTex[masPosY][masPosX] == 821) {
                    masTex[masPosY][masPosX] = 82;
                } else if (masTex[masPosY][masPosX] == 831) {
                    masTex[masPosY][masPosX] = 83;
                } else if (masTex[masPosY][masPosX] == 841) {
                    masTex[masPosY][masPosX] = 84;
                } else if (masTex[masPosY][masPosX] == 901) {
                    masTex[masPosY][masPosX] = 90;
                } else if (masTex[masPosY][masPosX] == 911) {
                    masTex[masPosY][masPosX] = 91;
                } else if (masTex[masPosY][masPosX] == 921) {
                    masTex[masPosY][masPosX] = 92;
                } else if (masTex[masPosY][masPosX] == 931) {
                    masTex[masPosY][masPosX] = 93;
                } else if (masTex[masPosY][masPosX] == 941) {
                    masTex[masPosY][masPosX] = 94;
                }

                stopRand=1;
                srand(time(NULL));            

                while (stopRand==1) {
                    r1 = rand() % 17;
                    r2 = rand() % 31;

                    if (masTex[r1][r2] == 50) {
                        masTex[r1][r2] = 501;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 70) {
                        masTex[r1][r2] = 701;
                        stopRand=0;
                    } else if (masTex[r1][r2]== 71) {
                        masTex[r1][r2] = 711;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 72) {
                        masTex[r1][r2] = 721;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 60) {
                        masTex[r1][r2] = 601;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 61) {
                        masTex[r1][r2] = 611;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 62) {
                        masTex[r1][r2] = 621;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 80) {
                        masTex[r1][r2] = 801;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 81) {
                        masTex[r1][r2] = 811;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 82) {
                        masTex[r1][r2] = 821;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 83) {
                        masTex[r1][r2] = 831;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 84) {
                        masTex[r1][r2] = 841;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 90) {
                        masTex[r1][r2] = 901;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 91) {
                        masTex[r1][r2] = 911;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 92) {
                        masTex[r1][r2] = 921;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 93) {
                        masTex[r1][r2] = 931;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 94) {
                        masTex[r1][r2] = 941;
                        stopRand=0;
                    }
                }
            }


            if (top < 50 || top > 1000) {
                tobY=(50*masPosY)+2; 
            }

            if (bot < 50 || bot > 1000) {
                bottomY=(50*(masPosY+1))-2; 
            }

            if (rig < 50 || rig > 1000) {
                rightX=(50*(masPosX+1))-7; 
            }

            if (lef < 50 || lef > 1000) {
                leftX=(50*masPosX)+7; 
            }

            // right boundary 
            if (dest4.x + dest4.w > rightX) {
                dest4.x = rightX - dest4.w;
                posX1 = dest4.x;
            }


            // left boundary 
            if (dest4.x < leftX) {
                dest4.x = leftX;
                posX1 = dest4.x;
            }


            // bottom boundary 
            if (dest4.y + dest4.h > bottomY) {
                dest4.y = bottomY - dest4.h;
                posY1 = dest4.y;
            }
            

            // upper boundary 
            if (dest4.y < tobY){
                dest4.y = tobY;
                posY1 = dest4.y;
            }

            // clears the screen 
            SDL_RenderClear(rend);

            //dest.y = 100;
            //dest.x = 100;

            

            int cutRoad = 0;
            for (int u = 0; u < 18; u++) {
                cutRoad = 0;

                if (u == 0) {
                    dest.y = 0;
                } else {
                    dest.y = 50 * u; 
                }

                
                for (int y = 0; y < 32; y++) {
                     
                    if (y == 0) {
                        dest.x = 0;
                    } else {
                        dest.x = 50 * y;
                    }


                    if (masTex[u][y] == 10) {
                        texBottpm = tex1;
                        cutRoad = 0;
                    } else if (masTex[u][y] == 50) {
                        texBottpm = roadTex4;
                        cutRoad = 0;
                    } else if (masTex[u][y] == 60 || masTex[u][y] == 61 || masTex[u][y] == 62) {
                        texBottpm = roadStart1;
                        if (masTex[u][y] == 60) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 61) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 62) {
                            cutRoad = 90;
                        }
                    } else if (masTex[u][y] == 70 || masTex[u][y] == 71 || masTex[u][y] == 72) {
                        texBottpm = roadTex1;
                        if (masTex[u][y] == 70) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 71) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 72) {
                            cutRoad = 90;
                        }
                    } else if (masTex[u][y] == 80 || masTex[u][y] == 81 || masTex[u][y] == 82 || masTex[u][y] == 83 || masTex[u][y] == 84) {
                        texBottpm = roadTex2;
                        if (masTex[u][y] == 80) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 81) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 82) {
                            cutRoad = 90;
                        } else if (masTex[u][y] == 83) {
                            cutRoad = 180;
                        } else if (masTex[u][y] == 84) {
                            cutRoad = 270;
                        }
                    } else if (masTex[u][y] == 90 || masTex[u][y] == 91 || masTex[u][y] == 92 || masTex[u][y] == 93 || masTex[u][y] == 94) {
                        texBottpm = roadTex3;
                        if (masTex[u][y] == 90) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 91) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 92) {
                            cutRoad = 90;
                        } else if (masTex[u][y] == 93) {
                            cutRoad = 180;
                        } else if (masTex[u][y] == 94) {
                            cutRoad = 270;
                        }
                    } else if (masTex[u][y] == 501) {
                        texBottpm = roadTex4star;
                        cutRoad = 0;
                    } else if (masTex[u][y] == 601 || masTex[u][y] == 611 || masTex[u][y] == 621) {
                        texBottpm = roadStart1star;
                        if (masTex[u][y] == 601) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 611) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 621) {
                            cutRoad = 90;
                        }
                    } else if (masTex[u][y] == 701 || masTex[u][y] == 711 || masTex[u][y] == 721) {
                        texBottpm = roadTex1star;
                        if (masTex[u][y] == 701) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 711) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 721) {
                            cutRoad = 90;
                        }
                    } else if (masTex[u][y] == 801 || masTex[u][y] == 811 || masTex[u][y] == 821 || masTex[u][y] == 831 || masTex[u][y] == 841) {
                        texBottpm = roadTex2star;
                        if (masTex[u][y] == 801) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 811) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 821) {
                            cutRoad = 90;
                        } else if (masTex[u][y] == 831) {
                            cutRoad = 180;
                        } else if (masTex[u][y] == 841) {
                            cutRoad = 270;
                        }
                    } else if (masTex[u][y] == 901 || masTex[u][y] == 911 || masTex[u][y] == 921 || masTex[u][y] == 931 || masTex[u][y] == 941) {
                        texBottpm = roadTex3star;
                        if (masTex[u][y] == 901) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 911) {
                            cutRoad = 0;
                        } else if (masTex[u][y] == 921) {
                            cutRoad = 90;
                        } else if (masTex[u][y] == 931) {
                            cutRoad = 180;
                        } else if (masTex[u][y] == 941) {
                            cutRoad = 270;
                        }
                    } else if (masTex[u][y] == 20) {
                        texBottpm = tex3send;
                        cutRoad = 0;
                    } else if (masTex[u][y] == 30) {
                        texBottpm = tex3;
                        cutRoad = 0;
                    } else if (masTex[u][y] == 40) {
                        texBottpm = tex4;
                        cutRoad = 0;
                    }

                    
                    //SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                    SDL_RenderCopyEx(rend, texBottpm, NULL, &dest, cutRoad, NULL, SDL_FLIP_NONE);
                    
                }

            }

            //SDL_RenderCopy(rend, tex4, NULL, &dest4);
            SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);

            // triggers the double buffers 
            // for multiple rendering 
            SDL_RenderPresent(rend);

            // calculates to 60 fps 
            SDL_Delay(1000 / 60);

        }


    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}


















































































































































//gcc main.c -o main -lmingw32 -lSDL2main -lSDL2_image -lSDL2

//printf ("aUR=---bUR=");


//#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {

    printf ("hello gamer");

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1600, 900, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* star;
    star = IMG_Load("img/star.bmp");



    SDL_Surface* road1;
    road1 = IMG_Load("img/road1.bmp");

    SDL_Surface* road2;
    road2 = IMG_Load("img/road2.bmp");

    SDL_Surface* road3;
    road3 = IMG_Load("img/road3.bmp");

    SDL_Surface* road4;
    road4 = IMG_Load("img/road4.bmp");

    SDL_Surface* roadStart;
    roadStart = IMG_Load("img/roadStart.bmp");



    SDL_Surface* road1star;
    road1star = IMG_Load("img/road1star.bmp");

    SDL_Surface* road2star;
    road2star = IMG_Load("img/road2star.bmp");

    SDL_Surface* road3star;
    road3star = IMG_Load("img/road3star.bmp");

    SDL_Surface* road4star;
    road4star = IMG_Load("img/road4star.bmp");

    SDL_Surface* roadStartstar;
    roadStartstar = IMG_Load("img/roadStartstar.bmp");



    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* send;
    send = IMG_Load("img/send.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/car2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* starTex;
    starTex = SDL_CreateTextureFromSurface(rend, star);
    SDL_FreeSurface(star);



    SDL_Texture* roadTex1;
    roadTex1 = SDL_CreateTextureFromSurface(rend, road1);
    SDL_FreeSurface(road1);

    SDL_Texture* roadTex2;
    roadTex2 = SDL_CreateTextureFromSurface(rend, road2);
    SDL_FreeSurface(road2);

    SDL_Texture* roadTex3;
    roadTex3 = SDL_CreateTextureFromSurface(rend, road3);
    SDL_FreeSurface(road3);

    SDL_Texture* roadTex4;
    roadTex4 = SDL_CreateTextureFromSurface(rend, road4);
    SDL_FreeSurface(road4);

    SDL_Texture* roadStart1;
    roadStart1 = SDL_CreateTextureFromSurface(rend, roadStart);
    SDL_FreeSurface(roadStart);



    SDL_Texture* roadTex1star;
    roadTex1star = SDL_CreateTextureFromSurface(rend, road1star);
    SDL_FreeSurface(road1star);

    SDL_Texture* roadTex2star;
    roadTex2star = SDL_CreateTextureFromSurface(rend, road2star);
    SDL_FreeSurface(road2star);

    SDL_Texture* roadTex3star;
    roadTex3star = SDL_CreateTextureFromSurface(rend, road3star);
    SDL_FreeSurface(road3star);

    SDL_Texture* roadTex4star;
    roadTex4star = SDL_CreateTextureFromSurface(rend, road4star);
    SDL_FreeSurface(road4star);

    SDL_Texture* roadStart1star;
    roadStart1star = SDL_CreateTextureFromSurface(rend, roadStartstar);
    SDL_FreeSurface(roadStartstar);




    SDL_Texture* tex3send;
    tex3send = SDL_CreateTextureFromSurface(rend, send);
    SDL_FreeSurface(send);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;
    SDL_Rect destStar;
    


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 500;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(starTex, NULL, NULL, &destStar.w, &destStar.h);
    //dest.w /= 3;
    //dest.h /= 3;

    destStar.w /= 4;
    destStar.h /= 4;

    SDL_QueryTexture(roadTex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1, NULL, NULL, &dest.w, &dest.h);


    SDL_QueryTexture(roadTex1star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1star, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 2;
    //dest.h /= 2;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    SDL_QueryTexture(tex3send, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    dest.w /= 2;
    dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3, degLeftRight=5, speedCutStop = 2;
    int muveIn=0, muveOut=0, bust=0, cut = 0, cutDeg=0, muveLeft=0, muveRight=0, direction=0;
    float posX1=dest4.x, posY1=dest4.y, posX2, posY2, aDes, bDes=3, cDes, tanAlfa, radAlfa, aUR, bUR, speedMath, firstStart=0;

    int rightX, leftX, tobY, bottomY, buttonR=0;
    int masPosX, masPosY;
    int top, bot, lef, rig;


    cutDeg = 90 - cut;
    radAlfa=cutDeg * M_PI/180;
    cDes = bDes/cos(radAlfa);
    aDes = sqrt((cDes * cDes) - (bDes * bDes));
    posX2 = posX1 + bDes;
    posY2 = posY1 - aDes;
    aUR = (posY2-posY1)/(posX2-posX1);
    bUR = posY1-posX1*aUR;
    speedMath=bDes/(cDes/speed);

    //printf ("aUR=%f---bUR=%f---\n", aUR, bUR);
    //printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
    //printf ("posX2=%f---posY2=%f---\n", posX2, posY2);
    //printf ("cDes=%f---aDes=%f---\n", cDes, aDes);
    //printf ("radAlfa=%f---\n\n\n", radAlfa);



    int masTex[18][32] = {  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 

                            10, 81, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 82, 10, 10, 81, 72, 72, 92, 72, 92, 72, 72, 72, 62, 72, 72, 72, 72, 72, 82, 10,

                            10, 71, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 71, 10, 81, 83, 10, 10, 71, 10, 71, 20, 20, 20, 20, 20, 20, 20, 20, 20, 61, 10,

                            10, 71, 10, 81, 72, 72, 72, 72, 72, 72, 82, 10, 84, 72, 83, 10, 10, 81, 83, 10, 71, 20, 20, 20, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 71, 20, 20, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 81, 72, 82, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10, 

                            10, 71, 10, 71, 10, 81, 72, 72, 62, 72, 94, 72, 72, 93, 10, 71, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 91, 72, 50, 72, 93, 10, 10, 10, 10, 10, 10, 10, 71, 10, 84, 62, 83, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 20, 20, 71, 10,

                            10, 71, 10, 71, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 10, 10, 10, 10, 71, 20, 30, 30, 30, 30, 30, 20, 20, 20, 71, 20,

                            10, 61, 10, 71, 10, 84, 72, 72, 72, 82, 30, 30, 10, 84, 72, 82, 10, 10, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 20, 20, 71, 20,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 71, 30, 30, 30, 10, 10, 84, 72, 82, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 30, 30, 30, 10, 71, 10, 30, 30, 30, 30, 10, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 30, 30, 10, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 81, 72, 94, 72, 92, 72, 82, 30, 30, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 20,

                            10, 84, 72, 94, 72, 82, 10, 71, 10, 10, 10, 71, 10, 71, 10, 10, 10, 71, 10, 10, 71, 20, 20, 30, 30, 20, 30, 30, 30, 20, 71, 20,

                            10, 10, 10, 10, 10, 91, 72, 93, 10, 10, 10, 91, 72, 94, 72, 82, 10, 71, 10, 10, 71, 20, 20, 20, 20, 20, 20, 20, 20, 20, 61, 10,

                            10, 30, 30, 10, 10, 84, 72, 83, 10, 10, 10, 84, 72, 62, 72, 94, 72, 94, 72, 72, 94, 72, 72, 72, 72, 72, 72, 72, 72, 72, 83, 10,

                            10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 20, 20, 10, 10, 10, 10, 10,

                            };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_R) {
                    buttonR = 1;               
                }

            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 0;               
                }

            }
        }

        if (buttonR == 1) {

            srand(time(NULL)); 
            int whileTest=1, rendStartTest=1;  
            int up = 0, rg = 0, dw = 0, lf = 0, colRect = 0;

            while (whileTest == 1) {
                if (rendStartTest == 1) {
                    up = 0; rg = 0; dw = 0; lf = 0; colRect = 0;

                    for (int i = 0; i < 18; i++) {
                        for (int j = 0; j < 32; j++){
                            masTex[i][j] = 71;
                        }
                    }

                    buttonR = 0;
                    whileTest = 0;
                    rendStartTest = 0; 
                    firstStart = 0;
                } else {

                }
            }

        }

        if (bust == 0) {
            speed = 3;
            degLeftRight = 5;
            speedCutStop = 2;
        } else {
            speed = 6;
            degLeftRight = 7;
            speedCutStop = 5;
        }

        if (muveIn==0 && muveOut==0) {
           if (muveLeft==1) {
                cut-=speedCutStop;
                if (cut<=0) {
                    cut=360;
                }
            }
            if (muveRight==1) {
                cut+=speedCutStop;
                if (cut>=360) {
                    cut=0;
                }
            } 
        }


        if (muveIn==1) {
            if (muveLeft==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
            if (muveRight==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
        }


        if (muveOut==1) {
            if (muveLeft==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
            if (muveRight==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
        }


        if (cut > 0 && cut <=89) {
            cutDeg = 90 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 90 && cut <=179) {
            cutDeg = 90 - (180 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 180 && cut <=269) {
            cutDeg = 270 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut > 270 && cut <=359) {
            cutDeg = 90 - (360 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut == 0 || cut == 360) {
            direction = 3;
            speedMath = speed;
        } else if (cut == 90) {
            direction = 4;
            speedMath = speed;
        } else if (cut == 180) {
            direction = 5;
            speedMath = speed;
        } else if (cut == 270) {
            direction = 6;
            speedMath = speed;
        }




        if (muveIn == 1) {
            if (direction == 1) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 -= speedMath;
            } else if (direction == 4) {
                posX1 += speedMath;
            } else if (direction == 5) {
                posY1 += speedMath;
            } else if (direction == 6) {
                posX1 -= speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 


        if (muveOut == 1) {
            if (direction == 1) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 += speedMath;
            } else if (direction == 4) {
                posX1 -= speedMath;
            } else if (direction == 5) {
                posY1 -= speedMath;
            } else if (direction == 6) {
                posX1 += speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 



    
        rightX=1600; 
        leftX=0;
        tobY=0; 
        bottomY=900;
        masPosX=round(posX1);
        masPosY=round(posY1);

        masPosY=(masPosY+12)/50;
        masPosX=(masPosX+12)/50;
        top = masTex[masPosY-1][masPosX];
        bot = masTex[masPosY+1][masPosX];
        rig = masTex[masPosY][masPosX+1];
        lef = masTex[masPosY][masPosX-1];
        int r1=0, r2=0, iNumRand=0, stopRand=0;

        if (firstStart==0) {
            for (int i = 0; i < 6; i++) {
                stopRand=1;
                srand(time(NULL));            

                while (stopRand==1) {
                    r1 = rand() % 17;
                    r2 = rand() % 31;

                    if (masTex[r1][r2] == 50) {
                        masTex[r1][r2] = 501;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 70) {
                        masTex[r1][r2] = 701;
                        stopRand=0;
                    } else if (masTex[r1][r2]== 71) {
                        masTex[r1][r2] = 711;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 72) {
                        masTex[r1][r2] = 721;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 60) {
                        masTex[r1][r2] = 601;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 61) {
                        masTex[r1][r2] = 611;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 62) {
                        masTex[r1][r2] = 621;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 80) {
                        masTex[r1][r2] = 801;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 81) {
                        masTex[r1][r2] = 811;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 82) {
                        masTex[r1][r2] = 821;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 83) {
                        masTex[r1][r2] = 831;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 84) {
                        masTex[r1][r2] = 841;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 90) {
                        masTex[r1][r2] = 901;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 91) {
                        masTex[r1][r2] = 911;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 92) {
                        masTex[r1][r2] = 921;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 93) {
                        masTex[r1][r2] = 931;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 94) {
                        masTex[r1][r2] = 941;
                        stopRand=0;
                    }
                }
                stopRand=1;
            }
            firstStart=1;
        }
        

        if (masTex[masPosY][masPosX] == 501 || masTex[masPosY][masPosX] == 601 || masTex[masPosY][masPosX] == 611 || masTex[masPosY][masPosX] == 621 || masTex[masPosY][masPosX] == 701 || masTex[masPosY][masPosX] == 711 || masTex[masPosY][masPosX] == 721 || masTex[masPosY][masPosX] == 801 || masTex[masPosY][masPosX] == 811 || masTex[masPosY][masPosX] == 821 || masTex[masPosY][masPosX] == 831 || masTex[masPosY][masPosX] == 841 || masTex[masPosY][masPosX] == 901 || masTex[masPosY][masPosX] == 911 || masTex[masPosY][masPosX] == 921 || masTex[masPosY][masPosX] == 931 || masTex[masPosY][masPosX] == 941) {
            if (masTex[masPosY][masPosX] == 501) {
                masTex[masPosY][masPosX] = 50;
            } else if (masTex[masPosY][masPosX] == 701) {
                masTex[masPosY][masPosX] = 70;
            } else if (masTex[masPosY][masPosX] == 711) {
                masTex[masPosY][masPosX] = 71;
            } else if (masTex[masPosY][masPosX] == 721) {
                masTex[masPosY][masPosX] = 72;
            } else if (masTex[masPosY][masPosX] == 601) {
                masTex[masPosY][masPosX] = 60;
            } else if (masTex[masPosY][masPosX] == 611) {
                masTex[masPosY][masPosX] = 61;
            } else if (masTex[masPosY][masPosX] == 621) {
                masTex[masPosY][masPosX] = 62;
            } else if (masTex[masPosY][masPosX] == 801) {
                masTex[masPosY][masPosX] = 80;
            } else if (masTex[masPosY][masPosX] == 811) {
                masTex[masPosY][masPosX] = 81;
            } else if (masTex[masPosY][masPosX] == 821) {
                masTex[masPosY][masPosX] = 82;
            } else if (masTex[masPosY][masPosX] == 831) {
                masTex[masPosY][masPosX] = 83;
            } else if (masTex[masPosY][masPosX] == 841) {
                masTex[masPosY][masPosX] = 84;
            } else if (masTex[masPosY][masPosX] == 901) {
                masTex[masPosY][masPosX] = 90;
            } else if (masTex[masPosY][masPosX] == 911) {
                masTex[masPosY][masPosX] = 91;
            } else if (masTex[masPosY][masPosX] == 921) {
                masTex[masPosY][masPosX] = 92;
            } else if (masTex[masPosY][masPosX] == 931) {
                masTex[masPosY][masPosX] = 93;
            } else if (masTex[masPosY][masPosX] == 941) {
                masTex[masPosY][masPosX] = 94;
            }

            stopRand=1;
            srand(time(NULL));            

            while (stopRand==1) {
                r1 = rand() % 17;
                r2 = rand() % 31;

                if (masTex[r1][r2] == 50) {
                    masTex[r1][r2] = 501;
                    stopRand=0;
                } else if (masTex[r1][r2] == 70) {
                    masTex[r1][r2] = 701;
                    stopRand=0;
                } else if (masTex[r1][r2]== 71) {
                    masTex[r1][r2] = 711;
                    stopRand=0;
                } else if (masTex[r1][r2] == 72) {
                    masTex[r1][r2] = 721;
                    stopRand=0;
                } else if (masTex[r1][r2] == 60) {
                    masTex[r1][r2] = 601;
                    stopRand=0;
                } else if (masTex[r1][r2] == 61) {
                    masTex[r1][r2] = 611;
                    stopRand=0;
                } else if (masTex[r1][r2] == 62) {
                    masTex[r1][r2] = 621;
                    stopRand=0;
                } else if (masTex[r1][r2] == 80) {
                    masTex[r1][r2] = 801;
                    stopRand=0;
                } else if (masTex[r1][r2] == 81) {
                    masTex[r1][r2] = 811;
                    stopRand=0;
                } else if (masTex[r1][r2] == 82) {
                    masTex[r1][r2] = 821;
                    stopRand=0;
                } else if (masTex[r1][r2] == 83) {
                    masTex[r1][r2] = 831;
                    stopRand=0;
                } else if (masTex[r1][r2] == 84) {
                    masTex[r1][r2] = 841;
                    stopRand=0;
                } else if (masTex[r1][r2] == 90) {
                    masTex[r1][r2] = 901;
                    stopRand=0;
                } else if (masTex[r1][r2] == 91) {
                    masTex[r1][r2] = 911;
                    stopRand=0;
                } else if (masTex[r1][r2] == 92) {
                    masTex[r1][r2] = 921;
                    stopRand=0;
                } else if (masTex[r1][r2] == 93) {
                    masTex[r1][r2] = 931;
                    stopRand=0;
                } else if (masTex[r1][r2] == 94) {
                    masTex[r1][r2] = 941;
                    stopRand=0;
                }
            }
        }


        if (top < 50 || top > 1000) {
            tobY=(50*masPosY)+2; 
        }

        if (bot < 50 || bot > 1000) {
            bottomY=(50*(masPosY+1))-2; 
        }

        if (rig < 50 || rig > 1000) {
            rightX=(50*(masPosX+1))-7; 
        }

        if (lef < 50 || lef > 1000) {
            leftX=(50*masPosX)+7; 
        }

        // right boundary 
        if (dest4.x + dest4.w > rightX) {
            dest4.x = rightX - dest4.w;
            posX1 = dest4.x;
        }


        // left boundary 
        if (dest4.x < leftX) {
            dest4.x = leftX;
            posX1 = dest4.x;
        }


        // bottom boundary 
        if (dest4.y + dest4.h > bottomY) {
            dest4.y = bottomY - dest4.h;
            posY1 = dest4.y;
        }
        

        // upper boundary 
        if (dest4.y < tobY){
            dest4.y = tobY;
            posY1 = dest4.y;
        }

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        

        int cutRoad = 0;
        for (int u = 0; u < 18; u++) {
            cutRoad = 0;

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 32; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 10) {
                    texBottpm = tex1;
                    cutRoad = 0;
                } else if (masTex[u][y] == 50) {
                    texBottpm = roadTex4;
                    cutRoad = 0;
                } else if (masTex[u][y] == 60 || masTex[u][y] == 61 || masTex[u][y] == 62) {
                    texBottpm = roadStart1;
                    if (masTex[u][y] == 60) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 61) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 62) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 70 || masTex[u][y] == 71 || masTex[u][y] == 72) {
                    texBottpm = roadTex1;
                    if (masTex[u][y] == 70) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 71) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 72) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 80 || masTex[u][y] == 81 || masTex[u][y] == 82 || masTex[u][y] == 83 || masTex[u][y] == 84) {
                    texBottpm = roadTex2;
                    if (masTex[u][y] == 80) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 81) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 82) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 83) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 84) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 90 || masTex[u][y] == 91 || masTex[u][y] == 92 || masTex[u][y] == 93 || masTex[u][y] == 94) {
                    texBottpm = roadTex3;
                    if (masTex[u][y] == 90) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 91) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 92) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 93) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 94) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 501) {
                    texBottpm = roadTex4star;
                    cutRoad = 0;
                } else if (masTex[u][y] == 601 || masTex[u][y] == 611 || masTex[u][y] == 621) {
                    texBottpm = roadStart1star;
                    if (masTex[u][y] == 601) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 611) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 621) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 701 || masTex[u][y] == 711 || masTex[u][y] == 721) {
                    texBottpm = roadTex1star;
                    if (masTex[u][y] == 701) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 711) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 721) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 801 || masTex[u][y] == 811 || masTex[u][y] == 821 || masTex[u][y] == 831 || masTex[u][y] == 841) {
                    texBottpm = roadTex2star;
                    if (masTex[u][y] == 801) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 811) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 821) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 831) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 841) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 901 || masTex[u][y] == 911 || masTex[u][y] == 921 || masTex[u][y] == 931 || masTex[u][y] == 941) {
                    texBottpm = roadTex3star;
                    if (masTex[u][y] == 901) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 911) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 921) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 931) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 941) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 20) {
                    texBottpm = tex3send;
                    cutRoad = 0;
                } else if (masTex[u][y] == 30) {
                    texBottpm = tex3;
                    cutRoad = 0;
                } else if (masTex[u][y] == 40) {
                    texBottpm = tex4;
                    cutRoad = 0;
                }

//roadStart1
                
                //SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                SDL_RenderCopyEx(rend, texBottpm, NULL, &dest, cutRoad, NULL, SDL_FLIP_NONE);
                
            }

        }

        //SDL_RenderCopy(rend, tex4, NULL, &dest4);
        SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
       SDL_Delay(1000 / 70);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}














































































































































//gcc main.c -o main -lmingw32 -lSDL2main -lSDL2_image -lSDL2

//printf ("aUR=---bUR=");


//#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {
    //printf ("direction=%d\n", time(NULL));
    


    srand(time(NULL)); 
    printf ("hello gamer\n");

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1600, 900, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* star;
    star = IMG_Load("img/star.bmp");



    SDL_Surface* road1;
    road1 = IMG_Load("img/road1.bmp");

    SDL_Surface* road2;
    road2 = IMG_Load("img/road2.bmp");

    SDL_Surface* road3;
    road3 = IMG_Load("img/road3.bmp");

    SDL_Surface* road4;
    road4 = IMG_Load("img/road4.bmp");

    SDL_Surface* roadStart;
    roadStart = IMG_Load("img/roadStart.bmp");

    SDL_Surface* roadStartCut;
    roadStartCut = IMG_Load("img/roadStartCut.bmp");

    SDL_Surface* roadStartCutStar;
    roadStartCutStar = IMG_Load("img/roadStartCutStar.bmp");



    SDL_Surface* road1star;
    road1star = IMG_Load("img/road1star.bmp");

    SDL_Surface* road2star;
    road2star = IMG_Load("img/road2star.bmp");

    SDL_Surface* road3star;
    road3star = IMG_Load("img/road3star.bmp");

    SDL_Surface* road4star;
    road4star = IMG_Load("img/road4star.bmp");

    SDL_Surface* roadStartstar;
    roadStartstar = IMG_Load("img/roadStartstar.bmp");



    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* send;
    send = IMG_Load("img/send.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/car2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* starTex;
    starTex = SDL_CreateTextureFromSurface(rend, star);
    SDL_FreeSurface(star);



    SDL_Texture* roadTex1;
    roadTex1 = SDL_CreateTextureFromSurface(rend, road1);
    SDL_FreeSurface(road1);

    SDL_Texture* roadTex2;
    roadTex2 = SDL_CreateTextureFromSurface(rend, road2);
    SDL_FreeSurface(road2);

    SDL_Texture* roadTex3;
    roadTex3 = SDL_CreateTextureFromSurface(rend, road3);
    SDL_FreeSurface(road3);

    SDL_Texture* roadTex4;
    roadTex4 = SDL_CreateTextureFromSurface(rend, road4);
    SDL_FreeSurface(road4);

    SDL_Texture* roadStart1;
    roadStart1 = SDL_CreateTextureFromSurface(rend, roadStart);
    SDL_FreeSurface(roadStart);

    SDL_Texture* roadStartCut1;
    roadStartCut1 = SDL_CreateTextureFromSurface(rend, roadStartCut);
    SDL_FreeSurface(roadStartCut);

    SDL_Texture* roadStartCutStar1;
    roadStartCutStar1 = SDL_CreateTextureFromSurface(rend, roadStartCutStar);
    SDL_FreeSurface(roadStartCutStar);



    SDL_Texture* roadTex1star;
    roadTex1star = SDL_CreateTextureFromSurface(rend, road1star);
    SDL_FreeSurface(road1star);

    SDL_Texture* roadTex2star;
    roadTex2star = SDL_CreateTextureFromSurface(rend, road2star);
    SDL_FreeSurface(road2star);

    SDL_Texture* roadTex3star;
    roadTex3star = SDL_CreateTextureFromSurface(rend, road3star);
    SDL_FreeSurface(road3star);

    SDL_Texture* roadTex4star;
    roadTex4star = SDL_CreateTextureFromSurface(rend, road4star);
    SDL_FreeSurface(road4star);

    SDL_Texture* roadStart1star;
    roadStart1star = SDL_CreateTextureFromSurface(rend, roadStartstar);
    SDL_FreeSurface(roadStartstar);




    SDL_Texture* tex3send;
    tex3send = SDL_CreateTextureFromSurface(rend, send);
    SDL_FreeSurface(send);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;
    SDL_Rect destStar;
    


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 500;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(starTex, NULL, NULL, &destStar.w, &destStar.h);
    //dest.w /= 3;
    //dest.h /= 3;

    destStar.w /= 4;
    destStar.h /= 4;

    SDL_QueryTexture(roadTex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStartCut1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStartCutStar1, NULL, NULL, &dest.w, &dest.h);


    SDL_QueryTexture(roadTex1star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1star, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 2;
    //dest.h /= 2;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    SDL_QueryTexture(tex3send, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    dest.w /= 2;
    dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3, degLeftRight=5, speedCutStop = 2;
    int muveIn=0, muveOut=0, bust=0, cut = 0, cutDeg=0, muveLeft=0, muveRight=0, direction=0;
    float posX1=dest4.x, posY1=dest4.y, posX2, posY2, aDes, bDes=3, cDes, tanAlfa, radAlfa, aUR, bUR, speedMath, firstStart=0;

    int rightX, leftX, tobY, bottomY, buttonR=0, buttonT=0;
    int masPosX, masPosY;
    int top, bot, lef, rig;
    int startX=0, startY=0, rendMass=0;
    int rendCar=0;
    


    cutDeg = 90 - cut;
    radAlfa=cutDeg * M_PI/180;
    cDes = bDes/cos(radAlfa);
    aDes = sqrt((cDes * cDes) - (bDes * bDes));
    posX2 = posX1 + bDes;
    posY2 = posY1 - aDes;
    aUR = (posY2-posY1)/(posX2-posX1);
    bUR = posY1-posX1*aUR;
    speedMath=bDes/(cDes/speed);

    //printf ("aUR=%f---bUR=%f---\n", aUR, bUR);
    //printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
    //printf ("posX2=%f---posY2=%f---\n", posX2, posY2);
    //printf ("cDes=%f---aDes=%f---\n", cDes, aDes);
    //printf ("radAlfa=%f---\n\n\n", radAlfa);
    int masSnow[3][1000];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1000; j++){
            masSnow[i][j] = 0;
        }
    }

    int masTex2[18][32];
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 32; j++){
            masTex2[i][j] = 10;
        }
    }
    int masTex[18][32] = {  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 

                            10, 62, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 63, 10, 10, 81, 72, 72, 92, 72, 92, 72, 72, 72, 61, 72, 72, 72, 72, 72, 82, 10,

                            10, 71, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 71, 10, 81, 83, 10, 10, 71, 10, 71, 20, 20, 20, 20, 20, 20, 20, 20, 20, 60, 10,

                            10, 71, 10, 81, 72, 72, 72, 72, 72, 72, 82, 10, 84, 72, 83, 10, 10, 81, 83, 10, 71, 20, 20, 20, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 71, 20, 20, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 81, 72, 82, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10, 

                            10, 71, 10, 71, 10, 81, 72, 72, 61, 72, 94, 72, 72, 93, 10, 71, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 91, 72, 50, 72, 93, 10, 10, 10, 10, 10, 10, 10, 71, 10, 84, 61, 83, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 20, 20, 71, 10,

                            10, 71, 10, 71, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 10, 10, 10, 10, 71, 20, 30, 30, 30, 30, 30, 20, 20, 20, 71, 20,

                            10, 60, 10, 71, 10, 84, 72, 72, 72, 82, 30, 30, 10, 84, 72, 82, 10, 10, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 20, 20, 71, 20,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 71, 30, 30, 30, 10, 10, 84, 72, 82, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 30, 30, 30, 10, 71, 10, 30, 30, 30, 30, 10, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 30, 30, 10, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 81, 72, 94, 72, 92, 72, 82, 30, 30, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 20,

                            10, 84, 72, 94, 72, 82, 10, 71, 10, 10, 10, 71, 10, 71, 10, 10, 10, 71, 10, 10, 71, 20, 20, 30, 30, 20, 30, 30, 30, 20, 71, 20,

                            10, 10, 10, 10, 10, 91, 72, 93, 10, 10, 10, 91, 72, 94, 72, 82, 10, 71, 10, 10, 71, 20, 20, 20, 20, 20, 20, 20, 20, 20, 60, 10,

                            10, 30, 30, 10, 10, 84, 72, 83, 10, 10, 10, 84, 72, 61, 72, 94, 72, 94, 72, 72, 94, 72, 72, 72, 72, 72, 72, 72, 72, 72, 83, 10,

                            10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 20, 20, 10, 10, 10, 10, 10,

                            };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_R) {
                    buttonR = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_T) {
                    buttonT = 1;               
                }

            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 0;               
                }

            }
        }

        if (buttonR == 1) {
            srand(time(NULL)); 
            int whileTest=1, rendStartTest=1;  
            int up = 0, rg = 0, dw = 0, lf = 0;
            int massX=32, massY=18, exitRand=0;
            int nowX=0, nowY=0, direction=0, res=0, fin=0; 
            int goX=0, goY=0;
            int colRect=0, maxBlock=130, max=0, min=0;
            int searchColAll=0, searchColNew=0;
            
            min=maxBlock-5;
            max=maxBlock+5;
            while (whileTest == 1) {
                
                searchColAll++;
                if (rendStartTest == 1) {
                    searchColNew++;
                    up = 0; rg = 0; dw = 0; lf = 0; colRect = 0;

                    for (int i = 0; i < massY; i++) {
                        for (int j = 0; j < massX; j++){
                            masTex2[i][j] = 10;
                        }
                    }

                    nowX = startX = round(rand() % ((massX-2) - 1 + 1) + 1);
                    nowY = startY = round(rand() % ((massY-2) - 1 + 1) + 1);
                    //printf ("startX=%d---startY=%d---\n", nowX, nowY);

                    masTex2[startY][startX] = 61;
                    posX1 = (50*(startX)+1)+25;
                    posY1 = (50*(startY)+1)+25;
                    
                    buttonR = 0;
                    rendStartTest = 0;
                    whileTest = 1;
                } else {
                    res = 0;
                    fin = 0;
                    direction = round(rand() % (4 - 1 + 1) + 1);
                    //printf ("direction=%d\n", direction);

                    //клетка трассы которую будем проверять
                    if (direction == 1) {
                        goX = nowX;
                        goY = nowY-1;
                        up=1;
                    } else if (direction == 2) {
                        goX = nowX+1;
                        goY = nowY;
                        rg=1;
                    } else if (direction == 3) {
                        goX = nowX;
                        goY = nowY+1;
                        dw=1;
                    } else if (direction == 4) {
                        goX = nowX-1;
                        goY = nowY;
                        lf=1;
                    }

                    //первое условие
                    if (goX < 1 || goX > massX-2) {
                        res=1;
                    } else if (goY < 1 || goY > massY-2) {
                        res=1;
                    }

                    //второе условие
                    if (res==0) {
                        if (masTex2[goY][goX] == 71) {
                            res=1;
                        }
                    }


                    //третье условие
                    if (res==0) {
                        if (masTex2[goY-1][goX] == 71 && (direction == 1 || direction == 2 || direction == 4)) {
                            res=1;
                        } else if (masTex2[goY][goX+1] == 71 && (direction == 1 || direction == 2 || direction == 3)) {
                            res=1;
                        } else if (masTex2[goY+1][goX] == 71 && (direction == 2 || direction == 3 || direction == 4)) {
                            res=1;
                        } else if (masTex2[goY][goX-1] == 71 && (direction == 1 || direction == 3 || direction == 4)) {
                            res=1;
                        }
                    }


                    //четвертое условие
                    if (res==0) {
                        if (masTex2[goY-1][goX] == 61 && (direction == 1 || direction == 2 || direction == 4)) {
                            fin=1;
                            res=1;
                        } else if (masTex2[goY][goX+1] == 61 && (direction == 1 || direction == 2 || direction == 3)) {
                            fin=1;
                            res=1;
                        } else if (masTex2[goY+1][goX] == 61 && (direction == 2 || direction == 3 || direction == 4)) {
                            fin=1;
                            res=1;
                        } else if (masTex2[goY][goX-1] == 61 && (direction == 1 || direction == 3 || direction == 4)) {
                            fin=1;
                            res=1;
                        }
                    }


                    //пятое условие
                    if (colRect < min || colRect > max) {
                        fin = 0;
                    }


                    //Проверка на законченость трассы. или генерация зашла в тупик
                    if (colRect < (max + 15) && res == 0 && fin == 0) {
                        up = 0; rg = 0; dw = 0; lf = 0;
                        colRect++;
                        nowX = goX;
                        nowY = goY;
                        masTex2[goY][goX] = 71;
                        whileTest=1;
                    } else if (up == 1 && rg == 1 && dw == 1 && lf == 1) {
                        rendStartTest = 1;
                        whileTest=1;
                    } else if (res == 1 && fin == 0) {
                        whileTest=1;
                    } else if (fin == 1) {
                        masTex2[goY][goX] = 71;
                        masTex2[startY][startX] = 71;
                        whileTest=0;                    
                        printf ("block - %d || search - %d || while - %d \n", colRect, searchColNew, searchColAll);
                        searchColNew=0;
                        searchColAll=0;
                        firstStart=0;
                        rendMass=1;
                    } else {
                        rendStartTest = 1;
                        whileTest=1;
                    }

                }

            }

        }

        if (buttonT == 1) {
            srand(time(NULL));
            int whileTest=1, rendStartTest=1, nextStep=0, snowflake=0; 
            int up = 0, rg = 0, dw = 0, lf = 0;
            int massX=32, massY=18, exitRand=0;
            int nowX=0, nowY=0, direction=0, res=0, fin=0; 
            int goX=0, goY=0, whileINtest=1;
            int colRect=0, maxBlock=130;
            
            while (whileTest == 1) {
            
                if (rendStartTest == 1) {
                    up = 0; rg = 0; dw = 0; lf = 0;

                    for (int i = 0; i < massY; i++) {
                        for (int j = 0; j < massX; j++){
                            masTex2[i][j] = 10;
                        }
                    }

                    nowX = startX = round(rand() % ((massX-2) - 1 + 1) + 1);
                    nowY = startY = round(rand() % ((massY-2) - 1 + 1) + 1);
                    //printf ("startX=%d---startY=%d---\n", nowX, nowY);

                    masTex2[startY][startX] = 71;
                    posX1 = (50*(startX)+1)+25;
                    posY1 = (50*(startY)+1)+25;
                    
                    rendStartTest = 0;
                    nextStep = 1;
                } else if (nextStep == 1) {

                    while (whileINtest == 1) {
                        res = 0;
                        fin = 0;
                        direction = round(rand() % (4 - 1 + 1) + 1);
                        //printf ("direction=%d\n", direction);

                        //клетка трассы которую будем проверять
                        if (direction == 1) {
                            goX = nowX;
                            goY = nowY-1;
                            up=1;
                        } else if (direction == 2) {
                            goX = nowX+1;
                            goY = nowY;
                            rg=1;
                        } else if (direction == 3) {
                            goX = nowX;
                            goY = nowY+1;
                            dw=1;
                        } else if (direction == 4) {
                            goX = nowX-1;
                            goY = nowY;
                            lf=1;
                        }

                        //первое условие
                        if (goX < 1 || goX > massX-2) {
                            res=1;
                        } else if (goY < 1 || goY > massY-2) {
                            res=1;
                        }

                        //второе условие
                        if (res==0) {
                            if (masTex2[goY][goX] == 71) {
                                res=1;
                            }
                        }

                        //третье условие
                        if (res==0) {
                            if (masTex2[goY-1][goX] == 71 && (direction == 1 || direction == 2 || direction == 4)) {
                                res=1;
                            } else if (masTex2[goY][goX+1] == 71 && (direction == 1 || direction == 2 || direction == 3)) {
                                res=1;
                            } else if (masTex2[goY+1][goX] == 71 && (direction == 2 || direction == 3 || direction == 4)) {
                                res=1;
                            } else if (masTex2[goY][goX-1] == 71 && (direction == 1 || direction == 3 || direction == 4)) {
                                res=1;
                            }
                        }

                        //четвертое условие
                        if (res==0) {
                            if ((goY-1)==startY && goX==startX && (direction == 1 || direction == 2 || direction == 4)) {
                                fin=1;
                                res=1;
                            } else if (goY==startY && (goX+1)==startX && (direction == 1 || direction == 2 || direction == 3)) {
                                fin=1;
                                res=1;
                            } else if ((goY+1)==startY && goX==startX && (direction == 2 || direction == 3 || direction == 4)) {
                                fin=1;
                                res=1;
                            } else if (goY==startY && (goX-1)==startX && (direction == 1 || direction == 3 || direction == 4)) {
                                fin=1;
                                res=1;
                            }
                        }

                        //пятое условие
                        if (colRect < 6) {
                            fin = 0;
                        }

                        //Проверка на законченость трассы. или генерация зашла в тупик
                        if (res == 0 && fin == 0) {
                            nextStep = 0;
                            snowflake = 1;
                            whileINtest = 0;
                        } else if (res == 1 && fin == 0) {
                            whileINtest = 1;
                        } else if (fin == 1) {
                            masTex2[goY][goX] = 71;
                            whileINtest = 0;   
                            whileTest = 0;  
                            buttonT = 0; 

                            printf ("block - %d ||\n", colRect);
                            firstStart = 0;
                            rendMass = 1;
                        } else {
                            nextStep = 0;
                            whileINtest = 1;
                        }


                    }
                    
                } else if (snowflake == 1) {
                    int stopWhile=0, colWhile=0, colForInWhile=0;
                    int testX, testY, testGoX, testGoY;

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 1000; j++){
                            masSnow[i][j] = 0;
                        }
                    }

                    masSnow[0][0] = 1;
                    masSnow[1][0] = goX;
                    masSnow[2][0] = goY;

                    while (stopWhile==1) {
                        colWhile++;

                        for (colForInWhile=0; colForInWhile<1000; colForInWhile++) {

                            if (masSnow[0][colForInWhile] == 0) {
                                colForInWhile=1001;
                            } else if (masSnow[0][colForInWhile] == colWhile) {
                                testX=masSnow[1][colForInWhile];
                                testY=masSnow[2][colForInWhile];

                                for (int i=1; i<=4; i++) {
                                    res = 0;
                                    fin = 0;
                                    direction = i;

                                    //клетка трассы которую будем проверять
                                    if (direction == 1) {
                                        testGoX = testX;
                                        testGoY = testY-1;
                                    } else if (direction == 2) {
                                        testGoX = nowX+1;
                                        testGoY = nowY;
                                    } else if (direction == 3) {
                                        testGoX = nowX;
                                        testGoY = nowY+1;
                                    } else if (direction == 4) {
                                        testGoX = nowX-1;
                                        testGoY = nowY;
                                    }

                                    //первое условие
                                    if (testGoX < 1 || testGoX > massX-2) {
                                        res=1;
                                    } else if (testGoY < 1 || testGoY > massY-2) {
                                        res=1;
                                    }

                                    //первое с половиной условие
                                    if (res==0) {
                                        for (int i=0; i<1000; i++) {
                                            if (testGoY == masTex2[2][i] && testGoX == masTex2[1][i]) {
                                                res=1;
                                            }
                                        }
                                    }
                                    

                                    //второе условие
                                    if (res==0) {
                                        if (masTex2[testGoY][testGoX] == 71) {
                                            res=1;
                                        }
                                    }


                                    //третье условие
                                    if (res==0) {
                                        if (masTex2[testGoY-1][testGoX] == 71 && (direction == 1 || direction == 2 || direction == 4)) {
                                            res=1;
                                        } else if (masTex2[testGoY][testGoX+1] == 71 && (direction == 1 || direction == 2 || direction == 3)) {
                                            res=1;
                                        } else if (masTex2[testGoY+1][testGoX] == 71 && (direction == 2 || direction == 3 || direction == 4)) {
                                            res=1;
                                        } else if (masTex2[testGoY][testGoX-1] == 71 && (direction == 1 || direction == 3 || direction == 4)) {
                                            res=1;
                                        }
                                    }


                                    //четвертое условие
                                    if (res==0) {
                                        if ((testGoY-1)==startY && testGoX==startX && (direction == 1 || direction == 2 || direction == 4)) {
                                            fin=1;
                                            res=1;
                                        } else if (testGoY==startY && (testGoX+1)==startX && (direction == 1 || direction == 2 || direction == 3)) {
                                            fin=1;
                                            res=1;
                                        } else if ((testGoY+1)==startY && testGoX==startX && (direction == 2 || direction == 3 || direction == 4)) {
                                            fin=1;
                                            res=1;
                                        } else if (testGoY == startY && (testGoX-1)==startX && (direction == 1 || direction == 3 || direction == 4)) {
                                            fin=1;
                                            res=1;
                                        }
                                    }


                                    //пятое условие
                                    if (colWhile < 6) {
                                        fin = 0;
                                    }


                                    //Проверка на законченость трассы. или генерация зашла в тупик
                                    if (res == 0 && fin == 0) {
                                        for (int i=0; i<1000; i++) {
                                            if (masTex2[0][i] == 0) {
                                                masTex2[0][i] = colWhile+1;
                                                masTex2[1][i] = testGoX;
                                                masTex2[2][i] = testGoY;
                                                i=1001;
                                            }
                                        }

                                    } else if (fin == 1) {
                                        buttonT = 0;
                                        nextStep = 0;
                                        snowflake = 0;
                                        whileTest = 0;
                                        rendMass = 1;
                                        printf ("test T --------\n");

                                    }

                                }

                            }

                        }

                    }










                    
                }

            }

        }

        if (rendMass==1) {

            for (int i = 0; i < 18; i++) {
                for (int j = 0; j < 32; j++){
                    masTex[i][j] = 10;
                }
            }

            for (int i = 0; i < 18; i++) {
                for (int j = 0; j < 32; j++){
                    if (masTex2[i][j] == 71) {
                        if (masTex2[i-1][j] == 71 && masTex2[i+1][j] == 71) {
                            masTex[i][j] = 71;
                        } else if (masTex2[i][j-1] == 71 && masTex2[i][j+1] == 71){
                            masTex[i][j] = 72;
                        } else if (masTex2[i-1][j] == 71 && masTex2[i][j+1] == 71){
                            masTex[i][j] = 84;
                        } else if (masTex2[i+1][j] == 71 && masTex2[i][j+1] == 71){
                            masTex[i][j] = 81;
                        } else if (masTex2[i+1][j] == 71 && masTex2[i][j-1] == 71){
                            masTex[i][j] = 82;
                        } else if (masTex2[i-1][j] == 71 && masTex2[i][j-1] == 71){
                            masTex[i][j] = 83;
                        }
                    }
                }
            }

            if (masTex2[startY-1][startX] == 71 && masTex2[startY+1][startX] == 71) {
                masTex[startY][startX] = 60;
                cut=0;
            } else if (masTex2[startY][startX-1] == 71 && masTex2[startY][startX+1] == 71) {
                masTex[startY][startX] = 61;
                cut=270;
            } else if (masTex2[startY-1][startX] == 71 && masTex2[startY][startX+1] == 71) {
                masTex[startY][startX] = 65;
                cut=315;
            } else if (masTex2[startY+1][startX] == 71 && masTex2[startY][startX+1] == 71) {
                masTex[startY][startX] = 62;
                cut=45;
            } else if (masTex2[startY+1][startX] == 71 && masTex2[startY][startX-1] == 71) {
                masTex[startY][startX] = 63;
                cut=315;
            } else if (masTex2[startY-1][startX] == 71 && masTex2[startY][startX-1] == 71) {
                masTex[startY][startX] = 64;
                cut=45;
            }
            rendCar=1;
            rendMass=0;
        }

        if (bust == 0) {
            speed = 3;
            degLeftRight = 5;
            speedCutStop = 2;
        } else {
            speed = 6;
            degLeftRight = 7;
            speedCutStop = 5;
        }

        if (muveIn==0 && muveOut==0) {
           if (muveLeft==1) {
                cut-=speedCutStop;
                if (cut<=0) {
                    cut=360;
                }
            }
            if (muveRight==1) {
                cut+=speedCutStop;
                if (cut>=360) {
                    cut=0;
                }
            } 
        }


        if (muveIn==1) {
            if (muveLeft==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
            if (muveRight==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
        }


        if (muveOut==1) {
            if (muveLeft==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
            if (muveRight==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
        }


        if (cut > 0 && cut <=89) {
            cutDeg = 90 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 90 && cut <=179) {
            cutDeg = 90 - (180 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 180 && cut <=269) {
            cutDeg = 270 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut > 270 && cut <=359) {
            cutDeg = 90 - (360 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut == 0 || cut == 360) {
            direction = 3;
            speedMath = speed;
        } else if (cut == 90) {
            direction = 4;
            speedMath = speed;
        } else if (cut == 180) {
            direction = 5;
            speedMath = speed;
        } else if (cut == 270) {
            direction = 6;
            speedMath = speed;
        }




        if (muveIn == 1) {
            if (direction == 1) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 -= speedMath;
            } else if (direction == 4) {
                posX1 += speedMath;
            } else if (direction == 5) {
                posY1 += speedMath;
            } else if (direction == 6) {
                posX1 -= speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 


        if (muveOut == 1) {
            if (direction == 1) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 += speedMath;
            } else if (direction == 4) {
                posX1 -= speedMath;
            } else if (direction == 5) {
                posY1 -= speedMath;
            } else if (direction == 6) {
                posX1 += speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 



    
        rightX=1600; 
        leftX=0;
        tobY=0; 
        bottomY=900;
        masPosX=round(posX1);
        masPosY=round(posY1);

        masPosY=(masPosY+12)/50;
        masPosX=(masPosX+12)/50;
        top = masTex[masPosY-1][masPosX];
        bot = masTex[masPosY+1][masPosX];
        rig = masTex[masPosY][masPosX+1];
        lef = masTex[masPosY][masPosX-1];
        int r1=0, r2=0, iNumRand=0, stopRand=0;

        
        firstStart=1;
        if (firstStart==0) {
            for (int i = 0; i < 6; i++) {
                stopRand=1;
                srand(time(NULL));            

                while (stopRand==1) {
                    r1 = rand() % 17;
                    r2 = rand() % 31;

                    if (masTex[r1][r2] == 50) {
                        masTex[r1][r2] = 501;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 70) {
                        masTex[r1][r2] = 701;
                        stopRand=0;
                    } else if (masTex[r1][r2]== 71) {
                        masTex[r1][r2] = 711;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 72) {
                        masTex[r1][r2] = 721;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 60) {
                        masTex[r1][r2] = 601;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 61) {
                        masTex[r1][r2] = 611;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 62) {
                        masTex[r1][r2] = 621;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 63) {
                        masTex[r1][r2] = 631;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 64) {
                        masTex[r1][r2] = 641;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 65) {
                        masTex[r1][r2] = 651;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 80) {
                        masTex[r1][r2] = 801;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 81) {
                        masTex[r1][r2] = 811;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 82) {
                        masTex[r1][r2] = 821;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 83) {
                        masTex[r1][r2] = 831;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 84) {
                        masTex[r1][r2] = 841;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 90) {
                        masTex[r1][r2] = 901;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 91) {
                        masTex[r1][r2] = 911;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 92) {
                        masTex[r1][r2] = 921;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 93) {
                        masTex[r1][r2] = 931;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 94) {
                        masTex[r1][r2] = 941;
                        stopRand=0;
                    }
                }
                stopRand=1;
            }
            firstStart=1;
        }
        

        if (masTex[masPosY][masPosX] >= 500) {
            if (masTex[masPosY][masPosX] == 501) {
                masTex[masPosY][masPosX] = 50;
            } else if (masTex[masPosY][masPosX] == 701) {
                masTex[masPosY][masPosX] = 70;
            } else if (masTex[masPosY][masPosX] == 711) {
                masTex[masPosY][masPosX] = 71;
            } else if (masTex[masPosY][masPosX] == 721) {
                masTex[masPosY][masPosX] = 72;
            } else if (masTex[masPosY][masPosX] == 601) {
                masTex[masPosY][masPosX] = 60;
            } else if (masTex[masPosY][masPosX] == 611) {
                masTex[masPosY][masPosX] = 61;
            } else if (masTex[masPosY][masPosX] == 621) {
                masTex[masPosY][masPosX] = 62;
            } else if (masTex[masPosY][masPosX] == 631) {
                masTex[masPosY][masPosX] = 63;
            } else if (masTex[masPosY][masPosX] == 641) {
                masTex[masPosY][masPosX] = 64;
            } else if (masTex[masPosY][masPosX] == 651) {
                masTex[masPosY][masPosX] = 65;
            } else if (masTex[masPosY][masPosX] == 801) {
                masTex[masPosY][masPosX] = 80;
            } else if (masTex[masPosY][masPosX] == 811) {
                masTex[masPosY][masPosX] = 81;
            } else if (masTex[masPosY][masPosX] == 821) {
                masTex[masPosY][masPosX] = 82;
            } else if (masTex[masPosY][masPosX] == 831) {
                masTex[masPosY][masPosX] = 83;
            } else if (masTex[masPosY][masPosX] == 841) {
                masTex[masPosY][masPosX] = 84;
            } else if (masTex[masPosY][masPosX] == 901) {
                masTex[masPosY][masPosX] = 90;
            } else if (masTex[masPosY][masPosX] == 911) {
                masTex[masPosY][masPosX] = 91;
            } else if (masTex[masPosY][masPosX] == 921) {
                masTex[masPosY][masPosX] = 92;
            } else if (masTex[masPosY][masPosX] == 931) {
                masTex[masPosY][masPosX] = 93;
            } else if (masTex[masPosY][masPosX] == 941) {
                masTex[masPosY][masPosX] = 94;
            }

            stopRand=1;
            srand(time(NULL));            

            while (stopRand==1) {
                r1 = rand() % 17;
                r2 = rand() % 31;

                if (masTex[r1][r2] == 50) {
                    masTex[r1][r2] = 501;
                    stopRand=0;
                } else if (masTex[r1][r2] == 70) {
                    masTex[r1][r2] = 701;
                    stopRand=0;
                } else if (masTex[r1][r2]== 71) {
                    masTex[r1][r2] = 711;
                    stopRand=0;
                } else if (masTex[r1][r2] == 72) {
                    masTex[r1][r2] = 721;
                    stopRand=0;
                } else if (masTex[r1][r2] == 60) {
                    masTex[r1][r2] = 601;
                    stopRand=0;
                } else if (masTex[r1][r2] == 61) {
                    masTex[r1][r2] = 611;
                    stopRand=0;
                } else if (masTex[r1][r2] == 62) {
                    masTex[r1][r2] = 621;
                    stopRand=0;
                } else if (masTex[r1][r2] == 63) {
                    masTex[r1][r2] = 631;
                    stopRand=0;
                } else if (masTex[r1][r2] == 64) {
                    masTex[r1][r2] = 641;
                    stopRand=0;
                } else if (masTex[r1][r2] == 65) {
                    masTex[r1][r2] = 651;
                    stopRand=0;
                } else if (masTex[r1][r2] == 80) {
                    masTex[r1][r2] = 801;
                    stopRand=0;
                } else if (masTex[r1][r2] == 81) {
                    masTex[r1][r2] = 811;
                    stopRand=0;
                } else if (masTex[r1][r2] == 82) {
                    masTex[r1][r2] = 821;
                    stopRand=0;
                } else if (masTex[r1][r2] == 83) {
                    masTex[r1][r2] = 831;
                    stopRand=0;
                } else if (masTex[r1][r2] == 84) {
                    masTex[r1][r2] = 841;
                    stopRand=0;
                } else if (masTex[r1][r2] == 90) {
                    masTex[r1][r2] = 901;
                    stopRand=0;
                } else if (masTex[r1][r2] == 91) {
                    masTex[r1][r2] = 911;
                    stopRand=0;
                } else if (masTex[r1][r2] == 92) {
                    masTex[r1][r2] = 921;
                    stopRand=0;
                } else if (masTex[r1][r2] == 93) {
                    masTex[r1][r2] = 931;
                    stopRand=0;
                } else if (masTex[r1][r2] == 94) {
                    masTex[r1][r2] = 941;
                    stopRand=0;
                }
            }
        }
        


        if (top < 50 || top > 1000) {
            tobY=(50*masPosY)+2; 
        }

        if (bot < 50 || bot > 1000) {
            bottomY=(50*(masPosY+1))-2; 
        }

        if (rig < 50 || rig > 1000) {
            rightX=(50*(masPosX+1))-7; 
        }

        if (lef < 50 || lef > 1000) {
            leftX=(50*masPosX)+7; 
        }

        // right boundary 
        if (dest4.x + dest4.w > rightX) {
            dest4.x = rightX - dest4.w;
            posX1 = dest4.x;
        }


        // left boundary 
        if (dest4.x < leftX) {
            dest4.x = leftX;
            posX1 = dest4.x;
        }


        // bottom boundary 
        if (dest4.y + dest4.h > bottomY) {
            dest4.y = bottomY - dest4.h;
            posY1 = dest4.y;
        }
        

        // upper boundary 
        if (dest4.y < tobY){
            dest4.y = tobY;
            posY1 = dest4.y;
        }

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        

        int cutRoad = 0;
        for (int u = 0; u < 18; u++) {
            cutRoad = 0;

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 32; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 10) {
                    texBottpm = tex1;
                    cutRoad = 0;
                } else if (masTex[u][y] == 50) {
                    texBottpm = roadTex4;
                    cutRoad = 0;
                } else if (masTex[u][y] == 60 || masTex[u][y] == 61) {
                    texBottpm = roadStart1;
                    if (masTex[u][y] == 60) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 61) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 62 || masTex[u][y] == 63 || masTex[u][y] == 64 || masTex[u][y] == 65) {
                    texBottpm = roadStartCut1;
                    if (masTex[u][y] == 62) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 63) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 64) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 65) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 70 || masTex[u][y] == 71 || masTex[u][y] == 72) {
                    texBottpm = roadTex1;
                    if (masTex[u][y] == 70) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 71) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 72) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 80 || masTex[u][y] == 81 || masTex[u][y] == 82 || masTex[u][y] == 83 || masTex[u][y] == 84) {
                    texBottpm = roadTex2;
                    if (masTex[u][y] == 80) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 81) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 82) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 83) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 84) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 90 || masTex[u][y] == 91 || masTex[u][y] == 92 || masTex[u][y] == 93 || masTex[u][y] == 94) {
                    texBottpm = roadTex3;
                    if (masTex[u][y] == 90) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 91) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 92) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 93) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 94) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 501) {
                    texBottpm = roadTex4star;
                    cutRoad = 0;
                } else if (masTex[u][y] == 601 || masTex[u][y] == 611) {
                    texBottpm = roadStart1star;
                    if (masTex[u][y] == 601) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 611) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 621 || masTex[u][y] == 631 || masTex[u][y] == 641 || masTex[u][y] == 651) {
                    texBottpm = roadStartCutStar1;
                    if (masTex[u][y] == 621) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 631) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 641) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 651) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 701 || masTex[u][y] == 711 || masTex[u][y] == 721) {
                    texBottpm = roadTex1star;
                    if (masTex[u][y] == 701) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 711) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 721) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 801 || masTex[u][y] == 811 || masTex[u][y] == 821 || masTex[u][y] == 831 || masTex[u][y] == 841) {
                    texBottpm = roadTex2star;
                    if (masTex[u][y] == 801) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 811) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 821) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 831) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 841) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 901 || masTex[u][y] == 911 || masTex[u][y] == 921 || masTex[u][y] == 931 || masTex[u][y] == 941) {
                    texBottpm = roadTex3star;
                    if (masTex[u][y] == 901) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 911) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 921) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 931) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 941) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 20) {
                    texBottpm = tex3send;
                    cutRoad = 0;
                } else if (masTex[u][y] == 30) {
                    texBottpm = tex3;
                    cutRoad = 0;
                } else if (masTex[u][y] == 40) {
                    texBottpm = tex4;
                    cutRoad = 0;
                }

//roadStart1
                
                //SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                SDL_RenderCopyEx(rend, texBottpm, NULL, &dest, cutRoad, NULL, SDL_FLIP_NONE);
                
            }

        }
        if (rendCar==1) {
            rendCar=0;
            dest4.x = (50*(startX)+1)+25;
            dest4.y = (50*(startY)+1)+25;
            SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);
        } else {
            SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);
        }

        //SDL_RenderCopy(rend, tex4, NULL, &dest4);
        //SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
       SDL_Delay(1000 / 70);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}




























































30-05-2020


//gcc main.c -o main -lmingw32 -lSDL2main -lSDL2_image -lSDL2

//printf ("aUR=---bUR=");


//#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char* args[]) {
    //printf ("direction=%d\n", time(NULL));
    


    srand(time(NULL)); 
    printf ("hello gamer\n");

    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1600, 900, 0);

    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
    SDL_SetRenderDrawColor(rend, 0, 0, 255, 255);
    SDL_RenderClear(rend);



    // creates a surface to load an image into the main memory 
    SDL_Surface* surface1;
    surface1 = IMG_Load("img/grass.bmp");

    SDL_Surface* star;
    star = IMG_Load("img/star.bmp");



    SDL_Surface* road1;
    road1 = IMG_Load("img/road1.bmp");

    SDL_Surface* road2;
    road2 = IMG_Load("img/road2.bmp");

    SDL_Surface* road3;
    road3 = IMG_Load("img/road3.bmp");

    SDL_Surface* road4;
    road4 = IMG_Load("img/road4.bmp");

    SDL_Surface* roadStart;
    roadStart = IMG_Load("img/roadStart.bmp");

    SDL_Surface* roadStartCut;
    roadStartCut = IMG_Load("img/roadStartCut.bmp");

    SDL_Surface* roadStartCutStar;
    roadStartCutStar = IMG_Load("img/roadStartCutStar.bmp");



    SDL_Surface* road1star;
    road1star = IMG_Load("img/road1star.bmp");

    SDL_Surface* road2star;
    road2star = IMG_Load("img/road2star.bmp");

    SDL_Surface* road3star;
    road3star = IMG_Load("img/road3star.bmp");

    SDL_Surface* road4star;
    road4star = IMG_Load("img/road4star.bmp");

    SDL_Surface* roadStartstar;
    roadStartstar = IMG_Load("img/roadStartstar.bmp");



    SDL_Surface* surface3;
    surface3 = IMG_Load("img/sea.bmp");

    SDL_Surface* send;
    send = IMG_Load("img/send.bmp");

    SDL_Surface* blok;
    blok = IMG_Load("img/car2.bmp");

    Uint32 rmask = 0xff000000;
    Uint32 gmask = 0x00ff0000;
    Uint32 bmask = 0x0000ff00;
    Uint32 amask = 0x000000ff;

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 32, rmask, gmask, bmask, amask);

    // loads image to our graphics hardware memory. 
    SDL_Texture* texBottpm;
    SDL_Texture* tex1;
    tex1 = SDL_CreateTextureFromSurface(rend, surface1);
    SDL_FreeSurface(surface1);

    SDL_Texture* starTex;
    starTex = SDL_CreateTextureFromSurface(rend, star);
    SDL_FreeSurface(star);



    SDL_Texture* roadTex1;
    roadTex1 = SDL_CreateTextureFromSurface(rend, road1);
    SDL_FreeSurface(road1);

    SDL_Texture* roadTex2;
    roadTex2 = SDL_CreateTextureFromSurface(rend, road2);
    SDL_FreeSurface(road2);

    SDL_Texture* roadTex3;
    roadTex3 = SDL_CreateTextureFromSurface(rend, road3);
    SDL_FreeSurface(road3);

    SDL_Texture* roadTex4;
    roadTex4 = SDL_CreateTextureFromSurface(rend, road4);
    SDL_FreeSurface(road4);

    SDL_Texture* roadStart1;
    roadStart1 = SDL_CreateTextureFromSurface(rend, roadStart);
    SDL_FreeSurface(roadStart);

    SDL_Texture* roadStartCut1;
    roadStartCut1 = SDL_CreateTextureFromSurface(rend, roadStartCut);
    SDL_FreeSurface(roadStartCut);

    SDL_Texture* roadStartCutStar1;
    roadStartCutStar1 = SDL_CreateTextureFromSurface(rend, roadStartCutStar);
    SDL_FreeSurface(roadStartCutStar);



    SDL_Texture* roadTex1star;
    roadTex1star = SDL_CreateTextureFromSurface(rend, road1star);
    SDL_FreeSurface(road1star);

    SDL_Texture* roadTex2star;
    roadTex2star = SDL_CreateTextureFromSurface(rend, road2star);
    SDL_FreeSurface(road2star);

    SDL_Texture* roadTex3star;
    roadTex3star = SDL_CreateTextureFromSurface(rend, road3star);
    SDL_FreeSurface(road3star);

    SDL_Texture* roadTex4star;
    roadTex4star = SDL_CreateTextureFromSurface(rend, road4star);
    SDL_FreeSurface(road4star);

    SDL_Texture* roadStart1star;
    roadStart1star = SDL_CreateTextureFromSurface(rend, roadStartstar);
    SDL_FreeSurface(roadStartstar);




    SDL_Texture* tex3send;
    tex3send = SDL_CreateTextureFromSurface(rend, send);
    SDL_FreeSurface(send);

    SDL_Texture* tex3;
    tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);

    SDL_Texture* tex4;
    tex4 = SDL_CreateTextureFromSurface(rend, blok);
    SDL_FreeSurface(blok);




    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest;
    SDL_Rect dest4;
    SDL_Rect destStar;
    


    // connects our texture with dest to control position 
    SDL_QueryTexture(tex4, NULL, NULL, &dest4.w, &dest4.h);
    dest4.w /= 4;
    dest4.h /= 4;
    dest4.x = (1000 - dest4.w) / 2;
    dest4.y = (1000 - dest4.h) / 2;

    dest4.x = 60;
    dest4.y = 500;

    SDL_QueryTexture(tex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(starTex, NULL, NULL, &destStar.w, &destStar.h);
    //dest.w /= 3;
    //dest.h /= 3;

    destStar.w /= 4;
    destStar.h /= 4;

    SDL_QueryTexture(roadTex1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStartCut1, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStartCutStar1, NULL, NULL, &dest.w, &dest.h);


    SDL_QueryTexture(roadTex1star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex2star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex3star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadTex4star, NULL, NULL, &dest.w, &dest.h);

    SDL_QueryTexture(roadStart1star, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 2;
    //dest.h /= 2;

    SDL_QueryTexture(tex3, NULL, NULL, &dest.w, &dest.h);
    SDL_QueryTexture(tex3send, NULL, NULL, &dest.w, &dest.h);
    //dest.w /= 3;
    //dest.h /= 3;
    dest.w /= 2;
    dest.h /= 2;



    // controls annimation loop 
    int close = 0;
    int speed = 3, degLeftRight=5, speedCutStop = 2;
    int muveIn=0, muveOut=0, bust=0, cut = 0, cutDeg=0, muveLeft=0, muveRight=0, direction=0;
    float posX1=dest4.x, posY1=dest4.y, posX2, posY2, aDes, bDes=3, cDes, tanAlfa, radAlfa, aUR, bUR, speedMath, firstStart=0;

    int rightX, leftX, tobY, bottomY, buttonR=0, buttonT=0;
    int masPosX, masPosY;
    int top, bot, lef, rig;
    int startX=0, startY=0, rendMass=0;
    int rendCar=0;
    


    cutDeg = 90 - cut;
    radAlfa=cutDeg * M_PI/180;
    cDes = bDes/cos(radAlfa);
    aDes = sqrt((cDes * cDes) - (bDes * bDes));
    posX2 = posX1 + bDes;
    posY2 = posY1 - aDes;
    aUR = (posY2-posY1)/(posX2-posX1);
    bUR = posY1-posX1*aUR;
    speedMath=bDes/(cDes/speed);

    //printf ("aUR=%f---bUR=%f---\n", aUR, bUR);
    //printf ("posX1=%f---posY1=%f---\n", posX1, posY1);
    //printf ("posX2=%f---posY2=%f---\n", posX2, posY2);
    //printf ("cDes=%f---aDes=%f---\n", cDes, aDes);
    //printf ("radAlfa=%f---\n\n\n", radAlfa);
    int masSnow[3][1000];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1000; j++){
            masSnow[i][j] = 0;
        }
    }

    int masTex2[18][32];
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 32; j++){
            masTex2[i][j] = 10;
        }
    }
    int masTex[18][32] = {  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 

                            10, 62, 72, 72, 72, 72, 72, 72, 72, 72, 72, 72, 63, 10, 10, 81, 72, 72, 92, 72, 92, 72, 72, 72, 61, 72, 72, 72, 72, 72, 82, 10,

                            10, 71, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 71, 10, 81, 83, 10, 10, 71, 10, 71, 20, 20, 20, 20, 20, 20, 20, 20, 20, 60, 10,

                            10, 71, 10, 81, 72, 72, 72, 72, 72, 72, 82, 10, 84, 72, 83, 10, 10, 81, 83, 10, 71, 20, 20, 20, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 71, 20, 20, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 10, 71, 10, 10, 81, 72, 82, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10, 

                            10, 71, 10, 71, 10, 81, 72, 72, 61, 72, 94, 72, 72, 93, 10, 71, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 91, 72, 50, 72, 93, 10, 10, 10, 10, 10, 10, 10, 71, 10, 84, 61, 83, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 20, 20, 71, 10,

                            10, 71, 10, 71, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 10, 10, 10, 10, 71, 20, 30, 30, 30, 30, 30, 20, 20, 20, 71, 20,

                            10, 60, 10, 71, 10, 84, 72, 72, 72, 82, 30, 30, 10, 84, 72, 82, 10, 10, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 20, 20, 71, 20,

                            10, 71, 10, 71, 10, 10, 10, 10, 10, 71, 30, 30, 30, 10, 10, 84, 72, 82, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 30, 30, 30, 10, 71, 10, 30, 30, 30, 30, 10, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 30, 30, 10, 10, 71, 10, 10, 10, 10, 30, 30, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 10,

                            10, 71, 10, 71, 10, 10, 10, 81, 72, 94, 72, 92, 72, 82, 30, 30, 10, 71, 10, 10, 71, 20, 30, 30, 30, 30, 30, 30, 30, 20, 71, 20,

                            10, 84, 72, 94, 72, 82, 10, 71, 10, 10, 10, 71, 10, 71, 10, 10, 10, 71, 10, 10, 71, 20, 20, 30, 30, 20, 30, 30, 30, 20, 71, 20,

                            10, 10, 10, 10, 10, 91, 72, 93, 10, 10, 10, 91, 72, 94, 72, 82, 10, 71, 10, 10, 71, 20, 20, 20, 20, 20, 20, 20, 20, 20, 60, 10,

                            10, 30, 30, 10, 10, 84, 72, 83, 10, 10, 10, 84, 72, 61, 72, 94, 72, 94, 72, 72, 94, 72, 72, 72, 72, 72, 72, 72, 72, 72, 83, 10,

                            10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 20, 20, 20, 10, 10, 10, 10, 10,

                            };

    // annimation loop 
    while (!close) {
        SDL_Event event;

        // Events mangement 
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                close = 1;
                break;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 1;                
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_R) {
                    buttonR = 1;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_T) {
                    buttonT = 1;               
                }

            } else if (event.type == SDL_KEYUP) {
                if (event.key.keysym.scancode == SDL_SCANCODE_W) {
                    muveIn = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_S) {
                    muveOut = 0;
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_B) {
                    bust = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_A) {
                    muveLeft = 0;               
                }

                if (event.key.keysym.scancode == SDL_SCANCODE_D) {
                    muveRight = 0;               
                }

            }
        }

        if (buttonR == 1) {
            srand(time(NULL)); 
            int whileTest=1, rendStartTest=1;  
            int up = 0, rg = 0, dw = 0, lf = 0;
            int massX=32, massY=18, exitRand=0;
            int nowX=0, nowY=0, direction=0, res=0, fin=0; 
            int goX=0, goY=0;
            int colRect=0, maxBlock=130, max=0, min=0;
            int searchColAll=0, searchColNew=0;
            
            min=maxBlock-5;
            max=maxBlock+5;
            while (whileTest == 1) {
                
                searchColAll++;
                if (rendStartTest == 1) {
                    searchColNew++;
                    up = 0; rg = 0; dw = 0; lf = 0; colRect = 0;

                    for (int i = 0; i < massY; i++) {
                        for (int j = 0; j < massX; j++){
                            masTex2[i][j] = 10;
                        }
                    }

                    nowX = startX = round(rand() % ((massX-2) - 1 + 1) + 1);
                    nowY = startY = round(rand() % ((massY-2) - 1 + 1) + 1);
                    //printf ("startX=%d---startY=%d---\n", nowX, nowY);

                    masTex2[startY][startX] = 61;
                    posX1 = (50*(startX)+1)+25;
                    posY1 = (50*(startY)+1)+25;
                    
                    buttonR = 0;
                    rendStartTest = 0;
                    whileTest = 1;
                } else {
                    res = 0;
                    fin = 0;
                    direction = round(rand() % (4 - 1 + 1) + 1);
                    //printf ("direction=%d\n", direction);

                    //клетка трассы которую будем проверять
                    if (direction == 1) {
                        goX = nowX;
                        goY = nowY-1;
                        up=1;
                    } else if (direction == 2) {
                        goX = nowX+1;
                        goY = nowY;
                        rg=1;
                    } else if (direction == 3) {
                        goX = nowX;
                        goY = nowY+1;
                        dw=1;
                    } else if (direction == 4) {
                        goX = nowX-1;
                        goY = nowY;
                        lf=1;
                    }

                    //первое условие
                    if (goX < 1 || goX > massX-2) {
                        res=1;
                    } else if (goY < 1 || goY > massY-2) {
                        res=1;
                    }

                    //второе условие
                    if (res==0) {
                        if (masTex2[goY][goX] == 71) {
                            res=1;
                        }
                    }


                    //третье условие
                    if (res==0) {
                        if (masTex2[goY-1][goX] == 71 && (direction == 1 || direction == 2 || direction == 4)) {
                            res=1;
                        } else if (masTex2[goY][goX+1] == 71 && (direction == 1 || direction == 2 || direction == 3)) {
                            res=1;
                        } else if (masTex2[goY+1][goX] == 71 && (direction == 2 || direction == 3 || direction == 4)) {
                            res=1;
                        } else if (masTex2[goY][goX-1] == 71 && (direction == 1 || direction == 3 || direction == 4)) {
                            res=1;
                        }
                    }


                    //четвертое условие
                    if (res==0) {
                        if (masTex2[goY-1][goX] == 61 && (direction == 1 || direction == 2 || direction == 4)) {
                            fin=1;
                            res=1;
                        } else if (masTex2[goY][goX+1] == 61 && (direction == 1 || direction == 2 || direction == 3)) {
                            fin=1;
                            res=1;
                        } else if (masTex2[goY+1][goX] == 61 && (direction == 2 || direction == 3 || direction == 4)) {
                            fin=1;
                            res=1;
                        } else if (masTex2[goY][goX-1] == 61 && (direction == 1 || direction == 3 || direction == 4)) {
                            fin=1;
                            res=1;
                        }
                    }


                    //пятое условие
                    if (colRect < min || colRect > max) {
                        fin = 0;
                    }


                    //Проверка на законченость трассы. или генерация зашла в тупик
                    if (colRect < (max + 15) && res == 0 && fin == 0) {
                        up = 0; rg = 0; dw = 0; lf = 0;
                        colRect++;
                        nowX = goX;
                        nowY = goY;
                        masTex2[goY][goX] = 71;
                        whileTest=1;
                    } else if (up == 1 && rg == 1 && dw == 1 && lf == 1) {
                        rendStartTest = 1;
                        whileTest=1;
                    } else if (res == 1 && fin == 0) {
                        whileTest=1;
                    } else if (fin == 1) {
                        masTex2[goY][goX] = 71;
                        masTex2[startY][startX] = 71;
                        whileTest=0;                    
                        printf ("block - %d || search - %d || while - %d \n", colRect, searchColNew, searchColAll);
                        searchColNew=0;
                        searchColAll=0;
                        firstStart=0;
                        rendMass=1;
                    } else {
                        rendStartTest = 1;
                        whileTest=1;
                    }

                }

            }

        }

        if (buttonT == 1) {
            srand(time(NULL));
            int whileTest=1, rendStartTest=1, nextStep=0, snowflake=0; 
            int up = 0, rg = 0, dw = 0, lf = 0;
            int massX=32, massY=18, exitRand=0;
            int nowX=0, nowY=0, direction=0, res=0, fin=0; 
            int goX=0, goY=0, whileINtest=1;
            int colRect=0, maxBlock=130;
            
            while (whileTest == 1) {
            
                if (rendStartTest == 1) {
                    up = 0; rg = 0; dw = 0; lf = 0;

                    for (int i = 0; i < massY; i++) {
                        for (int j = 0; j < massX; j++){
                            masTex2[i][j] = 10;
                        }
                    }

                    nowX = startX = round(rand() % ((massX-2) - 1 + 1) + 1);
                    nowY = startY = round(rand() % ((massY-2) - 1 + 1) + 1);
                    //printf ("startX=%d---startY=%d---\n", nowX, nowY);

                    masTex2[startY][startX] = 71;
                    posX1 = (50*(startX)+1)+25;
                    posY1 = (50*(startY)+1)+25;
                    
                    rendStartTest = 0;
                    nextStep = 1;
                } else if (nextStep == 1) {

                    while (whileINtest == 1) {
                        res = 0;
                        fin = 0;
                        direction = round(rand() % (4 - 1 + 1) + 1);
                        //printf ("direction=%d\n", direction);

                        //клетка трассы которую будем проверять
                        if (direction == 1) {
                            goX = nowX;
                            goY = nowY-1;
                            up=1;
                        } else if (direction == 2) {
                            goX = nowX+1;
                            goY = nowY;
                            rg=1;
                        } else if (direction == 3) {
                            goX = nowX;
                            goY = nowY+1;
                            dw=1;
                        } else if (direction == 4) {
                            goX = nowX-1;
                            goY = nowY;
                            lf=1;
                        }

                        //первое условие
                        if (goX < 1 || goX > massX-2) {
                            res=1;
                        } else if (goY < 1 || goY > massY-2) {
                            res=1;
                        }

                        //второе условие
                        if (res==0) {
                            if (masTex2[goY][goX] == 71) {
                                res=1;
                            }
                        }

                        //третье условие
                        if (res==0) {
                            if (masTex2[goY-1][goX] == 71 && (direction == 1 || direction == 2 || direction == 4)) {
                                res=1;
                            } else if (masTex2[goY][goX+1] == 71 && (direction == 1 || direction == 2 || direction == 3)) {
                                res=1;
                            } else if (masTex2[goY+1][goX] == 71 && (direction == 2 || direction == 3 || direction == 4)) {
                                res=1;
                            } else if (masTex2[goY][goX-1] == 71 && (direction == 1 || direction == 3 || direction == 4)) {
                                res=1;
                            }
                        }

                        //четвертое условие
                        if (res==0) {
                            if ((goY-1)==startY && goX==startX && (direction == 1 || direction == 2 || direction == 4)) {
                                fin=1;
                                res=1;
                            } else if (goY==startY && (goX+1)==startX && (direction == 1 || direction == 2 || direction == 3)) {
                                fin=1;
                                res=1;
                            } else if ((goY+1)==startY && goX==startX && (direction == 2 || direction == 3 || direction == 4)) {
                                fin=1;
                                res=1;
                            } else if (goY==startY && (goX-1)==startX && (direction == 1 || direction == 3 || direction == 4)) {
                                fin=1;
                                res=1;
                            }
                        }

                        //пятое условие
                        if (colRect < 10) {
                            fin = 0;
                        }

                        //Проверка на законченость трассы. или генерация зашла в тупик
                        if (res == 0 && fin == 0) {
                            nextStep = 0;
                            snowflake = 1;
                            whileINtest = 0;
                        } else if (res == 1 && fin == 0) {
                            whileINtest = 1;
                        } else if (fin == 1) {
                            masTex2[goY][goX] = 71;
                            whileINtest = 0;   
                            whileTest = 0;  
                            buttonT = 0; 

                            printf ("block - %d ||\n", colRect);
                            firstStart = 0;
                            rendMass = 1;
                        } else {
                            nextStep = 0;
                            whileINtest = 1;
                        }

                    }
                    
                } else if (snowflake == 1) {
                    int stopWhile=1, colWhile=0, colForInWhile=0;
                    int testX, testY, testGoX, testGoY, sel=0, fin2=0;

                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 1000; j++){
                            masSnow[i][j] = 0;
                        }
                    }

                    masSnow[0][0] = 1;
                    masSnow[1][0] = goX;
                    masSnow[2][0] = goY;

                    

                    while (stopWhile==1) {
                        colWhile++;

                        for (int i = 0; i < 1000; i++) {
                            if (fin2==1) {
                                fin2=0;
                                break;
                            }
                            if (masSnow[0][i]==colWhile) {
                                testX = masSnow[1][i];
                                testY = masSnow[2][i];

                                for (int i = 0; i < 4; i++) {
                                    sel = 0;
                                    if (i == 0) {
                                        testGoX = testX;
                                        testGoY = testY-1;
                                    } else if (i == 1) {
                                        testGoX = testX+1;
                                        testGoY = testY;
                                    } else if (i == 2) {
                                        testGoX = testX;
                                        testGoY = testY+1;
                                    } else if (i == 3) {
                                        testGoX = testX-1;
                                        testGoY = testY;
                                    }

                                    if (masTex2[testGoY][testGoX] == 71) {
                                        sel=1;
                                    }

                                    if (testGoX < 1 || testGoX > massX-2) {
                                        sel=1;
                                    } else if (testGoY < 1 || testGoY > massY-2) {
                                        sel=1;
                                    }                                

                                    if (masTex2[testGoY-1][testGoX] == 71 && (i == 1 || i == 2 || i == 4)) {
                                        sel=1;
                                    } else if (masTex2[testGoY][testGoX+1] == 71 && (i == 1 || i == 2 || i == 3)) {
                                        sel=1;
                                    } else if (masTex2[testGoY+1][testGoX] == 71 && (i == 2 || i == 3 || i == 4)) {
                                        sel=1;
                                    } else if (masTex2[testGoY][testGoX-1] == 71 && (i == 1 || i == 3 || i == 4)) {
                                        sel=1;
                                    }

                                    if ((testGoY-1)==startY && testGoX==startX && (i == 1 || i == 2 || i == 4)) {
                                        fin2=1;
                                        sel=0;
                                    } else if (testGoY==startY && (testGoX+1)==startX && (i == 1 || i == 2 || i == 3)) {
                                        fin2=1;
                                        sel=0;
                                    } else if ((testGoY+1)==startY && testGoX==startX && (i == 2 || i == 3 || i == 4)) {
                                        fin2=1;
                                        sel=0;
                                    } else if (testGoY==startY && (testGoX-1)==startX && (i == 1 || i == 3 || i == 4)) {
                                        fin2=1;
                                        sel=0;
                                    }  

                                    if (sel == 0) {
                                        for (int i = 0; i < 1000; i++) {
                                            if (masSnow[0][i]==0) {
                                                masSnow[0][i] = colWhile+1;
                                                masSnow[1][i] = testGoX;
                                                masSnow[2][i] = testGoY;
                                                break;
                                            }
                                        }

                                    } else if (fin2==1) {
                                        stopWhile=0;
                                        break;
                                    }

                                }





                            } else if (masSnow[0][i]==0 || masSnow[0][i]>colWhile) {
                                break;
                            }

                        }
                    }



                    

                }

            }

        }

        if (rendMass==1) {

            for (int i = 0; i < 18; i++) {
                for (int j = 0; j < 32; j++){
                    masTex[i][j] = 10;
                }
            }

            for (int i = 0; i < 18; i++) {
                for (int j = 0; j < 32; j++){
                    if (masTex2[i][j] == 71) {
                        if (masTex2[i-1][j] == 71 && masTex2[i+1][j] == 71) {
                            masTex[i][j] = 71;
                        } else if (masTex2[i][j-1] == 71 && masTex2[i][j+1] == 71){
                            masTex[i][j] = 72;
                        } else if (masTex2[i-1][j] == 71 && masTex2[i][j+1] == 71){
                            masTex[i][j] = 84;
                        } else if (masTex2[i+1][j] == 71 && masTex2[i][j+1] == 71){
                            masTex[i][j] = 81;
                        } else if (masTex2[i+1][j] == 71 && masTex2[i][j-1] == 71){
                            masTex[i][j] = 82;
                        } else if (masTex2[i-1][j] == 71 && masTex2[i][j-1] == 71){
                            masTex[i][j] = 83;
                        }
                    }
                }
            }

            if (masTex2[startY-1][startX] == 71 && masTex2[startY+1][startX] == 71) {
                masTex[startY][startX] = 60;
                cut=0;
            } else if (masTex2[startY][startX-1] == 71 && masTex2[startY][startX+1] == 71) {
                masTex[startY][startX] = 61;
                cut=270;
            } else if (masTex2[startY-1][startX] == 71 && masTex2[startY][startX+1] == 71) {
                masTex[startY][startX] = 65;
                cut=315;
            } else if (masTex2[startY+1][startX] == 71 && masTex2[startY][startX+1] == 71) {
                masTex[startY][startX] = 62;
                cut=45;
            } else if (masTex2[startY+1][startX] == 71 && masTex2[startY][startX-1] == 71) {
                masTex[startY][startX] = 63;
                cut=315;
            } else if (masTex2[startY-1][startX] == 71 && masTex2[startY][startX-1] == 71) {
                masTex[startY][startX] = 64;
                cut=45;
            }
            rendCar=1;
            rendMass=0;
        }

        if (bust == 0) {
            speed = 3;
            degLeftRight = 5;
            speedCutStop = 2;
        } else {
            speed = 6;
            degLeftRight = 7;
            speedCutStop = 5;
        }

        if (muveIn==0 && muveOut==0) {
           if (muveLeft==1) {
                cut-=speedCutStop;
                if (cut<=0) {
                    cut=360;
                }
            }
            if (muveRight==1) {
                cut+=speedCutStop;
                if (cut>=360) {
                    cut=0;
                }
            } 
        }


        if (muveIn==1) {
            if (muveLeft==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
            if (muveRight==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
        }


        if (muveOut==1) {
            if (muveLeft==1) {
                cut+=degLeftRight;
                if (cut>=360) {
                    cut=0;
                }
            }
            if (muveRight==1) {
                cut-=degLeftRight;
                if (cut<=0) {
                    cut=360;
                }
            }
        }


        if (cut > 0 && cut <=89) {
            cutDeg = 90 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 90 && cut <=179) {
            cutDeg = 90 - (180 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 + bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 1;
        } else if (cut > 180 && cut <=269) {
            cutDeg = 270 - cut;
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 + aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut > 270 && cut <=359) {
            cutDeg = 90 - (360 - cut);
            radAlfa=cutDeg * M_PI/180;
            cDes = bDes/cos(radAlfa);
            aDes = sqrt((cDes * cDes) - (bDes * bDes));
            posX2 = posX1 - bDes;
            posY2 = posY1 - aDes;
            aUR = (posY2-posY1)/(posX2-posX1);
            bUR = posY1-posX1*aUR;
            speedMath=bDes/(cDes/speed);
            direction = 2;
        } else if (cut == 0 || cut == 360) {
            direction = 3;
            speedMath = speed;
        } else if (cut == 90) {
            direction = 4;
            speedMath = speed;
        } else if (cut == 180) {
            direction = 5;
            speedMath = speed;
        } else if (cut == 270) {
            direction = 6;
            speedMath = speed;
        }




        if (muveIn == 1) {
            if (direction == 1) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 -= speedMath;
            } else if (direction == 4) {
                posX1 += speedMath;
            } else if (direction == 5) {
                posY1 += speedMath;
            } else if (direction == 6) {
                posX1 -= speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 


        if (muveOut == 1) {
            if (direction == 1) {
                posX1 -= speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 2) {
                posX1 += speedMath;
                posY1 = aUR*posX1+bUR;
            } else if (direction == 3) {
                posY1 += speedMath;
            } else if (direction == 4) {
                posX1 -= speedMath;
            } else if (direction == 5) {
                posY1 -= speedMath;
            } else if (direction == 6) {
                posX1 += speedMath;
            }
            dest4.x=round(posX1);
            dest4.y=round(posY1);
        } 



    
        rightX=1600; 
        leftX=0;
        tobY=0; 
        bottomY=900;
        masPosX=round(posX1);
        masPosY=round(posY1);

        masPosY=(masPosY+12)/50;
        masPosX=(masPosX+12)/50;
        top = masTex[masPosY-1][masPosX];
        bot = masTex[masPosY+1][masPosX];
        rig = masTex[masPosY][masPosX+1];
        lef = masTex[masPosY][masPosX-1];
        int r1=0, r2=0, iNumRand=0, stopRand=0;

        
        firstStart=1;
        if (firstStart==0) {
            for (int i = 0; i < 6; i++) {
                stopRand=1;
                srand(time(NULL));            

                while (stopRand==1) {
                    r1 = rand() % 17;
                    r2 = rand() % 31;

                    if (masTex[r1][r2] == 50) {
                        masTex[r1][r2] = 501;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 70) {
                        masTex[r1][r2] = 701;
                        stopRand=0;
                    } else if (masTex[r1][r2]== 71) {
                        masTex[r1][r2] = 711;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 72) {
                        masTex[r1][r2] = 721;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 60) {
                        masTex[r1][r2] = 601;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 61) {
                        masTex[r1][r2] = 611;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 62) {
                        masTex[r1][r2] = 621;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 63) {
                        masTex[r1][r2] = 631;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 64) {
                        masTex[r1][r2] = 641;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 65) {
                        masTex[r1][r2] = 651;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 80) {
                        masTex[r1][r2] = 801;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 81) {
                        masTex[r1][r2] = 811;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 82) {
                        masTex[r1][r2] = 821;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 83) {
                        masTex[r1][r2] = 831;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 84) {
                        masTex[r1][r2] = 841;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 90) {
                        masTex[r1][r2] = 901;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 91) {
                        masTex[r1][r2] = 911;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 92) {
                        masTex[r1][r2] = 921;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 93) {
                        masTex[r1][r2] = 931;
                        stopRand=0;
                    } else if (masTex[r1][r2] == 94) {
                        masTex[r1][r2] = 941;
                        stopRand=0;
                    }
                }
                stopRand=1;
            }
            firstStart=1;
        }
        

        if (masTex[masPosY][masPosX] >= 500) {
            if (masTex[masPosY][masPosX] == 501) {
                masTex[masPosY][masPosX] = 50;
            } else if (masTex[masPosY][masPosX] == 701) {
                masTex[masPosY][masPosX] = 70;
            } else if (masTex[masPosY][masPosX] == 711) {
                masTex[masPosY][masPosX] = 71;
            } else if (masTex[masPosY][masPosX] == 721) {
                masTex[masPosY][masPosX] = 72;
            } else if (masTex[masPosY][masPosX] == 601) {
                masTex[masPosY][masPosX] = 60;
            } else if (masTex[masPosY][masPosX] == 611) {
                masTex[masPosY][masPosX] = 61;
            } else if (masTex[masPosY][masPosX] == 621) {
                masTex[masPosY][masPosX] = 62;
            } else if (masTex[masPosY][masPosX] == 631) {
                masTex[masPosY][masPosX] = 63;
            } else if (masTex[masPosY][masPosX] == 641) {
                masTex[masPosY][masPosX] = 64;
            } else if (masTex[masPosY][masPosX] == 651) {
                masTex[masPosY][masPosX] = 65;
            } else if (masTex[masPosY][masPosX] == 801) {
                masTex[masPosY][masPosX] = 80;
            } else if (masTex[masPosY][masPosX] == 811) {
                masTex[masPosY][masPosX] = 81;
            } else if (masTex[masPosY][masPosX] == 821) {
                masTex[masPosY][masPosX] = 82;
            } else if (masTex[masPosY][masPosX] == 831) {
                masTex[masPosY][masPosX] = 83;
            } else if (masTex[masPosY][masPosX] == 841) {
                masTex[masPosY][masPosX] = 84;
            } else if (masTex[masPosY][masPosX] == 901) {
                masTex[masPosY][masPosX] = 90;
            } else if (masTex[masPosY][masPosX] == 911) {
                masTex[masPosY][masPosX] = 91;
            } else if (masTex[masPosY][masPosX] == 921) {
                masTex[masPosY][masPosX] = 92;
            } else if (masTex[masPosY][masPosX] == 931) {
                masTex[masPosY][masPosX] = 93;
            } else if (masTex[masPosY][masPosX] == 941) {
                masTex[masPosY][masPosX] = 94;
            }

            stopRand=1;
            srand(time(NULL));            

            while (stopRand==1) {
                r1 = rand() % 17;
                r2 = rand() % 31;

                if (masTex[r1][r2] == 50) {
                    masTex[r1][r2] = 501;
                    stopRand=0;
                } else if (masTex[r1][r2] == 70) {
                    masTex[r1][r2] = 701;
                    stopRand=0;
                } else if (masTex[r1][r2]== 71) {
                    masTex[r1][r2] = 711;
                    stopRand=0;
                } else if (masTex[r1][r2] == 72) {
                    masTex[r1][r2] = 721;
                    stopRand=0;
                } else if (masTex[r1][r2] == 60) {
                    masTex[r1][r2] = 601;
                    stopRand=0;
                } else if (masTex[r1][r2] == 61) {
                    masTex[r1][r2] = 611;
                    stopRand=0;
                } else if (masTex[r1][r2] == 62) {
                    masTex[r1][r2] = 621;
                    stopRand=0;
                } else if (masTex[r1][r2] == 63) {
                    masTex[r1][r2] = 631;
                    stopRand=0;
                } else if (masTex[r1][r2] == 64) {
                    masTex[r1][r2] = 641;
                    stopRand=0;
                } else if (masTex[r1][r2] == 65) {
                    masTex[r1][r2] = 651;
                    stopRand=0;
                } else if (masTex[r1][r2] == 80) {
                    masTex[r1][r2] = 801;
                    stopRand=0;
                } else if (masTex[r1][r2] == 81) {
                    masTex[r1][r2] = 811;
                    stopRand=0;
                } else if (masTex[r1][r2] == 82) {
                    masTex[r1][r2] = 821;
                    stopRand=0;
                } else if (masTex[r1][r2] == 83) {
                    masTex[r1][r2] = 831;
                    stopRand=0;
                } else if (masTex[r1][r2] == 84) {
                    masTex[r1][r2] = 841;
                    stopRand=0;
                } else if (masTex[r1][r2] == 90) {
                    masTex[r1][r2] = 901;
                    stopRand=0;
                } else if (masTex[r1][r2] == 91) {
                    masTex[r1][r2] = 911;
                    stopRand=0;
                } else if (masTex[r1][r2] == 92) {
                    masTex[r1][r2] = 921;
                    stopRand=0;
                } else if (masTex[r1][r2] == 93) {
                    masTex[r1][r2] = 931;
                    stopRand=0;
                } else if (masTex[r1][r2] == 94) {
                    masTex[r1][r2] = 941;
                    stopRand=0;
                }
            }
        }
        


        if (top < 50 || top > 1000) {
            tobY=(50*masPosY)+2; 
        }

        if (bot < 50 || bot > 1000) {
            bottomY=(50*(masPosY+1))-2; 
        }

        if (rig < 50 || rig > 1000) {
            rightX=(50*(masPosX+1))-7; 
        }

        if (lef < 50 || lef > 1000) {
            leftX=(50*masPosX)+7; 
        }

        // right boundary 
        if (dest4.x + dest4.w > rightX) {
            dest4.x = rightX - dest4.w;
            posX1 = dest4.x;
        }


        // left boundary 
        if (dest4.x < leftX) {
            dest4.x = leftX;
            posX1 = dest4.x;
        }


        // bottom boundary 
        if (dest4.y + dest4.h > bottomY) {
            dest4.y = bottomY - dest4.h;
            posY1 = dest4.y;
        }
        

        // upper boundary 
        if (dest4.y < tobY){
            dest4.y = tobY;
            posY1 = dest4.y;
        }

        // clears the screen 
        SDL_RenderClear(rend);

        //dest.y = 100;
        //dest.x = 100;

        

        int cutRoad = 0;
        for (int u = 0; u < 18; u++) {
            cutRoad = 0;

            if (u == 0) {
                dest.y = 0;
            } else {
                dest.y = 50 * u; 
            }

            
            for (int y = 0; y < 32; y++) {
                 
                if (y == 0) {
                    dest.x = 0;
                } else {
                    dest.x = 50 * y;
                }


                if (masTex[u][y] == 10) {
                    texBottpm = tex1;
                    cutRoad = 0;
                } else if (masTex[u][y] == 50) {
                    texBottpm = roadTex4;
                    cutRoad = 0;
                } else if (masTex[u][y] == 60 || masTex[u][y] == 61) {
                    texBottpm = roadStart1;
                    if (masTex[u][y] == 60) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 61) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 62 || masTex[u][y] == 63 || masTex[u][y] == 64 || masTex[u][y] == 65) {
                    texBottpm = roadStartCut1;
                    if (masTex[u][y] == 62) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 63) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 64) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 65) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 70 || masTex[u][y] == 71 || masTex[u][y] == 72) {
                    texBottpm = roadTex1;
                    if (masTex[u][y] == 70) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 71) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 72) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 80 || masTex[u][y] == 81 || masTex[u][y] == 82 || masTex[u][y] == 83 || masTex[u][y] == 84) {
                    texBottpm = roadTex2;
                    if (masTex[u][y] == 80) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 81) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 82) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 83) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 84) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 90 || masTex[u][y] == 91 || masTex[u][y] == 92 || masTex[u][y] == 93 || masTex[u][y] == 94) {
                    texBottpm = roadTex3;
                    if (masTex[u][y] == 90) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 91) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 92) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 93) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 94) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 501) {
                    texBottpm = roadTex4star;
                    cutRoad = 0;
                } else if (masTex[u][y] == 601 || masTex[u][y] == 611) {
                    texBottpm = roadStart1star;
                    if (masTex[u][y] == 601) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 611) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 621 || masTex[u][y] == 631 || masTex[u][y] == 641 || masTex[u][y] == 651) {
                    texBottpm = roadStartCutStar1;
                    if (masTex[u][y] == 621) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 631) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 641) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 651) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 701 || masTex[u][y] == 711 || masTex[u][y] == 721) {
                    texBottpm = roadTex1star;
                    if (masTex[u][y] == 701) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 711) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 721) {
                        cutRoad = 90;
                    }
                } else if (masTex[u][y] == 801 || masTex[u][y] == 811 || masTex[u][y] == 821 || masTex[u][y] == 831 || masTex[u][y] == 841) {
                    texBottpm = roadTex2star;
                    if (masTex[u][y] == 801) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 811) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 821) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 831) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 841) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 901 || masTex[u][y] == 911 || masTex[u][y] == 921 || masTex[u][y] == 931 || masTex[u][y] == 941) {
                    texBottpm = roadTex3star;
                    if (masTex[u][y] == 901) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 911) {
                        cutRoad = 0;
                    } else if (masTex[u][y] == 921) {
                        cutRoad = 90;
                    } else if (masTex[u][y] == 931) {
                        cutRoad = 180;
                    } else if (masTex[u][y] == 941) {
                        cutRoad = 270;
                    }
                } else if (masTex[u][y] == 20) {
                    texBottpm = tex3send;
                    cutRoad = 0;
                } else if (masTex[u][y] == 30) {
                    texBottpm = tex3;
                    cutRoad = 0;
                } else if (masTex[u][y] == 40) {
                    texBottpm = tex4;
                    cutRoad = 0;
                }

//roadStart1
                
                //SDL_RenderCopy(rend, texBottpm, NULL, &dest);
                SDL_RenderCopyEx(rend, texBottpm, NULL, &dest, cutRoad, NULL, SDL_FLIP_NONE);
                
            }

        }
        if (rendCar==1) {
            rendCar=0;
            dest4.x = (50*(startX)+1)+25;
            dest4.y = (50*(startY)+1)+25;
            SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);
        } else {
            SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);
        }

        //SDL_RenderCopy(rend, tex4, NULL, &dest4);
        //SDL_RenderCopyEx(rend, tex4, NULL, &dest4, cut, NULL, SDL_FLIP_NONE);

        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend);

        // calculates to 60 fps 
       SDL_Delay(1000 / 70);
    }

    // destroy texture 
    SDL_DestroyTexture(tex1);
    //SDL_DestroyTexture(tex2);
    //SDL_DestroyTexture(tex3);
    SDL_DestroyTexture(tex4);

    // destroy renderer 
    SDL_DestroyRenderer(rend);

    // destroy window 
    SDL_DestroyWindow(win);
    return 0;
}












Всем привет. Меня зовут Рома. Играю в VR игры. Хочу поделиться этим с миром. Планирую затронуть много проектов. Начать свой канал решил с игры Beat Saber. Мой слоган "Один день - Одна песня!". Если вам нравиться мой контент. Рад приветствовать в нашей дружной компании. Присоединяйтесь будем играть-веселиться вместе на стримах. Готов предоставить улыбки, позитив и просто хорошее настроение. И готов принять тоже самое. Если вы дочитали до этого места. Вы точно заинтересовались моим каналом. Точно читаю все комментарии ;););) =)=)=) !!!!!!!!!!!!!!!!!!!!!!!!!!!! 





























C:\Users\roman\progect\raceSdl>gcc main.c -o main -lmingw32 -lSDL2main -lSDL2_image -lSDL2
main.c: In function 'SDL_main':
main.c:19:5: warning: implicit declaration of function 'srand'; did you mean 'scanf'? [-Wimplicit-function-declaration]
     srand(time(NULL));
     ^~~~~
     scanf
main.c:418:43: warning: implicit declaration of function 'rand'; did you mean 'nanl'? [-Wimplicit-function-declaration]
                     nowX = startX = round(rand() % ((massX-2) - 1 + 1) + 1);
                                           ^~~~
                                           nanl

C:\Users\roman\progect\raceSdl>



































while (whileINtest == 1) {
                        for (int i = 0; i < 3; i++) {
                            for (int j = 0; j < 1000; j++){
                                masSnow[i][j] = 0;
                            }
                        }


                        res = 0;
                        fin = 0;
                        direction = round(rand() % (4 - 1 + 1) + 1);
                        //printf ("direction=%d\n", direction);

                        //клетка трассы которую будем проверять
                        if (direction == 1) {
                            testGoX = goX = nowX;
                            testGoY = goY = nowY-1;
                            up=1;
                        } else if (direction == 2) {
                            testGoX = goX = nowX+1;
                            testGoY = goY = nowY;
                            rg=1;
                        } else if (direction == 3) {
                            testGoX = goX = nowX;
                            testGoY = goY = nowY+1;
                            dw=1;
                        } else if (direction == 4) {
                            testGoX = goX = nowX-1;
                            testGoY = goY = nowY;
                            lf=1;
                        }

                        masSnow[0][0] = 1;
                        masSnow[1][0] = goX;
                        masSnow[2][0] = goY;


                        searchTheWay=1;

                        while (searchTheWay==1) {

                            //первое условие
                            if (goX < 1 || goX > massX-2) {
                                res=1;
                            } else if (goY < 1 || goY > massY-2) {
                                res=1;
                            }

                            //второе условие
                            if (res==0) {
                                if (masTex2[goY][goX] == 71) {
                                    res=1;
                                }
                            }

                            //третье условие
                            if (res==0) {
                                if (masTex2[goY-1][goX] == 71 && (direction == 1 || direction == 2 || direction == 4)) {
                                    res=1;
                                } else if (masTex2[goY][goX+1] == 71 && (direction == 1 || direction == 2 || direction == 3)) {
                                    res=1;
                                } else if (masTex2[goY+1][goX] == 71 && (direction == 2 || direction == 3 || direction == 4)) {
                                    res=1;
                                } else if (masTex2[goY][goX-1] == 71 && (direction == 1 || direction == 3 || direction == 4)) {
                                    res=1;
                                }
                            }

                            //четвертое условие
                            if (res==0) {
                                if ((goY-1)==startY && goX==startX && (direction == 1 || direction == 2 || direction == 4)) {
                                    fin=1;
                                    res=1;
                                } else if (goY==startY && (goX+1)==startX && (direction == 1 || direction == 2 || direction == 3)) {
                                    fin=1;
                                    res=1;
                                } else if ((goY+1)==startY && goX==startX && (direction == 2 || direction == 3 || direction == 4)) {
                                    fin=1;
                                    res=1;
                                } else if (goY==startY && (goX-1)==startX && (direction == 1 || direction == 3 || direction == 4)) {
                                    fin=1;
                                    res=1;
                                }
                            }

                            //пятое условие
                            if (colRect < 10) {
                                fin = 0;
                            }


                            //Проверка на законченость трассы. или генерация зашла в тупик
                            if (res == 0 && fin == 0) {

                            } else if (res == 1 && fin == 0) {

                            } else if (fin == 1) {

                            } else {

                            }

                        }

                    }