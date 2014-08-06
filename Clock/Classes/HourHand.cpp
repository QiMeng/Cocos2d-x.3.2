//
//  HourHand.cpp
//  Clock
//
//  Created by strongsoft on 14-8-6.
//
//

#include "HourHand.h"

bool HourHand::init() {
    return true;
}

Sprite * HourHand::getSprite() {
    
    return this->m_sprite;
    
}


void HourHand::bindSprite(Sprite * sprite) {
    
    m_sprite = sprite;
    m_sprite->setAnchorPoint(Point(0,0.5));
    
    m_sprite->setScale(.2);
    m_sprite->setRotation(-90);
    
    this->addChild(m_sprite);
}
