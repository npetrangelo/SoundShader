in float sample;
in float time;

uniform int sample_rate;

varying float gain;

void main() {
  gl_sample = sample * gain;
}