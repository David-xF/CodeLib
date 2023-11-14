#pragma once

#include <code/code.h>

namespace mc {
    int toInt(float input) {
        bool negative = input < 0.0f;
    	if (negative) input *= -1.0f; 

    	uint32_t output = static_cast<uint32_t>(input);
    	if (negative) {
    		output -= 0x80000000;
            output  = 0x80000000 - output;
    		output -= 1;
    	}
    
    	return output;
    }

    float toFloat(int input) {
        bool negative = 0 > input;
        unsigned int output_tmp = negative ? -input : input;
        float output = static_cast<float>(output_tmp);
        return negative ? -output : output;
    }
}