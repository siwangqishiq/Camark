//
//  Map.cpp
//  PyMario
//
//  Created by panyi  on 2018/6/13.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#include "CApp.h"
#include "Map.hpp"

#include <iostream>

using namespace std;

Map::Map(Camera *_pCamera,SDL_Renderer *renderer){
    this->pCamera = _pCamera;
   
    loadResource(renderer);
    
    mMapSrcNormalCubeRect.x = 1;
    mMapSrcNormalCubeRect.y = 1;
    mMapSrcNormalCubeRect.w = 16;
    mMapSrcNormalCubeRect.h = 16;
    
    mMapSrcBrickCubeRect.x = 33;
    mMapSrcBrickCubeRect.y = 1;
    mMapSrcBrickCubeRect.w = 16;
    mMapSrcBrickCubeRect.h = 16;
    //test
}


void Map::loadResource(SDL_Renderer *renderer){
    this->mMapTexture = CApp::load_image(renderer, "tileset_gutter.png");
}

void Map::update(){
    pCamera->getVieWidth();
}

void Map::render(SDL_Renderer *render){
    int left = 0;
    int top = 0;
    
    
    
    for(int i = 0 ; i < ROW_NUM ;i++){
        top = i * Map::CUBE_SIZE;
        
        for(int j = 0; j < COL_NUM ;j++){
            //cout << ""<<maps[i][j];
            left = j * Map::CUBE_SIZE;
            mMapDstRect.x = left;
            mMapDstRect.y = top;
            mMapDstRect.w = Map::CUBE_SIZE;
            mMapDstRect.h = Map::CUBE_SIZE;
            
            switch(maps[i][j]){
                case 0:
                    break;
                case 1://障碍
                    SDL_RenderCopy(render, mMapTexture, &mMapSrcNormalCubeRect, &mMapDstRect);
                    break;
                case 2://砖块
                    SDL_RenderCopy(render, mMapTexture, &mMapSrcBrickCubeRect, &mMapDstRect);
                    break;
                
            }//end switch
        }
        cout << endl;
    }//end for i
    cout << endl;
}
