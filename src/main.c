#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <math.h>
#include <string.h>

#include <SDL3/SDL.h>

#include "../include/base.h"
#include "../include/matrix.h"

#define windowWidth 640
#define windowHeight 480

bool running = true;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void quit(void){
    // destroy everything
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void input_handler(void){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if (event.type == SDL_EVENT_QUIT){
            quit();
            running = false;
        }
    }
}

int renderGraph(char* equation);

int main(void){
    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("[ERROR] Could not initialize SDL_INIT_VIDEO: %s", SDL_GetError());
        return 1;
    }
    if (!SDL_Init(SDL_INIT_EVENTS)){
        SDL_Log("[ERROR] Could not initialize SDL_INIT_EVENTS: %s", SDL_GetError());
        return 1;
    }

    if (!SDL_CreateWindowAndRenderer("graphy", windowWidth, windowHeight, SDL_WINDOW_MOUSE_FOCUS, &window, &renderer)){
        SDL_Log("[ERROR] Could not create window context: %s", SDL_GetError());
        return 1;
    }else SDL_Log("[INFO] Sucessfully created window context");

    if (!SDL_SetRenderVSync(renderer, 1)){
        SDL_Log("[WARNING] Could not enable vsync: %s", SDL_GetError());
    }
    while(running){
        input_handler();
    }
    return 0;
}
