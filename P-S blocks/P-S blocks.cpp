
#include <iostream>
#include <vector>

// Функція для прямого S-блоку
std::vector<int> forwardSBlock(std::vector<int> input, std::vector<int> sBox) {
    std::vector<int> output;
    for (int i = 0; i < input.size(); i++) {
        output.push_back(sBox[input[i]]);
    }
    return output;
}

// Функція для зворотного S-блоку
std::vector<int> reverseSBlock(std::vector<int> input, std::vector<int> inverseSBox) {
    std::vector<int> output;
    for (int i = 0; i < input.size(); i++) {
        output.push_back(inverseSBox[input[i]]);
    }
    return output;
}

// Функція для P-блоку
std::vector<int> permutationBlock(std::vector<int> input, std::vector<int> permutationTable) {
    std::vector<int> output;
    for (int i = 0; i < permutationTable.size(); i++) {
        output.push_back(input[permutationTable[i]]);
    }
    return output;
}

int main() {
    // Приклади таблиць та даних для S-блоку та P-блоку
    std::vector<int> sBox = { 2, 4, 1, 3, 0, 5, 7, 6 };
    std::vector<int> inverseSBox = { 4, 2, 0, 3, 6, 1, 7, 5 };
    std::vector<int> permutationTable = { 1, 0, 3, 2 };

    // Приклад вхідних даних
    std::vector<int> inputData = { 1, 2, 3, 4 };

    // Виконуємо пряме S-блок та P-блок перетворення
    std::vector<int> forwardSResult = forwardSBlock(inputData, sBox);
    std::vector<int> permutationResult = permutationBlock(forwardSResult, permutationTable);

    // Виконуємо зворотне P-блок та S-блок перетворення
    std::vector<int> reversePermutationResult = permutationBlock(permutationResult, permutationTable);
    std::vector<int> reverseSResult = reverseSBlock(reversePermutationResult, inverseSBox);

    // Виводимо результати
    std::cout << "Input Data: ";
    for (int i : inputData) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Forward S-Block Result: ";
    for (int i : forwardSResult) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Permutation Result: ";
    for (int i : permutationResult) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse Permutation Result: ";
    for (int i : reversePermutationResult) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse S-Block Result: ";
    for (int i : reverseSResult) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
