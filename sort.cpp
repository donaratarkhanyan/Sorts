#include "sort.hpp"

template<typename T>
Array<T>::Array(std::vector<T> arr) : m_arr{arr}
{}

template<typename T>
Array<T>::Array(std::initializer_list<T> init) : m_arr{init}
{}

template <typename T>
void Array<T>::shuffleArray()
{
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(std::begin(m_arr), std::end(m_arr), g);
}

template <typename T>
void Array<T>::printArray()
{
    for (auto& elem : m_arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void Array<T>::BubbleSort() {
    for (int i = 0; i < m_arr.size() - 1; ++i) {
        bool flag = false;
        for (int j = 0; j < m_arr.size() - i - 1; ++j) {
            if (m_arr[j] > m_arr[j + 1]) {
                std::swap(m_arr[j], m_arr[j + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}


template <typename T>
void Array<T>::SelectionSort() {
    for (size_t i = 0; i < m_arr.size() - 1; ++i) {
        size_t index = i;
        for (size_t j = i + 1; j < m_arr.size(); ++j) {
            if (m_arr[j] < m_arr[index]) {
                index = j;
            }
        }
        if (index != i) {
            std::swap(m_arr[index], m_arr[i]);
        }
    }
}

template <typename T>
void Array<T>::InsertionSort()
{
    for (int i = 1; i < m_arr.size() - 1; ++i) {
        int key = m_arr[i];
        int j = i - 1;
        while (j >= 0 && key < m_arr[j]){
            m_arr[j + 1] = m_arr[j];
            --j;
        }
        m_arr[j + 1] = key;
    }
}

template <typename T>
void Array<T>::MergeSort()
{
    if (!m_arr.empty()) {
        mergesort(m_arr, 0, m_arr.size() - 1);
    }
}

template <typename T>
void Array<T>::mergesort(std::vector<T>& arr, int start, int end)
{
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

template <typename T>
void Array<T>::Merge(std::vector<T>& arr, int start, int mid, int end) 
{
    int size1 = mid - start + 1;
    int size2 = end - mid;
    std::vector<T>v1 (size1);
    std::vector<T>v2 (size2);
    for (int i = 0; i < size1; ++i){
        v1[i] = arr[i + start];
    }
    for (int i = 0; i < size2; ++i){
        v2[i] = arr[i + mid + 1];
    }
    int k = start;
    int i = 0;
    int j = 0;
    while (i < size1 && j < size2) {
        if (v1[i] < v2[j]) {
            arr[k++] = v1[i++];
        } else {
            arr[k++] = v2[j++];
        }
    }

    while (i < size1) {
        arr[k++] = v1[i++];
    } 

    while (j < size2) {
        arr[k++] = v2[j++];
    }
}

template <typename T>
void Array<T>::QuickSort()
{
    if (!m_arr.empty()) {
        quicksort(m_arr, 0, m_arr.size() - 1);
    }
}

template <typename T>
void Array<T>::quicksort(std::vector<T>& arr, int start, int end)
{
    if (start < end) {
        int pi = partition(arr, start, end);
        quicksort(arr, start, pi - 1);
        quicksort(arr, pi + 1, end);
    }
}

template <typename T>
int Array<T>::partition(std::vector<T>& arr, int start, int end)
{
    int pivot = m_arr[end];
    int i = start;
    int j = end - 1;
    while (true) {
        while (i <= j && m_arr[i] < pivot){
            ++i;
        }
        while (i <= j && m_arr[j] > pivot) {
            --j;
        }
        if (i >= j){
            break;
        }
        std::swap(m_arr[i++], m_arr[j--]);
    }
    std::swap(m_arr[i], m_arr[end]);
    return i;
}

template <typename T>
void Array<T>::CountingSort()
{
    int min = *std::min_element(m_arr.begin(), m_arr.end());
    int max = *std::max_element(m_arr.begin(), m_arr.end());
    int range = max - min + 1;
    std::vector<int>count (range);
    for (int i = 0; i < m_arr.size(); ++i) {
        ++count[m_arr[i] - min];
    }

    for (int i = 1; i < range; ++i) {
        count[i] += count[i - 1];
    }

    std::vector<T> output (m_arr.size());
    for (int i = m_arr.size(); i >= 0; --i) {
        output[count[m_arr[i] - min] - 1] = m_arr[i];
    }

    m_arr = output;
}

template <typename T>
void Array<T>::RadixSort()
{
    std::vector<T> positive;
    std::vector<T> negative;
    for (auto& elem : m_arr) {
        if (elem >= 0) {
            positive.push_back(elem);
        } else {
            negative.push_back(-elem);
        }
    }
    if (!positive.empty()) {
        int max = *max_element(positive.begin(), positive.end());
        for (int exp = 1; max / exp > 0; exp *= 10) {
            counting(positive, exp); 
        }
    }

    if (!negative.empty()) {
        int max = *max_element(negative.begin(), negative.end());
        for (int exp = 1; max / exp > 0; exp *= 10) {
            counting(negative, exp); 
        }
        std::reverse(negative.begin(), negative.end());  
    }

    for (auto& elem : negative) {
        elem = -elem;
    }

    m_arr = std::move(negative);
    m_arr.insert(m_arr.end(), positive.begin(), positive.end());
}

template <typename T>
void Array<T>::counting(std::vector<T>& arr, int exp)
{
    std::vector<T> output(arr.size());
    int count[10] = {0};
    for (int i = 0; i < arr.size(); ++i) {
        ++count[(arr[i] / exp) % 10];
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; --i) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        --count[(arr[i] / exp) % 10];
    }
    arr = std::move(output);
}

template <typename T>
void Array<T>::BucketSort()
{
    T max = *max_element(m_arr.begin(), m_arr.end());
    T min = *min_element(m_arr.begin(), m_arr.end());
    int bucketCount = 30;
    std::vector<std::vector<int>> bucket(bucketCount);
    for (int i = 0; i < m_arr.size(); ++i) {
        int bi = (m_arr[i] - min) / (max - min) * (bucketCount - 1);
        bucket[bi].push_back(m_arr[i]);
    }

    for (int i = 0; i < bucket.size(); ++i){
        if (!bucket[i].empty()){
            insertion(bucket[i]);
        }
    }
    int ind = 0;
    for (int i = 0; i < bucketCount; ++i){
        if (!bucket[i].empty()){
            for (int j = 0; j < bucket[i].size(); ++j) {
                m_arr[ind++] = bucket[i][j];
            }
        }
    }
}

template <typename T>
void Array<T>::insertion(std::vector<T>& arr)
{
    for (int i = 1; i < arr.size() - 1; ++i){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template<typename T>
Array<T>::~Array()
{}

template <typename T>
int Array<T>::upper_bound(int target)
{
    int start = 0;
    int end = m_arr.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (m_arr[mid] < target){
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}

template <typename T>
int Array<T>::lower_bound(int target)
{
    int start = 0;
    int end = m_arr.size() - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (m_arr[mid] <= target){
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;   
}

