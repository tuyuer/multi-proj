//
//  SceneGaming.cpp
//  CrystaLua
//
//  Created by tuyuer wen on 13-6-6.
//
//

#include "SceneGaming.h"
#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"
USING_NS_CC;

SceneGaming::SceneGaming(){
    arrayCrystals=CCArray::createWithCapacity(100);
    arrayCrystals->retain();
}

SceneGaming::~SceneGaming(){
    arrayCrystals->release();
}

CCScene * SceneGaming::scene(){
    CCScene * scene=CCScene::create();
    CCLayer * layer=new SceneGaming();
    layer->autorelease();
    scene->addChild(layer);
    return scene;
}

void SceneGaming::onEnter(){
    SceneHL::onEnter();
    //开启触摸
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority, true);
    this->setTouchEnabled(true);
    
    
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("SceneGaming.lua");
    pEngine->executeScriptFile(path.c_str());
    
    pEngine->getLuaStack()->pushCCObject(this, "CCNode");
    pEngine->executeGlobalFunction("setRoot",1);
    
    pEngine->getLuaStack()->pushCCObject(arrayCrystals, "CCArray");
    pEngine->executeGlobalFunction("initCrystals",1);
}

void SceneGaming::onEnterTransitionDidFinish(){
    SceneHL::onEnterTransitionDidFinish();
    this->initUI();
}

void SceneGaming::initUI(){
    //添加内容节点
    nodeContent=CCNode::create();
    this->addChild(nodeContent);
    
    //添加网格节点
    nodeSquares=CCNode::create();
    this->addChild(nodeSquares);
    //初始化界面
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    
    //加载关卡
    pEngine->getLuaStack()->pushCCObject(arrayCrystals, "CCArray");
    pEngine->getLuaStack()->pushCCObject(nodeSquares, "CCNode");
    pEngine->getLuaStack()->pushCCObject(nodeContent, "CCNode");
    pEngine->getLuaStack()->pushInt(1);
    pEngine->executeGlobalFunction("loadLevel", 4);
}

void SceneGaming::update(float delta){
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    pEngine->getLuaStack()->pushFloat(delta);
    pEngine->executeGlobalFunction("update",1);
}

bool SceneGaming::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    pEngine->getLuaStack()->pushCCObject(pTouch, "CCTouch");
    pEngine->executeGlobalFunction("touchBegin",1);
    return true;
}
void SceneGaming::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    pEngine->getLuaStack()->pushCCObject(pTouch, "CCTouch");
    pEngine->executeGlobalFunction("touchMove",1);
}
void SceneGaming::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    pEngine->getLuaStack()->pushCCObject(pTouch, "CCTouch");
    pEngine->executeGlobalFunction("touchEnded",1);
}
void SceneGaming::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){

}





