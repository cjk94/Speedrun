#include "Block.h"

#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>

Block::Block(SDL_Rect r, int b, bool m, float s, float t) : block_rect{r}, block_type{b}, moving{m}, speed{s}, time_period{t}
{
    //normal
    if(b==0){
        red = 130;
        green = 100;
        blue = 20;
    }else if(b==1){ //frictionless
        red = 180;
        green = 255;
        blue = 255;
    }else if(b==2){ //bouncy
        red = 255;
        green = 80;
        blue = 240;
    }else {         //win
        red = 100;
        green = 255;
        blue = 130;
    }

}

void Block::updatePosition()
{
    
    if(moving){
        time+=1;
        if(time >= time_period){
            speed*=-1;
            time = 0;
        }

        block_rect.x += speed;
    }
    

}
