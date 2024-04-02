#include <iostream>
#include <vector>
#include <bitset>
#include <tuple>


void zavd1() {
    // Визначення множин
    std::vector<char> A = { 'a', 'b', 'c' };
    std::vector<char> B = { 'x', 'y', 'z' };
    std::vector<int> C = { 0, 1 };

    // Створення множини B × A × C
    std::vector<std::tuple<char, char, int>> result;

    for (char b : B) {
        for (char a : A) {
            for (int c : C) {
                result.push_back(std::make_tuple(b, a, c));
            }
        }
    }

    // Виведення результату
    std::cout << "B * A * C = {";
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << "(" << std::get<0>(result[i]) << ", " << std::get<1>(result[i]) << ", " << std::get<2>(result[i]) << ")";
        if (i != result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "}" << std::endl;
}

std::vector<std::bitset<5>> zavd2() {
    int U[] = { 1, 2, 3, 4, 5 }; // універсум
    int A[] = { 1, 2 }; // множина A
    int B[] = { 2, 3, 4 }; // множина B

    // Створюємо бітові рядки для множин A та B
    std::vector<std::bitset<5>> sets;
    std::bitset<5> Abit, Bbit;

    for (int i = 0; i < sizeof(U) / sizeof(U[0]); i++) {
        for (int j = 0; j < sizeof(A) / sizeof(A[0]); j++) {
            if (U[i] == A[j]) {
                Abit.set(i);
                break;
            }
        }
        for (int j = 0; j < sizeof(B) / sizeof(B[0]); j++) {
            if (U[i] == B[j]) {
                Bbit.set(i);
                break;
            }
        }
    }

    // Виконуємо операції над множинами
    std::bitset<5> notA = ~Abit;
    std::bitset<5> AandB = Abit & Bbit;
    std::bitset<5> AorB = Abit | Bbit;
    std::bitset<5> AdiffB = Abit & ~Bbit;
    std::bitset<5> AxorB = Abit ^ Bbit;

    // Виводимо результати
    std::cout << "A: " << Abit << std::endl;
    std::cout << "B: " << Bbit << std::endl;
    std::cout << "notA: " << notA << std::endl;
    std::cout << "A and B: " << AandB << std::endl;
    std::cout << "A or B: " << AorB << std::endl;
    std::cout << "A diff B: " << AdiffB << std::endl;
    std::cout << "A xor B: " << AxorB << std::endl;

    sets.push_back(Abit);
    sets.push_back(Bbit);
    sets.push_back(notA);
    sets.push_back(AandB);
    sets.push_back(AorB);
    sets.push_back(AdiffB);
    sets.push_back(AxorB);

    return sets;
}

int main() {
    std::cout << "Choose task: ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        zavd1();
    }
    else if (choice == 2) {
        zavd2();
    }
    else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
