#define UNICODE

#include <iostream>
#include <Windows.h>
#include <vector>
//#include "data.h"
#include "scene.h"  

int main() {
    std::cout <<  "hi" << std::endl;
    scene* test = new scene();
    std::cout <<  "construct" << std::endl;
    test->clear();  
    std::cout <<  "set" << std::endl;
    //test->update();
    std::cout <<  "render" << std::endl;

    while(1) {
        // noth
    }
    std::cout <<  "bye" << std::endl;

    return 0;
}

