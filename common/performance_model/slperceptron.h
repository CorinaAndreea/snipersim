#ifndef SLPERCEPTRON_H
#define SLPERCEPTRON_H

#include <vector>
#include "fixed_types.h"
#include <unordered_map>


class SLPerceptron {
private:
    
    struct Perceptron {
        std::vector<UInt64> weights;  // Weights for perceptron
        UInt64 bias;  
   
        //Default constructor
        Perceptron() : bias(0){}

        Perceptron(UInt64 numInputs);
    };

    UInt64 numInputs;   // Number of inputs (PC bits + state bits + core ID)
    UInt64 threshold;                      
    UInt64 maxWeight;                 
    std::unordered_map<UInt64, Perceptron> perceptronTable;  


    UInt64 hashInputs(IntPtr pc, UInt64 coreState, UInt64 coreId);


    UInt64 sign(UInt64 value);


    UInt64 getInputBit(UInt64 i, IntPtr pc, UInt64 coreState, UInt64 coreId);

public:

    SLPerceptron(UInt64 numInputs, UInt64 threshold, UInt64 maxWeight);

    
    UInt64 predict(IntPtr pc, UInt64 coreState, UInt64 coreId);

    
    void train(IntPtr pc, UInt64 coreState, UInt64 coreId, UInt64 actualState);
};

#endif  // SLPERCEPTRON_H
