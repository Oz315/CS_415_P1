#include <iostream>
#include <fstream>
#include <cmath>
#include <filesystem>
#include <vector>
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

//don't think we have to count operations for task 2

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
    int input;
    int counter = 0;
    std::ofstream output_file;
    output_file.open("csvs/fibonacci.csv");
    if (!output_file.is_open()) {
        std::cerr << "Error opening file" << std::strerror(errno);
        return 1;
    }
    output_file << "n,TimeComplexity\n";
    for (int n = 0; n < 30; n++) {
        int temp = Fib(n, counter); //ill update this to apply the values to some array for gcd
        output_file << n << "," << counter << "\n";
        counter = 0; //counter is basically the time complexity, i think
    }

    output_file.close();
    /*
    std::cout << "Please enter value for Fibonacci sequence: ";
    //there is absolutely no safety checks, implement them later
    std::cin >> input;
    std::cout << "This is the Fibonacci sequence for " << input << std::endl;
    std::cout << Fib(input, counter) << std::endl;
    std::cout << "The number of additions is " << counter << std::endl;
    */
    return 0;
}