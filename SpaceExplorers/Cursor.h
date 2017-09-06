#pragma once

#include "SceneObject.h"
#include "IGui.h"


namespace SpaceExplorers
{
namespace View
{

class Cursor : public IGui
{
public:

  Cursor();
  virtual ~Cursor() { }

  virtual bool loadAllTextures() override;

  bool setTexture(const std::string& pTextureName);

private:

  Doh3d::TextureId d_ti;

  virtual bool updateSelf(float pDt) override;
  virtual bool drawSelf(Doh3d::Sprite& pSprite) const override;

};

} // ns View
} // ns SpaceExplorers
