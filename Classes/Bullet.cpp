//
//  Bullet.cpp
//  Flyaway
//
//  Created by ph0ly on 15/9/4.
//
//

#include "Bullet.h"
USING_NS_CC;

Bullet::Bullet() : state(State::ALIVE) {}

Bullet* Bullet::create() {
    auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName("DrDogZD.png");
    
    auto bullet = new (std::nothrow) Bullet;
    //bullet->setPosition(pos);
    if (bullet && spriteFrame && bullet->initWithSpriteFrame(spriteFrame))
    {
        bullet->autorelease();
        return bullet;
    }
    CC_SAFE_DELETE(bullet);
    return nullptr;
}

void Bullet::dead() {
    this->state = State::DEAD;
    this->stopAllActions();
    this->setVisible(false);
}
