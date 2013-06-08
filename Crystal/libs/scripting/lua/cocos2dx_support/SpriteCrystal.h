//
//  SpriteCrystal.h
//  CrystaLua
//
//  Created by tuyuer wen on 13-6-6.
//
//

#ifndef __CrystaLua__SpriteCrystal__
#define __CrystaLua__SpriteCrystal__

#include <iostream>
#include "SpriteHL.h"

class SpriteCrystal:public SpriteHL{
private:
    //crystal coordinate
    cocos2d::CCPoint m_coordinate;
    //crystal type
    int m_type;
public:
          
public:
    SpriteCrystal();
    
    //need regist to lua
    static SpriteCrystal* create();
    void reset();
    
    
    cocos2d::CCPoint getCoordinate();
    void setCoordinate(cocos2d::CCPoint ptCoordinate);
    int getType();
    void setType(int crastalType);
    
    //for transition
    virtual void onEnter();
    virtual void onExit();
 
};

#endif /* defined(__CrystaLua__SpriteCrystal__) */
