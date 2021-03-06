#include "stdafx.h"
#include "Cursor.h"


namespace View
{

Cursor::Cursor()
{
  d_ti = 0;
}


bool Cursor::update(float i_dt)
{
  setPosition(Doh3d::InputMan::getCursor().getPosition());

  return true;
}

bool Cursor::draw(Doh3d::Sprite& i_sprite) const
{
  if (!i_sprite.draw(Doh3d::ResourceMan::getTexture(d_ti).get(), &Doh3d::ResourceMan::getTexture(d_ti).getFrame(0),
                    0, getPosition(), D3DCOLOR_ARGB(255, 255, 255, 255)))
  {
    return false;
  }

  return true;
}


bool Cursor::loadAllTextures()
{
  if (!Doh3d::ResourceMan::getTexture(d_ti).load())
    return false;

  return true;
}


bool Cursor::setTexture(const std::string& pTextureName)
{
  if (!Doh3d::ResourceMan::getTi(pTextureName, d_ti))
    return false;

  return true;
}

} // ns View
