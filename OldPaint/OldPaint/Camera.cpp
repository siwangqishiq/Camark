//
//  Camera.cpp
//  PyMario
//
//  Created by panyi  on 2018/6/13.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#include "Camera.hpp"
#include "Map.hpp"

#include <iostream>

using namespace std;

void Camera::moveToLeft(){
    mCenterX -= 10;
    limitMove();
}

void Camera::moveToRight(){
    mCenterX += 10;
    limitMove();
    
    //cout << "move Right " <<mCenterX << endl;
}

void Camera::limitMove(){
    int halfWidth = SCREEN_WIDTH >> 1;
    
    if(mCenterX - halfWidth < 0)
        mCenterX = halfWidth;
    
    if(mCenterX + halfWidth > Map::CUBE_SIZE * Map::COL_NUM)
        mCenterX = Map::CUBE_SIZE * Map::COL_NUM - halfWidth;
}

