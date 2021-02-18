#include "noise-recognition.h"
#include <arduinoFFT.h>
namespace noise_recognition{


bool noiseRecognition::noiseRecognition(double freq){
    /*if(freq >= threshHoldValue)
    {
        return true
    }
    else{
    return false
    }*/
}

void noiseRecognition::performFFT(){
    //FFT must be global variable
    //Need to find a way to iterate
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
}

void noiseRecognition::setSamples(){
//set global FFT variable to value obtained from getSample
}

double noiseRecognition::getSamples(){
// get input from Mic
// assign value to global decimal number
    return Samples;
}
