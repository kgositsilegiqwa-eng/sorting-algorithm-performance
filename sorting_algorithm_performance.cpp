#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

//Random Array Generator:
vector<int> generateRandomInputVector(int size)
{
    vector<int> inputDataVector(size); //creates a vector that contains the specified number of elements

    for (int i = 0; i < size; i++){       //loops through each index of the vector and assigns a random integer of 0 to 9999 to the index
        inputDataVector[i] = rand() % 10000;
    }
    return inputDataVector; //returns the generated vector of random integer values
}

//Bubble Sort Algorithm
void bubbleSortAlgo(vector<int>& inputDataVector){

    int numberOfElements = inputDataVector.size(); //get number of elements in the vector being sorted

    bool swapped;
    for (int i = 0; i < numberOfElements - 1; i++){ //outer for loop
        swapped = false;
        for (int j = 0; j < numberOfElements - i - 1; j++){ //innner for loop that does adjacent swaps the larger value to the next index and sends the largest value to the last index minus the current iteration per iteration
            if (inputDataVector[j] > inputDataVector[j + 1]){
                swap(inputDataVector[j], inputDataVector[j + 1]); //swap adjacent elements
                swapped = true;
            }
        }
        if (swapped == false){ //breaks the for loop early before the full number of iterations is carried out if the elements are already sorted
            break;
        }
    }
}


//Merge Sort:
void mergeAlgo(vector<int>& inputDataVector, int left, int middle, int right){

    int numberOfElementsLeft = middle - left + 1; //Calculates how many elements will be in the left sub-vector
    int numberOfElementsRight = right - middle; //Calculates how many elements will be in the right sub-vector

    vector<int> leftSubVector(numberOfElementsLeft);
    vector<int> rightSubVector(numberOfElementsRight);

    //Copy elements from the left half of the input vector to the left sub-vector
    for (int i = 0; i < numberOfElementsLeft; i++){
        leftSubVector[i] = inputDataVector[left + i];
    }

    ////Copy elements from the right half of the input vector to the right sub-vector
    for (int j = 0; j < numberOfElementsRight; j++){
        rightSubVector[j] = inputDataVector[middle + 1 + j];
    }

    //index counters:
    int i = 0; //starting index of the left sub-vector
    int j = 0; //starting index of the right sub-vector
    int k = left; //starting index of the original input vector

    //while loop that does a side by side comparison of elements from both sub-vectors and inserts the smaller one into the main array, then increments the counter of the subarray that's had an element inserted
    while (i < numberOfElementsLeft && j < numberOfElementsRight){
        if (leftSubVector[i] <= rightSubVector[j]){
            inputDataVector[k] = leftSubVector[i]; //places an element of the left sub-vectot into the sorted input vector
            i++; //advances the left sub-vector index by 1
        }
        else if(leftSubVector[i] > rightSubVector[j]){
            inputDataVector[k] = rightSubVector[j]; //places an element of the right sub-vectot into the sorted input vector
            j++; //advances the right sub-vector index by 1
        }

        k++; //advances the input vector index by 1
    }

    while (i < numberOfElementsLeft){
        inputDataVector[k] = leftSubVector[i]; //copies any remaining elements from the sorted left sub-vector into the sorted  input vector
        i++;
        k++;
    }

    while (j < numberOfElementsRight){
        inputDataVector[k] = rightSubVector[j]; //copies any remaining elements from the sorted right sub-vector into the sorted  input vector
        j++;
        k++;
    }
}

//Merge Sort Recursive Function
void recursiveMergeSortAlgo(vector<int>& inputDataVector, int left, int right){
    if (left < right){
        int middle = left + (right - left) / 2;

        recursiveMergeSortAlgo(inputDataVector, left, middle);

        recursiveMergeSortAlgo(inputDataVector, middle + 1, right);

        mergeAlgo(inputDataVector, left, middle, right);
    }
}

//Measure Bubble Sort Algorithm Performance
void BubbleSortAlgorithmPerformance(vector<int>& inputDataVector, double& timeExecuted, double& timeComplexity){

    timeComplexity = pow(inputDataVector.size(), 2);//calculate bubble sort time complexity->O(n^2)

    clock_t bubblesortAlgoRunStartTime = clock(); //calls the clock() function which records time before sorting begins as ticks
    bubbleSortAlgo(inputDataVector); //call bubble-sort function
    clock_t bubblesortAlgoRunEndTime = clock();//record time after sorting ends as ticks
    timeExecuted =((double)bubblesortAlgoRunEndTime - (double)bubblesortAlgoRunStartTime) / CLOCKS_PER_SEC;//subtract start and end times and divides the difference by CLOCKS_PER_SEC to convert the ticks into seconds

}


