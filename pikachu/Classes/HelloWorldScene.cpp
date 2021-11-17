

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include"GameScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto background = Sprite::create("image_text_pikachu.png");
    background->setAnchorPoint(Vec2(0, 0));
    background->setPosition(Vec2(0,0));
    background->setScale(1.15);
    addChild(background);
    auto play = MenuItemLabel::create(Label::createWithTTF("PLAY", "fonts/Marker Felt.ttf",40), CC_CALLBACK_1(HelloWorld::play, this));
    
    auto menu = Menu::create(play, NULL);
    menu->setPosition(Vec2(visibleSize * 0.5));
    
    addChild(menu);

    return true;
}

void HelloWorld::play(Ref* pSender)
{
    auto gameScene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1,gameScene,Color3B(0,255,255)));
}

