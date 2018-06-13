//
//  Sprite.cpp
//  Paint
//
//  Created by panyi  on 2018/6/8.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <vector>
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <SDL2_image/SDL_image.h>

class IObj{
public:
    virtual void update() = 0;
    virtual void render(SDL_Renderer *render) = 0;
};

class Sprite : public IObj{
public:
    enum State{
        IDLE,JUMP,RUN,WALK
    };
    
public:
    State mState = IDLE;
    
    Sprite(){
        this->mState = IDLE;
        this->mImageIndex = 0;
    }
    
    void loadRes(SDL_Renderer *render);
    
    virtual void update();
    
    virtual void render(SDL_Renderer *render);
    
    void onDestory();
    
    void move(int dir);
    
    void stop();
    
private:
    std::vector<SDL_Texture *> mIdleImages;
    std::vector<SDL_Texture *> mIdleLeftImages;
    std::vector<SDL_Texture *> mWalkRightImages;
    std::vector<SDL_Texture *> mWalkLeftImages;
    
    int mImageIndex = 0;
    
    SDL_Rect mSrcRect;
    SDL_Rect mDstRect;
    int mDirection = 1;
    
    float dx;
    
    void freeImagesTexture(std::vector<SDL_Texture *> &imagesVector);
    
    void loadImageRes(SDL_Renderer *renderer , std::vector<std::string> &filenames ,
                      std::vector<SDL_Texture *> &images, bool flip);
};
#endif
