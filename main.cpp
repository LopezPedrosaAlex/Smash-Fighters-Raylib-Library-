//
//  main.cpp
//  Smash_Fighters
//
//  Created by Alex Lopez  on 19/11/19.
//  Copyright © 2019 Alex Lopez . All rights reserved.
//
#include <iostream>
#include <vector>
#include "raylib.h"
#include "Platforms.hpp"
#include "constants.hpp"
#include "Shotlist.hpp"
#include "Players.hpp"
#include "Shot.hpp"
using namespace std;

void loadTX() {
    TXmap = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/Fondo.png");
    TXplayer1 = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/Jugador1.png");
    TXplayer1Inverse = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/Jugador1Reves.png");
    TXplayer2 = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/Jugador2.png");
    TXplayer2Inverse = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/Jugador2Reves.png");
    TXbullet1 = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/bala1.png");
    TXbullet1Inverse = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/Bala1Reves.png");
    TXplayer1SR = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/J1disparader.png");
    TXplayer1SD = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/J1disparaizq.png");
    TXplayer2SR = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/J2disparader.png");
    TXplayer2SD = LoadTexture("/Users/Alex/Desktop/Github/Smash_Fighters/Files/J2disparaizq.png");
}

int main() {
    InitWindow(SCREENWIDTH, SCREENHEIGHT, "Basic Physics");
    SetTargetFPS(60);
    loadTX();
    Player P1(TXplayer1, 10, 1);
    Player P2(TXplayer2Inverse, 700, -1);
    shotlist SL;
    Platforms PL;
    bool start = false;
    bool game_over1 = false;
    bool game_over2 = false;
    while(!WindowShouldClose()) {
        SetExitKey(KEY_ESCAPE);
        
        //Pintar
        BeginDrawing();
        DrawTextureEx(TXmap, { 0, 0 } , 0, 1, WHITE);
        PL.draw();
        
        if(IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT) && IsKeyUp(KEY_DOWN))
        {
            P1.draw(TXplayer1, TXplayer1Inverse, TXplayer1SR, TXplayer1SD, false, false, false);
        }
        else if (IsKeyDown(KEY_LEFT))    { P1.draw(TXplayer1, TXplayer1Inverse, TXplayer1SR, TXplayer1SD,
                                                 true, false, false); }
        else if (IsKeyDown(KEY_RIGHT))    { P1.draw(TXplayer1, TXplayer1Inverse, TXplayer1SR, TXplayer1SD,
                                                  false, true, false); }
        else if (IsKeyDown(KEY_DOWN))    { P1.draw(TXplayer1, TXplayer1Inverse, TXplayer1SR, TXplayer1SD,
                                                 false, false, true); }
        
         if(IsKeyUp(KEY_A) && IsKeyUp(KEY_D) && IsKeyUp(KEY_S))
         {
             P2.draw(TXplayer2, TXplayer2Inverse, TXplayer2SR, TXplayer2SD, false, false, false);
         }
        if (IsKeyDown(KEY_A))    { P2.draw(TXplayer2, TXplayer2Inverse, TXplayer2SR, TXplayer2SD,
                                                 true, false, false); }
        else if (IsKeyDown(KEY_D))    { P2.draw(TXplayer2, TXplayer2Inverse, TXplayer2SR, TXplayer2SD,
                                                  false, true, false); }
        else if (IsKeyDown(KEY_S))    { P2.draw(TXplayer2, TXplayer2Inverse, TXplayer2SR, TXplayer2SD,
                                                 false, false, true); }
        SL.draw(P1);
        SL.draw(P2);
        SL.LifeDraw();
       
        if(!start)     { DrawText("PRESS SPACE", SCREENWIDTH/5, SCREENHEIGHT/3, 60, BLACK);
            DrawText("TO START", SCREENWIDTH/4, SCREENHEIGHT/2, 60, BLACK); }
        if(game_over1) { DrawText("PLAYER 2 WINS", SCREENWIDTH/5, SCREENHEIGHT/3, 60, BLACK); }
        if(game_over2) { DrawText("PLAYER 1 WINS", SCREENWIDTH/5, SCREENHEIGHT/3, 60, BLACK); }
        EndDrawing();
        if(IsKeyPressed(KEY_SPACE)) { start = true; }
        if(start == true) {
            if(!game_over1 && !game_over2) {
                
                //Movement
                if(IsKeyUp(KEY_LEFT) && IsKeyUp(KEY_RIGHT))     P1.move(TXplayer1, false, false);
                else if (IsKeyDown(KEY_LEFT))                   P1.move(TXplayer1, true, false);
                else if (IsKeyDown(KEY_RIGHT))                  P1.move(TXplayer1, false, true);
                
                if(IsKeyUp(KEY_A) && IsKeyUp(KEY_D))            P2.move(TXplayer2, false, false);
                else if (IsKeyDown(KEY_A))                      P2.move(TXplayer2, true, false);
                else if (IsKeyDown(KEY_D))                      P2.move(TXplayer2, false, true);
                
                SL.move();
                if (IsKeyPressed(KEY_UP))    P1.jump();
                if (IsKeyPressed(KEY_W))     P2.jump(); 
            }
            
            //Limits
            P1.limits(PL);
            P2.limits(PL);
            SL.out();
            if(SL.Nlife1() == 0) { game_over1 = true; }
            if(SL.Nlife2() == 0) { game_over2 = true; }
            SL.new_shot1(P1);
            SL.new_shot2(P2);
            SL.hit1(P2);
            SL.hit2(P1);
        }
    }
    CloseWindow();
    return 0;
}
