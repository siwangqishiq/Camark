//
//  Camera.hpp
//  PyMario
//
//  Created by panyi  on 2018/6/13.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp
#include "Config.h"

class Camera{
public:
    Camera(int _x , int _y):mCenterX(_x) ,mCenterY(_y){
        mVieWidth = SCREEN_WIDTH;
        mViewHeight = SCREEN_HEIGHT;
    }
    
    void moveCamera(int x , int y){
        this->mCenterX = x;
        this->mCenterY = y;
    }
    
    int getVieWidth(){
        return this->mVieWidth;
    }
    
    int getViewHeight(){
        return this->mViewHeight;
    }
    
    int getCenterX(){
        return this->mCenterX;
    }
    
    int getCenterY(){
        return this->mCenterY;
    }
private:
    int mCenterX;
    int mCenterY;
    int mVieWidth;
    int mViewHeight;
    
    int mOffset;//绘制
};

#endif /* Camera_hpp */
