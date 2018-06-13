// ============================================================================
// [Include Section]
// ============================================================================
#include "CApp.h"

// ============================================================================
// [Defines & Constants]
// ============================================================================
#define APPTITLE 		"SDL2 Template Program"

const int SCREEN_WIDTH 	= 1280;
const int SCREEN_HEIGHT	= 800;

CApp::CApp() :
	running(false)
{
}

CApp::~CApp()
{
	OnCleanup();
}

int CApp::OnInit(){
	// Initialize the SDL library.
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "SDL_Init() failed: %s\n", SDL_GetError());
		return APP_FAILED;
	}
    
    IMG_Init(IMG_INIT_PNG);
	
	window = SDL_CreateWindow(APPTITLE, 
							  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
							  SCREEN_WIDTH, SCREEN_HEIGHT, 
							  SDL_WINDOW_SHOWN);
    //SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    
	if (window != NULL) {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}
    
    mRunTexture = load_image(renderer, "idle_1.png");
    mSrc.x = mSrc.y = 0;
    SDL_QueryTexture(mRunTexture, nullptr, nullptr, &mSrc.w, &mSrc.h);
    
    std::cout << "w = " <<mSrc.w <<std::endl;
    std::cout << "h = " <<mSrc.h << std::endl;
    
    mDst.w = mSrc.w / 2;
    mDst.h = mSrc.h / 2;
    
    mDst.x = 100;
    mDst.y = SCREEN_HEIGHT - mDst.h;
    
    mSprite = new Sprite();
    mSprite->loadRes(renderer);
	return APP_OK;
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
    long delta = 0;
    mLastTime = SDL_GetTicks();
	while (running){
        while (SDL_PollEvent(&event)) {
            OnEvent(&event);
            std::cout << "handle input" <<std::endl;
        }
        
        //std::cout << "fuck" <<std::endl;
        
        delta = SDL_GetTicks() - mLastTime;
        mLastTime = SDL_GetTicks();
		
		OnUpdate(delta);
		OnRender(delta);
        
        SDL_Delay(30);
        //SDL_UpdateWindowSurface(window);
        //std::cout << "delta = " << delta <<std::endl;
	}//end while
	
	return state;
}

void CApp::OnEvent(SDL_Event* event)
{
	switch (event->type)
	{
		case SDL_QUIT:
			running = false;
			break;
			
		case SDL_KEYDOWN:
			if (event->key.keysym.sym == SDLK_ESCAPE) {
				running = false;
            }else if(event->key.keysym.sym == SDLK_RIGHT){
                mSprite->move(1);
            }else if(event->key.keysym.sym == SDLK_LEFT){
                mSprite->move(-1);
            }
            break;
        case SDL_KEYUP:
            mSprite->stop();
            break;
		default:
			break;
	}
}

void CApp::OnUpdate(long delta){
	// Update your game logic here
    if(mSprite != nullptr)
        mSprite->update();
}

void CApp::OnRender(long delta){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
	// Do your drawing here
    //SDL_Point p={0,0};
    //SDL_RenderCopyEx(renderer , mRunTexture , nullptr , nullptr , 180, &p,SDL_FLIP_NONE);
    
    SDL_RenderCopy(renderer, mRunTexture, &mSrc, &mDst);
    
    if(mSprite != nullptr)
        mSprite->render(renderer);
    
	SDL_RenderPresent(renderer);
    //SDL_UpdateWindowSurface(window);
}

void CApp::OnCleanup(){
    if(mSprite != nullptr)
        mSprite->onDestory();
    
    if(mRunTexture != nullptr)
        SDL_DestroyTexture(mRunTexture);
    
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr)    {
        SDL_DestroyWindow(window);
    }
    
    SDL_Quit();
    IMG_Quit();
}
