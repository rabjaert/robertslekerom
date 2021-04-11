#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iterator>


//taken much from geeksforgeeks for test purposes only..
void bucketSortVoid(float array[], int numberOfBuckets)
{
    std::vector<std::vector<float>> buckets(numberOfBuckets);
    for (int i = 0; i < numberOfBuckets; i++) {
        buckets[int(numberOfBuckets * array[i])].push_back(array[i]);
    }
    for (int i = 0; i < numberOfBuckets; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < numberOfBuckets; i++) {
        for (size_t j = 0; j < buckets[i].size(); j++) {
            array[index++] = buckets[i][j];
        }
    }
}

std::vector<float> bucketSortReturningVector(float array[], int numberOfBuckets)
{
    std::vector<std::vector<float>> buckets(numberOfBuckets);
    for (int i = 0; i < numberOfBuckets; i++) {
        buckets[int(numberOfBuckets * array[i])].push_back(array[i]);
    }
    for (int i = 0; i < numberOfBuckets; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    std::vector<float> result;
    for (int i = 0; i < numberOfBuckets; i++) {
        for (size_t j = 0; j < buckets[i].size(); j++) {
            result.push_back(buckets[i][j]);

        }
    }
        
    return result;
}

std::vector<float> bucketSortReturningVectorWithNBuckets(float intFromFile[], int numberOfBuckets, int arraySize)
{
    
    std::vector<std::vector<float>> buckets((arraySize / numberOfBuckets));
    for (int i = 0; i < arraySize; i++) {
        buckets[int(numberOfBuckets * intFromFile[i])].push_back(intFromFile[i]);
    }
   
    for (int i = 0; i < buckets.size(); i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    std::vector<float> result;
    for (int i = 0; i < numberOfBuckets; i++) {
        //std::cout << "bucket: " << i << std::endl;
        //std::cout << std::endl;
        for (size_t j = 0; j < buckets[i].size(); j++) {
           // std::cout << buckets[i][j] << std::endl;
            result.push_back(buckets[i][j]);
        }
        
    }
    
    return result;
}

int main() {
    
    /* Random declerations */
    std::random_device rnd_d;
    std::mt19937 rng(rnd_d());
    std::uniform_real_distribution<float> uniform_dist(0, 1);


    constexpr size_t SIZE = 1000000;
    constexpr int nBuckets = 10;
    /* Allocate the array on the heap. The array might be too large for the stack */
    float* arr = new float[SIZE];
    /* Fill the array with randomly distributed floats */
    for (int i = 0; i < SIZE; i++) {
        arr[i] = uniform_dist(rng);
    }
    
    /* Time measures */
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    /* Sort */
    bucketSortVoid(arr, SIZE);
    //bucketSort2(arr, SIZE);
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    auto k1 = high_resolution_clock::now();
    /* Sort */
    bucketSortReturningVector(arr, SIZE);
    //bucketSort2(arr, SIZE);
    auto k2 = high_resolution_clock::now();
    /* Getting number of milliseconds as an integer. */
    auto ks_int = duration_cast<milliseconds>(k2 - k1);

    auto clock1 = high_resolution_clock::now();

    bucketSortReturningVectorWithNBuckets(arr, nBuckets, SIZE);

    auto clock2 = high_resolution_clock::now();

    auto clock_int = duration_cast<milliseconds>(clock2 - clock1);

    std::cout << "Bucket Sort void, not returning array" << std::endl;
    std::cout << ms_int.count() << "ms\n";

    std::cout << "Bucket Sort vector, returning a vector" << std::endl;
    std::cout << ks_int.count() << "ms\n";

    std::cout << "Bucket Sort vector, returning a vector with:" << nBuckets << "buckets." << std::endl;
    std::cout << clock_int.count() << "ms\n";
      
   



    /* Delete the array */
    delete[] arr;
    return 0;


}