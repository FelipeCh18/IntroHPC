#include "vector_ops.hpp"
double mean(const std::vector<double> & data)
{
    if (data.empty()) {
        return 0; // Handle empty vector case (optional)
    }
    double sum = 0.0;
    for (const double& value : data) {
        sum += value;
    }
    return sum / data.size();
}