// ============================================================================
// [Include Section]
// ============================================================================
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <SDL2_image/SDL_image.h>
#include <string>
#include <iostream>
#include "Config.h"
#include "Camera.hpp"
#include "Map.hpp"

// ============================================================================
// [Defines & Constants]
// ============================================================================


// ============================================================================
// [CApp]
// ============================================================================
// This is just a sample SDL application class to test that the app works.
class CApp{
    
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


private:
	
	// Whether the application is running.
	bool running;

	SDL_Window *window;
	SDL_Renderer *renderer;
    
    Camera *mCamera;
    Map *mMap;
    

	// Initialize application
	int OnInit();
	
	// Clean up the application
	void OnCleanup();

	// Called to process SDL event.
	void OnEvent(SDL_Event* event);

	// Called to update game logic
	void OnUpdate();
	
	// Called to render the app.
	void OnRender();
    
};
