#include <iostream>
#include <vector>
#include <algorithm>

class SortStrategy {
public:
    virtual ~SortStrategy() {}
    virtual void sort(std::vector<int>& data) = 0;  // Pure virtual function
};

class BubbleSortStrategy : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        int i, j;
        for (i = 0; i < data.size()-1; i++)
            for (j = 0; j < data.size()-i-1; j++)
                if (data[j] > data[j+1])
                    std::swap(data[j], data[j+1]);
    }
};

class QuickSortStrategy : public SortStrategy {
public:
    void sort(std::vector<int>& data) override {
        quickSort(data, 0, data.size() - 1);
    }

private:
    int partition(std::vector<int>& data, int low, int high) {
        int pivot = data[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (data[j] < pivot) {
                i++;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return (i + 1);
    }

    void quickSort(std::vector<int>& data, int low, int high) {
        if (low < high) {
            int pi = partition(data, low, high);
            quickSort(data, low, pi - 1);
            quickSort(data, pi + 1, high);
        }
    }
};

class SortingSystem {
public:
    SortingSystem(SortStrategy* strategy) : strategy(strategy) {}
    ~SortingSystem() { delete strategy; }

    void sort(std::vector<int>& data) {
        strategy->sort(data);
    }

private:
    SortStrategy* strategy;
};

int main() {
    std::vector<int> data = {64, 34, 25, 12, 22, 11, 90};

    SortingSystem* system = new SortingSystem(new BubbleSortStrategy());
    system->sort(data);
    for(int i : data)
        std::cout << i << " ";
    delete system;

    std::cout << std::endl;

    data = {64, 34, 25, 12, 22, 11, 90};  // Reset the data
    system = new SortingSystem(new QuickSortStrategy());
    system->sort(data);
    for(int i : data)
        std::cout << i << " ";
    delete system;

    return 0;
}
