/**
 * @brief �������� �������
 * @param matrix �������, ���� ���������
 * @param size ������ �������
*/
void displayMatrix(double** matrix, int size);
/**
 * @brief ������� ������������
 * @param matrix �������, � ������� ������� ������������
 * @param size ������ �������
*/
double calculateDeterminant(double** matrix, int size);
/**
 * @brief ������  �������� ������� �� ��������� ������������ 
 * @param A �������
 * @param B ��������� �������
 * @param N ����� ������� ������� � �������� �� B
*/
void solveSystem(double** A, double* B, int N);