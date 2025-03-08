#include <iostream>
#include <vector>

float fir(float *input, float *filter, int i, int numTaps) {
    float sum = 0;
    for (int j = 0; j < numTaps; j++) {
        if (i < j) {
            continue;
        }
        sum += input[i-j] * filter[j];
    }
    return sum;
}

int main() {
    // Example usage
    std::vector<float> input = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<float> filter = {0.1, 0.2, 0.3};
    int numTaps = filter.size();
    std::vector<float> output(input.size());

    for (int i = 0; i < input.size(); i++) {
        output[i] = fir(input.data(), filter.data(), i, numTaps);
        std::cout << "Output[" << i << "] = " << output[i] << std::endl;
    }

    return 0;
}
