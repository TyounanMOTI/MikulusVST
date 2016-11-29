#pragma once
#include <public.sdk/source/vst/vsteditcontroller.h>

class MikulusController
  : public Steinberg::Vst::EditController
{
public:
  static Steinberg::FUnknown* createInstance(void* context)
  {
    return (Steinberg::Vst::IEditController*) new MikulusController;
  }

  Steinberg::IPlugView* PLUGIN_API createView(Steinberg::FIDString name);
};
