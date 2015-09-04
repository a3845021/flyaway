//
//  IntroScene.cpp
//  Flyaway
//
//  Created by ph0ly on 15/9/4.
//
//

#include "IntroScene.h"
#include "MenuScene.h"
USING_NS_CC;

bool IntroScene::init() {
    auto size = Director::getInstance()->getVisibleSize();
    
    auto cache = SpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("menu.plist");
    cache->addSpriteFramesWithFile("background.plist");
    cache->addSpriteFramesWithFile("scene.plist");
    auto logoFrame = cache->getSpriteFrameByName("cat.png");
    auto logoSprite = Sprite::createWithSpriteFrame(logoFrame);
    logoSprite->setPosition(size.width/2, (size.height+logoSprite->getPosition().y/2)/2);

    auto fire = ParticleFire::create();
    fire->setEmitterMode(ParticleSystem::Mode::GRAVITY);
    fire->setPosition(size.width/2, (size.height)/2);
    
    this->addChild(logoSprite);
    this->addChild(fire);
    
    this->scheduleOnce([=](float t) {
        Director::getInstance()->replaceScene(TransitionSlideInT::create(1.0f, MenuScene::create()));
    }, 2, "intro scene");
    
    return true;
}
