//
//  SpriteCrystal.cpp
//  CrystaLua
//
//  Created by tuyuer wen on 13-6-6.
//
//

#include "SpriteCrystal.h"
#include "TouchPriorities.h"
USING_NS_CC;

SpriteCrystal::SpriteCrystal(){
    this->reset();
    this->setVisible(false);
}

SpriteCrystal* SpriteCrystal::create()
{
    SpriteCrystal *pSprite = new SpriteCrystal();
    if (pSprite && pSprite->init())
    {
        pSprite->autorelease();
        return pSprite;
    }
    CC_SAFE_DELETE(pSprite);
    return NULL;
}

void SpriteCrystal::onEnter(){
    SpriteHL::onEnter();
}

void SpriteCrystal::onExit(){
    SpriteHL::onExit();
}

void SpriteCrystal::reset(){
    m_coordinate=ccp(-1,-1);
    m_type=0;
    this->setVisible(true);
}

CCPoint SpriteCrystal::getCoordinate(){
    return m_coordinate;
}

int SpriteCrystal::getType(){
    return m_type;
}

void SpriteCrystal::setCoordinate(cocos2d::CCPoint ptCoordinate){
    m_coordinate=ptCoordinate;
}

void SpriteCrystal::setType(int crastalType){
    m_type=crastalType;
}





