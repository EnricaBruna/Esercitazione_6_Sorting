#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

int main(int argc, char ** argv)
{

    double sumMerge = 0.0;
    double sumBubble = 0.0;

    if (!(argc > 1))
    {
        cerr << "The input arguments are missing" << endl;
        return 1;
    }

    srand(time(NULL));

    for (int i = 1; i< argc; i++ )
    {
        if (stoi(argv[i]) < 0)
        {
            cerr << "The size of a vector can't be negative" << endl;
            return 2;
        }

        unsigned int size = stoi(argv[i]);

        vector<int> v(size);

        for (unsigned int j =0; j < size;j++)
        {
            v[j] = rand()%1000;
        }

        vector<int> v1 = v;
        vector<int> v2 = v;

        cout << "Vector of size " << size << endl;

        std::chrono::steady_clock::time_point t_b_Merge=std::chrono::steady_clock::now();
        MergeSort(v1);
        std::chrono::steady_clock::time_point t_e_Merge=std::chrono::steady_clock::now();
        double durationMerge = std::chrono::duration_cast<std::chrono::microseconds>(t_e_Merge-t_b_Merge).count();
        cout<< "MergeSort algorithm took " << durationMerge<< " microseconds"<<endl;
        sumMerge += durationMerge;

        std::chrono::steady_clock::time_point t_b_Bubble=std::chrono::steady_clock::now();
        BubbleSort(v2);
        std::chrono::steady_clock::time_point t_e_Bubble=std::chrono::steady_clock::now();
        double durationBubble = std::chrono::duration_cast<std::chrono::microseconds>(t_e_Bubble-t_b_Bubble).count();
        cout<< "BubbleSort algorithm took " << durationBubble<< " microseconds"<<endl;
        sumBubble += durationBubble;
        cout << endl;

    }

    double averageMerge = sumMerge/(argc-1);
    double averageBubble = sumBubble/(argc-1);
    cout << "The average time taken by the function MergeSort is " << averageMerge << " microseconds" << endl;
    cout << "The average time taken by the function BubbleSort is " << averageBubble << " microseconds" << endl;

    return 0;
}

