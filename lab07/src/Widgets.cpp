#include "Widgets.h"

Button::Button(): m_color{"gray"}{}


std::string Button::widgetDescription() const
{
    return m_color + " button";
}

void Button::paint()
{
    m_color = "blue";
}

EditBox::EditBox(): m_color{"gray"}{}


std::string EditBox::widgetDescription() const
{
    return m_color + " editbox";
}

void EditBox::paint()
{
    m_color = "red";
}

RadioButton::RadioButton(): m_color{"gray"}{}


std::string RadioButton::widgetDescription() const
{
    return m_color + " radiobutton";
}

void RadioButton::paint()
{
    m_color = "blue";
}

MaskedEditBox::MaskedEditBox(): m_color{"gray"}{}


std::string MaskedEditBox::widgetDescription() const
{
    return m_color + " maskededitbox";
}

void MaskedEditBox::paint()
{
    m_color = "red";
}



void WidgetPainter::paintWidgets(std::vector<Widget*> widgets)
{
    for (auto* x: widgets){
      
        if(auto *b = dynamic_cast<Button*> (x)){
            b->paint();
        }
        else if(auto *e = dynamic_cast<EditBox*> (x)){
            e->paint();
        }
    }
}