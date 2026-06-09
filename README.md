<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Global Lagrange Interpolation - Project Documentation</title>
</head>
<body>

<h1>Global Lagrange Interpolation</h1>

<p>Educational project on numerical methods: <strong>global interpolation of a function using the Lagrange polynomial</strong>.</p>

<p>The C++ program generates random nodes on a given interval, computes function values, constructs the global Lagrange interpolation polynomial, and writes the results to a file. A Python script loads the data and plots the original function alongside the interpolating polynomial. Instructor requirements for the task: the use of <code>std::vector</code> is not allowed; manual memory management and OOP practices must be employed.</p>

<h2>Project Structure</h2>
<pre>
global_lagrange/
├── src/          # C++ source code
├── include/      # header files
├── scripts/      # Python script for visualisation
├── Makefile      # builds the C++ part
└── requirements.txt  # Python dependencies
</pre>

<h2>Requirements</h2>
<ul>
    <li>C++ compiler with C++11 support (e.g., <code>g++</code>)</li>
    <li><code>make</code> utility</li>
    <li>Python 3.6 or higher</li>
    <li>Python libraries: <code>matplotlib</code>, <code>numpy</code> (installed via <code>requirements.txt</code>)</li>
</ul>

<h2>Quick Start</h2>
<ol>
    <li>
        <strong>Clone the repository:</strong>
        <pre><code>git clone https://github.com/g30613740/global_lagrange.git
cd global_lagrange</code></pre>
    </li>
    <li>
        <strong>Build the C++ program:</strong>
        <pre><code>make</code></pre>
    </li>
    <li>
        <strong>Run the program – it will create the data file <code>parameters.txt</code>:</strong>
        <pre><code>./a</code></pre>
    </li>
    <li>
        <strong>Install Python dependencies (if not already installed):</strong>
        <pre><code>pip install -r requirements.txt</code></pre>
    </li>
    <li>
        <strong>Generate the plot:</strong>
        <pre><code>python scripts/create_plot.py</code></pre>
        <p>As a result, the image <code>lagrange_plot.png</code> will appear.</p>
    </li>
</ol>

<h2>Example Result</h2>
<p><a href="https://github.com/g30613740/global_lagrange/blob/main/lagrange_plot.png">https://github.com/g30613740/global_lagrange/blob/main/lagrange_plot.png</a></p>

<h2>Adjusting Interpolation Parameters</h2>
<p>You can change the interpolated function, the interpolation interval, the number of nodes, and other parameters by editing the files <code>src/main.cpp</code> or <code>include/functions.h</code>. After making changes, rebuild the program (<code>make</code>) and run it again.</p>

<h2>License</h2>
<p>This project is distributed under the MIT License. See the <code>LICENSE</code> file for details.</p>

</body>
</html>