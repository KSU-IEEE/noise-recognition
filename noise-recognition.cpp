#include "noise-recognition.h"
#include <arduinoFFT.h>
#include <math.h> 
namespace noise_recognition{

double vReal[SAMPLES_]; //create vector of size SAMPLES to hold real values
double vImag[SAMPLES_]; //create vector of size SAMPLES to hold imaginary values

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



bool listen()
{
arduinoFFT samples = getSamples();
bool existingFreq = hasFreq(samples);
return existingFreq;
} 

bool noiseRecognition::hasFreq(arduinoFFT FFT) {
    // line 65
    // check if double peak is within a tolerance (class variable)
     double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
     if (peak > 0)
     {
         return true;
     }
     else{
        return false;
     }
}

//void noiseRecognition::performFFT(){
    //FFT must be global variable
    //Need to find a way to iterate
    
    
}

// return vector
void noiseRecognition::getSamples(){
//set global FFT variable to value obtained from getSample
// lines 45 - 57
//getting fft value
arduinoFFT FFT = arduinoFFT();
for (int i = 0; i < sizeOf(vReal); ++i)
    {
    vReal[i] = analogRead(0);
    vImag[i] = 0;
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
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