
 #include <iostream>
#include <cmath>

// Функція для знаходження коренів квадратного рівняння та визначення їх типу
void solveQuadratic(double a, double b, double c, double& x1, double& x2) {
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {
        x1 = x2 = -b / (2 * a);
    } else {
        // Якщо дискримінант менше за нуль, корені уявні
        x1 = x2 = 1; // Позначимо умовно, що корені уявні
    }
}

int main() {
    // Отримання a та b з консолі
    int a, b;
    std::cout << "Enter values for a and b: ";
    std::cin >> a >> b;
    
    const int rows = 3;
    const int cols = 3;
    
    // Заповнення матриці з консолі
    int matrix[rows][cols];
    std::cout << "Enter values for the 3x3 matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    // Розв'язання квадратних нерівностей
    double roots[rows][cols];
    for (int i = 0; i < rows; ++i) {
        solveQuadratic(matrix[i][0], matrix[i][1], matrix[i][2], roots[i][0], roots[i][1]);
        roots[i][2] = (roots[i][0] == 1 || roots[i][1] == 1) ? 1 : 0;
    }
    
    // Виведення результату коренів на консоль
    std::cout << "Roots of quadratic inequalities and their type:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << roots[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    // Сума елементів у стовпцях без від'ємних значень
    for (int j = 0; j < cols; ++j) {
        int sum = 0;
        bool hasNegative = false;
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
                break;
            }
            sum += matrix[i][j];
        }
        if (!hasNegative) {
            std::cout << "Sum of elements in column " << j << ": " << sum << std::endl;
        }
    }
    
    // Пошук суми чисел більших та менших за задані з консолі числа
    int greaterThan, lessThan;
    std::cout << "Enter a number to find elements greater than: ";
    std::cin >> greaterThan;
    std::cout << "Enter a number to find elements less than: ";
    std::cin >> lessThan;
    
    int sumGreaterThan = 0;
    int countLessThan = 0;
    int totalLessThan = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] > greaterThan) {
                sumGreaterThan += matrix[i][j];
            }
            if (matrix[i][j] < lessThan) {
                countLessThan++;
                totalLessThan += matrix[i][j];
            }
        }
    }
    
    std::cout << "Sum of elements greater than " << greaterThan << ": " << sumGreaterThan << std::endl;
    if (countLessThan != 0) {
        double averageLessThan = static_cast<double>(totalLessThan) / countLessThan;
        std::cout << "Average of elements less than " << lessThan << ": " << averageLessThan << std::endl;
    } else {
        std::cout << "No elements found less than " << lessThan << std::endl;
    }
    
    // Пошук мінімального та максимального елементів
    int minElement = matrix[0][0];
    int maxElement = matrix[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
            }
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
            }
        }
    }
    
    std::cout << "Minimum element: " << minElement << std::endl;
    std::cout << "Maximum element: " << maxElement << std::endl;

    return 0;
}