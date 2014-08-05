//
//  ClockBackgroundScene.cpp
//  Clock
//
//  Created by strongsoft on 14-8-5.
//
//

#include "ClockBackgroundScene.h"

USING_NS_CC;

Scene * ClockBackgroundScene:: createScene()
{
    auto scene = Scene::create();
    
    auto layer = ClockBackgroundScene::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool ClockBackgroundScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    Size winSize = Director::getInstance()->getWinSize();
    Sprite * clockBk = Sprite::create("background.jpg");
    clockBk->setPosition(winSize.width/2.0, winSize.height/2.0);
    clockBk->setScale(.5);
    this->addChild(clockBk);
    
    return true;
}


