//
//  Card.cpp
//  QM2048
//
//  Created by strongsoft on 14-8-6.
//
//

#include "Card.h"

USING_NS_CC;

bool Card::init(){
    if (!Sprite::init()) {
        return false;
    }
    return true;
}
Card * Card::createCard(int number, float width ,float heigth, cocos2d::Point position){
    
    Card *card = new Card();
    
    if (card && card->init()) {
        card->autorelease();
        card->initCard(number, width, heigth, position);
        return card;
    }
    CC_SAFE_DELETE(card);
    
    return card;
}
int Card::getNumber(){
    return number;
}
void Card::setNumber(int num){
    
    number = num;
    
    
    //判断数字的大小来调整颜色
	if(number == 0){
		colorBg->setColor(Color3B(200,190,180));
	}
	if (number == 2) {
		colorBg->setColor(Color3B(240,230,220));
	}
	if (number == 4) {
		colorBg->setColor(Color3B(240,220,200));
	}
	if (number == 8) {
		colorBg->setColor(Color3B(240,180,120));
	}
	if (number == 16) {
		colorBg->setColor(Color3B(240,140,90));
	}
	if (number == 32) {
		colorBg->setColor(Color3B(240,120,90));
	}
	if (number == 64) {
		colorBg->setColor(Color3B(240,90,60));
	}
	if (number == 128) {
		colorBg->setColor(Color3B(240,90,60));
	}
	if (number == 256) {
		colorBg->setColor(Color3B(240,200,70));
	}
	if (number == 512) {
		colorBg->setColor(Color3B(240,200,70));
	}
	if (number == 1024) {
		colorBg->setColor(Color3B(0,130,0));
	}
	if (number == 2048) {
		colorBg->setColor(Color3B(0,130,0));
	}
}

void Card::initCard(int number, float width ,float heigth, cocos2d::Point position) {
    
    this->number = number;
    
    colorBg = LayerColor::create(Color4B(200, 190, 180, 255), width, heigth);
    colorBg->setPosition(position);
    
    if (number>0) {
        
        labelCardNumber = Label::createWithSystemFont(__String::createWithFormat("%i",number)->getCString(), "Consolas", 20);
        
    }else {
        
        labelCardNumber = Label::createWithSystemFont("", "Consolas", 20);
        
    }
    
    labelCardNumber->setPosition(colorBg->getContentSize().width/2.0, colorBg->getContentSize().height/2.0);
    
    colorBg->addChild(labelCardNumber);
    
    
    addChild(colorBg);
}


