#include <iostream>
#include <fstream>
#include <cmath>
#include <filesystem>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// Task 1
// Fibonacci Sequence (Recursive Form)
long long fib(int k, int &count) {
    if (k == 0)
        return 0;
    if (k == 1)
        return 1;
    count++;
    return fib(k - 1, count) + fib(k - 2, count);
}

//GCD (Using Euclid's Algorithm/Iterative)
long long gcd(long long m, long long n, int &count) {
    int r = 0;
    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
        count++;
    }
    return m;
}

// Task 2
// Decrease-by-one exponentiation
// This version keeps subtracting 1 from n until n reaches 0
long long dbo(long long a, int n, long long &counter) {

    // Base case: any number to the power of 0 is 1
    if (n == 0) {
        return 1;
    }

    // Solve the smaller problem first, which is a^(n - 1)
    long long smaller = dbo(a, n - 1, counter);

    // We are about to multiply a by the smaller answer
    // This is the basic operation we are counting
    ++counter;

    // Example: if n = 4, this would be a * a^3
    return a * smaller;
}


// Decrease-by-constant-factor exponentiation
// This version makes n much smaller by dividing it by 2
long long dbcf(long long a, int n, long long &counter) {

    // Base case: a^0 = 1
    if (n == 0) {
        return 1;
    }

    // If n is even, we can split the exponent in half
    if (n % 2 == 0) {

        // Only make ONE recursive call and save the answer
        // Example: a^8 can use a^4
        long long smaller = dbcf(a, n / 2, counter);

        // Now multiply the smaller answer by itself
        // Example: a^4 * a^4 = a^8
        ++counter;

        return smaller * smaller;
    }

    // If n is odd, we cannot divide it evenly by 2
    else {

        // Subtract 1 first so the exponent becomes even,
        // then divide it by 2
        // Example: if n = 5, (5 - 1) / 2 = 2
        long long smaller = dbcf(a, (n - 1) / 2, counter);

        // First multiply the smaller answer by itself
        // Example: a^2 * a^2 = a^4
        ++counter;
        long long square = smaller * smaller;

        // Since the original exponent was odd,
        // multiply by one more a
        // Example: a * a^4 = a^5
        ++counter;

        return a * square;
    }
}


