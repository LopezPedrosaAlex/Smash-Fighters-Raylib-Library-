//
//  constants.h
//  Smash_Fighters
//
//  Created by Alex Lopez  on 22/11/19.
//  Copyright © 2019 Alex Lopez . All rights reserved.
//

#ifndef constants_hpp
#define constants_hpp

#include "raylib.h"

// Screen Size
const int SCREENWIDTH  = 800;
const int SCREENHEIGHT = 550;

// Gravity
const float GRAVITY = 2.5;

// Height Map
const int HEIGHTMAP = 47;

// Frames
int FramesSpeed   = 0, FramesSpeed2  = 0;
int FramesCounter = 0;
int CurrentFrame  = 0, CurrentFrame2 = 0;

// Textures game
Texture2D TXmap, TXplayer1, TXplayer2, TXplayer1Inverse, TXplayer2Inverse,
TXbullet1, TXbullet1Inverse, TXplayer1SD, TXplayer1SR, TXplayer2SR, TXplayer2SD;

// Platforms
const int nPlatforms = 16;

// Players
int PLAYER1_LIFE = 200;
int PLAYER2_LIFE = 200;

#endif /* constants_hpp */
