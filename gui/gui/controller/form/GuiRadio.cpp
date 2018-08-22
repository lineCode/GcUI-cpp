//
//  GuiRadio.cpp
//  gui
//
//  Created by working on 2018/8/21.
//  Copyright © 2018年 working. All rights reserved.
//

#include "GuiRadio.hpp"

namespace gc {
    
    using namespace std;
    
    GuiRadio::GuiRadio(GcRect rect, GcColor backgroundColor, GcColor checkedColor): GuiView(rect, backgroundColor),
        rect(rect),
        backgroundColor(backgroundColor),
        checkedColor(checkedColor) {

    }
    
    GuiRadio::~GuiRadio(){
        
    }
    
    void GuiRadio::Draw() {
        GcRect rect = this->rect;
        GcRect checkedRect(rect.x+2, rect.y+2, rect.width-4, rect.height-4);
        
        GcColor backgroundColor = this->backgroundColor;
        GcColor checkedColor = this->checkedColor;
        this->renderer->DrawRect(rect, backgroundColor);
        
        if (this->checked) {
            this->renderer->RenderFillRect(checkedRect, checkedColor);
        }
    }
    
    void GuiRadio::Initialize() {
    }
    
    void GuiRadio::OnMouse(GcEvent event) {
        //        std::cout << "btn," << std::endl;
        int x = event.x;
        int y = event.y;
        GcPoint point(x, y);
        GcRect rect = this->rect;
        
        int type = event.type;
        
        if (type == EnumMouseButtonDown) {
            if (PointInRect(point, rect)) {
                this->checked = true;
            } else {
                this->checked = false;
            }
        } else if (type == EnumMouseButtonUp) {
            this->checked = false;
        }
    }
    
}
