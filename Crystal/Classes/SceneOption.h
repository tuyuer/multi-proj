//
//  SceneOption.h
//  CrystaLua
//
//  Created by tuyuer wen on 13-6-5.
//
//

#ifndef __CrystaLua__SceneOption__
#define __CrystaLua__SceneOption__

#include <iostream>
#include "SceneHL.h"

class SceneOption:public SceneHL{
protected:
    
public:
    static cocos2d::CCScene * scene();
    
    virtual void onEnterTransitionDidFinish();
    virtual void initUI();
};

#endif /* defined(__CrystaLua__SceneOption__) */
