#include <iostream>
using namespace std;

int findMax(int arr[], int n)
{
    if (n <= 0) 
	{
        return -2147483648; 
    }
    int maxVal = arr[0];
    for (int i = 1; i < n; ++i) 
	{
        if (arr[i] > maxVal) 
		{
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() 
{
    int myArray[] = {5, 12, 8, 20, 3, 15};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    int maxValue = findMax(myArray, size);
    cout << "Maximum value: " << maxValue << endl;
    return 0;
}
