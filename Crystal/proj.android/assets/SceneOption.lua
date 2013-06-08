
-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end

--btn play game clicked
local function playGame(sender)
    CCDirector:sharedDirector():replaceScene(SceneGaming:scene())
end

--加载界面元素到场景
function loadUI(nodeParrent)
    local bg = CCSprite:create("background.png")
    bg:setAnchorPoint(ccp(0,0))
    bg:setPosition(ccp(0,0))
    nodeParrent:addChild(bg)
    
    --properties of menus
    local item1NomalImage="btn-play.png" 
    local item1TouchImage="btn-play-down.png"
    local item1Position=ccp(320,480)

    -- menu
    local item1 = CCMenuItemImage:create(item1NomalImage, item1TouchImage)
    item1:registerScriptTapHandler(playGame)
    item1:setPosition(item1Position)
    
    local menu = CCMenu:create()
    menu:addChild(item1)
    menu:setPosition(CCPointMake(0, 0))
    
    nodeParrent:addChild(menu)

end


local function main()
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)
end


xpcall(main, __G__TRACKBACK__)