// ============================================================================
// [Include Section]
// ============================================================================
#include "CApp.h"



CApp::CApp() :
	running(false){
}

CApp::~CApp()
{
	OnCleanup();
}

int CApp::OnInit()
{
	// Initialize the SDL library.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "SDL_Init() failed: %s\n", SDL_GetError());
		return APP_FAILED;
	}
	
	window = SDL_CreateWindow(APPTITLE, 
							  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
							  SCREEN_WIDTH, SCREEN_HEIGHT, 
							  SDL_WINDOW_SHOWN);

	if (window != NULL) {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}
    
    
    mCamera = new Camera(SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2);
	mMap = new Map(mCamera , renderer);
	// Success
	return APP_OK;
}

void CApp::OnCleanup(){
    if(mMap != nullptr){
        delete mMap;
    }
    
    if(mCamera != nullptr){
        delete mCamera;
    }
    
	if (renderer != nullptr) {
		SDL_DestroyRenderer(renderer);	
	}
	if (window != nullptr)	{
		SDL_DestroyWindow(window);
	}

	SDL_Quit();
}

int CApp::OnExecute()
{
	// Initialize application.
	int state = OnInit();
	if (state != APP_OK) {
		return state;
	}
	
	// Enter the SDL event loop.
	SDL_Event event;

	running = true;
	
	while (running)
	{
		while (SDL_PollEvent(&event)) {
        	OnEvent(&event);
        }
		
		OnUpdate();
		OnRender();
	}
	
	return state;
}

void CApp::OnEvent(SDL_Event* event){
	switch (event->type)
	{
		case SDL_QUIT:
			running = false;
			break;
			
		case SDL_KEYDOWN:
            /**
             SDLK_RIGHT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT),
             SDLK_LEFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT),
             SDLK_DOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN),
             SDLK_UP
             */
            switch(event->key.keysym.sym){
                case SDLK_ESCAPE:
                    running = false;
                    break;
                case SDLK_LEFT:
                    mCamera->moveToLeft();
                    break;
                case SDLK_RIGHT:
                    mCamera->moveToRight();
                    break;
            }//end switch
		default:
			break;
	}
}

void CApp::OnUpdate(){
	// Update your game logic here
    mMap->update();
}

void CApp::OnRender(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	// Do your drawing here
    mMap->render(renderer);
	
	SDL_RenderPresent(renderer);
}
