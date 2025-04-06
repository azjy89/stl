#include <iostream>

#include "Vector.h"

int main()
{
    std::cout << "=== Test: Default Constructor ===\n";
    Vector<int> vec;
    std::cout << "Initial size: " << vec.size() << "\n";
    std::cout << "Is empty? " << std::boolalpha << vec.empty() << "\n\n";

    std::cout << "=== Test: push_back ===\n";
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    std::cout << "After push_back operations:\n";
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n";
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec.at(i) << " ";
    }
    std::cout << "\n\n";

    std::cout << "=== Test: pop_back ===\n";
    vec.pop_back();
    std::cout << "After pop_back:\n";
    std::cout << "Size: " << vec.size() << "\n";
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec.at(i) << " ";
    }
    std::cout << "\n\n";

    std::cout << "=== Test: resize (increase size) ===\n";
    // Resize to 5 elements, new elements initialized to 100.
    vec.resize(5, 100);
    std::cout << "After resizing to 5 with default value 100:\n";
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << "\n";
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec.at(i) << " ";
    }
    std::cout << "\n\n";

    std::cout << "=== Test: reserve ===\n";
    vec.reserve(15);
    std::cout << "After reserving capacity for 15 elements:\n";
    std::cout << "Capacity: " << vec.capacity() << "\n\n";

    std::cout << "=== Test: shrink_to_fit ===\n";
    vec.shrink_to_fit();
    std::cout << "After shrink_to_fit:\n";
    std::cout << "Capacity: " << vec.capacity() << ", Size: " << vec.size() << "\n\n";

    std::cout << "=== Test: Copy Constructor ===\n";
    Vector<int> vec_copy(vec);
    std::cout << "Copy constructed vector elements: ";
    for (size_t i = 0; i < vec_copy.size(); ++i)
    {
        std::cout << vec_copy.at(i) << " ";
    }
    std::cout << "\n\n";

    std::cout << "=== Test: Copy Assignment Operator ===\n";
    Vector<int> vec_assigned;
    vec_assigned = vec;
    std::cout << "Assigned vector elements: ";
    for (size_t i = 0; i < vec_assigned.size(); ++i)
    {
        std::cout << vec_assigned.at(i) << " ";
    }
    std::cout << "\n\n";

    std::cout << "=== Test: clear ===\n";
    vec.clear();
    std::cout << "After clear, size: " << vec.size() << "\n";

    return 0;
}
