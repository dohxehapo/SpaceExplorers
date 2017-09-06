#include "stdafx.h"
#include "Scene.h"

#include "Game.h"


namespace SpaceExplorers
{
namespace Controller
{

Scene::Scene(Game& i_game)
  : d_game(i_game)
{
}

Scene::~Scene()
{
}

} // ns Controller
} // ns SpaceExplorers
