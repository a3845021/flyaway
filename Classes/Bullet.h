//
//  Bullet.h
//  Flyaway
//
//  Created by ph0ly on 15/9/4.
//
//

#ifndef __Flyaway__Bullet__
#define __Flyaway__Bullet__

#include "cocos2d.h"

class Bullet : public cocos2d::Sprite {
public:
    
    Bullet();
    
    typedef enum {
        DEAD,
        ALIVE
    } State;
    
    static Bullet* create();
    
    bool isAlive() {
        return this->state == State::ALIVE;
    }
    
    void dead();
    
private:
    State state;
};

#endif /* defined(__Flyaway__Bullet__) */
