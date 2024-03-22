#include <iostream>
#include <vector>

// Function to print a subset
void printSubset(const std::vector<int> &subset)
{
    for (const auto &element : subset)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

// Recursive function to generate all subsets
void generateSubsets(const std::vector<int> &array, std::vector<int> &subset, int index)
{
    // Base case: if we've reached the end of the array, print the current subset
    if (index == array.size())
    {
        printSubset(subset);
        return;
    }

    // Exclude the current element
    generateSubsets(array, subset, index + 1);

    // Include the current element
    subset.push_back(array[index]);
    generateSubsets(array, subset, index + 1);

    // Remove the last element added to backtrack and explore other possibilities
    subset.pop_back();
}

int main()
{
    std::vector<int> array = {1, 2, 3};
    std::vector<int> subset;
    generateSubsets(array, subset, 0);
    return 0;
}
