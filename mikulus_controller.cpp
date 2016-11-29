#include "mikulus_controller.h"
#include <vstgui/plugin-bindings/vst3editor.h>

using namespace Steinberg;
using namespace Steinberg::Vst;

IPlugView* PLUGIN_API MikulusController::createView(FIDString name)
{
  if (strcmp(name, ViewType::kEditor) == 0) {
    return new VSTGUI::VST3Editor(this, "view", "mikulus_editor.uidesc");
  }
  return nullptr;
}
