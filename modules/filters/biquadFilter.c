#ifndef __BIQUAD_FILTER_C__
#define __BIQUAD_FILTER_C__

#pragma systemFile

#ifndef __BIQUAD_FILTERS_H__
#include "biquadFilters.h"
#endif

int BiquadFilterInit(
    struct BiquadFilter* filter,
    enum BiquadFilterType type,
    float sampleFreq,
    float cutoffFreq,
    float defaultValue)
{
  if (filter == 0) return -1;

  float w0 = 2 * PI * cutoffFreq / sampleFreq;
  float cosw0 = cos(w0);
  float sinw0 = sin(w0);

  float Q = 0.707;
  float alpha = sinw0 / (2 * Q);
  float b0, b1, b2, a0, a1, a2;

  writeDebugStreamLine("%f %f %f %f", cosw0, sinw0, alpha, Q);

  // Calculates the coefficients for the transfer function.
  switch (type)
  {
    case LOWPASS:
      b0 = (1 - cosw0) / 2;
      b1 = (1 - cosw0);
      b2 = (1 - cosw0) / 2;
      a0 = 1 + alpha;
      a1 = -2 * cosw0;
      a2 = 1 - alpha;
      break;

    case HIGHPASS:
      b0 = (1 + cosw0) / 2;
      b1 = -(1 + cosw0);
      b2 = (1 + cosw0) / 2;
      a0 = 1 + alpha;
      a1 = -2 * cosw0;
      a2 = 1 - alpha;
      break;

    default:
      return -1;
  }

  // Normalize the coefficients so that a0 = 1.
  filter->b0 = b0 / a0;
  filter->b1 = b1 / a0;
  filter->b2 = b2 / a0;
  filter->a1 = a1 / a0;
  filter->a2 = a2 / a0;

  filter->old_input[0] = filter->old_input[1] = defaultValue;
  filter->old_output[0] = filter->old_output[1] = defaultValue;

  return 0;
}

float BiquadFilterSample(struct BiquadFilter* filter, float data)
{
  if (filter == 0) return -1;

  float output =
    filter->b0 * data +
    filter->b1 * filter->old_input[0] +
    filter->b2 * filter->old_input[1] -
    filter->a1 * filter->old_output[0] -
    filter->a2 * filter->old_output[1];

  filter->old_input[1] = filter->old_input[0];
  filter->old_input[0] = data;

  filter->old_output[1] = filter->old_output[0];
  filter->old_output[0] = output;

  return output;
}

#endif
