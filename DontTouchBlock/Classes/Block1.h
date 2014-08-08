//
//  Block1.h
//  DontTouchBlock
//
//  Created by strongsoft on 14-8-8.
//
//

#ifndef __DontTouchBlock__Block1__
#define __DontTouchBlock__Block1__

#include <iostream>
#include <cocos2d.h>

USING_NS_CC;

class Block:public Sprite {
    
private:
    static Vector<Block*> * blocks;
    int lineIndex;
    
public:
    
    static Vector<Block*> * getBlocks();
    
    static Block* createWithArgs(Color3B color,Size size,std::string label,float fontSize,Color4B textColor);
    
    virtual bool initWithArgs(Color3B color,Size size,std::string label,float fontSize,Color4B textColor);
    
    void removeBlock();
    
    int getLineIndex();
    void setLineIndex(int lineIndex);
    
    void moveDown();
};


#endif /* defined(__DontTouchBlock__Block1__) */
