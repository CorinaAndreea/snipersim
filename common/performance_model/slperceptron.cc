#include "slperceptron.h"
#include <cmath>
#include <algorithm>

SLPerceptron::Perceptron::Perceptron(UInt64 numInputs)
    : weights(numInputs, 0), bias(0) {}


SLPerceptron::SLPerceptron(UInt64 numInputs, UInt64 threshold, UInt64 maxWeight)
    : numInputs(numInputs), threshold(threshold), maxWeight(maxWeight) {}


UInt64 SLPerceptron::hashInputs(IntPtr pc, UInt64 coreState, UInt64 coreId) {
    return (pc ^ (coreState << 5) ^ (coreId << 10)) % 1024;  
}


UInt64 SLPerceptron::sign(UInt64 value) {
    return value >= 0 ? 1 : 0;  //  1- active , 0- idle
}


UInt64 SLPerceptron::getInputBit(UInt64 i, IntPtr pc, UInt64 coreState, UInt64 coreId) {
    if (i < 16) {
        return (pc >> i) & 1;  // PC bits
    } else if (i < 24) {
        return (coreState >> (i - 16)) & 1;  // core state bits
    } else {
        return (coreId >> (i - 24)) & 1;  // core ID bits
    }
}


UInt64 SLPerceptron::predict(IntPtr pc, UInt64 coreState, UInt64 coreId) {
    UInt64 hashIndex = hashInputs(pc, coreState, coreId);
    if (perceptronTable.find(hashIndex) == perceptronTable.end()) {
        perceptronTable[hashIndex] = Perceptron(numInputs); 
    }

    Perceptron& perceptron = perceptronTable[hashIndex];
    UInt64 output = perceptron.bias;

    // Weighted sum 
    for (UInt64 i = 0; i < numInputs; ++i) {
        UInt64 input = getInputBit(i, pc, coreState, coreId);
        output += perceptron.weights[i] * input;
    }

    return sign(output);  // 1 (active) or 0 (idle)
}

UInt64 absoluteValue(UInt64 x) {
    return (x < 0) ? -x : x;
}


void SLPerceptron::train(IntPtr pc, UInt64 coreState, UInt64 coreId, UInt64 actualState) {


    UInt64 hashIndex = hashInputs(pc, coreState, coreId);
    if (perceptronTable.find(hashIndex) == perceptronTable.end()) {
        perceptronTable[hashIndex] = Perceptron(numInputs);  
    }

    Perceptron& perceptron = perceptronTable[hashIndex];
    UInt64 output = perceptron.bias;


    for (UInt64 i = 0; i < numInputs; ++i) {
        UInt64 input = getInputBit(i, pc, coreState, coreId);
        output += perceptron.weights[i] * input;
    }

    UInt64 prediction = sign(output);

    if (prediction != actualState || absoluteValue(output) <= threshold) {
        for (UInt64 i = 0; i < numInputs; ++i) {
            UInt64 input = getInputBit(i, pc, coreState, coreId);
            perceptron.weights[i] += input * (actualState ? 1 : -1);
            perceptron.weights[i] = std::max(-maxWeight, std::min(maxWeight, perceptron.weights[i]));  // Saturate weights
        }
        perceptron.bias += (actualState ? 1 : -1);
        perceptron.bias = std::max(-maxWeight, std::min(maxWeight, perceptron.bias));  // Saturate bias
    }
}
