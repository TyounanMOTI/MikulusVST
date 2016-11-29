#pragma once

#include <public.sdk/source/vst/vstaudioeffect.h>

class Mikulus : public Steinberg::Vst::AudioEffect
{
  using FUnknown = Steinberg::FUnknown;
  using tresult = Steinberg::tresult;

public:
  Mikulus();

  static FUnknown* createInstance(void* context)
  {
    return (Steinberg::Vst::IAudioProcessor*) new Mikulus;
  }

  tresult PLUGIN_API initialize(FUnknown* context);
  tresult PLUGIN_API terminate();
  tresult PLUGIN_API setActive(Steinberg::TBool state);
  tresult PLUGIN_API process(Steinberg::Vst::ProcessData& data);
};
