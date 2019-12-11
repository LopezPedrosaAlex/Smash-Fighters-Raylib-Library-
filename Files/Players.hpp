//
//  Players.h
//  Smash_Fighters
//
//  Created by Alex Lopez  on 22/11/19.
//  Copyright © 2019 Alex Lopez . All rights reserved.
//

#ifndef Players_hpp
#define Players_hpp

#include <iostream>
#include <iterator>
#include "raylib.h"
#include "Platforms.hpp"
#include "Shot.hpp"
#include "constants.hpp"
using namespace std;

class Player
{
    Vector2 position;
    Vector2 velocity;
    Vector2 Vshot;
    int Plife;
    float position_x_jump;
    bool over_platform;
    bool saltant;
    int direction;
public:
    Player(Texture2D player, float pos, int dir);
    float pos_x() { return position.x; }
    float pos_y() { return position.y; }
    int life()    { return Plife; }
    int way() { return direction; }
    void draw(Texture2D player, Texture2D playerinverse, Texture2D playerSR, Texture2D playerSD,
              bool left, bool right, bool down);
    void move(Texture2D player, bool left, bool right);
    void jump();
    void limits(Platforms P);
    shot *boom();
    int ShotHit(int hit) { return Plife -= hit; }
};

Player::Player(Texture2D player, float pos, int dir)
{
    position = { pos, SCREENHEIGHT - static_cast<float>(player.height)-HEIGHTMAP };
    direction = dir;
    velocity = { 0, 0 };
    saltant = false;
    over_platform = false;
    Plife = 100;
}

void Player::draw(Texture2D player, Texture2D playerinverse, Texture2D playerSR, Texture2D playerSD,
                  bool left, bool right, bool down)
{
    Rectangle frameRec = { 0, 0, static_cast<float>(player.width/6), static_cast<float>(player.height) };
    
    if( !left && !right && !down )
    {
        if(direction != -1) { DrawTextureRec(player, frameRec, position, WHITE); }
        if(direction == -1) { DrawTextureRec(playerinverse, frameRec, position, WHITE); }
    }
    if( left && !down )
    {
        if (CurrentFrame > 5)
        {
            CurrentFrame = 0;
            FramesSpeed --;
        }
        frameRec.x = FramesSpeed * playerinverse.width/6;
        DrawTextureRec(playerinverse, frameRec, position, WHITE);
    }
    if( right && !down )
    {
        if (CurrentFrame > 5)
        {
            CurrentFrame = 0;
            FramesSpeed ++;
        }
        frameRec.x = FramesSpeed * TXplayer1.width/6;
        DrawTextureRec(player, frameRec, position, WHITE);
    }
    if( down )
    {
        if(direction != -1) { DrawTextureRec(playerSR, frameRec, position, WHITE); }
        if(direction == -1) { DrawTextureRec(playerSD, frameRec, position, WHITE); }
    }
}

void Player::move(Texture2D player, bool left, bool right)
{
    if (left)  { position.x -= 3.0f; direction = -1; CurrentFrame++; }
    if (right) { position.x += 3.0f; direction =  1; CurrentFrame++; }
    
    if(position.x > SCREENWIDTH) { position.x -= SCREENWIDTH; }
    if(position.x < 0)           { position.x  = SCREENWIDTH; }
    
    if (saltant) {
        velocity.y -= GRAVITY * 0.1;
        position.y -= velocity.y;
    }
    
    if (position.y > SCREENHEIGHT - player.height - HEIGHTMAP) {
        velocity.y = 0;
        position.y = SCREENHEIGHT - player.height - HEIGHTMAP;
        saltant = false;
    }
}

void Player::jump()
{
    if (!saltant)
    {
        velocity.y = 6;
        saltant = true;
    }
}

void Player::limits(Platforms P)
{
    int nPlat = 0;
    for(int i = 0; i <= nPlatforms; i++)
    {
        if(P.is_limit_of(position.x, position.y, velocity.y, i))
        {
            position.y = P.ret_is_limit_of(i) - 5 - 65;
            nPlat = i;
            over_platform = true;
            saltant = false;
        }
    }
    if(P.fall(position.x, nPlat) && over_platform)
    {
        saltant = true;
        over_platform = false;
    }
    else if(!over_platform && position.y > SCREENHEIGHT - 10) { saltant = false; }
}

shot *Player::boom()
{
    Vector2 Vshot = { direction * 7.0f, 0 };
    
    Vshot.x += velocity.x;
    Vshot.y += 0;
    return new shot(position, Vshot, direction);
    
}

#endif /* Players_hpp */
