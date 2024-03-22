#include <iostream>
#include <vector>

/*
consider a problem where we are given an array of n positive integers and a target sum x, 
and we want to find a subarray whose sum is x or report that there is no such subarray.
*/
void findSubarrayWithGivenSum(const std::vector<int> &arr, int sum)
{
    int start = 0;
    int end = 0;
    int currentSum = 0;

    while (end < arr.size())
    {
        currentSum += arr[end];

        while (currentSum > sum && start < end)
        {
            currentSum -= arr[start];
            start++;
        }

        if (currentSum == sum)
        {
            std::cout << "Sum found between indexes " << start << " and " << end << std::endl;
            return;
        }

        end++;
    }

    std::cout << "No subarray with sum " << sum << " found." << std::endl;
}

int main()
{
    std::vector<int> arr = {15, 2, 4, 8, 5, 10, 23};
    int target_sum = 21;

    findSubarrayWithGivenSum(arr, target_sum);

    return 0;
}
