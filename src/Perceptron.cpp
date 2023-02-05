#include"Perceptron.h"
#include<iostream>

Perceptron::Perceptron(int capasity)
{
    weights.resize(capasity);
    for(auto& x : weights)
    {
        x=(rand()%1000-500)/1000.0;
    }
    bias=(rand()%1000-500)/1000.0;
}

void Perceptron::setPerceptron(int capasity)
{
    weights.resize(capasity);
    for(auto& x : weights)
    {
        x=(rand()%1000-500)/1000.0;
    }
    bias=(rand()%1000-500)/1000.0;
}

double Perceptron::construct(const vector<double>& args)
{
    exInputs=args;
    summ=0;

    for (int i = 0; i < weights.size(); i++)
    {
        summ+=args[i]*weights[i];
    }
    summ+=bias;
    return activationFunction(summ);
}

void Perceptron::learn(double answear)
{
    double error=answear-activationFunction(summ);
    double teta=error*deactivationFunction(summ);

    for (int i = 0; i < weights.size(); i++)
    {
        weights[i]+=learningSpeed*teta*exInputs[i];
    }
    bias+=learningSpeed*teta;
}

double Perceptron::activationFunction(double value)
{
    return 1.0 / (1.0 + exp(-value));
}

double Perceptron::deactivationFunction(double value)
{
    return activationFunction(value) * (1. - activationFunction(value));
}

const double Perceptron::getOutPut()
{
    return activationFunction(summ);
}

void Perceptron::setLearningSpeed(double speed)
{
    this->learningSpeed=speed;
}

const double Perceptron::getError(double answear)
{
    return answear-activationFunction(summ);
}

const vector<double> Perceptron::getWeights() 
{
    return weights;
}

void saveWeights(string fileName, Perceptron& per)
{
    ofstream file;
    file.open(fileName);
    for(auto& x : per.getWeights())
    {
        file<<to_string(x)+"\n";
    }
    file.close();
}

void Perceptron::loadWieghts(string fileName)
{
    ifstream file;
    file.open(fileName);
    for(auto& x:weights)
    {
        string buff;
        getline(file, buff);
        x=stod(buff);
    }
    file.close();
}