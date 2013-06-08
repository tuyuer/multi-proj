//
//  SceneGaming.h
//  CrystaLua
//
//  Created by tuyuer wen on 13-6-6.
//
//

#ifndef __CrystaLua__SceneGaming__
#define __CrystaLua__SceneGaming__

#include <iostream>
#include "SceneHL.h"

class SceneGaming:public SceneHL {
private:
    cocos2d::CCArray * arrayCrystals;
    cocos2d::CCNode * nodeContent;  
    cocos2d::CCNode * nodeSquares;  
private:

public:
    SceneGaming();
    ~SceneGaming();
    
    static cocos2d::CCScene * scene();
    
    virtual void update(float delta);
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    virtual void initUI();
    
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif /* defined(__CrystaLua__SceneGaming__) */