//Measure Merge Sort Algorithm Performance
void MergeSortAlgorithmPerformance(vector<int>& inputDataVector, double& timeExecuted, double& timeComplexity){


    timeComplexity = inputDataVector.size() * log2(inputDataVector.size());//calculate merrge sort time complexity->O(nlogn)

    clock_t mergeSortAlgoRunStartTime = clock();//record time before merge-sort algo is excecuted
    recursiveMergeSortAlgo(inputDataVector, 0, inputDataVector.size() - 1);//call merge-sort function
    clock_t mergeSortAlgoRunEndTime = clock();//record time after merge-sort algo execution
    timeExecuted =((double)mergeSortAlgoRunEndTime - (double)mergeSortAlgoRunStartTime) / CLOCKS_PER_SEC;

}


int main()
{
    srand(time(0));

    double timeExecuted1; //receives sort execution time via pass-by-reference
    double timeComplexity1; //receives sort complexity value via pass-by-reference
    double timeExecuted2;
    double timeComplexity2;

     //vectors of 100 elements
    {
        vector<int> unsortedVector100 = generateRandomInputVector(100); //generates a random input vector using the generateRandomInputVector function and copies the result onto the unsortedVector

        vector<int> bubbleSortInputVector100 = unsortedVector100; //creates a copy of the unsorted vector for use in function calls
        vector<int> mergeSortInputVector100 = unsortedVector100;

        BubbleSortAlgorithmPerformance(bubbleSortInputVector100, timeExecuted1, timeComplexity1); //calls and excutes the bubble sort performance measurement function which executes the sorting algorithm on the vector and measures performance
        MergeSortAlgorithmPerformance(mergeSortInputVector100, timeExecuted2, timeComplexity2); //calls and excutes the merge sort performance measurement function which executes the sorting algorithm on the vector and measures performance

        cout << "-----------------" << endl;
        cout << "|Input Size: 100|" << endl;
        cout << "-----------------" << endl;
        cout << "|Bubble-sort" << endl;
        cout << "|Execution-time: " << timeExecuted1 << "seconds" << endl;
        cout << "|Time-complexity: " << timeComplexity1 << endl;
        cout << "-----------" << endl;
        cout << "|Merge-sort" << endl;
        cout << "|Execution-time: " << timeExecuted2 << "seconds" << endl;
        cout << "|Time-complexity: " << timeComplexity2 << endl;
        cout << "-----------" << endl;

    }

    //vectors of 1000 elements
    {
        vector<int> unsortedVector1000 = generateRandomInputVector(1000);

        vector<int> bubbleSortInputVector1000 = unsortedVector1000;
        vector<int> mergeSortInputVector1000 = unsortedVector1000;

        BubbleSortAlgorithmPerformance(bubbleSortInputVector1000, timeExecuted1, timeComplexity1);
        MergeSortAlgorithmPerformance(mergeSortInputVector1000, timeExecuted2, timeComplexity2);

        cout << endl;
        cout << "------------------" << endl;
        cout << "|Input Size: 1000|" << endl;
        cout << "------------------" << endl;
        cout << "|Bubble-sort" << endl;
        cout << "|Execution-time: " << timeExecuted1 << " seconds" << endl;
        cout << "|Time-complexity: " << timeComplexity1 << endl;
        cout << "-----------" << endl;
        cout << "|Merge-sort" << endl;
        cout << "|Execution-time: " << timeExecuted2 << " seconds" << endl;
        cout << "|Time-complexity: " << timeComplexity2 << endl;
        cout << "-----------" << endl;

    }

    //vectors of 5000 elements
    {
        vector<int> unsortedVector5000 = generateRandomInputVector(5000);

        vector<int> bubbleSortInputVector5000 = unsortedVector5000;
        vector<int> mergeSortInputVector5000 = unsortedVector5000;

        BubbleSortAlgorithmPerformance(bubbleSortInputVector5000, timeExecuted1, timeComplexity1);
        MergeSortAlgorithmPerformance(mergeSortInputVector5000, timeExecuted2, timeComplexity2);

        cout << endl;
        cout << "------------------" << endl;
        cout << "|Input Size: 5000|" << endl;
        cout << "------------------" << endl;
        cout << "|Bubble-sort" << endl;
        cout << "|Execution-time: " << timeExecuted1 << " seconds" << endl;
        cout << "|Time-complexity: " << timeComplexity1 << endl;
        cout << "-----------" << endl;
        cout << "|Merge-sort" << endl;
        cout << "|Execution-time: " << timeExecuted2 << " seconds" << endl;
        cout << "|Time-complexity: " << timeComplexity2 << endl;
        cout << "-----------" << endl;

    }

    cout << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Time-complexity formula for Bubble-sort: O(n^2)" << endl;
    cout << "Time-complexity formula for Merge-sort: O(nlogn)" << endl;
    cout << "------------------------------------------------" << endl;

    return 0;
}
