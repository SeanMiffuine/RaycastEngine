#define UNICODE

#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include "scene.h"

scene::scene() {
    sBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); 
    screen = new wchar_t[screenW*screenH];
} //constructor 

void scene::clear() {
    std::fill_n(screen, (screenW * screenH), L' ');
} //clear the screen

void scene::render() {
    SetConsoleActiveScreenBuffer(sBuffer);
    WriteConsoleOutputCharacterW(sBuffer, screen, screenW * screenH, { 0,0 }, &dwBytesWritten);
} //updates the screen







