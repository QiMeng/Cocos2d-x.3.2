#include "HelloWorldScene.h"
#include "AtlasLoader.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

//    Director::getInstance()->getTextureCache()->addImage("atlas.png");
    
    AtlasLoader::getInstance()->loadAtlas("atlas.txt", Director::getInstance()->getTextureCache()->addImage("atlas.png"));
    
    
    //创建背景
    
    time_t t = time(NULL);
    tm* lt = localtime(&t);
    int hour = lt->tm_hour;
    
    //create the background image according to the current time;
    Sprite *background;
    if(hour >= 6 && hour <= 17){
        background = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_day"));
    }else{
        background = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_night"));
    }
    
    background->setAnchorPoint(Point::ZERO);
//    background->setPosition(origin);
    this->addChild(background);
    
    
//    Sprite * bg = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bg_day"));
//    bg->setAnchorPoint(Point(0,1));
//    bg->setPosition(0, origin.y + visibleSize.height);
//    addChild(bg);
    
    Sprite * land0 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("land"));
    land0->setAnchorPoint(Point::ZERO);
    addChild(land0, 0, 100);
    Sprite * land1 = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("land"));
    land1->setAnchorPoint(Point::ZERO);
    addChild(land1,0,101);

    
    this->schedule(schedule_selector(HelloWorld::scrollLand), 0.1);
    
    //创建鸟
	Sprite *bird = Sprite::createWithSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bird0_0"));
	bird->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height/2));
    
	Animation *animation = Animation::create();
	animation->setDelayPerUnit(0.1f);
	animation->addSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bird0_1"));
	animation->addSpriteFrame(AtlasLoader::getInstance()->getSpriteFrameByName("bird0_2"));
	Animate *animate = Animate::create(animation);
	bird->runAction(RepeatForever::create(animate));
	this->addChild(bird);
    

    
    
    return true;
}

void HelloWorld::scrollLand(float dt) {
    
    Sprite * land0 = (Sprite *)this->getChildByTag(100);
    Sprite * land1 = (Sprite *)this->getChildByTag(101);
    land0 ->setPositionX(land0->getPositionX()-2.0f);
    land1->setPositionX(land0->getPositionX()+land0->getContentSize().width-2.0f);
    
    if (land1->getPositionX()==0) {
        land0->setPositionX(0);
    }
    
    
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
