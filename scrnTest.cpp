#define UNICODE

#include <iostream>
#include <algorithm>
#include <Windows.h>

int screenW = 120;
int screenH = 80; 
wchar_t *screen = new wchar_t[screenW*screenH];

int main() {

    HANDLE hDialogue = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hDialogue);
	DWORD dwBytesWritten = 0;
    std::fill_n(screen , (screenW * screenH), L'X');
    WriteConsoleOutputCharacterW(hDialogue, screen, screenW * screenH, { 0,0 }, &dwBytesWritten);
    
}