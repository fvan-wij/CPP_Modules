#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T& container, const int target) {

    auto it = std::find(container.begin(), container.end(), target);

    if (it == container.end())
	{
        throw std::out_of_range("Element not found in the container.");
    }

    return it;
}
