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

class ClockBackgroundScene : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    CREATE_FUNC(ClockBackgroundScene);
    
};



#endif /* defined(__Clock__ClockBackgroundScene__) */
