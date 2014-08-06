//
//  HourHand.h
//  Clock
//
//  Created by strongsoft on 14-8-6.
//
//

#ifndef __Clock__HourHand__
#define __Clock__HourHand__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;
class HourHand : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(HourHand);
    Sprite * getSprite();
    void bindSprite(Sprite * sprite);
    
private:
    Sprite * m_sprite;
    
    
};
#endif /* defined(__Clock__HourHand__) */
