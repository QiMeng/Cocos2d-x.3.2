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
    
    //时针
    m_hour = HourHand::create();
    m_hour->bindSprite(Sprite::create("shi.png"));
    m_hour->setPosition(winSize.width/2.0, winSize.height/2.0);
    this->addChild(m_hour);
    
    //分针
    m_minute = HourHand::create();
    m_minute->bindSprite(Sprite::create("fen.png"));
    m_minute->setPosition(winSize.width/2.0, winSize.height/2.0);
    this->addChild(m_minute);
    
    //秒针
    m_second = HourHand::create();
    m_second->bindSprite(Sprite::create("miao.png"));
    m_second->setPosition(winSize.width/2.0, winSize.height/2.0);
    this->addChild(m_second);
    
    
    struct timeval now;
    gettimeofday(&now,NULL);
    struct tm *tm;
    tm = localtime(&now.tv_sec);
    
    nHour = tm->tm_hour;
    nMinute = tm->tm_min;
    nSecond = tm->tm_sec;
    
    this->MutUpdate(0);
    
    this->schedule(schedule_selector(ClockBackgroundScene::MutUpdate), 1.0f);
//    this->schedule(schedule_selector(ClockBackgroundScene::MutUpdate),1);
    
    return true;
}

void ClockBackgroundScene::MutUpdate(float tim) {
    
    static int mRotation=nMinute*6;  //分针初始角度
    static int sRotation=nSecond*6;  //秒针初始角度
    
    static int hRotatio;            /*小时的计数不同于分和秒，分和秒一个周期都是60，而小时数在一天之中是从1-24，我们需要将获取到的时间先转换
                                     成12时制，再将其按照比例变成60为周期的数，即给当前小时*5 */
    if(nHour>12){                     //当 当前时间大于上午12点时
        hRotatio=(nHour-12)*5*6+(mRotation/72)*6;   /*将其转换成12时制 并*5变成以60为周期的数，因为60对应360度，所以应换算成度数应再*6，
                                                     换算完成后还应该加上分针走过的偏转角，由于分针走360度，时针走30度，所以分针每走72度时针走6度*,故用分针旋转角除以72后再乘以6 */
    }
    else{                             //当前时间小于或等于12点
        hRotatio=(nHour)*5*6+(mRotation/72)*6;
    }
    
    m_second->setRotation(sRotation);  //重新设置秒针的位置，另其角度顺时针旋转6度，即走一秒钟
    m_minute->setRotation(mRotation);  //重置分针位置
    m_hour->setRotation(hRotatio);     //重置时针位置
    if(sRotation>=360){                //当秒针走了一圈（360度）时
        sRotation=0;                   //秒针旋转角归零
        mRotation+=6;                  //分针转6度，即走了一分钟
        m_minute->setRotation(mRotation); //重置分针指针位置
        if(mRotation%72==0){                 //每当分针转到72的倍数时
            hRotatio+=6;                     //时针转六度
            m_hour->setRotation(hRotatio);   //重置时针位置
            if(mRotation>=360){              //当分针转了一圈时
                mRotation=0;                 //分针旋转角归零
            }
        }
    }
    sRotation+=6;
    
    
}
