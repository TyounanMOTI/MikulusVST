#pragma once

#include <public.sdk/source/vst/vstaudioeffect.h>
#include <ip/UdpSocket.h>
#include <array>

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

private:
  UdpTransmitSocket oscSocket;
  static const size_t oscBufferSize = 1024;
  std::array<char, oscBufferSize> oscBuffer;
  double bpm = 0.0;
  Steinberg::Vst::TQuarterNotes projectTime = 0.0;
  Steinberg::Vst::TQuarterNotes barPosition = 0.0;
};
