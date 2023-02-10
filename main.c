//gcc main.c -o main -lmingw32 -lSDL2main -lSDL2_image -lSDL2

//printf ("aUR=---bUR=");


//#include <conio.h>
#include <stdio.h>
#include <time.h>
//#include <stdlib.h>
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

    SDL_Surface* surface5 = SDL_CreateRGBSurface(0, 100, 100, 0, rmask, gmask, bmask, amask);

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
                    int whileTestNum = 0;
                    while (whileTestNum == 0) {
                        direction = round(rand() % (4 - 1 + 1) + 1);
                        if (direction == 1 && up==1) {
                            whileTestNum=0;
                        } else if (direction == 2 && rg==1) {
                            whileTestNum=0;
                        } else if (direction == 3 && dw==1) {
                            whileTestNum=0;
                        } else if (direction == 4 && lf==1) {
                            whileTestNum=0;
                        } else {
                            whileTestNum=1;
                        }
                    }
                    //direction = round(rand() % (4 - 1 + 1) + 1);
                    //printf ("direction=%d\n", direction);

                    if (direction == 1 && up==1) {
                        res=1;
                    } else if (direction == 2 && rg==1) {
                        res=1;
                    } else if (direction == 3 && dw==1) {
                        res=1;
                    } else if (direction == 4 && lf==1) {
                        res=1;
                    }

                    //клетка трассы которую будем проверять
                    if (res==0) {
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
                    }

                    //первое условие
                    if (res==0) {
                        if (goX < 1 || goX > massX-2 || goY < 1 || goY > massY-2) {
                            res=1;
                        }
                    }

                    if (res==0) {
                        if (goY < 1 || goY > massY-2) {
                            res=1;
                        }
                    }

                    //второе условие
                    if (res==0) {
                        if (masTex2[goY][goX] == 71 || masTex2[goY][goX] == 61) {
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
                    if (res == 0 && fin == 0) {
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
            int testGoX=0, testGoY=0, searchTheWay=0;
            int goSnowX=0, goSnowY=0;
            int colRect=0, maxBlock=130;
            int searchColAll=0, searchColNew=0;


            searchColAll++;
            while (whileTest == 1) {
                searchColNew++;
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

                    masTex2[startY][startX] = 61;
                    posX1 = (50*(startX)+1)+25;
                    posY1 = (50*(startY)+1)+25;
                    
                    buttonT = 0;
                    rendStartTest = 0;
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
                    }

                    if (res==0) {
                        if (goY < 1 || goY > massY-2) {
                            res=1;
                        }
                    }

                    //второе условие
                    if (res==0) {
                        if (masTex2[goY][goX] == 71 || masTex2[goY][goX] == 61) {
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



                    if (res == 0 && fin == 0) {
                        masSnow[0][0] = 1;
                        masSnow[1][0] = goX;
                        masSnow[2][0] = goY;
                        for (int i = 0; i < 1000; i++) {
                            int stop = 0;
                            testGoX = masSnow[1][i];
                            testGoY = masSnow[2][i];
                            for (int i = 1; i <= 4; i++) {
                                res = 0;
                                fin = 0;
                                direction = i;
                                //printf ("direction=%d\n", direction);

                                //клетка трассы которую будем проверять
                                if (direction == 1) {
                                    goSnowX = testGoX;
                                    goSnowY = testGoY-1;
                                } else if (direction == 2) {
                                    goSnowX = testGoX+1;
                                    goSnowY = testGoY;
                                } else if (direction == 3) {
                                    goSnowX = testGoX;
                                    goSnowY = testGoY+1;
                                } else if (direction == 4) {
                                    goSnowX = testGoX-1;
                                    goSnowY = testGoY;
                                }

                                //первое условие
                                if (goSnowX < 1 || goSnowX > massX-2) {
                                    res=1;
                                }

                                if (res==0) {
                                    if (goSnowY < 1 || goSnowY > massY-2) {
                                        res=1;
                                    }
                                }

                                //второе условие
                                if (res==0) {
                                    if (masTex2[goSnowY][goSnowX] == 71 || masTex2[goSnowY][goSnowX] == 61) {
                                        res=1;
                                    }
                                }

                                //третье условие
                                if (res==0) {
                                    if (masTex2[goSnowY-1][goSnowX] == 71 && (direction == 1 || direction == 2 || direction == 4)) {
                                        res=1;
                                    } else if (masTex2[goSnowY][goSnowX+1] == 71 && (direction == 1 || direction == 2 || direction == 3)) {
                                        res=1;
                                    } else if (masTex2[goSnowY+1][goSnowX] == 71 && (direction == 2 || direction == 3 || direction == 4)) {
                                        res=1;
                                    } else if (masTex2[goSnowY][goSnowX-1] == 71 && (direction == 1 || direction == 3 || direction == 4)) {
                                        res=1;
                                    }
                                }

                                //четвертое условие
                                if (res==0) {
                                    if (masTex2[goSnowY-1][goSnowX] == 61 && (direction == 1 || direction == 2 || direction == 4)) {
                                        fin=1;
                                        res=1;
                                    } else if (masTex2[goSnowY][goSnowX+1] == 61 && (direction == 1 || direction == 2 || direction == 3)) {
                                        fin=1;
                                        res=1;
                                    } else if (masTex2[goSnowY+1][goSnowX] == 61 && (direction == 2 || direction == 3 || direction == 4)) {
                                        fin=1;
                                        res=1;
                                    } else if (masTex2[goSnowY][goSnowX-1] == 61 && (direction == 1 || direction == 3 || direction == 4)) {
                                        fin=1;
                                        res=1;
                                    }
                                }


                                if (res == 0 && fin == 0) {
                                    int snowTestInt = 0;
                                    for (int i = 0; i < 1000; i++) {
                                        if (masSnow[1][i] == goSnowX && masSnow[2][i] == goSnowY) {
                                            snowTestInt = 1;
                                            break;
                                        } else {
                                            snowTestInt = 0;
                                        }
                                    }
                                    if (snowTestInt == 0) {
                                        for (int i = 0; i < 1000; i++) {
                                            if (masSnow[0][i] == 0) {
                                                masSnow[0][i] = 1;
                                                masSnow[1][i] = goSnowX;
                                                masSnow[2][i] = goSnowY;
                                                break;
                                            }
                                        }
                                    }
                                    
                                } else if (fin == 1) {
                                    stop = 1;
                                    break;
                                }

                            }
                            if (stop == 1) {
                                up = 0; rg = 0; dw = 0; lf = 0;
                                colRect++;
                                nowX = goX;
                                nowY = goY;
                                masTex2[goY][goX] = 71;
                                whileTest=1;
                                break;
                            } else {
                                whileTest=1;
                            }

                        }
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
                        whileTest=1;
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