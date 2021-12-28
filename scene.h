#ifndef SCENE_H_
#define SCENE_H_

#include <iostream>
#include <Windows.h>
#include <vector>

class scene {
public:
 // variables and information that will be helpful, you know
    const int screenW = 120; //120
    const int screenH = 80; //80
    wchar_t* screen; // = new wchar_t[screenW*screenH];

    // functions I would like to use
    scene(); //constructor 
    void clear(); //clear the screen
    void update(); //updates the screen
    

private:
    // variables and information that will be helpful, you know
    HANDLE sBuffer; // = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    DWORD dwBytesWritten; // = 0;

};

#endif