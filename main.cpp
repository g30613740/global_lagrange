#include "functions.h"

int main () {

	const long double a = 0.0, b = 6.5;
    const size_t N = 20, M = 500;                   
    long double *x = nullptr, *y = nullptr, *z = nullptr;

    int error = resources_filling (x, y, z, N, a, b);
    if (error == -1) {
        cout << "Error while allocating resources" << endl;
        return -1;
    }

    extract_parameters_to_the_file (x, y, z, N, M, a, b);

    string comand_and_filename = "python3 create_plot.py"; // start Python
    system (comand_and_filename.c_str ());                 // calling Python

    freeing_up_resources (x, y, z);

    return 0;
}