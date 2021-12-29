#ifndef SCENE_H_
#define SCENE_H_

#include <iostream>
#include <Windows.h>
#include <vector>

class scene {
public:

 // variables and information that will be helpful, you know
    const int screenW = 120; //120
    const int screenH = 40; //80
    wchar_t* screen; // = new wchar_t[screenW*screenH];
    HANDLE sBuffer;
    DWORD dwBytesWritten = 0; 

    // functions I would like to use
    scene(); //constructor 
    void clear(); //clear the screen
    void render(); //render the screen
    
};

#endif