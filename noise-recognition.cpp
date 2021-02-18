#include "noise-recognition.h"
#include <arduinoFFT.h>
namespace noise_recognition{


/*
useage:

noiseRecognition nr;
nh.listen(); // 1.) get_sample() 2.) performFFT() 3.) hasFreq() <- return hasFreq()
*/


noiseRecognition::noiseRecognition(double freq){
    /*if(freq >= threshHoldValue)
    {
        return true
    }
    else{
    return false
    }*/
}

void setFreq(double val); 
bool listen(); 

bool noiseRecognition::hasFreq() {
    // line 65
    // check if double peak is within a tolerance (class variable)
}

void noiseRecognition::performFFT(){
    //FFT must be global variable
    //Need to find a way to iterate
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
}

// return vector
void noiseRecognition::getSamples(){
//set global FFT variable to value obtained from getSample
// lines 45 - 57

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
