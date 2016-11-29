#include "mikulus.h"
#include "class_ids.h"

using namespace Steinberg;
using namespace Steinberg::Vst;

Mikulus::Mikulus()
{
  setControllerClass(MikulusControllerUID);
}

tresult PLUGIN_API Mikulus::initialize(FUnknown * context)
{
  auto status = AudioEffect::initialize(context);
  if (status != kResultOk) {
    return status;
  }

  addEventInput(STR16("Event In"), 1);
  addAudioOutput(STR16("Audio Out"), SpeakerArr::kMono);

  return kResultOk;
}

tresult PLUGIN_API Mikulus::terminate()
{
  return AudioEffect::terminate();
}

tresult PLUGIN_API Mikulus::setActive(Steinberg::TBool state)
{
  return AudioEffect::setActive(state);
}

tresult PLUGIN_API Mikulus::process(Steinberg::Vst::ProcessData & data)
{
  return kResultOk;
}
