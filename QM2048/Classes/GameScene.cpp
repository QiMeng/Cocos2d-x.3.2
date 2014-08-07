//
//  GameScene.cpp
//  QM2048
//
//  Created by strongsoft on 14-8-6.
//
//

#include "GameScene.h"


Scene * GameScene::createScene() {
    
    auto scene = Scene::create();
    
    auto layer = GameScene::create();
    
    scene->addChild(layer);
    
    return scene;
    
}

bool GameScene::init() {
    
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    //游戏背景
    auto layerBg = LayerColor::create(Color4B(180, 170, 160, 255));
    this->addChild(layerBg);
    
    //暂停按钮
    MenuItemFont::setFontName("Consolas");
    MenuItemFont::setFontSize(20);
    auto menuItemPause = MenuItemFont::create("PAUSE", CC_CALLBACK_1(GameScene::onPause, this));
    
    auto menu = Menu::create(menuItemPause, NULL);
    addChild(menu);
    menu->setPosition(visibleSize.width - 50, visibleSize.height - 20);
    
    //分数
    auto cardNumberTitle = Label::createWithSystemFont("SCORE", "Consolas", 20);
    cardNumberTitle->setPosition(visibleSize.width - 50, visibleSize.height-100);
    addChild(cardNumberTitle);
    
    score = 0;
    cardNumberTTF = Label::createWithSystemFont("0", "Consolas", 20);
    cardNumberTTF->setPosition(visibleSize.width - 50, visibleSize.height - 150);
    addChild(cardNumberTTF);
    
    createCardSprite(visibleSize);
    
    createCardNumber(false);
    createCardNumber(false);
    
    return true;
}

#pragma mark - 暂停
void GameScene::onPause(Ref* pSender){
    
}


//根据屏幕大小创建卡片
void GameScene::createCardSprite(Size size)
{
    //求出单元格的宽和高
    //左右边距 cellSpace
    cellSize = (size.width - 3*cellSpace -20)/4.0;
    
    
    //绘制出4X4的单元格
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            //需要屏幕分辨率适配
            Card *card = Card::createCard(0, cellSize, cellSize, getPosition(i, j));
            cardArr[i][j] = card;
            addChild(card);
        }
    }
}
Point GameScene::getPosition(int i, int j)
{
    float pX = 10 + i*(cellSize+cellSpace);
    float pY = 10 + j*(cellSize+cellSpace);
    
    return Point(pX,pY);
}

//创建生成随机卡片
void GameScene::createCardNumber(bool animation)
{
    
    while (1) {
        int i = CCRANDOM_0_1() * 4;        //生成0~3随机数
        int j = CCRANDOM_0_1() * 4;
        
        log("[%d][%d]",i,j);
        
        if (cardArr[i][j]->getNumber() == 0)
        {
            //2和4的生成率为9:1
            cardArr[i][j]->setNumber(CCRANDOM_0_1()*10 < 1 ? 4 : 2);
            if(animation)
            {
//                cardArr[i][j]->runNewNumberAction();
            }
            break;
        }
        
//        if (!shouldCreateCardNumber()) {
//            break;
//        }
    }
}






