#define UNICODE

#include <iostream>
#include <Windows.h>
#include <vector>
#include "scene.h"


    // functions I would liek to use

scene::scene() {
    sBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    dwBytesWritten = 0;
    wchar_t *screen = new wchar_t[screenW*screenH];
} //constructor 

void scene::clear(wchar_t & screen) {
    std::fill_n(screen, (screenW * screenH), ' ');
} //clear the screen

void scene::update() {
    WriteConsoleOutputCharacterW(sBuffer, screen, screenW * screenH, { 0,0 }, &dwBytesWritten);
} //updates the screen

 // variables and information that will be helpful, you know

//HANDLE sBuffer; // = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
//DWORD dwBytesWritten; // = 0;




