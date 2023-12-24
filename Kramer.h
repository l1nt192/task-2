/**
 * @brief Создание матрицы
 * @param matrix матрица, куда считываем
 * @param size размер матрицы
*/
void displayMatrix(double** matrix, int size);
/**
 * @brief Подсчет определителя
 * @param matrix матрица, у которой считаем определитель
 * @param size размер матрицы
*/
double calculateDeterminant(double** matrix, int size);
/**
 * @brief Замена  столбцов матрицы на свободные коэффециенты 
 * @param A матрица
 * @param B свободный столбец
 * @param N какой столбец матрицы А заменяем на B
*/
void solveSystem(double** A, double* B, int N);