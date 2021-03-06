#pragma once

#include "Behaviour.h"


namespace Model
{

class Prototype final
{
public:

  Prototype();
  virtual ~Prototype();

  const std::string& getName() const { return d_name; }
  void setName(const std::string& i_name) { d_name = i_name; }

  const std::string& getTextureName() const { return d_textureName; }
  void setTextureName(const std::string& i_textureName) { d_textureName = i_textureName; }

  int getTi() const { return d_ti; }
  void setTi(int i_ti) { d_ti = i_ti; }

  const Doh3d::Size2I& getSize() const { return d_size; }
  const Doh3d::Size2I& getSize2() const { return d_size2; }
  void setSize(const Doh3d::Size2I& i_size) { d_size = i_size; d_size2 = i_size / 2; }


  Doh3d::Position2I getTextureOffset() const { return d_textureOffset; }
  void setTextureOffset(Doh3d::Position2I i_textureOffset) { d_textureOffset = i_textureOffset; }

  bool getMovable() const { return d_movable; }
  void setMovable(bool i_movable) { d_movable = i_movable; }

  bool getPassable() const { return d_passable; }
  void setPassable(bool i_passable) { d_passable = i_passable; }

  bool getPickable() const { return d_pickable; }
  void setPickable(bool i_pickable) { d_pickable = i_pickable; }

  const Doh3d::IShape* getCollisionShape() const { return d_collisionShape; }
  void setCollisionShape(const Doh3d::IShape* i_shape);
  void resetCollisionShape();

  Behaviour getBehaviour() const { return d_behaviour; }
  void setBehaviour(Behaviour i_behaviour) { d_behaviour = i_behaviour; }

  Doh3d::AnimationSet& getAnimationSet() { return d_animationSet; }
  const Doh3d::AnimationSet& getAnimationSet() const { return d_animationSet; }

private:

  std::string d_name;

  bool d_movable;
  bool d_passable;
  bool d_pickable;

  std::string d_textureName;
  int d_ti;

  Doh3d::Position2I d_textureOffset;

  Doh3d::Size2I d_size;
  Doh3d::Size2I d_size2;

  const Doh3d::IShape* d_collisionShape;

  Behaviour d_behaviour;

  Doh3d::AnimationSet d_animationSet;

};

} // ns Model
