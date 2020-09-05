#pragma once


class Neuron
{
public:
	double ProcessInputData(double input) const;
	double RestoreInputData(double output) const;
	void Train(double input, double expectedResult);
	double GetErrorValue() const;
	double GetWeight()const;
	void SetSmoothing(double smoothing_in);
	double GetSmoothing() const;
private:
	double weight = 0.5;
	double errorValue;
	double smoothing = 0.00001;
};