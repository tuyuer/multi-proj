
-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end


local sceneGaming=nil;
local arrayCrystals=nil;

-- 获取一个空闲的宝石
local function getIdleCrastal()
    local crastalNumber=arrayCrystals:count()
    crastalNumber=crastalNumber-1
    
    --寻找一个空闲Crastal
    for i=0,crastalNumber do
        local crastal=tolua.cast(arrayCrystals:objectAtIndex(i),"SpriteCrystal")
        
        if crastal:getType()==0 then
            return crastal;
        end
    end
end

--初始化宝石
function initCrystals(arrayCrystal)
    --初始化300个宝石
    for i=1,300 do
        local crastal=SpriteCrystal:create()
        arrayCrystal:addObject(crastal)
    end
end

--加载关卡
--para1 数组， para2 宫格节点，para3 关卡号
function loadLevel(arrayCrystal,nodeSquareds,nodeParrent,level)
    --赋值操作
    arrayCrystals=arrayCrystal

    --保函对应关卡的lua头文件
    if level==1 then
        require "level1.lua"
    elseif level==2 then
        require "level2.lua"
    end
        
    load(arrayCrystal,nodeSquareds,nodeParrent)
    
 
end



--设置sceneGaming
function setRoot(nodeRoot)
    sceneGaming=nodeRoot

--    nodeRoot:scheduleUpdateWithPriorityLua(update, 0)
end


--更新函数
function update(fDelta)
    
end



--处理触摸开始
function touchBegin(pTouch)
    local touchLocation=pTouch:getLocation()
    
end

function touchMove(pTouch)
    local touchLocation=pTouch:getLocation()
    
end

function touchEnded(pTouch)
    local touchLocation=pTouch:getLocation()
    
end
--处理触摸结束



local function main()
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)
end


xpcall(main, __G__TRACKBACK__)




