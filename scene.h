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

private:
    // variables and information that will be helpful, you know

    wchar_t *screen; // = new wchar_t[screenW*screenH];
    HANDLE sBuffer; // = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    DWORD dwBytesWritten; // = 0;

    // functions I would liek to use
    scene(); //constructor 
    void clear(wchar_t & screen); //clear the screen
    void update(); //updates the screen
};

#endif