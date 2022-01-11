#ifndef SCENE_H_
#define SCENE_H_
#define UNICODE
#define PI 3.14159265
#define MAP_SIZE 30 // width/height of map generated

#include <iostream>
#include <utility>
#include <Windows.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>

class scene {
public:

 // variables and information that will be helpful, you know
    const int screenW = 120; // 120
    const int screenH = 30; // 30
    const double FOV = (PI / 2); //90 degrees, pi/2
    const double rotateAngle = PI;
    const double moveSpeed = 2; // per second

    double playerX;
    double playerY;
    double playerAngle; //direction angle; unit angles
    double vision = mapSize / 2;
    
    
    wchar_t* screen; // = new wchar_t[screenW*screenH];
    HANDLE sBuffer;
    DWORD dwBytesWritten = 0; 

    //note: map is inverse
    int map[MAP_SIZE][MAP_SIZE];

    // functions I would like to use
    scene();        // constructor 
    void clear();   // clear the screen
    void render();  // render the screen
    void update();  // updates the screen array & raycast
    void startScreen(); // updates title screen of game
    void maze(int size);    // generates maze

    
};

class block { // block for maze generation; is 'next tile' w/ connector
public:
    std::pair<int, int> connector;  // connecting tile (wall)
    std::pair<int, int> newBlock;   // main tile 

    block();                                    // default constructor
    block(int x, int y, int conX, int conY);    // constructor
};

#endif