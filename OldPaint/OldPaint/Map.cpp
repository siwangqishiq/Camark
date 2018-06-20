//
//  Map.cpp
//  PyMario
//
//  Created by panyi  on 2018/6/13.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#include "CApp.h"
#include "Map.hpp"
#include <cmath>
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
    //pCamera->getVieWidth();
    
    //cout << pCamera->getCenterX() <<endl;
    int halfWidth = pCamera->getVieWidth() / 2;
    
    this->mStartXIndex = max((int)((pCamera->getCenterX() - halfWidth) / Map::CUBE_SIZE) , 0);
    this->mEndXIndex = min((int)((pCamera->getCenterX() + halfWidth) / Map::CUBE_SIZE + 1) , (int)Map::COL_NUM);
    
    mOffsetLeft = pCamera->getCenterX() - halfWidth - mStartXIndex * Map::CUBE_SIZE;
}

void Map::render(SDL_Renderer *render){
    int left;
    int top = 0;
    
    
    for(int i = mStartYIndex ; i < mEndYIndex ;i++){
        top = i * Map::CUBE_SIZE;
        
        left = -mOffsetLeft;
        for(int j = mStartXIndex; j < mEndXIndex ;j++){
            //cout << ""<<maps[i][j];
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
            
            left += Map::CUBE_SIZE;
        }
        //cout << endl;
    }//end for i
    //cout << endl;
}
