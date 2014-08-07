//
//  Card.h
//  QM2048
//
//  Created by strongsoft on 14-8-6.
//
//

#ifndef __QM2048__Card__
#define __QM2048__Card__

#include <iostream>
#include "cocos2d.h"

class Card : public cocos2d::Sprite
{
public:
    virtual bool init();
    static Card * createCard(int number, float width ,float heigth, cocos2d::Point position);
    int getNumber();
    void setNumber(int num);
    
private:
    void initCard(int number, float width ,float heigth, cocos2d::Point position);
    
    
    
private:
    int number;
    //背景
    cocos2d::LayerColor * colorBg;
    //数字控件
    cocos2d::Label * labelCardNumber;
    
    
};


#endif /* defined(__QM2048__Card__) */
