//
//  Shotlist.hpp
//  Smash_Fighters
//
//  Created by Alex Lopez  on 24/11/19.
//  Copyright © 2019 Alex Lopez . All rights reserved.
//

#ifndef Shotlist_hpp
#define Shotlist_hpp

#include <iostream>
#include <vector>
#include "constants.hpp"
#include "Players.hpp"
#include "Shot.hpp"
using namespace std;


class shotlist {
    vector<shot*> shoting1;
    vector<shot*> shoting2;
public:
    int  Nlife1() { return PLAYER1_LIFE; }
    int  Nlife2() { return PLAYER2_LIFE; }
    void LifeDraw();
    void new_shot1(Player player);
    void new_shot2(Player player);
    void move();
    void draw(Player player);
    void hit1(Player player);
    void hit2(Player player);
    void out();
    bool game_over();
};

void shotlist::new_shot1(Player player) {
    if(IsKeyPressed(KEY_DOWN)) { shoting1.push_back(player.boom()); }
}

void shotlist::new_shot2(Player player) {
    if(IsKeyPressed(KEY_S))    { shoting2.push_back(player.boom()); }
}

void shotlist::move() {
    vector<shot*>::iterator it1 = shoting1.begin();
    for(; it1 != shoting1.end(); it1++) {
        (*it1)->move();
    }
    vector<shot*>::iterator it2 = shoting2.begin();
    for(; it2 != shoting2.end(); it2++) {
        (*it2)->move();
    }
}

void shotlist::draw(Player player) {
    vector<shot*>::iterator it1 = shoting1.begin();
    for(; it1 != shoting1.end(); it1++) {
        (*it1)->draw(player.way());
    }
    vector<shot*>::iterator it2 = shoting2.begin();
    for(; it2 != shoting2.end(); it2++) {
        (*it2)->draw(player.way());
    }
}

void shotlist::out() {
    vector<shot*>::iterator it1 = shoting1.begin();
    while(it1 != shoting1.end()) {
        if((*it1)->out()) {
            delete(*it1);
            it1 = shoting1.erase(it1);
        }
        else it1++;
    }
    vector<shot*>::iterator it2 = shoting2.begin();
    while(it2 != shoting2.end()) {
        if((*it2)->out()) {
            delete(*it2);
            it2 = shoting2.erase(it2);
        }
        else it2++;
    }
    
}

void shotlist::hit1(Player player) {
    vector<shot*>::iterator it1 = shoting1.begin();
    while(it1 != shoting1.end()) {
        if(player.pos_x() > (*it1)->position_x() - 4 &&
           player.pos_x() < (*it1)->position_x() + 4 &&
           player.pos_y() > (*it1)->position_y() - TXplayer2.height &&
           player.pos_y() < (*it1)->position_y()) {
            PLAYER1_LIFE -= 50;
            delete(*it1);
            it1 = shoting1.erase(it1);
        }
        else it1++;
    }
}

void shotlist::hit2(Player player) {
    vector<shot*>::iterator it2 = shoting2.begin();
    while(it2 != shoting2.end()) {
        if(player.pos_x() >= (*it2)->position_x() - 4 &&
           player.pos_x() <= (*it2)->position_x() + 4 &&
           player.pos_y() > (*it2)->position_y() - TXplayer1.height &&
           player.pos_y() < (*it2)->position_y()) {
            PLAYER2_LIFE -= 50;
            delete(*it2);
            it2 = shoting2.erase(it2);
        }
        else it2++;
        
    }
}

void shotlist::LifeDraw() {
    DrawText("Player 2", 10, 10, 20, BLACK);
    DrawRectangle(10, 30, PLAYER2_LIFE, 20, BLACK);
    DrawText("Player 1", 590, 10, 20, BLACK);
    DrawRectangle(590, 30, PLAYER1_LIFE, 20, BLACK);
}


#endif /* Shotlist_hpp */
