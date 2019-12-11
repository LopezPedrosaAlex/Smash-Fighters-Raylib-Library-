//
//  Shots.hpp
//  Smash_Fighters
//
//  Created by Alex Lopez  on 22/11/19.
//  Copyright © 2019 Alex Lopez . All rights reserved.
//

#ifndef Shot_hpp
#define Shot_hpp

#include <iostream>
#include "raylib.h"
using namespace std;

class shot {
    Vector2 position;
    Vector2 shotvelocity;
    int direction;
public:
    shot(Vector2 pos, Vector2 vel, int direction);
    bool out();
    float position_x() { return position.x; }
    float position_y() { return position.y; }
    void draw(int i);
    void move();
};

shot::shot(Vector2 pos, Vector2 vel, int direction) {
    position.y    = pos.y + 20;
    if(direction == 1)  { position.x = pos.x + 60; }
    if(direction == -1) { position.x = pos.x; }
    
    shotvelocity  = vel;
}

void shot::move() {
    position.x += shotvelocity.x;
    position.y += shotvelocity.y;
}

void shot::draw(int i) {
    if(i == 1) {
        DrawTextureEx(TXbullet1, position , 0, 0.5, WHITE);
    }
    if(i == -1) {
        DrawTextureEx(TXbullet1Inverse, position , 0, 0.5, WHITE);
    }
}

bool shot::out() {
    if(position.x < 0 or position.x > SCREENWIDTH or
       position.y < 0 or position.y > SCREENHEIGHT) {
        return true;
    }
    else return false;
    
}


#endif /* Shot_hpp */
