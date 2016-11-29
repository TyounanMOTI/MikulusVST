#include "mikulus.h"
#include "class_ids.h"
#include <osc/OscOutboundPacketStream.h>
#include <pluginterfaces/vst/ivstprocesscontext.h>

using namespace Steinberg;
using namespace Steinberg::Vst;

Mikulus::Mikulus()
  : oscSocket(IpEndpointName("127.0.0.1", 393939))
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
  if (data.processContext) {
    if (data.processContext->state & ProcessContext::kTempoValid) {
      auto newBpm = data.processContext->tempo;
      if (newBpm != bpm) {
        bpm = newBpm;

        osc::OutboundPacketStream out(oscBuffer.data(), oscBufferSize);
        out
          << osc::BeginBundleImmediate
          << osc::BeginMessage("/VST/BPM")
          << bpm
          << osc::EndMessage
          << osc::EndBundle;

        oscSocket.Send(out.Data(), out.Size());
      }
    }
    if (data.processContext->state & ProcessContext::kProjectTimeMusicValid) {
      auto newProjectTime = std::floor(data.processContext->projectTimeMusic);
      if (newProjectTime != projectTime) {
        projectTime = newProjectTime;

        osc::OutboundPacketStream out(oscBuffer.data(), oscBufferSize);
        out
          << osc::BeginBundleImmediate
          << osc::BeginMessage("/VST/OnBeat")
          << projectTime
          << osc::EndMessage
          << osc::EndBundle;

        oscSocket.Send(out.Data(), out.Size());

      }
    }
  }

  return kResultOk;
}
