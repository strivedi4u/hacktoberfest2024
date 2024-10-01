#include <iostream>
using namespace std;

int *arr;
int size;

void insert(int index)
{
    int parent;
    while (index > 1)
    {
        if (index % 2 == 0)
        {
            parent = index / 2;
        }
        else
        {
            parent = (index - 1) / 2;
        }

        if (arr[parent] > arr[index])
        {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else
        {
            return;
        }
    }
}

void create(int size)
{
    arr = (int *)malloc((size + 1) * sizeof(int));
    arr[0] = 0;

    for (int i = 1; i <= size; i++)
    {
        cin >> arr[i];
    }
    for (int i = 2; i <= size; i++)
    {
        insert(i);
    }
}

int del(int endindex)
{
    int i = 1, j = 2 * i;
    int delval = arr[1];
    arr[1] = arr[endindex];
    arr[endindex] = delval;

    while (j > endindex - 1)
    {
        if (arr[j + 1] < arr[j])
        {
            j++;
        }
        if (arr[i] > arr[j])
        {
            swap(arr[i], arr[j]);
            i = j;
            j = 2 * i;
        }
        else
        {
            break;
        }
    }
    return delval;
}

int main()
{
    int size = 0;
    cin >> size;
    create(size);

    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";

    cout << arr[1] << "\n";

    for (int i = size; i > 1; i--)
    {
        del(i);
    }

    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
