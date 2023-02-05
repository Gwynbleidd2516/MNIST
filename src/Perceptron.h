#pragma once

#include<vector>
#include<string>
#include<fstream>
using namespace std;

class Perceptron
{
private:
    double activationFunction(double value);
    double deactivationFunction(double value);

    double summ;
    vector<double> weights;
    vector<double> exInputs;
    double learningSpeed;
    double bias;

public:
    Perceptron(int capasity);

    Perceptron(){}

    void setPerceptron(int capasity);

    void setLearningSpeed(double speed);

    double construct(const vector<double>& args);

    void learn(double answer);

    const double getOutPut();

    const double getError(double answear);

    const vector<double> getWeights();

    void loadWieghts(string fileName);
};

void saveWeights(string fileName, Perceptron& per);