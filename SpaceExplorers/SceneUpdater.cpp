#include "stdafx.h"
#include "SceneUpdater.h"

#include "Scene.h"


namespace SpaceExplorers
{
namespace Controller
{

bool SceneUpdater::update(Scene& pScene, float pDt)
{
  if (!pScene.update(pDt))
    return false;

  return true;
}

} // ns Controller
} // ns SpaceExplorers
