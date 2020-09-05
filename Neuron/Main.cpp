#include "Neuron.h"
#include <iostream>

int main()
{
	static const double usd = 100;
	static const double uah = 2770.52;
	std::cout << "Write number of USD to convert to UAH \nCurrent course is "<< uah <<" UAH to "<< usd <<" USD" << std::endl;
	double number;
	std::cin >> number;
	Neuron* neuron = new Neuron;

	//neuron->SetSmoothing(0.00001);
	int iteration = 0;
	while (neuron->GetErrorValue() > neuron->GetSmoothing() || neuron->GetErrorValue() < -neuron->GetSmoothing())
	{
		iteration++;
		neuron->Train(usd, uah);
		
		if (iteration % 10000 == 0)
		{
			std::cout << "Iteration: " << iteration << " Error: " << neuron->GetErrorValue() << std::endl;
		}
		
	}
	
	std::cout << "training completed" << std::endl;
	std::cout << "Last iteration: " << iteration << " Error: " << neuron->GetErrorValue() << std::endl;

	
	std::cout << neuron->ProcessInputData(number) << " UAH in " << number << " USD" << std::endl;
	//std::cout << neuron->ProcessInputData(666) << " UAH in " << 666 << " USD" << std::endl;
	//std::cout << neuron->ProcessInputData(69) << " UAH in " << 69 << " USD" << std::endl;
	//std::cout << neuron->RestoreInputData(70) << " USD in " << 70 << " UAH" << std::endl;
	
	delete neuron;
	neuron = nullptr;
	
	std::cin.get();
	return 0;
}