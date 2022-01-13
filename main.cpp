#define UNICODE

#include <iostream>
#include <Windows.h>
#include <chrono>
#include <vector>
#include <cmath>
#include <mmsystem.h>

#include "scene.h"  

int main() {
    //initialize game
    scene* game = new scene();
    game->clear();
    game->maze(MAP_SIZE);
    auto timeStart = std::chrono::system_clock::now();
    auto timeFin = std::chrono::system_clock::now();

    double moveX;
    double moveY;
    int futurePositionX;
    int futurePositionY;
    //game loop
    while(1) {

        //controls
        timeFin = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = timeFin - timeStart;
        timeStart = timeFin;
		double timeElapsed = elapsed.count();

		// turn left
		if (GetAsyncKeyState((unsigned short)'A') & 0x8000) {
			game->playerAngle += game->rotateAngle * timeElapsed;
            //std::cout << game->playerAngle << std::endl; 
        }
		// turn right
		if (GetAsyncKeyState((unsigned short)'D') & 0x8000) {
			game->playerAngle -= game->rotateAngle * timeElapsed;
            //std::cout << game->playerAngle << std::endl;
        }
		// Handle Forwards movement & collision
		if (GetAsyncKeyState((unsigned short)'W') & 0x8000) {

            //PlaySound(L"footsteps.wav", NULL, SND_FILENAME | SND_ASYNC);

            // !!! depending on playerAngle must +-;
            
            moveX = cos(game->playerAngle) * game->moveSpeed * timeElapsed;
            moveY= sin(game->playerAngle) * game->moveSpeed * timeElapsed;
            futurePositionX = (int)(game->playerX + moveX);
            futurePositionY = (int)(game->playerY + moveY);

            // corner case
            if (game->map[futurePositionX][futurePositionY] == 0) {
                game->playerX += moveX; 
			    game->playerY += moveY;
                //std::cout << "x: " << game->playerX << " y: " << game->playerY << std::endl;
            } else if (game->map[futurePositionX][(int)game->playerY] == 0) {
                    game->playerX += moveX; 
            } else if (game->map[(int)game->playerX][futurePositionY] == 0) {
                    game->playerY += moveY;
            } 

        }
        if(game->map[futurePositionX][futurePositionY] == 2) {
            exit(0);
        }		

        //update and render game data
        game->update();
        game->render();
    }
    return 0;
}

