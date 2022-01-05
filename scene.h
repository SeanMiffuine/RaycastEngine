#ifndef SCENE_H_
#define SCENE_H_
#define UNICODE
#define PI 3.14159265

#include <iostream>
#include <utility>
#include <Windows.h>
#include <vector>

class scene {
public:

 // variables and information that will be helpful, you know
    const int screenW = 120; // 120
    const int screenH = 30; // 30
    const int mapSize = 10;
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
    int map[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    // functions I would like to use
    scene(); //constructor 
    void clear(); //clear the screen
    void render(); //render the screen
    void update(); //updates the screen array & raycast
};

#endif