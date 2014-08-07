#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    
    cocos2d::Animation* createAnimation(std::string prefixName, int* pFramesOrder, int framesNum, float delay);
    
    cocos2d::Vector<cocos2d::Sprite *> molesVector;
    cocos2d::Animation * laughAnim;
    cocos2d::Animation * hitAnim;
    
    
    void tryPopMoles(float dt);
    void setTappable(Ref* pSender);
    void unsetTappable(Ref* pSender);
    void popMole(cocos2d::Sprite *mole);
    
    cocos2d::Label * scoreLabel;
    int score;
    
    
};

#endif // __HELLOWORLD_SCENE_H__
