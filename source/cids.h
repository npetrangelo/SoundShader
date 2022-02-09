//------------------------------------------------------------------------
// Copyright(c) 2022 F Around Media.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace FAM {
//------------------------------------------------------------------------
static const Steinberg::FUID kSoundShaderEffectProcessorUID (0x1A3C1F65, 0x3E67544F, 0xB8FD3A4E, 0x05C7025D);
static const Steinberg::FUID kSoundShaderEffectControllerUID (0xD0337BCB, 0x8D7657C0, 0x8710894B, 0xF9519C32);

#define SoundShaderEffectVST3Category "Fx"

//------------------------------------------------------------------------
} // namespace FAM
