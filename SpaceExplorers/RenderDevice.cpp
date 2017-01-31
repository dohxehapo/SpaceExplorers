#include "stdafx.h"
#include "RenderDevice.h"


bool RenderDevice::check()
{
  return Doh3d::RenderMan::isCreated();
}

bool RenderDevice::recreate(const std::string& pWindowCaption)
{
  LOG(__FUNCTION__);

  if (!Doh3d::RenderMan::recreate(getRenderPars(), pWindowCaption))
  {
    echo("ERROR: Can't recreate RenderMan.");
    return false;
  }

  return true;
}


Doh3d::RenderPars RenderDevice::getRenderPars()
{
  Doh3d::RenderPars renderPars;

  renderPars.resolutionWidth() = 1280;
  renderPars.resolutionHeight() = 1024;
  renderPars.windowed() = true;
  renderPars.fullScreenRefreshRate() = 60;
  renderPars.hasBorder() = false;

  return renderPars;
}