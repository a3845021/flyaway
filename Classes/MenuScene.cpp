//
//  MenuScene.cpp
//  Flyaway
//
//  Created by ph0ly on 15/9/4.
//
//

#include "MenuScene.h"
#include "GameScene.h"
USING_NS_CC;

bool MenuScene::init() {
    auto vSize = Director::getInstance()->getVisibleSize();
    
    auto cache = SpriteFrameCache::getInstance();
    auto bgFrame = cache->getSpriteFrameByName("bg.png");
    
    auto bgSprite = Sprite::createWithSpriteFrame(bgFrame);
    bgSprite->setAnchorPoint(Vec2());
    
    this->addChild(bgSprite);
    
    auto menu = Menu::create();
    auto newGame = MenuItemSprite::create(Sprite::createWithSpriteFrameName("newgameA.png"), Sprite::createWithSpriteFrameName("newgameB.png"), [](Ref* ref) {
        auto gameScene = GameScene::create();
        Director::getInstance()->replaceScene(TransitionZoomFlipX::create(1.0f, gameScene));
    });
    menu->addChild(newGame);
    
    auto about = MenuItemSprite::create(Sprite::createWithSpriteFrameName("aboutA.png"), Sprite::createWithSpriteFrameName("aboutB.png"), [](Ref* ref) {
    });
    about->setPosition(Vec2(0, -newGame->getContentSize().height-10));
    menu->addChild(about);
    
    menu->setPosition(Vec2(vSize.width/2, vSize.height/2+newGame->getContentSize().height));
    this->addChild(menu);
    
    return true;
}
