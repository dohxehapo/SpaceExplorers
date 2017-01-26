#pragma once

#ifndef INC_GAME_H
#define INC_GAME_H


#include "RenderDevice.h"
#include "InputDevice.h"
#include "SceneUpdater.h"
#include "SceneDrawer.h"


class Game
{
public:

  void run(const Doh3d::StartupPars& pStartupPars);


private:

  const std::string GAME_NAME = "SpaceExplorers";
  const std::string GAME_FILE_NAME = GAME_NAME + ".exe";

  const std::string LOG_DIR_NAME = "Logs";
  const std::string LOG_FILE_NAME = "Log.txt";
  const std::string LOG_FILE_FULL_NAME = LOG_DIR_NAME + "/" + LOG_FILE_NAME;


private:

  RenderDevice d_renderDevice;
  InputDevice d_inputDevice;
  SceneUpdater d_sceneUpdater;
  SceneDrawer d_sceneDrawer;

  bool d_runMainLoop;


  bool registerWinClass(const Doh3d::StartupPars& pStartupPars);
  bool mainLoop();
  bool unregisterWinClass();

};


#endif // INC_GAME_H
