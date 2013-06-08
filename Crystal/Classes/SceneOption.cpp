//
//  SceneOption.cpp
//  CrystaLua
//
//  Created by tuyuer wen on 13-6-5.
//
//

#include "SceneOption.h"
#include "script_support/CCScriptSupport.h"
#include "CCLuaEngine.h"

USING_NS_CC;

CCScene * SceneOption::scene(){
    CCScene * scene=CCScene::create();
    CCLayer * layer=new SceneOption();
    layer->autorelease();
    scene->addChild(layer);
    return scene;
}

void SceneOption::initUI(){
    CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
    std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("SceneOption.lua");
    pEngine->executeScriptFile(path.c_str());
    CCNode * nodeContent=CCNode::create();
    this->addChild(nodeContent);
    
    pEngine->getLuaStack()->pushCCObject(nodeContent, "CCNode");
    pEngine->executeGlobalFunction("loadUI",1);
}

void SceneOption::onEnterTransitionDidFinish(){
    SceneHL::onEnterTransitionDidFinish();
    this->initUI();
}