// Divide-and-conquer exponentiation
// This also divides n by 2, but it makes TWO recursive calls
// instead of saving one answer and reusing it
long long dac(long long a, int n, long long &counter) {

    // Base case: a^0 = 1
    if (n == 0) {
        return 1;
    }

    // If n is even, both recursive calls use n / 2
    if (n % 2 == 0) {

        // Find the first half
        long long left = dac(a, n / 2, counter);

        // Find the second half
        // We actually call the function again here
        long long right = dac(a, n / 2, counter);

        // Multiply the two halves together
        // Example: a^4 * a^4 = a^8
        ++counter;

        return left * right;
    }

    // If n is odd, subtract 1 first so it can be divided by 2
    else {

        // First recursive half
        long long left = dac(a, (n - 1) / 2, counter);

        // Second recursive half
        // This is another full recursive call
        long long right = dac(a, (n - 1) / 2, counter);

        // Multiply the two recursive answers together
        ++counter;
        long long product = left * right;

        // Because n was odd, multiply by one extra a
        ++counter;

        return a * product;
    }
}
//Task 3
// Sorts the array using Selection Sort
void selectionSort(vector<int> &array, long long &counter) {
    int size = array.size(); // Store the number of values in the array

    // Move through each position in the array
    for (int i = 0; i < size - 1; i++) {
        int min = i;   // Assume the current position has the smallest value

        // Look through the rest of the array for a smaller value
        for (int j = i + 1; j < size; j++) {
            ++counter;   // Count the comparison between two array values

            // If a smaller value is found, remember its position
            if (array[j] < array[min]) {
                min = j;
            }
        }

        // Swap the smallest value found with the current position
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}


// Sorts the array using Insertion Sort
void insertionSort(vector<int> &array, long long &counter) {
    // Store the number of values in the array
    int size = array.size();

    // Start at the second value because the first value is already considered sorted
    for (int i = 1; i < size; i++) {
        // Save the value that needs to be placed
         // Start checking the value directly before it
        int value = array[i];
        int j = i - 1;

        // Keep checking values to the left while there are still values left
         // Count the comparison between array[j] and value
        while (j >= 0) {
            ++counter;

            // If the value on the left is larger, move it one position to the right
            if (array[j] > value) {
                array[j + 1] = array[j];
                j--;
            }
            else {
                // Stop once the correct position for value is found
                break;
            }
        }

        // Place the saved value into its correct position
        array[j + 1] = value;
    }
}

// Reads the numbers from a file and stores them in a vector
bool readFile(string filename, vector<int> &array) {
    ifstream inputFile(filename);

    // Check if the file opened correctly
    if (!inputFile) {
        cout << "Unable to open " << filename << endl;
        return false;
    }

    int number;

    // Read each number from the file
    while (inputFile >> number) {
        array.push_back(number);
    }

    inputFile.close();
    return true;
}

// User testing mode for Task 3
void task3UserTesting() {
    int n;

    cout << endl;
    cout << "------------------------" << endl;
    cout << "Task 3 User Testing Mode" << endl;
    cout << "------------------------" << endl;

    // Ask the user what size list they want to test
    cout << "Enter a list size from 10 to 100 in increments of 10: ";
    cin >> n;

    // Make sure the user entered a valid size
    if (n < 10 || n > 100 || n % 10 != 0) {
        cout << "Invalid size." << endl;
        return;
    }

    // Build the name of the smallSet file using the size entered
    string filename = "smallSet/data" + to_string(n) + ".txt";

    // Store the original numbers read from the file
    vector<int> originalArray;

    // Stop if the file could not be opened
    if (!readFile(filename, originalArray)) {
        return;
    }

    // Make a copy for each sorting algorithm
    // This lets both sorts start with the exact same values
    vector<int> selectionArray = originalArray;
    vector<int> insertionArray = originalArray;

    // Keep track of comparisons for each sorting method
    long long selectionCounter = 0;
    long long insertionCounter = 0;

    // Sort one copy using Selection Sort
    selectionSort(selectionArray, selectionCounter);

    cout << endl;
    cout << "Selection Sort:" << endl;

    // Print the sorted values from Selection Sort
    for (int number : selectionArray) {
        cout << number << " ";
    }

    // Print how many comparisons Selection Sort made
    cout << endl;
    cout << "Comparisons: " << selectionCounter << endl;

    // Sort the other copy using Insertion Sort
    insertionSort(insertionArray, insertionCounter);

    cout << endl;
    cout << "Insertion Sort:" << endl;

    // Print the sorted values from Insertion Sort
    for (int number : insertionArray) {
        cout << number << " ";
    }

    // Print how many comparisons Insertion Sort made
    cout << endl;
    cout << "Comparisons: " << insertionCounter << endl;
}

// Scatter plot mode for Task 3
void task3ScatterMode() {
    // Files for the best, average, and worst case graphs
    ofstream bestFile("csvs/task3_best.csv");
    ofstream averageFile("csvs/task3_average.csv");
    ofstream worstFile("csvs/task3_worst.csv");

    // Make sure all output files opened correctly
    if (!bestFile || !averageFile || !worstFile) {
        cout << "Unable to create CSV files." << endl;
        return;
    }

    // Column names expected by the HTML graph
    bestFile << "impl,N,elapsed_ms,ops_total" << endl;
    averageFile << "impl,N,elapsed_ms,ops_total" << endl;
    worstFile << "impl,N,elapsed_ms,ops_total" << endl;

    // Test sizes from 100 to 10000
    for (int n = 100; n <= 10000; n += 100) {

        // Build the three filenames for this value of n
        string randomFilename =
            "data/testSet/data" + to_string(n) + ".txt";

        string sortedFilename =
            "data/testSet/data" + to_string(n) + "_sorted.txt";

        string reverseFilename =
            "data/testSet/data" + to_string(n) + "_rSorted.txt";

        vector<int> randomData;
        vector<int> sortedData;
        vector<int> reverseData;

        // Read the random input file
        if (!readFile(randomFilename, randomData)) {
            return;
        }

        // Read the already sorted input file
        if (!readFile(sortedFilename, sortedData)) {
            return;
        }

        // Read the reverse sorted input file
        if (!readFile(reverseFilename, reverseData)) {
            return;
        }


        // --------------------------------
        // Selection Sort
        // --------------------------------

        long long selectionRandomCounter = 0;
        long long selectionSortedCounter = 0;
        long long selectionReverseCounter = 0;

        // Make copies because sorting changes the original vector
        vector<int> selectionRandom = randomData;
        vector<int> selectionSorted = sortedData;
        vector<int> selectionReverse = reverseData;

        selectionSort(selectionRandom, selectionRandomCounter);
        selectionSort(selectionSorted, selectionSortedCounter);
        selectionSort(selectionReverse, selectionReverseCounter);


        // --------------------------------
        // Insertion Sort
        // --------------------------------

        long long insertionRandomCounter = 0;
        long long insertionSortedCounter = 0;
        long long insertionReverseCounter = 0;

        // Make separate copies for Insertion Sort
        vector<int> insertionRandom = randomData;
        vector<int> insertionSorted = sortedData;
        vector<int> insertionReverse = reverseData;

        insertionSort(insertionRandom, insertionRandomCounter);
        insertionSort(insertionSorted, insertionSortedCounter);
        insertionSort(insertionReverse, insertionReverseCounter);


      // --------------------------------
      // Store results in CSV files
      // --------------------------------

       // The 0 is for elapsed_ms because we are only counting basic operations

        // Best case uses the sorted input file
        bestFile << "selection_sort,"
                 << n << ",0,"
                 << selectionSortedCounter << endl;

        bestFile << "insertion_sort,"
                 << n << ",0,"
                 << insertionSortedCounter << endl;


        // Average case uses the random input file
        averageFile << "selection_sort,"
                    << n << ",0,"
                    << selectionRandomCounter << endl;

        averageFile << "insertion_sort,"
                    << n << ",0,"
                    << insertionRandomCounter << endl;


        // Worst case uses the reverse sorted input file
        worstFile << "selection_sort,"
                  << n << ",0,"
                  << selectionReverseCounter << endl;

        worstFile << "insertion_sort,"
                  << n << ",0,"
                  << insertionReverseCounter << endl;


        // Shows progress while the program is running
        cout << "Finished n = " << n << endl;
    }

    // Close the CSV files
    bestFile.close();
    averageFile.close();
    worstFile.close();

    cout << endl;
    cout << "Task 3 scatter mode finished." << endl;
    cout << "Created task3_best.csv" << endl;
    cout << "Created task3_average.csv" << endl;
    cout << "Created task3_worst.csv" << endl;
}



int main() {
    //this N deals with the number of values we are using for Task 1
    int mode = 0;
    cout << "Which mode would you like to enter?\nType 1 for User Testing\nType 2 for Scatterplots\n";
    cin >> mode;
    if (!(mode == 1 || mode == 2)) {
        cerr << "Please enter a valid Mode...\n";
        return 1;
    }
    //
    if (mode == 1) {
        int k = 0;
        int a = 0;
        int n = 0;
        int n2 = 0;
        int counter = 0;
        long long dboCounter = 0;
        long long dbcfCounter = 0;
        long long dacCounter = 0;
        cout << "For Task 1, please enter a value for k for the programs Fib(k) and GCD(m, n): ";
        cin >> k;
        cout << "For Task 2, please enter values for a and n for exponential functions (first is a, the base): ";
        cin >> a;
        cout << "Now the value for n(the power): ";
        cin >> n;
        cout << "For Task 3, just enter a value for n for the size of the list. Ensure the value is between 10-100 with increments of 10: ";
        cin >> n2;
        if (n2 < 10 || n2 > 100 || n2 % 10 != 0) {
            cerr << "Please enter a valid value for n\n";
            return 1;
        }
        long long gcd_input[k];
        ofstream output_file;

        // This section is Task 1A
        output_file.open("csvs/fibonacci_gcd.csv");
        if (!output_file.is_open()) {
            cerr << "Error opening file because: " << strerror(errno);
            return 1;
        }
        long long temp = 0;
        output_file << "impl,N,elapsed_ms,ops_total\n";
        for (int i = 0; i < k; i++) {
            temp = fib(i, counter); //ill update this to apply the values to some array for gcd
            gcd_input[i] = temp;
            output_file << "Fibonacci," << i << ",0," << counter << "\n";
            counter = 0; //counter is basically the asmyptotic complexity
        }
        //At this point temp should be holding the proper fib(k) value so we print it
        cout << "Fib(" << k << ") = " << temp << "\n";
        //Now we try task 1B
        for (int i = 1; i+1 < k; i++) {
            temp = gcd(gcd_input[i+1], gcd_input[i], counter);
            output_file << "GCD," << i << ",0," << counter << "\n";
            counter = 0;
        }
        cout << "GCD(Fib(" << k << "+1), Fib(" << k << ") = " << temp << "\n\n";

        output_file.close();

        // Test decrease-by-one
        cout << "Decrease-by-one: " << dbo(2, 5, dboCounter) << endl;
        cout << "Multiplications: " << dboCounter << endl;

        cout << endl;

        // Test decrease-by-constant-factor
        cout << "Decrease-by-constant-factor: " << dbcf(2, 5, dbcfCounter) << endl;
        cout << "Multiplications: " << dbcfCounter << endl;

        cout << endl;

        // Test divide-and-conquer
        cout << "Divide-and-conquer: " << dac(2, 5, dacCounter) << endl;
        cout << "Multiplications: " << dacCounter << endl;

        cout << endl;
        cout << "------------------------" << endl;
        cout << "Task 3 Sorting Tests" << endl;
        cout << "------------------------" << endl;

        // Same starting values for both sorting methods
        vector<int> selectionArray = {5, 2, 4, 1, 3};
        vector<int> insertionArray = {5, 2, 4, 1, 3};

        // Separate counters for each sorting method
        long long selectionCounter = 0;
        long long insertionCounter = 0;

        // Test Selection Sort
        selectionSort(selectionArray, selectionCounter);

        // Print the sorted Selection Sort array
        cout << "Selection Sort: ";
        for (int number : selectionArray) {
            cout << number << " ";
        }

        // Print the number of comparisons Selection Sort made
        cout << endl;
        cout << "Comparisons: " << selectionCounter << endl;

        cout << endl;

        // Test Insertion Sort
        insertionSort(insertionArray, insertionCounter);

        // Print the sorted Insertion Sort array
        cout << "Insertion Sort: ";
        for (int number : insertionArray) {
            cout << number << " ";
        }

        // Print the number of comparisons Insertion Sort made
        cout << endl;
        cout << "Comparisons: " << insertionCounter << endl;

        // Run Task 3 user testing mode
        //   task3UserTesting();
        task3ScatterMode();
    }
    else { //This else is for Scatterplot mode, there technically isn't much to do here
        //I guess we can check to make sure the necessary csv files exist

    }
    return 0;
}