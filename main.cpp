// Implementation of Mergesort from Introduction To Algorithms Fourth Edition.

#include <iostream>
#include <vector>

void MergeSort(std::vector<int>& A, int p, int r);
void Merge(std::vector<int>& A, int p, int q, int r);



int main() {
    std::vector<int> A = { 4, 25, 60, 11, 20, 88, 5, 2, 51 };
    int n = A.size();

    MergeSort(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }

    return 0;
}


void MergeSort(std::vector<int>& A, int p, int r) {
    //p is starting point r is end
    if (p >= r)  // zero or one element
        return;

    int q = (p + r) / 2;  // midpoint of A[p : r]

    MergeSort(A, p, q);   // recursively sort A[p : q]
    MergeSort(A, q + 1, r); // recursively sort A[q + 1 : r]
    Merge(A, p, q, r);    // merge A[p : q] and A[q + 1 : r] into A[p : r]
}

void Merge(std::vector<int>& A, int p, int q, int r) {
    int nL = q - p + 1;  // length of A[p : q]
    int nR = r - q;      // length of A[q + 1 : r]

    std::vector<int> L(nL), R(nR);

    for (int i = 0; i < nL; i++)
        L[i] = A[p + i]; // copy A[p : q] into L[0 : nL - 1]

    for (int j = 0; j < nR; j++)
        R[j] = A[q + 1 + j]; // copy A[q + 1 : r] into R[0 : nR - 1]

    int i = 0, j = 0, k = p;

    // Merge the two subarrays back into A
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L, if there are any
    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R, if there are any
    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }
}
