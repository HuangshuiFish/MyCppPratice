#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#include <iterator>
#include <functional>
#include <algorithm>
#include <vector>

template <typename IterT,
          typename T = typename std::iterator_traits<IterT>::value_type>
void counting_sort(IterT first, IterT last) {
    const auto len = std::distance(first, last);//需要拷贝元素，但不可修改拷贝出来的值时，使用 for(const auto x:range)，避免拷贝开销
    if (len < 2) { return; }

    const T max = *std::max_element(first, last);
    if (max == 0) { return; }

    std::vector<size_t> counter(max + 1);
    for (IterT i = first; i != last; ++i) {
        ++counter[*i];
    }
    for (size_t i = 1; i != max + 1; ++i) {
        const size_t j = max - i;
        counter[j] += counter[j + 1];  // Liam Huang: count of numbers that is not less than j.
    }

    std::vector<T> temp(len);
    for (IterT i = first; i != last; ++i) {
        temp[len - counter[*i]] = *i;
        --counter[*i];                 // Liam Huang: stable for relative position.
    }
    std::copy(temp.begin(), temp.end(), first);
}


#endif // COUNTING_SORT_HPP
