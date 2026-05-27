import matplotlib.pyplot as plt
import numpy as np
import math
import sys

def main():
       f = open ("parameters.txt", "r")

       a = float (f.readline ())
       b = float (f.readline ())
       N = int (f.readline ())
       M = int (f.readline ())

       x = (f.readline ()).split ()
       y = (f.readline ()).split ()
       for i in range (N):
              x[i] = float (x[i])
              y[i] = float (y[i])

       grid_x = (f.readline ()).split ()
       value_of_the_math_function_in_the_point = (f.readline ()).split()
       polynoms_value_in_the_point = (f.readline ()).split()

       for i in range (M):
              grid_x[i] = float (grid_x[i])
              value_of_the_math_function_in_the_point[i] = float (value_of_the_math_function_in_the_point[i])
              polynoms_value_in_the_point[i] = float (polynoms_value_in_the_point[i])

       f.close ()

       fig, ax = plt.subplots ()                                                                         # create plot
       ax.plot (grid_x, value_of_the_math_function_in_the_point, "k:", linewidth = 1.0, label = "f(x)")  # draw f(x)
       ax.plot (grid_x, polynoms_value_in_the_point, "k", linewidth = 2.0, label = "L(x)")               # draw L(x)
       ax.plot (x, y, "o")
       ax.legend ()
       ax.grid ()

       # save the plot
       output_filename = 'lagrange_plot.png'
       plt.savefig(output_filename, dpi=150, bbox_inches='tight')
       
       # plt.show ()                                                                                       # show the figure

if __name__ == '__main__':
       main()