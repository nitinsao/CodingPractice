#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 5, 7, 9, 10, 18, 20, 29, 43, 51}; //{1, 10, 9, 20, 5, 7, 18, 29, 51, 43};
    int target = 15;
    int s = 0;
    int e = (sizeof(arr)/ sizeof(int)) - 1;
    int mid, index = -1;
    while(s <= e)
    {
        mid = (s+e)/2;
        if(arr[mid] == target)
        {
            index = mid;
            break;
        }
        else if(arr[mid] < target)
            s = mid+1;
        else
            e = mid-1;
    }
    if(index < 0)
        cout << target << " not found" << endl;
    else
        cout << "Found at " << index << ": " << arr[index] << endl;
}