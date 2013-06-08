//
//  SpriteHL.h
//  CrystaLua
//
//  Created by tuyuer wen on 13-6-5.
//
//  
//  提供lua与继承类之间的公共方法调用注册
#ifndef __CrystaLua__SpriteHL__
#define __CrystaLua__SpriteHL__

#include <iostream>
#include "cocos2d.h"

class SpriteHL:public cocos2d::CCSprite {
public:
    void setImageWithFileName(const char * pszFileName);
};

#endif /* defined(__CrystaLua__SpriteHL__) */
