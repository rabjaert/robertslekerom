#include <iostream>
#include <vector>
#include <algorithm>


int maximumElementArray(int array[], int index) {

    int n;
    int max = array[0];

    for (n = 1; n < index; n++) {
        if (array[n] > max)
            max = array[n];
    }
    return max;
}

int minimumElementArray(int array[], int index) {

    int n;
    int max = array[0];

    for (n = 1; n < index; n++) {
        if (array[n] < max)
            max = array[n];
    }
    return max;
}


int bucketSort(int array[], int numberOfBuckets) {

    int arraySize = sizeof(array) / sizeof(array[0]);

    int maximumElement = maximumElementArray(array, arraySize + 1);
    int minimumElement = minimumElementArray(array, arraySize + 1);
    int range = (maximumElement - minimumElement) / numberOfBuckets;

    int constantValue = numberOfBuckets;
    //("%d", arraySize);

    int* bucketList = new int[numberOfBuckets];
    int bucketSize = sizeof(*bucketList) / sizeof(bucketList[0]);
    //1. create n arrays of amound of NumberOfBuckets
    for (int i = 0; i <= numberOfBuckets; i++) {
        int test[4];
        bucketList[numberOfBuckets] = *test;
        
    }
   
    
    //2. creating index for each number, and add them to the right index in the array
    for (int i = 0; i < arraySize - 1; i++) {
        int bucketIndex = (i - minimumElement) / range;
        bucketList[bucketIndex] = i;
       
    }

    for (int i = 0; i < bucketSize - 1; i++) {
        std::cout << bucketList[i] << std::endl;
    }
    /*
    //3. sort the array
    for (int i = 0; i < bucketList.size(); i++) {
        bucketList[i] //sort
    }

    //4. add the sorted array to a final list
    for (int i = 0; i < bucketList.size(); i++) {
        //new array
        newArray.push(bucketList[i]);
    }
    */
    return 0;

}


int main() {

    int test[] = { 10,20,4, 45};

    bucketSort(test, 4);

    return 0;


}