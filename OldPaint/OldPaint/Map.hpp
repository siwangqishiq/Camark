//
//  Map.hpp
//  PyMario
//
//  Created by panyi  on 2018/6/13.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "Camera.hpp"

class Map{
public:
    static const int CUBE_SIZE = 50;
    
    Map(Camera *_pCamera,SDL_Renderer *renderer);
    ~Map(){}
    
    void update();
    void render(SDL_Renderer *render);
    
    static const int ROW_NUM = 12;
    static const int COL_NUM = 40;
    
    int maps[ROW_NUM][COL_NUM] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1},
        {1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
private:
    Camera *pCamera;
    SDL_Texture *mMapTexture;
    
    void loadResource(SDL_Renderer *renderer);
    
    SDL_Rect mMapSrcNormalCubeRect;
    SDL_Rect mMapSrcBrickCubeRect;
    SDL_Rect mMapDstRect;
    
    int mStartXIndex = 0;
    int mEndXIndex = COL_NUM;
    int mStartYIndex = 0;
    int mEndYIndex = ROW_NUM;
    
    int mOffsetLeft;//绘制x偏移
    int mOffsetTop;//绘制y偏移
};

#endif /* Map_hpp */
