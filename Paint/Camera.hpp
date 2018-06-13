//
//  Camera.hpp
//  Paint
//
//  Created by panyi  on 2018/6/11.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

class Camera{
public:
    Camera(int _viewWidth , int _viewHeight) : x(0) , y(0) , viewWidth(_viewWidth) ,
    viewHeight(_viewHeight){}
    
    void move(int _x , int _y){
        this->x = _x;
        this->y = _y;
    }
    
    int getX(){
        return x;
    }
    
    int getY(){
        return y;
    }
    
    int getViewWidth(){
        return this->viewWidth;
    }
    
    int getViewHeight(){
        return this->viewHeight;
    }
private:
    int x;
    int y;
    int viewWidth;
    int viewHeight;
};

#endif /* Camera_hpp */
