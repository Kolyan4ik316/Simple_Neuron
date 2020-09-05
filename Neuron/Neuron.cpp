#include "Neuron.h"

double Neuron::ProcessInputData(double input) const
{
    return input * weight;
}

double Neuron::RestoreInputData(double output) const
{
    return output / weight;
}

void Neuron::Train(double input, double expectedResult)
{
    double actualResult = input * weight;
    errorValue = expectedResult - actualResult;
    double correction = (errorValue / actualResult) * smoothing;
    weight += correction;
}

double Neuron::GetErrorValue() const
{
    return errorValue;
}

double Neuron::GetWeight() const
{
    return weight;
}

void Neuron::SetSmoothing(double smoothing_in)
{
    smoothing = smoothing_in;
}

double Neuron::GetSmoothing() const
{
    return smoothing;
}
