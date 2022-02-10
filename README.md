# SoundShaderEffect
A VST plugin for writing shaders to apply audio effects.

## How to build
Make sure you have [cmake](https://cmake.org/download/) installed, download the [VST SDK](https://developer.steinberg.help/display/VST/How+to+set+up+my+system+for+VST+3), and follow the [instructions](https://developer.steinberg.help/display/VST/VST+3+Project+Generator) for generating a VST project for whatever system you have with the namespace `FAM`. Replace all the source files and resource files with the files from here, and configure IDE specific files to recognize any new files. Then, build!
