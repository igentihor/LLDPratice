#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int constructSegmentTree(int arr[], int segmentTree[], int low, int high, int index) {
    if(low==high) {
        segmentTree[index] = arr[low];
        return arr[low];
    }
    int mid = (low+high)/2;
    int leftMax = constructSegmentTree(arr, segmentTree, low, mid, 2*index+1);
    int rightMax = constructSegmentTree(arr, segmentTree, mid+1, high, 2*index+2);
    segmentTree[index] = max(leftMax, rightMax);
    return segmentTree[index];
}

int findMaxInRange(int segmentTree[], int low, int high, int index, int leftR, int rightR) {
    if(high<leftR || low>rightR) {
        return INT_MIN;
    } else if(low>=leftR && high<=rightR) {
        return segmentTree[index];
    } else {
        int mid = (low+high)/2;
        int leftMax = findMaxInRange(segmentTree, low, mid, 2*index+1, leftR, rightR);
        int rightMax = findMaxInRange(segmentTree, mid+1, high, 2*index+2, leftR, rightR);
        return max(leftMax, rightMax);
    }
}

void updateTree(int segmentTree[], int low, int high, int index, int updateIdx, int value) {
    if(low==high) {
        segmentTree[index] = value;
    } else {
        int mid = low + (high-low)/2;
        if(updateIdx>=low && updateIdx<=mid) {
            updateTree(segmentTree, low, mid, 2*index+1, updateIdx, value);
        } else {
            updateTree(segmentTree, mid+1, high, 2*index+2, updateIdx, value);
        }
        segmentTree[index] = min(segmentTree[2*index+1], segmentTree[2*index+2]);
    }
}

int main() {
    int arr[] = {5,6,3,8,9,45,67,34,56,23,4,5,67,87};
    int n = sizeof(arr)/sizeof(arr[0]);
    int segmentTree[4*n];
    constructSegmentTree(arr, segmentTree, 0, n-1, 0);
    
    // running code for sample queries
    cout << findMaxInRange(segmentTree, 0, n-1, 0, 2, 6) << endl;
    cout << findMaxInRange(segmentTree, 0, n-1, 0, 8, 8) << endl;
    cout << findMaxInRange(segmentTree, 0, n-1, 0, 3, 5) << endl;
    cout << findMaxInRange(segmentTree, 0, n-1, 0, 1, 7) << endl;
    cout << findMaxInRange(segmentTree, 0, n-1, 0, 0, 2) << endl;
    cout << findMaxInRange(segmentTree, 0, n-1, 0, 0, 13) << endl;
}