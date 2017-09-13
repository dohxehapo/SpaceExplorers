#include "stdafx.h"
#include "MapController.h"

#include "Game.h"
#include "Map.h"
#include "Scene.h"
#include "Camera.h"
#include "GameObjectCreator.h"


namespace Controller
{

MapController::MapController(Game& i_game)
  : d_game(i_game)
{
}


bool MapController::createMap(int i_width, int i_height)
{
  d_map = new Model::Map(20, 20);
  if (!d_map)
    return false;


  d_map->getTileAt(0, 0)->setTurf(GameObjectCreator::createLattice(*d_map));
  d_map->getTileAt(1, 1)->setTurf(GameObjectCreator::createLattice(*d_map));

  for (int y = 2; y <= 10; ++y)
  {
    for (int x = 2; x <= 8; ++x)
    {
      d_map->getTileAt(x, y)->setTurf(GameObjectCreator::createLattice(*d_map));
    }
  }

  for (int y = 6; y <= 8; ++y)
  {
    for (int x = 3; x <= 6; ++x)
    {
      d_map->getTileAt(x, y)->resetTurf();
    }
  }

  for (int y = 2; y <= 5; ++y)
  {
    for (int x = 3; x <= 8; ++x)
    {
      d_map->getTileAt(x, y)->setFloor(GameObjectCreator::createFloor(*d_map));
    }
  }

  d_map->getTileAt(4, 2)->setWall(GameObjectCreator::createWall(*d_map));
  d_map->getTileAt(4, 3)->setWall(GameObjectCreator::createDoor(*d_map));
  d_map->getTileAt(4, 4)->setWall(GameObjectCreator::createWall(*d_map));

  d_map->getTileAt(7, 3)->setWall(GameObjectCreator::createWall(*d_map));
  d_map->getTileAt(7, 4)->setWall(GameObjectCreator::createWall(*d_map));

  for (int y = 6; y < 9; ++y)
  {
    d_map->getTileAt(7, y)->setTurf(GameObjectCreator::createLattice(*d_map));
    d_map->getTileAt(7, y)->setFloor(GameObjectCreator::createFloor(*d_map));
    d_map->getTileAt(7, y)->setWall(GameObjectCreator::createWall(*d_map));
  }


  auto* pMan = GameObjectCreator::createMan(*d_map);
  pMan->setPosition({ 160, 160 });
  pMan->setName("Player");
  d_map->addGameObject(pMan);

  return true;
}

bool MapController::deleteMap()
{
  LOG(__FUNCTION__);

  if (!d_map)
  {
    echo("ERROR: Can't delete map - no map.");
    return false;
  }

  delete d_map;
  d_map = nullptr;

  return true;
}


bool MapController::update(float i_dt)
{
  if (!d_map)
    return true;

  if (!d_map->getMapBackgound().update(i_dt))
    return false;

  for (int y = 0; y < d_map->getHeight(); ++y)
  {
    for (int x = 0; x < d_map->getWidth(); ++x)
    {
      if (!d_map->getTileAt(x, y)->update(i_dt))
        return false;
    }
  }

  for (auto* pObject : d_map->getObjects())
    pObject->update(i_dt);

  return true;
}

bool MapController::draw(Doh3d::Sprite& i_sprite) const
{
  if (!d_map)
    return true;

  if (!d_map->getMapBackgound().draw(i_sprite))
    return false;

  auto* pCamera = d_game.getScene().getCamera();
  if (!pCamera)
    return false;

  Doh3d::SpriteTransformGuard spriteTransformGuard(i_sprite);

  const Doh3d::Position2I cameraTranslation = -pCamera->getPosition();
  i_sprite.setTranslation(cameraTranslation);

  for (int y = 0; y < d_map->getHeight(); ++y)
  {
    for (int x = 0; x < d_map->getWidth(); ++x)
    {
      if (!d_map->getTileAt(x, y)->draw(i_sprite))
        return false;
    }
  }

  for (auto* pObject : d_map->getObjects())
    pObject->draw(i_sprite);

  return true;
}

} // ns Controller
