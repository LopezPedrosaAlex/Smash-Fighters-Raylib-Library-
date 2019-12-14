//
//  Platforms.hpp
//  Smash_Fighters
//
//  Created by Alex Lopez  on 22/11/19.
//  Copyright © 2019 Alex Lopez . All rights reserved.
//

#ifndef Platforms_hpp
#define Platforms_hpp

#include <iostream>
#include <vector>
#include "constants.hpp"
using namespace std;

class Platforms {
    int width;
    int height;
    vector<pair<float, float> > P;
public:
    Platforms();
    void draw();
    bool fall(float x, int i);
    bool is_limit_of(float x, float y, float vel, int i);
    int ret_is_limit_of(int i) { return P[i].second; };
};

Platforms::Platforms() {
    width  = 50;
    height = 10;
    P.push_back(make_pair(20, 500 - HEIGHTMAP));
    P.push_back(make_pair(40, 400 - HEIGHTMAP));
    P.push_back(make_pair(110, 450 - HEIGHTMAP));
    P.push_back(make_pair(210, 400 - HEIGHTMAP));
    P.push_back(make_pair(260, 400 - HEIGHTMAP));
    P.push_back(make_pair(310, 400 - HEIGHTMAP));
    P.push_back(make_pair(360, 400 - HEIGHTMAP));
    P.push_back(make_pair(410, 400 - HEIGHTMAP));
    P.push_back(make_pair(460, 400 - HEIGHTMAP));
    P.push_back(make_pair(510, 400 - HEIGHTMAP));
    P.push_back(make_pair(730, 500 - HEIGHTMAP));
    P.push_back(make_pair(710, 400 - HEIGHTMAP));
    P.push_back(make_pair(620, 450 - HEIGHTMAP));
}

void Platforms::draw() {
    DrawRectangle( P[0].first, P[0].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[1].first, P[1].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[2].first, P[2].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[3].first, P[3].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[4].first, P[4].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[5].first, P[5].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[6].first, P[6].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[7].first, P[7].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[8].first, P[8].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[9].first, P[9].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[10].first, P[10].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[11].first, P[11].second, width, height, (Color){ 0, 121, 241, 255 });
    DrawRectangle( P[12].first, P[12].second, width, height, (Color){ 0, 121, 241, 255 });
}

bool Platforms::is_limit_of(float x, float y, float vel, int i) {
    if(x > P[i].first - 30 && x < P[i].first + width
       && y < P[i].second - 65 && y > P[i].second - 75 && vel <= 0) {
        return true;
    }
    else { return false; }
}

bool Platforms::fall(float x, int i) {
    if(x < P[i].first or x > P[i].first + width) {
        return true;
    }
    else return false;
}

#endif /* Platforms_hpp */
