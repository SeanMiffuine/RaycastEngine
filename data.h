#ifndef DATA_H_
#define DATA_H_

#define UNICODE

#include <iostream>
#include <Windows.h>
#include <vector>

class data {
public:

    int mapW;
    int mapH;
    int map[10][10] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };


};

#endif