#include <arduinoFFT.h>
#ifndef NOISE_RECOGNITION_H
#define NOISE_RECOGNITION_H
#include <Vector.h>
// #include <arduinoFFT>

namespace noise_recognition{

class noiseRecognition {
	
	public:
	noiseRecognition();
	~noiseRecognition();

	
	void performFFT();

	bool peak(int freq){
		double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
		// if peak > threshhold, target = A
		// else target = B
	}

	void setSamples(int sample) {samples_ =sample;}
	int getSamples() {return samples_;}
	private:
	int lower_freq;
	int samples_ = 128;
 	int SAMPLING_FREQUENCY = 2048;

arduinoFFT FFT = arduinoFFT();
unsigned int samplingPeriod;
unsigned long microSeconds;

Vector<double> vReal(samples_);
//double vReal[samples_];//create vector of size SAMPLES to hold real values
//double vImag[samples_]; //create vector of size SAMPLES to hold imaginary values

};
}

#endif //NOISE_RECOGNITION_H