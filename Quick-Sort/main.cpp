//
//  main.cpp
//  Quick-Sort
//
//  Created by Desislava Stoyanova on 10/3/15.
//  Copyright © 2015 Desislava Stoyanova. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Swap(int& a,int& b) {
    int temp = a;
    a = b;
    b = temp;
}

unsigned long Partition(vector<int>& vec,unsigned long p,unsigned long r) {
    int item = vec[r];
    unsigned long i = p - 1;
    for (unsigned long j = p; j < r; j++) {
        if (vec[j] <= item) {
            i = i + 1;
            Swap(vec[i],vec[j]);
        }
    }
    Swap(vec[i+1], vec[r]);
    return i + 1;
}

void QuickSort(vector<int>& vec,unsigned long p,unsigned long r) {
    if (p < r) {
        unsigned long q = Partition(vec, p, r);
        QuickSort(vec, p, q-1);
        QuickSort(vec, q+1, r);
    }
}

int main(int argc, const char * argv[]) {
    vector<int> vec;
    int number;
    // Open the file to read numbers
    ifstream file_read;
    file_read.open("nums.txt");
    while (file_read >> number) {
        vec.push_back(number);
    }
    file_read.close();
    // Quick sort
    QuickSort(vec, 0, vec.size()-1);
    // Open file to write numbers in sorted order 
    ofstream file_write;
    file_write.open("nums_sorted.txt");
    for (int i = 0; i < vec.size(); i++) {
        file_write << vec[i];
        file_write << "\n";
    }
    file_write.close();
    return 0;
}
