#include <iostream>
#include <fstream>
#include <cmath>
#include <filesystem>
#include <array>
#include <cstring>
//Just a note for all these functions, I don't think we're exactly
//allowed to have another parameter for counting but I'm doing it just cause its easiest
//but the only other thing i can think of while keeping these functions
//as basic as possible is to create a struct/class and use that for
//count but that seems also really poor

//return kth fib number AND number of additions-recursive
int Fib(int k, int &count) {
    if (k == 0)
        return 0;
    if (k == 1)
        return 1;
    count++;
    return Fib(k - 1, count) + Fib(k - 2, count);
}

// For task 1b, its the same GCD algorithm that we did on the homework
// But he's saying for testing that the pattern of fibonacci
// 0 1 1 2 3 5 8 13...
// we can test GCD(m, n) by using any two consecutive numbers
// so m = 8 and n = 5 or m = 13 and n = 8 because that will give us the worst case
// also we are presuming for this function that n <= m
// it doesn't say whether to make it recursive or not but im making it iterative

int gcd(int m, int n, int &count) {
    int r = 0;
    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
        count++;
    }
    return m;
}

// This is exponentiation done decrease-by-one
int dbo(int a, int n) {
    if (n == 0)
        return 1;
    return a * dbo(n - 1, n);
}

//decrease by constant factor
int dbcf(int a, int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 0) // if even then...
        return std::pow(dbcf(a, n / 2), 2); //pow returns double for some reason but i think its fine
    else
        return a * std::pow(dbcf(a, n-1 / 2), 2);
}

// divide and conquer
int dac(int a, int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return dac(a, n / 2) * dac(a, n / 2);
    else
        return a * dac(a, n-1 / 2) * dac(a, n-1 / 2);
}

//if the array has n elements, size = n
void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (array[min] > array[j]) { //found a smaller number
                min = j;
            }
        }
        //swap values...could just use the swap function here but up to you, makes it easier to count basic operations
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

// hopefully implemented this right
void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {

        for (int j = i - 1; j >= 0 && array[j] > array[i]; j--) {
            int temp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = temp;
        }
    }
}
// obviously need to still implement the code to test the functions
int main() {
    //this N deals with the number of values we are using for Task 1
    int mode = 0;
    std::cout << "Which mode would you like to enter?\nType 1 for User Testing\nType 2 for Scatterplots\n";
    std::cin >> mode;
    if (!(mode == 1 || mode == 2)) {
        std::cerr << "Please enter a valid Mode...\n";
        return 1;
    }
    //
    if (mode == 1) {
        int k = 0;
        int a = 0;
        int n = 0;
        int n2 = 0;
        int counter = 0;
        std::cout << "For Task 1, please enter a value for k for the programs Fib(k) and GCD(m, n): ";
        std::cin >> k;
        std::cout << "For Task 2, please enter values for a and n for exponential functions (first is a, the base): ";
        std::cin >> a;
        std::cout << "Now the value for n(the power): ";
        std::cin >> n;
        std::cout << "For Task 3, just enter a value for n for the size of the list. Ensure the value is between 10-100 with increments of 10: ";
        std::cin >> n2;
        if (n2 < 10 || n2 > 100 || n2 % 10 != 0) {
            std::cerr << "Please enter a valid value for n\n";
            return 1;
        }
        int gcd_input[k];
        std::ofstream output_file;

        // This section is Task 1A
        output_file.open("csvs/fibonacci_gcd.csv");
        if (!output_file.is_open()) {
            std::cerr << "Error opening file because: " << std::strerror(errno);
            return 1;
        }
        output_file << "impl,N,elapsed_ms,ops_total\n";
        for (int i = 0; i < k; i++) {
            gcd_input[i] = Fib(i, counter); //ill update this to apply the values to some array for gcd
            output_file << "Fibonacci," << i << ",0," << counter << "\n";
            counter = 0; //counter is basically the asmyptotic complexity
        }
        //Now we try task 1B
        for (int i = 1; i+1 < k; i++) {
            int temp = gcd(gcd_input[i+1], gcd_input[i], counter);
            output_file << "GCD," << i << ",0," << counter << "\n";
            counter = 0;
        }

        output_file.close();

        //Here is the portion for Task 2

        //Here we do Task 3
    }
    else { //This else is for Scatterplot mode, there technically isn't much to do here
        //I guess we can check to make sure the necessary csv files exist

    }
    return 0;
}