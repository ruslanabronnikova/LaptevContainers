#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <map>
#include <string>

class Rand
{
    std::vector<double> inputData;

    std::vector<double> functionData;

public:
    Rand()
    {
        int dataSize, i, j;

        double dataElement;

        std::cin >> dataSize;

        for (i = 0; i < dataSize; i++)
        {
            std::cin >> dataElement;

            inputData.push_back(dataElement);
        }

        for (j = 0; j < dataSize; j++)
        {
            std::cin >> dataElement;

            functionData.push_back(dataElement);
        }

        displayStatistics();
    }

private:

    double calculateMean(const std::vector<double>& data)
    {
        return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    }

    double calculateVariance(const std::vector<double>& data)
    {
        int k;

        double meanValue = calculateMean(data);

        double variance = 0;

        for (k = 0; k < data.size(); k++)
            variance += pow((data[k] - meanValue), 2);

        variance /= (data.size());

        return variance;
    }

    double calculateMonteCarlo()
    {
        int f;

        double sum = 0, result;

        for (f = 0; f < inputData.size(); f++)
            sum += functionData[f];

        result = (inputData.back() - inputData.front()) * sum / inputData.size();

        //if (result == 24)
            //result = 74;

        return result;
    }

    void displayStatistics()
    {
        std::cout << "input= argument ";

        for (double input : inputData)
            std::cout << input << ' ';

        std::cout << "\nfunction ";

        for (double functionValue : functionData)
            std::cout << functionValue << ' ';

        std::cout << " MO X= " << calculateMean(inputData) << " Disp X= " << calculateVariance(inputData);

        std::cout << " MO Y= " << calculateMean(functionData) << " Disp Y= " << calculateVariance(functionData) << "\n";

        std::cout << "MonteKarlo= " << calculateMonteCarlo() << "\n";
    }
};

int main()
{
    Rand analyzer;

    return 0;
}