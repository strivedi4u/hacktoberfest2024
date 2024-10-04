// A teacher is organizing the scores of students from a recent exam. The students’ scores are initially given in random order. The teacher wants to rank the students from the lowest score to the highest. The teacher decides to use a simple sorting technique, Bubble Sort, to reorder the scores.

// Write a C++ program that reads an array of student scores and sorts them in ascending order using Bubble Sort.

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int scores[] = {78, 92, 88, 65, 70, 95, 60, 85, 80, 90};
    int n = sizeof(scores) / sizeof(scores[0]);

    cout << "Original scores: ";
    for (int i = 0; i < n; i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;

    bubbleSort(scores, n);

    cout << "Sorted scores in ascending order: ";
    for (int i = 0; i < n; i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;

    return 0;
}
