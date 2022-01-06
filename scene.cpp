#define UNICODE

#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include "scene.h"


scene::scene() {
    sBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL); 
    screen = new wchar_t[screenW*screenH];

    playerX = 1.0;
    playerY = 1.0;
    playerAngle = PI / 2; //facing up
} //constructor 

void scene::clear() {
    std::fill_n(screen, (screenW * screenH), L'x');
} //clear the screen

void scene::render() {
    SetConsoleActiveScreenBuffer(sBuffer);
    WriteConsoleOutputCharacterW(sBuffer, screen, screenW * screenH, { 0,0 }, &dwBytesWritten);
} //updates the screen

void scene::update() {
    // for loop through screen character width,
    // representing ecah colomn of render.
    // technically one frame. 

    for (int x = 0; x < screenW; x++) {

        double angle; // angle of ray accoridng to unit circle.
        double direction; //against the grain of unit circle.
    
    // accumulators
        // total distances
        double totalX;
        double totalY;
        double vectorX;
        double vectorY;
        double vectorXperUnit;
        double vectorYperUnit;

        // current map tile 
        int curPosX = (int) playerX;
        int curPosY = (int) playerY;

        // icrement direction, 1 or -1, in euclidian direction
        int incX;
        int incY;

        while (playerAngle >= (2 * PI)) {
            playerAngle -= (2 * PI);
        }
        while (playerAngle < 0.0) {
            playerAngle += (2 * PI);
        }
        angle = (FOV / screenW) * x; 
        direction = (playerAngle + (FOV / 2)) - angle; 
        //check if over unit circle
        while (direction >= (2 * PI)) {
            direction -= (2 * PI);
        }
        while (direction < 0.0) {
            direction += (2 * PI);
        }

        //std::cout << "angle: " << playerAngle << std::endl;

    //check initial step within block
        
        //note* euclidian coords and angles
        // check up down ; not on border of cell
        if ((int)playerY != playerY) { // up
            if (direction >= 0 && direction < PI) {
                totalY = (1.0 - (playerY - curPosY));
                incY = 1;
            } else { // down
                totalY = playerY - curPosY;
                incY = -1;
            }
        } else { // on border of cell
            if (direction >= 0 && direction < PI) { // up
                totalY = 0;
                incY = 1;
            } else { // down
                totalY = 0;
                incY = -1;
            }
        }
        // check left right
        if ((int)playerX != playerX) {
            if (direction >= (PI / 2) && direction < (PI + (PI / 2))) { // left
                totalX = playerX - curPosX;
                incX = -1;
            } else { // right
                totalX = (1.0 - (playerX - curPosX));
                incX = 1;
            }
        } else {
            if (direction >= (PI / 2) && direction < (PI + (PI / 2))) { // left
                totalX = 0;
                incX = -1;
            } else { // right
                totalX = 0;
                incX = 1;
            }
        }

        // using direction radians and total x & y displacement, find vector length
        if (cos(direction) == 0) {
            vectorX = abs(totalX);
            vectorXperUnit = 1;
        } else {
            vectorX = abs(totalX / (cos(direction)));
            vectorXperUnit = abs(1 / (cos(direction)));
        }
        if (sin(direction) == 0) {
            vectorY = abs(totalY);
            vectorYperUnit = 1;
        } else {
            vectorY = abs(totalY / (sin(direction)));
            vectorYperUnit = abs(1 / (sin(direction)));
        }
        
        // DDA algorithm : check inc x or y, depending on lowest increment
        int side; // side of wall; left right = 1, up down = 0;
        bool hit  = false; // hit wall or not
        while (!hit) {
            // Walk along shortest path
			if (vectorX < vectorY) {
				curPosX += incX;
				vectorX += vectorXperUnit;
                side = 1;
			} else {
				curPosY += incY;
				vectorY += vectorYperUnit;
                side = 0;
			}
            if (map[curPosX][curPosY] == 1) {
                hit = true;
            }
        }

        // information with finished ray
        double totalLength;
        double rayPosX;
        double rayPosY;
        if (side == 1) {
            totalLength = vectorX -= vectorXperUnit; // CHANGED ???
            rayPosX = vectorX * (cos(direction));
            rayPosY = vectorX * (sin(direction));
        } else {
            totalLength = vectorY -= vectorYperUnit;
            rayPosX = vectorY * (cos(direction));
            rayPosY = vectorY * (sin(direction));
        }
        rayPosX += playerX;
        rayPosY += playerY;
        /*
        std::cout << "angle: " << direction << " side: " << side << std::endl;
        std::cout << "total ray: " << totalLength << std::endl;
        */
        //render onto column on screen, different texture if near the gap btwn tile
        
        // indexes per column
        int wallHeight = screenH / totalLength;
        int ceiling = (screenH / 2) - (wallHeight / 2);
        int floor = ceiling + wallHeight + 1;
        short blank = L' ';
        short tile;
        short floorClose = L'=';
        short floorMed = L'-';
        short floorFar = L'.';
        
        if (side == 1) { // left right walls
            if (rayPosY - (int)rayPosY <= 0.05 || rayPosY - (int)rayPosY >= 0.95) {
                tile = L' ';
            } else if (totalLength <= vision / 3) { // close
                tile = 0x2588;
            } else if (totalLength <= vision / 2) {
                tile = 0x2593;
            } else if (totalLength <= vision) {
                tile = 0x2591;
            } else { // unseeably far
                tile = L' ';
            }
        } else { // front back walls
            if (rayPosX - (int)rayPosX <= 0.05 || rayPosX - (int)rayPosX >= 0.95) {
                tile = L' ';
            } else if (totalLength <= vision / 3) { // close
                tile = L'#';
            } else if (totalLength <= vision / 2) {
                tile = L'O';
            } else if (totalLength <= vision) {
                tile = L'1';
            } else { // unseeably far
                tile = L' ';
            }
        }
        for (int y = 0; y < screenH; y++) {
            if (y <= ceiling) {
                screen[x + (screenW * y)] = blank;
            } else if (y > ceiling && y <= floor) {
                screen[x + (screenW * y)] = tile;
            } else {
                if (y < (screenH - 5)) {
                    screen[x + (screenW * y)] = floorFar;
                } else if (y < (screenH - 2)) {
                    screen[x + (screenW * y)] = floorMed;
                } else {
                    screen[x + (screenW * y)] = floorClose;
                }
            }   
        }
        
    }
}







