//
//  ClockBackgroundScene.h
//  Clock
//
//  Created by strongsoft on 14-8-5.
//
//

#ifndef __Clock__ClockBackgroundScene__
#define __Clock__ClockBackgroundScene__

#include <iostream>
#include "cocos2d.h"

#include "HourHand.h"

class ClockBackgroundScene : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(ClockBackgroundScene);
    
    void MutUpdate(float tim);
    
public:
    HourHand * m_hour;
    HourHand * m_minute;
    HourHand * m_second;
    
    
public:
    int nHour;
    int nMinute;
    int nSecond;
    
};



#endif /* defined(__Clock__ClockBackgroundScene__) */
