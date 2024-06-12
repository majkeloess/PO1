#ifndef WIDGETS_H
#define WIDGETS_H

#include <iostream>
#include <vector>
#include <string>

class Widget
{
public:
    virtual std::string widgetDescription() const = 0;
    virtual void paint() = 0;
    ~Widget() = default;
};

class Button: public Widget
{
private:
  std::string m_color;
public:
    Button();
    std::string widgetDescription() const override;
    void paint() override; 
};


class EditBox: public Widget
{
private:
  std::string m_color;
public:
    EditBox();
    std::string widgetDescription() const override;
    void paint() override;

};


class RadioButton: public Button
{
  private:
    std::string m_color;
public:
    RadioButton();
    std::string widgetDescription() const override;
    void paint() override;
};


class MaskedEditBox: public EditBox
{
private:
    std::string m_color;
public:
    MaskedEditBox();
    std::string widgetDescription() const override;
    void paint() override;


};


class WidgetPainter
{
public:
    
    WidgetPainter() = default;
    void paintWidgets(std::vector<Widget*> object);
    std::vector<Widget*> widgets;
    ~WidgetPainter() = default; 
};

#endif