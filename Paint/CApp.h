// ============================================================================
// [Include Section]
// ============================================================================
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <SDL2_image/SDL_image.h>

#include <iostream>
#include <string>
#include "Sprite.h"

// ============================================================================
// [CApp]
// ============================================================================
// This is just a sample SDL application class to test that the app works.
class CApp
{
public:

	// Application state
	enum APP_STATE
	{
		APP_OK = 0,
		APP_FAILED = 1
	};

	CApp();
	~CApp();
	
	// Run application, called by your code.
	int 			OnExecute();
    
    SDL_Rect mSrc;
    SDL_Rect mDst;
    
    Sprite *mSprite;

private:
	
	// Whether the application is running.
	bool 			running;

	SDL_Window*	    	window;
	SDL_Renderer*    	renderer;
    //SDL_Surface*     mRunSurface;
    SDL_Texture*    mRunTexture;

	// Initialize application
	int 			OnInit();
	
	// Clean up the application
	void 			OnCleanup();

	// Called to process SDL event.
	void 			OnEvent(SDL_Event* event);

	// Called to update game logic
	void			OnUpdate(long delta);
	
	// Called to render the app.
	void 			OnRender(long delta);
public:
    long mLastTime;
    
    static SDL_Surface *load_png_image(std::string filename){
        if(filename.size() == 0)
            return nullptr;
        
        SDL_Surface *image = IMG_Load(filename.c_str());
        return image;
    }
    
    static SDL_Texture *load_image(SDL_Renderer *render , std::string filename){
        SDL_Surface *surface = load_png_image(filename);
        SDL_Texture *texture = nullptr;
        if(surface != nullptr){
            texture = SDL_CreateTextureFromSurface(render, surface);
            SDL_FreeSurface(surface);
        }
        
        return texture;
    }
};

//SDL_Surface *load_image(std::string filename){
//    if(filename.size() == 0)
//        return nullptr;
//
//    SDL_Surface *load_image = nullptr;
//    SDL_Surface *optimized_image = nullptr;
//
//    load_image = IMG_Load(filename.c_str());
//    if(load_image != nullptr){
//        //IMG_LoadBMP_RW(<#SDL_RWops *src#>)
//        //optimized_image = SDL_ConvertSurfaceFormat(<#SDL_Surface *src#>, <#Uint32 pixel_format#>, <#Uint32 flags#>);
//        SDL_FreeSurface(load_image);
//    }
//
//    return optimized_image;
//}







