
local gravity=10;
local rows=10
local cols=8

local tableGraph={
    function() return 0,0,1,0,1,1,0 end, 
    function() return 0,0,1,0,1,1,0 end, 
    function() return 0,0,1,0,1,1,0 end, 
    function() return 0,0,1,0,1,1,0 end, 
    function() return 0,0,1,0,1,1,0 end, 
    function() return 0,0,1,0,1,1,0 end, 
    function() return 0,0,1,0,1,1,0 end, 
    function() return 0,0,1,0,1,1,0 end, 
    function() return 0,0,1,0,1,1,0 end, 
    function() return 0,0,1,0,1,1,0 end
}


--进行界面的加载布局
function load(arrayCrystal,nodeSquareds,nodeParrent)
    
    local bg = CCSprite:create("background.png")
    bg:setAnchorPoint(ccp(0,0))
    bg:setPosition(ccp(0,0))
    nodeParrent:addChild(bg)
    
    --加载行
    for row=1,rows do
        --加载列
--        local rowValues=tableGraph[row]
--        for col=1,cols do
--            local colValue=rowValues[col]
        
--        end

    end
    
    
end