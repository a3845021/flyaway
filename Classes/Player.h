//
//  Player.h
//  Flyaway
//
//  Created by ph0ly on 15/9/4.
//
//

#ifndef __Flyaway__Player__
#define __Flyaway__Player__
#include "cocos2d.h"

class Player : public cocos2d::Sprite {
public:
    Player();
    
    static Player* create();
    
    typedef enum State {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        STOP,
        SHOOT
    } State;
    
    int getScore() {
        return this->score;
    }
    
    void setScore(int newScore) {
        this->score = newScore;
    }
    
    State getState() {
        return this->state;
    }
    
    void setState(State state) {
        this->state = state;
    }
    
    void stop();
    void moveLeft(int step = 5);
    void moveRight(int step = 5);
    void moveUp(int step = 5);
    void moveDown(int step = 5);
    void shoot();
    
private:
    
    int score;
    
    State state;
    
};

#endif /* defined(__Flyaway__Player__) */
