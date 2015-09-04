//
//  GameScene.cpp
//  Flyaway
//
//  Created by ph0ly on 15/9/4.
//
//

#include "GameScene.h"
#include "Player.h"
USING_NS_CC;

bool GameScene::init() {
    auto vSize = Director::getInstance()->getVisibleSize();
    auto galaxy = ParticleRain::create();
    galaxy->setPosition(Vec2(vSize.width/2, vSize.height));
    galaxy->setEmissionRate(60.0f);
    galaxy->setSpeed(300.0f);
    this->addChild(galaxy);
    
    auto player = Player::create();
    player->setAnchorPoint(Vec2(0.5, 0));
    player->setPosition(Vec2(vSize.width/2, 0));
    this->addChild(player);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    auto keybdListener = EventListenerKeyboard::create();
    
    touchListener->onTouchBegan = [=](Touch* t, Event* e) {
        
        return true;
    };
    
    touchListener->onTouchEnded = [=](Touch* t, Event* e) {
        player->stop();
    };
    
    keybdListener->onKeyPressed = [=](EventKeyboard::KeyCode code, Event* e) {
        Player::State state = Player::State::STOP;
        switch (code) {
            case cocos2d::EventKeyboard::KeyCode::KEY_A:
                state = Player::State::LEFT;
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_D:
                state = Player::State::RIGHT;
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_W:
                state = Player::State::UP;
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_S:
                state = Player::State::DOWN;
                break;
            case cocos2d::EventKeyboard::KeyCode::KEY_J:
                state = Player::State::SHOOT;
                break;
            default:
                break;
        }
        player->setState(state);
    };
    
    keybdListener->onKeyReleased = [=](EventKeyboard::KeyCode code, Event* e) {
        player->setState(Player::State::STOP);
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keybdListener, this);
    
    this->schedule([=](float dt) {
        Player::State state = player->getState();
        switch (state) {
            case Player::State::LEFT:
                player->moveLeft();
                break;
            case Player::State::RIGHT:
                player->moveRight();
                break;
            case Player::State::UP:
                player->moveUp();
                break;
            case Player::State::DOWN:
                player->moveDown();
                break;
            case Player::State::SHOOT:
                player->shoot();
                break;
            default:
                break;
        }
        
    }, 0.01f, "timer");
    
    return true;
}

