def input_matrix(rows, cols):
    matrix = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(int(input(f"Enter element [{i+1}][{j+1}]: ")))
        matrix.append(row)
    return matrix

def print_matrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))

def add_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    return result

def subtract_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix1[0])):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    return result

def multiply_matrices(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            sum = 0
            for k in range(len(matrix2)):
                sum += matrix1[i][k] * matrix2[k][j]
            row.append(sum)
        result.append(row)
    return result

def transpose_matrix(matrix):
    result = []
    for i in range(len(matrix[0])):
        row = []
        for j in range(len(matrix)):
            row.append(matrix[j][i])
        result.append(row)
    return result

def main():
    rows1 = int(input("Enter the number of rows for the first matrix: "))
    cols1 = int(input("Enter the number of columns for the first matrix: "))
    print("Enter elements of the first matrix:")
    matrix1 = input_matrix(rows1, cols1)

    rows2 = int(input("Enter the number of rows for the second matrix: "))
    cols2 = int(input("Enter the number of columns for the second matrix: "))
    print("Enter elements of the second matrix:")
    matrix2 = input_matrix(rows2, cols2)
    while True:
        print("\nMenu:")
        print("1. Addition of two matrices")
        print("2. Subtraction of two matrices")
        print("3. Multiplication of two matrices")
        print("4. Transpose of a matrix")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            result = add_matrices(matrix1, matrix2)
            print("Result of addition:")
            print_matrix(result)
        elif choice == 2:
            result = subtract_matrices(matrix1, matrix2)
            print("Result of subtraction:")
            print_matrix(result)
        elif choice == 3:
            result = multiply_matrices(matrix1, matrix2)
            print("Result of multiplication:")
            print_matrix(result)
        elif choice == 4:
            rows = int(input("Enter the number of rows for the matrix: "))
            cols = int(input("Enter the number of columns for the matrix: "))
            print("Enter elements of the matrix:")
            matrix = input_matrix(rows, cols)
            result = transpose_matrix(matrix)
            print("Transpose of the matrix:")
            print_matrix(result)
        elif choice == 5:
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()