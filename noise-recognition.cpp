#include "noise-recognition.h"
#include <arduinoFFT.h>
#include <math.h> 
namespace noise_recognition{
#include <Arduino.h>


/*
useage:
noiseRecognition nr;
nh.listen(); // 1.) get_sample() 2.) performFFT() 3.) hasFreq() <- return hasFreq()
Commented out stuff:
noiseRecognition::noiseRecognition(double freq){
    /*if(freq >= threshHoldValue)
    {
        return true
    }
    else{
    return false
    }
    }*/


//void setFreq(double val); 


/*
EXAMPLE
in an ino 
noiseRecognition nr = noiseRecognition();
noiseRecognition nr = new noiseRecognition(3200);
*/
noiseRecognition::noiseRecognition() {
    variance_ = 30;
}


// noiseRecognition::noiseRecognition(float variance) {
//     var_ = variance;
// }

// noiseRecognition::noiseRecognition(float variance, float targetFrequency) {
//     noiseRecognition(variance);
//     targetF_ = targetFrequency;
// }

noiseRecognition::noiseRecognition(int AnalogPin, float variance, float targetFrequency) {
   // noiseRecognition(variance);
    variance_ = variance;
    targetF_ = targetFrequency;
    pin_ = AnalogPin;
}

bool noiseRecognition::listenFor(float frequency)
{
    /*
    1. getSamples 
        returns an FFT object 
    2. hasFreq
    */
    getSamples();
    bool existingFreq = hasFreq(frequency);
    return existingFreq;
} 

bool noiseRecognition::hasFreq(float targetFreq) {
    // line 65
    // check if double peak is within a tolerance (class variable)
     double peak = FFT.MajorPeak(vReal, samples_, SAMPLING_FREQUENCY);
     if (targetFreq <= peak + variance_ || targetFreq >= peak + variance_ )
     {
         return true;
     }
     else{
        return false;
     }
}


// return vector
void noiseRecognition::getSamples(){
//set global FFT variable to value obtained from getSample
// lines 45 - 57
//getting fft value

// runs for 5 second incrememts
    FFT = arduinoFFT();
for (int i = 0; i < samples_; ++i)
    {
    vReal[i] = pin_;
    vImag[i] = 0;

    float start_time = micros();
    while(micros() - start_time < samplingPeriod)
        {
        FFT.Windowing(vReal, samples_, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
        FFT.Compute(vReal, vImag, samples_, FFT_FORWARD);
        FFT.ComplexToMagnitude(vReal, vImag, samples_);
        }

    /*
    t of the for loop = 1 / samplingPeriod * sizeOf(vReal)
    t = 5 s
    samplingPeriod 10,000 hz 
    */
    }

}

 
/*
wave = r * cos(T + phi) + i * sin(T + phi)
            i
            |
            |
            |
            |         
------------*-------------r
            |
            |
            |
            |
Sample - array of i and array of r 
Sample Frequency - how often you save i and r 
Sample frequency = 20,000
const int FS_HZ = 20000;  // samping frequency
const int SAMP_PERIOD_US = (1 / FS_HZ) * 10000000// sampling period
while(micros() <= (microSeconds + SAMP_PERIOD_US))
*/
}