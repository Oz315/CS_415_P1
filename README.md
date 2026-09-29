# Team Information
Oscar Huitron-Gonzalez
Shakira Garcia

# Generative AI Usage

I used Generated AI to help me better understand the project requirements by helping me refresh my understanding of scatterplots, which has been a while for me. I know it's in one of the sections, but I still need more of a grasp. I was also looking at GeekforGeeks further visualization of it: (https://www.geeksforgeeks.org/maths/scatter-plot/). I also asked what's the purpose of having two modes like User testing mode and Scatter Plot mode. 

Prompts/chat history:
"I needed a refresher about scatter plot. What is a scatter plot's job and purpose?"

A scatter plot is a graph used to show the relationship between two numerical values.
Each dot represents one pair of values:
(x,y)
For example, imagine you want to see how study time relates to exam scores:
Hours studied     Exam score
1                 60
2                 68
3                 75
4                 84
5                 91

A scatter plot would put:
- Hours studied on the x-axis
- Exam score on the y-axis
- One dot for each pair, such as (1,60), (2,68), etc.
The main purpose of the scatter plot is to let you see a pattern or trend in the data. You might notice that as one value increases, the other increases, decreases, stays about the same, or grows in a particular shape.


"What's the purpose of having two modes and what's purpose of them individually?"
The purpose of having two modes is to separate two different jobs:
- one mode is for a person to try the program manually
- the other mode is for the program to run a large experiment automatically
User Testing Mode
The purpose of User Testing Mode is to let the user choose a small input and see that the program actually works.
It is interactive:
User enters input
        ↓
Program runs the algorithm
        ↓
Program displays the result
        ↓
Program ends

For example, if the algorithm takes two numbers, User Testing Mode might do:
Enter a: 2
Enter n: 5

Result: 32

This mode is mainly about correctness.
It answers:
"If I give this program an input, does it produce the right answer?"

It is also useful for your professor because they can run the executable, enter their own values, and test your functions without modifying your code.

Scatterplot Mode
The purpose of Scatterplot Mode is not really to test one answer. It is to collect a lot of measurements automatically so you can study how the algorithm grows as the input gets larger.
It works more like:
Program chooses many input sizes automatically
        ↓
Runs algorithm for each input size
        ↓
Counts the basic operations
        ↓
Saves those measurements
        ↓
Program ends


# Instructions/ Compiling the Program
Screenshots of the scatterplot graphs are provided in the zip folder.


For Task 1 in user testing mode, k is all that is needed to find the k-1 term in the Fibonacci sequence which will then be used to find GCD, treating k-1 as k+1 in terms of GCD(Fib(k+1), Fib(k)) for GCD's worst case.
In user testing mode, that term will be printed out alongside with GCD.

In scatterplot mode, a range of k is used instead to calculate for Fibonacci and GCD, both of which have their values stored onto the fibonacci_gcd.csv file.
Elapsed time is not recorded, only the number of basic operations (additions for Fibonacci and divisions for GCD).

The respective image for Task 1 is aptly named, task1.png.
To use the scatterplot yourself, open the scatterplot_fibonacci_gcd.html file in a browser, set the y metric to ops_total, choose the previously mentioned csv file, and the scale to what you choose.
Please note that in terms of the csv file, Fibonacci records starting from one and not zero, because GCD also starts from one. The two base cases of Fibonacci, if included, create an offset on the graph.

// Generate Task 2 scatterplot data
    task2ScatterMode();   <-- function call that actually runs the Task 2 scatterplot-data

The program is written in C++ and can be compiled with:
g++ main.cpp -o main

Running the Program
Run the program with:
./main

The program prints the results of the implemented algorithms and their basic operation counts.
For the scatter plot data, the program creates CSV files containing the operation counts. The CSV files can then be loaded into the provided D3 HTML graph.
Task 2 CSV
Task 2 creates:
task2.csv

This file contains the results for:
decrease_by_one
decrease_by_constant_factor
divide_and_conquer

The CSV uses the format:
impl,N,elapsed_ms,ops_total

For the graphs, ops_total is the basic operation count.
Task 3 CSV Files
Task 3 creates:
task3_best.csv
task3_average.csv
task3_worst.csv

These files compare Selection Sort and Insertion Sort.
task3_best.csv
    Uses the sorted input files.

task3_average.csv
    Uses the random input files.

task3_worst.csv
    Uses the reverse-sorted input files.


The Task 3 data files are located inside the testSet folder.
Viewing the Graphs
Open:
insertion_sort_tooltips_slider_selectors_fixed.html

In a web browser:
Use the CSV file option and select the CSV that you want to graph.
Set:
Y metric: ops_total
X scale: linear

For Task 2, load:
task2.csv

For Task 3, load each of these separately:
task3_best.csv
task3_average.csv
task3_worst.csv

The x-axis represents the input size N. The y-axis represents the basic operation count.
