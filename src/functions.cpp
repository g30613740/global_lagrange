#include "functions.h"


int resources_filling (
    long double* &a_x,
    long double* &a_y,
    long double* &a_z,
    const size_t len_XYZ,
    const long double bound_a,
    const long double bound_b) {

    a_x = new long double[len_XYZ];                          // array of x_i
    // uniform distribution filling array x
    random_device rd;                                        // a seed source for the random number engine
    mt19937 gen (rd ());                                     // mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> distrib (bound_a, bound_b);  // segment boundaries
    size_t k = 1;
    while (true) {
        if (k == len_XYZ - 1)
            break;
        a_x[k] = distrib (gen);
        if (k == 1) {
            ++k;
            continue;
        }
        unsigned int count = 0;
        for (size_t i = 1; i < k; ++i) {
            if (fabs (a_x[k] - a_x[i]) < 1.0e-3)
                ++count;
        }
        if (count > 0)
            continue;
        else
            ++k;
    }
  
    a_x[0] = bound_a;
    a_x[len_XYZ-1] = bound_b;

    // filling array y
    a_y = new long double[len_XYZ];
    for (size_t i = 0; i < len_XYZ; ++i)
        a_y[i] = get_value_of_the_math_function_in_the_point (a_x[i]);

    // filling an array z
    // z is the array of denumenator values
    a_z = new long double[len_XYZ];
    for (size_t i = 0; i < len_XYZ; ++i) {
        long double prod = 1.;
        for (size_t j = 0; j < len_XYZ; ++j) {
            if (i == j)
                continue;
            prod *= a_x[i] - a_x[j];
        }
        a_z[i] = prod;
    }

    if (a_x == nullptr or a_y == nullptr or a_z == nullptr)
    	return -1;

    return 0;
}

long double get_polynoms_value_in_the_point (
    long double* a_x,
    long double* a_y,
    long double* a_z,
    const size_t len_XYZ,
    const long double point) {

    long double sum = 0.; // value of polynom in given point
    for (size_t i = 0; i < len_XYZ; ++i) {
        long double prod = 1.; // numerator
        for (size_t j = 0; j < len_XYZ; ++j) {
            if (i != j)
                prod *= point - a_x[j];
        }
        sum += a_y[i] * prod / a_z[i]; 
    }
    return sum;
}

void freeing_up_resources (
    long double* &a_x,
    long double* &a_y,
    long double* &a_z) {

    delete [] a_x;
    delete [] a_y;
    delete [] a_z;
}

long double get_value_of_the_math_function_in_the_point (long double point) {
    return sin (point);
}

void extract_parameters_to_the_file (
    long double* &a_x,
    long double* &a_y,
    long double* &a_z,
    const size_t len_XYZ,
    const size_t len_of_grid,
    const long double bound_a,
    const long double bound_b) {

    ofstream file;                                                                           // create file "parameters.txt"
    
    file.open ("parameters.txt");                                                            // writing to this file parameters
    file << bound_a << '\n' << bound_b << '\n' << len_XYZ << '\n' << len_of_grid << '\n';    // 1st string: a and b and M

    for (size_t i = 0; i < len_XYZ; ++i) {
        file << a_x[i] << ' ';
    }
    file << '\n';

    for (size_t i = 0; i < len_XYZ; ++i) {
        file << a_y[i] << ' ';
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
        file << get_polynoms_value_in_the_point (a_x, a_y, a_z, len_XYZ, bound_a + delta * i) << ' ';
    file << get_polynoms_value_in_the_point (a_x, a_y, a_z, len_XYZ, bound_b) << endl;

    file.close ();
}
