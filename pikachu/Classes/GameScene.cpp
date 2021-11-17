

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include"HelloWorldScene.h"
#include"boardView.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    auto scene = Scene::create();

    auto layer = GameScene::create();

    scene->addChild(layer);
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto back = MenuItemImage::create("back1.png", "back2.png", CC_CALLBACK_1(GameScene::back, this));
    auto menu = Menu::create(back, NULL);
    menu->setPosition(Vec2( 20.f,750.f ));
    this->addChild(menu);


    showBoard();

    return true;
}

void GameScene::back(Ref* pSender)
{
    auto homeScene = HelloWorld::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1, homeScene, Color3B(0, 255, 255)));
}

Layer* GameScene::showBoard()
{
    std::vector<int> count(21, 4);
    Board* board = new Board(7, 12, 21, count);
    auto boardView = BoardView::createBoardView(board);
    this->addChild(boardView, 1);
    float x = (Director::getInstance()->getVisibleSize().width - boardView->getContentSize().width) / 2;
    float y = (Director::getInstance()->getVisibleSize().height - boardView->getContentSize().height) / 2;
    boardView->setPosition({ x, y });
    return boardView;
}

