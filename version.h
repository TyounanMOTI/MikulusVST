﻿#pragma once

#include "pluginterfaces/base/fplatform.h"

#define MAJOR_VERSION_STR "1"
#define MAJOR_VERSION_INT 1

#define SUB_VERSION_STR "0"
#define SUB_VERSION_INT 0

#define RELEASE_NUMBER_STR "0"
#define RELEASE_NUMBER_INT 0

#define BUILD_NUMBER_STR "2" // Build number to be sure that each result could identified.
#define BUILD_NUMBER_INT 2

// Version with build number (example "1.0.3.342")
#define FULL_VERSION_STR MAJOR_VERSION_STR "." SUB_VERSION_STR "." RELEASE_NUMBER_STR "." BUILD_NUMBER_STR

// Version without build number (example "1.0.3")
#define VERSION_STR MAJOR_VERSION_STR "." SUB_VERSION_STR "." RELEASE_NUMBER_STR

#define stringOriginalFilename	"MikulusVST.vst3"
#define stringPluginName "Mikulus VST3"
#if PLATFORM_64
#define stringFileDescription	"Mikulus VST3 (64Bit)"
#else
#define stringFileDescription	"Mikulus VST3"
#endif
#define stringCompanyName		"@TyounanMOTI"
#define stringCompanyUrl    "http://twitter.com/tyounanmoti"
#define stringCompanyMailto "tyounan.moti@gmail.com"
#define stringLegalCopyright	"(c) 2016 @TyounanMOTI"
#define stringLegalTrademarks	"VST is a trademark of Steinberg Media Technologies GmbH"

#pragma once
