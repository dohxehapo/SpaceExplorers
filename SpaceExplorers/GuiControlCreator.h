#pragma once

#ifndef INC_GUICONTROLCREATOR_H
#define INC_GUICONTROLCREATOR_H


#include "GuiObject.h"
#include "Cursor.h"
#include "Panel.h"
#include "Button.h"
#include "Text.h"


class GuiControlCreator
{
public:

  static GuiObject* create_guiObject();
  static Cursor* create_cursor();

  static Panel* create_loadScreen_background();

  static Panel* create_mainMenu_backGround();
  static Button* create_mainMenu_button();
  static Text* create_mainMenu_text();

};


#endif // INC_GUICONTROLCREATOR_H
