#include "stdafx.h"
#include "GuiCreator.h"

#include "GuiNames.h"


GuiObject* GuiCreator::create_guiObject()
{
  auto* pGuiObject = new GuiObject();
  pGuiObject->name() = GuiNames::GUI_OBJECT;
  return pGuiObject;
}

Cursor* GuiCreator::create_cursor()
{
  const std::string cursor_texture_fileName = "Cursor_32_32_1_n.png";
  const Doh3d::Size2 cursor_size = { 32, 32 };


  auto* pCursor = new Cursor();
  pCursor->name() = GuiNames::CURSOR;


  if (!pCursor->setTexture(cursor_texture_fileName))
  {
    delete pCursor;
    return nullptr;
  }

  pCursor->setSize(cursor_size);


  return pCursor;
}


Panel* GuiCreator::create_loadScreen_background()
{
  const std::string loadScreen_background_texture_fileName = "Loading_256_64_1_n.png";
  const Doh3d::Size2 loadScreen_background_size = { 256, 64 };


  auto* pPanel = new Panel();
  pPanel->name() = GuiNames::LOADING_SCREEN_BACKGROUND;


  if (!pPanel->setTexture(loadScreen_background_texture_fileName))
  {
    delete pPanel;
    return nullptr;
  }

  pPanel->setSize(loadScreen_background_size);


  return pPanel;
}


Panel* GuiCreator::create_mainMenu_backGround()
{
  const std::string mainMenu_background_texture_fileName = "MainMenu_1920_1080_1_n.png";
  const Doh3d::Size2 mainMenu_background_size = { 1920, 1080 };


  auto* pPanel = new Panel();
  pPanel->name() = GuiNames::MAINMENU_BACKGROUND;


  if (!pPanel->setTexture(mainMenu_background_texture_fileName))
  {
    delete pPanel;
    return nullptr;
  }

  pPanel->setSize(mainMenu_background_size);


  return pPanel;
}
