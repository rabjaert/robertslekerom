#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iterator>
#include <math.h> 


std::vector<int> bucketSortReturningVectorWithNBuckets(int intFromFile[], int numberOfBuckets, int arraySize, int arrayMin, int arrayMax, int arrayRange, bool print)
{
    //adding vector inside a vector
    std::vector<std::vector<int>> buckets((arraySize / numberOfBuckets) + 10);
    for (int i = 0; i < numberOfBuckets; i++) {
        std::vector<std::vector<int>> list;
        buckets.insert(buckets.end(), list.begin(), list.end()); 
       
    }
    //looping through input array, and calculate bucketNumber. Adding input from array on bucketNumber index.
    for (int i = 0; i < arraySize; i++) {
        int bucketNumber = ((intFromFile[i] - arrayMin) / arrayRange);
        buckets.at(bucketNumber).push_back(intFromFile[i]);
       
    }
    
    //sorting the vector
    for (int i = 0; i < buckets.size(); i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    //adding the values to a final vector
    std::vector<int> result;
    for (int i = 0; i < buckets.size(); i++) {
        for (size_t j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);
            //std::cout << buckets[i][j] << std::endl;
            //std::cout << result[i][j] << std::endl;
            
        }
        
    }
    if (print) {
        //printing the elements
        for (int i = 0; i < result.size(); i++) {
            std::cout << result[i] << std::endl;
        }
    }
   
    return result;
}

int main() {
    
    /* Random declerations */
    std::random_device rnd_d;
    std::mt19937 rng(rnd_d());
    std::uniform_int_distribution<int> uniform_dist(1, 1000);
    std::uniform_int_distribution<int> uniform_dist1(1, 99);


    /*----------------------------------------------------------*/
    /*-----------------------BIG ARRAY---------------------------*/
    /*----------------------------------------------------------*/
    constexpr size_t SIZE = 1000000;
    constexpr int nBuckets = 10;
    int min, max;
    /* Allocate the array on the heap. The array might be too large for the stack */
    int* arr = new int[SIZE];
    /* Fill the array with randomly distributed floats */
    for (int i = 0; i < SIZE; i++) {
        arr[i] = uniform_dist(rng);
    }

    min = arr[0];
    max = arr[0];

    for (int i = 0; i < SIZE; i++) {
        if (min > arr[i]) {
            min = arr[i];
        }
        else if (max < arr[i]) {
            max = arr[i];
        }
    }

    int range = (max - min) / nBuckets;
    /*---------------------------------------------------------*/
    /*----------------------------------------------------------*/
    /*----------------------------------------------------------*/
    
   
    
    /*----------------------------------------------------------*/
    /*-----------------------SMALL ARRAY---------------------------*/
    /*----------------------------------------------------------*/
    
    constexpr size_t SIZESmallArray = 20;
    int minSmallArray, maxSmallArray;
    /* Allocate the array on the heap. The array might be too large for the stack */
    int* smallArray = new int[SIZESmallArray];
    /* Fill the array with randomly distributed floats */
    for (int i = 0; i < SIZESmallArray; i++) {
        smallArray[i] = uniform_dist1(rng);
    }

    minSmallArray = smallArray[0];
    maxSmallArray = smallArray[0];

    for (int i = 0; i < SIZESmallArray; i++) {
        if (minSmallArray > smallArray[i]) {
            minSmallArray = smallArray[i];
        }
        else if (maxSmallArray < smallArray[i]) {
            maxSmallArray = smallArray[i];
        }
    }
    int rangeSmallArray = (maxSmallArray - minSmallArray) / nBuckets;
    
    /*---------------------------------------------------------*/
    /*----------------------------------------------------------*/
    /*----------------------------------------------------------*/
    
    /* Time measures */
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

   

    std::cout << "Bucket Sort vector implementation in C++ compared to Java" << std::endl;
    std::cout << "Printing small array first to see if it works properly" << std::endl;
    
    std::cout << "UNSORTED ARRAY..................." << std::endl;
   for (int i = 0; i < SIZESmallArray; i++) {
       std::cout << smallArray[i] << std::endl;
   }
   std::cout << "------------------------------------------------" << std::endl;
  
   std::cout << "SORTED ARRAY..................." << std::endl;
   bucketSortReturningVectorWithNBuckets(smallArray, nBuckets, SIZESmallArray, minSmallArray, maxSmallArray, rangeSmallArray, true);
   std::cout << "------------------------------------------------" << std::endl;

    auto t1 = high_resolution_clock::now();
    /* Sort */
    bucketSortReturningVectorWithNBuckets(arr, nBuckets, SIZE, min, max, range, false);
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    std::cout << std::endl;
    std::cout << "Bucket Sort vector implementation in C++ with: " << nBuckets << "buckets." << std::endl;
    std::cout << "Average time taken to bucketsort 10^6 numbers with 10 buckets in JAVA is: 400-500ms" << std::endl;
    std::cout << "Time taken:" << " " << ms_int.count() << "ms\n";


    /* Delete the array */
    delete[] arr;
    delete[]smallArray;
    return 0;


}