#include <arduinoFFT.h>
#ifndef NOISE_RECOGNITION_H
#define NOISE_RECOGNITION_H
#include <Vector.h>
#include <Arduino.h>
// #include <arduinoFFT>

namespace noise_recognition{

class noiseRecognition {
	
	public:
	noiseRecognition();
	// noiseRecognition(float variance);
	// noiseRecognition(float variance, float targetFrequency);
	~noiseRecognition(){};
	noiseRecognition::noiseRecognition(int AnalogPin, float variance, float targetFrequency);
	void performFFT();
	bool listen();
	bool listenFor(float variance);
	bool hasFreq(float frequency);
	void getSamples();
	
	private:

	float variance_;
	float targetF_;
	int pin_;
	int lower_freq;		
	const static long SAMPLING_FREQUENCY = 5000;
	const static int samples_ = (((1/SAMPLING_FREQUENCY) * 5) * 1000000);
 
 	double vReal[samples_]; 
	double vImag[samples_]; 
	arduinoFFT FFT = arduinoFFT();
	const static unsigned long samplingPeriod = 1 / SAMPLING_FREQUENCY;
	unsigned long microSeconds;

};
}

#endif //NOISE_RECOGNITION_H

// Arduino: 1.8.13 (Windows Store 1.8.42.0) (Windows 10), Board: "Arduino Uno"
/*
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp: In constructor 'noise_recognition::noiseRecognition::noiseRecognition()':
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp:34:5: error: 'var_' was not declared in this scope
     var_ = 30;
     ^~~~
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp: At global scope:
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp:47:35: error: expected constructor, destructor, or type conversion before '(' token
 noiseRecognition::noiseRecognition(pin AnalogPin, float variance, float targetFrequency) {
                                   ^
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp:52:6: error: 'noiserecognition' has not been declared
 bool noiserecognition::listenFor(float frequency)
      ^~~~~~~~~~~~~~~~
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp: In function 'bool noise_recognition::listenFor(float)':
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp:59:5: error: 'getSamples' was not declared in this scope
     getSamples();
     ^~~~~~~~~~
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp:60:25: error: 'hasFreq' was not declared in this scope
     bool existingFreq = hasFreq(frequency);
                         ^~~~~~~
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp: At global scope:
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp:64:48: error: no 'bool noise_recognition::noiseRecognition::hasFreq(float)' member function declared in class 'noise_recognition::noiseRecognition'
 bool noiseRecognition::hasFreq(float targetFreq) {
                                                ^
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp:79:6: error: prototype for 'void noise_recognition::noiseRecognition::getSamples()' does not match any in class 'noise_recognition::noiseRecognition'
 void noiseRecognition::getSamples(){
      ^~~~~~~~~~~~~~~~
In file included from C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp:1:0:
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.h:19:6: error: candidate is: int noise_recognition::noiseRecognition::getSamples()
  int getSamples() {return samples_;}
      ^~~~~~~~~~
C:\Users\Jordan Halim\Documents\Arduino\libraries\noise-recognition\noise-recognition.cpp:126:1: error: expected '}' at end of input
 }
 ^
exit status 1
Error compiling for board Arduino Uno.
This report would have more information with
"Show verbose output during compilation"
option enabled in File -> Preferences.
*/