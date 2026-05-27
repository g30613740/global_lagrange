#include "functions.h"

const long double MIN_DISTANCE = 1.0e-3;

int resources_filling (
    long double* &x_nodes,
    long double* &y_nodes,
    long double* &weights,
    const size_t len_XYZ,
    const long double bound_a,
    const long double bound_b) {

    // uniform distribution filling array x
    x_nodes = new long double[len_XYZ];                      // array of nodes of Lagrange polynom
    random_device rd;                                        // a seed source for the random number engine
    mt19937 gen (rd ());                                     // mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> distrib (bound_a, bound_b);  // segment boundaries
    size_t k = 1;
    while (true) {
        if (k == len_XYZ - 1)
            break;
        x_nodes[k] = distrib (gen);
        if (k == 1) {
            ++k;
            continue;
        }
        unsigned int count = 0;
        for (size_t i = 1; i < k; ++i) {
            if (fabs (x_nodes[k] - x_nodes[i]) < MIN_DISTANCE)
                ++count;
        }
        if (count > 0)
            continue;
        else
            ++k;
    }
  
    x_nodes[0] = bound_a;
    x_nodes[len_XYZ-1] = bound_b;

    // filling array y
    y_nodes = new long double[len_XYZ];
    for (size_t i = 0; i < len_XYZ; ++i)
        y_nodes[i] = get_value_of_the_math_function_in_the_point (x_nodes[i]);

    // w is the array of denomenator values
    weights = new long double[len_XYZ];
    for (size_t i = 0; i < len_XYZ; ++i) {
        long double prod = 1.;
        for (size_t j = 0; j < len_XYZ; ++j) {
            if (i == j)
                continue;
            prod *= x_nodes[i] - x_nodes[j];
        }
        weights[i] = prod;
    }

    return 0;
}

long double get_polynoms_value_in_the_point (
    long double* x_nodes,
    long double* y_nodes,
    long double* weights,
    const size_t len_XYZ,
    const long double point) {

    long double sum = 0.; // value of polynom in given point
    for (size_t i = 0; i < len_XYZ; ++i) {
        long double prod = 1.; // numerator
        for (size_t j = 0; j < len_XYZ; ++j) {
            if (i != j)
                prod *= point - x_nodes[j];
        }
        sum += y_nodes[i] * prod / weights[i]; 
    }
    return sum;
}

void freeing_up_resources (
    long double* &x_nodes,
    long double* &y_nodes,
    long double* &weights) {

    delete [] x_nodes;
    delete [] y_nodes;
    delete [] weights;
}

long double get_value_of_the_math_function_in_the_point (long double point) {
    return sin (point);
}

void extract_parameters_to_the_file (
    long double* &x_nodes,
    long double* &y_nodes,
    long double* &weights,
    const size_t len_XYZ,
    const size_t len_of_grid,
    const long double bound_a,
    const long double bound_b) {

    ofstream file;                                                                           // create file "parameters.txt"
    
    file.open ("parameters.txt");                                                            // writing to this file parameters
    file << bound_a << '\n' << bound_b << '\n' << len_XYZ << '\n' << len_of_grid << '\n';    // 1st string: a and b and M

    for (size_t i = 0; i < len_XYZ; ++i) {
        file << x_nodes[i] << ' ';
    }
    file << '\n';

    for (size_t i = 0; i < len_XYZ; ++i) {
        file << y_nodes[i] << ' ';
    }
    file << '\n';

    long double delta = (bound_b - bound_a) / len_of_grid;                                   // grid step
    // problem: b = 1 is not in an array 
    for (size_t i = 0; i < len_of_grid - 1; ++i)                                             // 2nd string: grid for x
        file << bound_a + delta * i << ' ';
    file << bound_b << endl;

    for (size_t i = 0; i < len_of_grid - 1; ++i)                                             // 3rd string: values of math function in points of grid
        file << get_value_of_the_math_function_in_the_point (bound_a + delta * i) << ' ';
    file << get_value_of_the_math_function_in_the_point (bound_b) << endl;

    for (size_t i = 0; i < len_of_grid - 1; ++i)                                             // 4th string: values of lagrange polynom in points of grid
        file << get_polynoms_value_in_the_point (x_nodes, y_nodes, weights, len_XYZ, bound_a + delta * i) << ' ';
    file << get_polynoms_value_in_the_point (x_nodes, y_nodes, weights, len_XYZ, bound_b) << endl;

    file.close ();
}
