//
//  Player.cpp
//  Flyaway
//
//  Created by ph0ly on 15/9/4.
//
//

#include "Player.h"
#include "Bullet.h"
USING_NS_CC;

Player::Player() : state(State::STOP) {
}

Player* Player::create() {
    auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName("catBody1.png");
    
    auto player = new (std::nothrow) Player;
    if (player && spriteFrame && player->initWithSpriteFrame(spriteFrame))
    {
        player->autorelease();
        return player;
    }
    CC_SAFE_DELETE(player);
    return nullptr;
}

void Player::moveLeft(int step) {
    Vec2 pos = this->getPosition();
    this->setPosition(Vec2(pos.x-step, pos.y));
}

void Player::moveRight(int step) {
    Vec2 pos = this->getPosition();
    this->setPosition(Vec2(pos.x+step, pos.y));
}

void Player::moveUp(int step) {
    Vec2 pos = this->getPosition();
    this->setPosition(Vec2(pos.x, pos.y+step));
}

void Player::moveDown(int step) {
    Vec2 pos = this->getPosition();
    this->setPosition(Vec2(pos.x, pos.y-step));
}

void Player::stop() {
    this->stopAllActions();
    this->state = State::STOP;
}

void Player::shoot() {
    auto pos = this->getPosition();
    auto vSize = Director::getInstance()->getVisibleSize();
    auto bullet = Bullet::create();
    bullet->setAnchorPoint(Vec2());
    bullet->setPosition(Vec2(pos.x, pos.y+bullet->getContentSize().height));
    getParent()->addChild(bullet, -1);
    bullet->runAction(Sequence::create(MoveTo::create(1.0f, Vec2(pos.x, vSize.height)), DelayTime::create(2.0f), CallFunc::create([=]() {
        //bullet->release();
    }), NULL));
    
}


