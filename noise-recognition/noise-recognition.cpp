#include "noise-recognition.h"
namespace noise_recognition{
// /*    void setup() 
// {
//     Serial.begin(115200); //Baud rate for the Serial Monitor
//     samplingPeriod = round(1000000*(1.0/SAMPLING_FREQUENCY)); //Period in microseconds 
// }
 
// void loop() 
// {  
//     /*Sample SAMPLES times*/
//     for(int i=0; i<SAMPLES; i++)
//     {
//         microSeconds = micros();    //Returns the number of microseconds since the Arduino board began running the current script. 
     
//         vReal[i] = analogRead(0); //Reads the value from analog pin 0 (A0), quantize it and save it as a real term.
//         vImag[i] = 0; //Makes imaginary term 0 always

//         /*remaining wait time between samples if necessary*/
//         while(micros() < (microSeconds + samplingPeriod))
//         {
//           //do nothing
//         }
//     }

//    /*Perform FFT on samples*/
//     FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
//     FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
//     FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);

//     /*Find peak frequency and print peak*/
//     double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);

//     //send peak to machine for evaluation
// }
}
