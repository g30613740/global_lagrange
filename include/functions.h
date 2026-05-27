#include <iostream>
#include <fstream>
#include <random>

using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int resources_filling (
    long double* &x_nodes,
    long double* &y_nodes,
    long double* &weights,
    const size_t len_XYZ,
    const long double bound_a,
    const long double bound_b);

long double get_polynoms_value_in_the_point (
    long double *x_nodes,
    long double *y_nodes,
    long double *weights,
    const size_t len_XYZ,
    const long double point);

void freeing_up_resources (
    long double* &x_nodes,
    long double* &y_nodes,
    long double* &weights);

long double get_value_of_the_math_function_in_the_point (long double point);

void extract_parameters_to_the_file (
    long double* &x_nodes,
    long double* &y_nodes,
    long double* &weights,
    const size_t len_XYZ,
    const size_t len_of_grid,
    const long double bound_a,
    const long double bound_b);

#endif