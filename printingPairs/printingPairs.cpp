#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = (sizeof(arr)/ sizeof(int));

    for(int i = 0; i < len; i++)
    {
        for(int j = i+1; j < len; j++)
            cout << "[" << arr[i] << "," << arr[j] << "], ";
        cout << endl;
    }
    return 0;
}