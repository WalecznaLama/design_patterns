from abc import ABC, abstractmethod
from typing import List


class SortStrategy(ABC):
    @abstractmethod
    def sort(self, data: List[int]) -> List[int]:
        pass


class BubbleSortStrategy(SortStrategy):
    def sort(self, data: List[int]) -> List[int]:
        data = data.copy()
        n = len(data)
        for i in range(n):
            for j in range(0, n-i-1):
                if data[j] > data[j+1] :
                    data[j], data[j+1] = data[j+1], data[j]
        return data


class QuickSortStrategy(SortStrategy):
    def sort(self, data: List[int]) -> List[int]:
        data = data.copy()
        self.quick_sort(data, 0, len(data) - 1)
        return data

    def partition(self, data: List[int], low: int, high: int) -> int:
        i = low - 1
        pivot = data[high]
        for j in range(low, high):
            if data[j] <= pivot:
                i += 1
                data[i], data[j] = data[j], data[i]
        data[i+1], data[high] = data[high], data[i+1]
        return i+1

    def quick_sort(self, data: List[int], low: int, high: int):
        if low < high:
            pi = self.partition(data, low, high)
            self.quick_sort(data, low, pi - 1)
            self.quick_sort(data, pi + 1, high)


class SortingSystem:
    def __init__(self, strategy: SortStrategy):
        self.strategy = strategy

    def sort(self, data: List[int]) -> List[int]:
        return self.strategy.sort(data)


if __name__ == "__main__":
    # Użycie
    bubble_sort_strategy = BubbleSortStrategy()
    quick_sort_strategy = QuickSortStrategy()

    data = [64, 34, 25, 12, 22, 11, 90]

    system = SortingSystem(bubble_sort_strategy)
    print(system.sort(data))  # Sortuje danymi używając strategii Bubble Sort

    system = SortingSystem(quick_sort_strategy)
    print(system.sort(data))  # Sortuje danymi używając strategii Quick Sort
