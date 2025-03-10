
#include <iostream>
#include "Vector2D.h"
#include "LayerList.h"

#include "GameLayer.hpp"
#include "GameObject.hpp"
#include "Rendering.hpp"
#include "GameHandler.hpp"

GameLayer layer0(
    {
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {" "," "," "," ","_","_","_","_","_","_","_","_","_"},
    {"_","_","_"," ","_","_","_","_","_","_","_","_","_"},
    {"_","_","_"," ","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"},
    {"_","_","_","_","_","_","_","_","_","_","_","_","_"}},
    false
    );

GameLayer layer1({
    {"0","1","2","3","4","5","6","7","8","9","0","1","2"},
    {"1"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"2"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"3"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"4"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"5"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"6"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"7"," "," "," "," "," "," ","-"," "," "," "," "," "},
    {"8"," "," "," "," "," "," "," "," "," "," "," "," "},
    {"9"," "," "," "," "," "," "," "," "," "," "," "," "} },
    true
    );


layerList gameLayerList = { layer0, layer1 };

GameHandler gameHandler;

GameObject objeto("objeto", "W", true, 1, {1,4});



void update() {

    //while (_kbhit()) {
    //    char tecla = ' ';
    //    tecla = _getch();
    //    switch (tecla) {
    //    case 'a':
    //    case 'A':
    //        //objeto.PositionYX[1] -= 1;
    //        break;
    //    default:
    //        break;
    //    }
    //}

    layer1.layer[2][3] = objeto.visual;

    objeto.debugObject();
    



    gameHandler.updater(gameLayerList);
}

int main()
{
    gameHandler.start({ objeto });
    
    
    while (gameHandler.isRunning() == true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        update();
    }
    

}