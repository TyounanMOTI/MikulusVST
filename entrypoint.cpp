#include <public.sdk/source/main/pluginfactoryvst3.h>
#include <public.sdk/source/vst/vstaudioeffect.h>
#include "version.h"
#include "class_ids.h"
#include "mikulus.h"
#include "mikulus_controller.h"

bool InitModule()
{
  return true;
}

bool DeinitModule()
{
  return true;
}

BEGIN_FACTORY_DEF(
  stringCompanyName,
  stringCompanyUrl,
  stringCompanyMailto
  )

  DEF_CLASS2(
    INLINE_UID_FROM_FUID(MikulusProcessorUID),
    PClassInfo::kManyInstances,
    kVstAudioEffectClass,
    stringPluginName,
    Vst::kDistributable,
    "Instrument",
    FULL_VERSION_STR,
    kVstVersionString,
    Mikulus::createInstance
  )

  DEF_CLASS2(
    INLINE_UID_FROM_FUID(MikulusControllerUID),
    PClassInfo::kManyInstances,
    kVstComponentControllerClass,
    stringPluginName " Controller",
    0,
    "",
    FULL_VERSION_STR,
    kVstVersionString,
    MikulusController::createInstance
  )

END_FACTORY
