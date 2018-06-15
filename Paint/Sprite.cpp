//
//  Sprite.cpp
//  Paint
//
//  Created by panyi  on 2018/6/8.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//
#include "CApp.h"
#include "Sprite.h"

#include <iostream>

void Sprite::loadRes(SDL_Renderer *render){
//    SDL_Texture *texture = CApp::load_image(render , "Idle_1.png");
//
//    mIdleImages.push_back(CApp::load_image(render , "Idle_1.png"));
//    mIdleImages.push_back(CApp::load_image(render , "Idle_2.png"));
//    mIdleImages.push_back(CApp::load_image(render , "Idle_3.png"));
//    mIdleImages.push_back(CApp::load_image(render , "Idle_4.png"));
//    mIdleImages.push_back(CApp::load_image(render , "Idle_5.png"));
//    mIdleImages.push_back(CApp::load_image(render , "Idle_6.png"));
//    mIdleImages.push_back(CApp::load_image(render , "Idle_7.png"));
//    mIdleImages.push_back(CApp::load_image(render , "Idle_8.png"));
//    mIdleImages.push_back(CApp::load_image(render , "Idle_9.png"));
//    mIdleImages.push_back(CApp::load_image(render , "Idle_10.png"));
    
    std::vector<std::string> file_list = {"Idle_1.png" , "Idle_2.png" , "Idle_3.png" ,"Idle_4.png", "Idle_5.png",
        "Idle_6.png" , "Idle_7.png" , "Idle_8.png" ,"Idle_9.png", "Idle_10.png"
    };
    loadImageRes(render , file_list ,  mIdleImages , true);
    
    std::vector<std::string> file_list2 = {"walk_1.png" , "walk_2.png" , "walk_3.png" ,"walk_4.png", "walk_5.png",
        "walk_6.png" , "walk_7.png" , "walk_8.png" ,"walk_9.png", "walk_10.png"
    };
    loadImageRes(render , file_list2 ,  mWalkRightImages , true);
    
    
    std::cout << "load res image for " <<mIdleImages.size() << std::endl;
    
    int src_w;
    int src_h;
    SDL_QueryTexture(mIdleImages[0], nullptr, nullptr, &src_w, &src_h);
    std::cout << "image w = " << src_w << " h = " << src_h << std::endl;
    
    mSrcRect.x = 0;
    mSrcRect.y = 0;
    mSrcRect.w = src_w;
    mSrcRect.h = src_h;
    
    mDstRect.x = 0;
    mDstRect.y = 0;
    mDstRect.w = mSrcRect.w / 2;
    mDstRect.h = mSrcRect.h / 2;
}

void Sprite::update(){
    mImageIndex++;
    
    switch(mState){
        case IDLE:
            if(mImageIndex >= mIdleImages.size())
                mImageIndex = 0;
            break;
        case WALK:
            if(mImageIndex >= mIdleImages.size())
                mImageIndex = 0;
            mDstRect.x += dx;
            break;
        default:
            break;
    }//end switch
    //mDstRect.x += 5;

}

void  Sprite::render(SDL_Renderer *render){
    
    switch(mState){
        case IDLE:
            if(mDirection >= 0){
                SDL_RenderCopy(render, mIdleImages[mImageIndex], &mSrcRect, &mDstRect);
            }else{
                 SDL_RenderCopy(render, mIdleImages[mImageIndex], &mSrcRect, &mDstRect);
            }
            break;
        case WALK:
            if(mDirection >= 0){
                 SDL_RenderCopy(render, mWalkRightImages[mImageIndex], &mSrcRect, &mDstRect);
            }else{
                 SDL_RenderCopy(render, mIdleImages[mImageIndex], &mSrcRect, &mDstRect);
            }
            break;
        default:
            break;
    }//end switch
    
    //debug
    
    SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
    SDL_RenderDrawRect(render, &mDstRect);
}

void Sprite::move(int dir){
    if(mState == WALK)
        return;
    
    if(dir > 0){//move right
        //std::cout << "move right" <<std::endl;
        this->dx = 10;
        this->mDirection = 1;
    }else{
        //std::cout << "move left" <<std::endl;
        this->dx = -10;
        this->mDirection = -1;
    }
    
    this->mState = WALK;
}

void Sprite::stop(){
    if(mState == IDLE)
        return;
    
    this->mState = IDLE;
    this->mImageIndex = 0;
    std::cout << "move stop" <<std::endl;
}

void  Sprite::onDestory(){
    freeImagesTexture(mIdleImages);
    freeImagesTexture(mIdleLeftImages);
    freeImagesTexture(mWalkLeftImages);
    freeImagesTexture(mWalkRightImages);
}

void Sprite::freeImagesTexture(std::vector<SDL_Texture *> &imagesVector){
    for(SDL_Texture *texture : imagesVector){
        //std::cout << "free for " << imagesVector.size() << std::endl;
        SDL_DestroyTexture(texture);
    }
    imagesVector.clear();
}

void Sprite::loadImageRes(SDL_Renderer *renderer , std::vector<std::string> &filenames ,
                          std::vector<SDL_Texture *> &images , bool flip){
    images.clear();
    for(std::string filename : filenames){
        SDL_Texture *texture = CApp::load_image(renderer , filename);
        if(texture == nullptr)
            continue;
        
        if(flip){
            
            SDL_Rect rect;
            rect.x = rect.y = 0;
            SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
            
            SDL_Point p;
            p.x = rect.w / 2;
            p.y = rect.h / 2;
            
            int success = SDL_RenderCopyEx(renderer, texture, nullptr, &rect, 180, &p, SDL_FLIP_HORIZONTAL);
            std::cout << "flip success " << success << std::endl;
        }
        images.push_back(texture);
    }//end for each
}





