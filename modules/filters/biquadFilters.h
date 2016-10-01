#ifndef __BIQUAD_FILTERS_H__
#define __BIQUAD_FILTERS_H__

// Biquad filter is a standard 2nd-order filter
// The transfer function follows the following format:
// H(z) = (b0 + b1*z^-1 + b2*z^-2) / (1 + a1*z^-1 + a2*z^-2)
struct BiquadFilter
{
  float b0, b1, b2, a1, a2;

  float old_input[2];
  float old_output[2];
};

// The response of the filter, default is butterworth.
enum BiquadFilterType
{
  LOWPASS,
  HIGHPASS
};

// Initializes biquad filter.
// Sample Freq and cutoff freq is in hertz.
// Ex. If you sample a gyroscope 100 times a second, sample
//     freq is 100 and cutoff freq is the -3db point for the
//     filter, such as 40.
int BiquadFilterInit(
    struct BiquadFilter* filter,
    enum BiquadFilterType type,
    float sampleFreq,
    float cutoffFreq,
    float defaultValue = 0.0);

// Takes sensor input and returns a filtered value.
float BiquadFilterSample(struct BiquadFilter* filter, float data);

#include "biquadFilter.c"

#endif
