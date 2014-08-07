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
    
    
    recognizer = new SimpleRecognizer();
    
    auto listener = EventListenerTouchOneByOne::create();

    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    //创建4*4 卡片
    createCardSprite(visibleSize);
    
    createCardNumber(true);
    createCardNumber(true);
    
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
                cardArr[i][j]->runNewNumberAction();
            }
            break;
        }
        
        if (!shouldCreateCardNumber()) {
            break;
        }
    }
}

bool GameScene::shouldCreateCardNumber() {
    
    bool isCreate = false;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (cardArr[i][j]->getNumber() == 0) {
                isCreate = true;
                break;
            }
        }
    }
    
    return isCreate;
}


bool GameScene::onTouchBegan(Touch *touch, Event *unused_event){
    
    Point pos = touch->getLocation();
    recognizer->beginPoint(pos);
    
    return true;
}
void GameScene::onTouchMoved(Touch *touch, Event *unused_event){
    Point pos = touch->getLocation();
    recognizer->movePoint(pos);

}

void GameScene::onTouchEnded(Touch *touch, Event *unused_event){
    Point pos = touch->getLocation();
    SimpleGestures gesture = recognizer->endPoint(pos);
    
    switch (gesture) {
        case SimpleGesturesLeft:
            doLeft();
            log("left");
            break;
        case SimpleGesturesRight:
            doRight();
            log("right");
            break;
        case SimpleGesturesUp:
            doUp();
            log("up");
            break;
        case SimpleGesturesDown:
            doDown();
            log("dowm");
            break;
            
        default:
            break;
    }
    
    createCardNumber(true);
    
}

bool GameScene::doLeft(){

    //判断有没有发生移动
    bool isMove = false;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            for (int x1 = x+1; x1<4; x1++)
            {
                if (cardArr[x1][y]->getNumber() > 0)
                {
                    if (cardArr[x][y]->getNumber() <= 0)
                    {
                        cardArr[x][y]->setNumber(cardArr[x1][y]->getNumber());
                        cardArr[x1][y]->setNumber(0);
                        x--;
                        isMove = true;
                    }
                    else if(cardArr[x][y]->getNumber() == cardArr[x1][y]->getNumber())
                    {
                        cardArr[x][y]->setNumber(cardArr[x][y]->getNumber() * 2);
                        cardArr[x1][y]->setNumber(0);
                        
                        //改变分数
                        score += cardArr[x][y]->getNumber();
                        isMove = true;
                    }
                    break;
                }
            }
        }
    }
    
    return isMove;
}
bool GameScene::doRight(){
    bool isMove = false;
    
    return isMove;
}
bool GameScene::doUp(){
    bool isMove = false;
    
    return isMove;
}
bool GameScene::doDown(){
    bool isMove = false;
    
    return isMove;
}




