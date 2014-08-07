//
//  GameScene.h
//  QM2048
//
//  Created by strongsoft on 14-8-6.
//
//

#ifndef __QM2048__GameScene__
#define __QM2048__GameScene__

#include <iostream>

#include "cocos2d.h"
#include "Card.h"

#include "SimpleGestures.h"

USING_NS_CC;

class GameScene: public cocos2d::Layer {
    
public:
    virtual bool init();
    static cocos2d::Scene * createScene();
    CREATE_FUNC(GameScene);
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    
private:
    void createCardSprite(cocos2d::Size size);
    void createCardNumber(bool animation);
    bool shouldCreateCardNumber();
    
    cocos2d::Point getPosition(int i, int j);
    
    bool doLeft();
    bool doRight();
    bool doUp();
    bool doDown();
    
    
private:
    
    void onPause(Ref* pSender);
    
    float cellSize = 0;
    float cellSpace = 10;
    
    int score ;
    
    cocos2d::Label * cardNumberTTF;
    
    Card * cardArr[4][4];
    
    SimpleRecognizer *recognizer;
};



#endif /* defined(__QM2048__GameScene__) */
