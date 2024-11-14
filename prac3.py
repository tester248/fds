def menu():
    print("\nMatrix Operations Menu")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Transpose")
    print("5. Exit")

def input_matrix(rows, cols):
    matrix = []
    print(f"Enter the elements of the matrix ({rows}x{cols}):")
    for i in range(rows):
        row = list(map(int, input().split()))
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
            cell = 0
            for k in range(len(matrix2)):
                cell += matrix1[i][k] * matrix2[k][j]
            row.append(cell)
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
    while True:
        menu()
        choice = int(input("Enter your choice: "))
        
        if choice == 5:
            print("Exiting the program.")
            break
        
        rows1, cols1 = map(int, input("Enter the number of rows and columns of the first matrix: ").split())
        matrix1 = input_matrix(rows1, cols1)
        
        if choice in [1, 2, 3]:
            rows2, cols2 = map(int, input("Enter the number of rows and columns of the second matrix: ").split())
            matrix2 = input_matrix(rows2, cols2)

        if choice == 1:
            if rows1 == rows2 and cols1 == cols2:
                result = add_matrices(matrix1, matrix2)
                print("Result of Addition:")
                print_matrix(result)
            else:
                print("Matrices must be of the same size for addition.")
        
        elif choice == 2:
            if rows1 == rows2 and cols1 == cols2:
                result = subtract_matrices(matrix1, matrix2)
                print("Result of Subtraction:")
                print_matrix(result)
            else:
                print("Matrices must be of the same size for subtraction.")
        
        elif choice == 3:
            if cols1 == rows2:
                result = multiply_matrices(matrix1, matrix2)
                print("Result of Multiplication:")
                print_matrix(result)
            else:
                print("Number of columns of the first matrix must equal the number of rows of the second matrix.")
        
        elif choice == 4:
            print("Transpose of the First Matrix:")
            print_matrix(transpose_matrix(matrix1))
        
        else:
            print("Invalid choice. Please choose again.")

if __name__ == "__main__":
    main()
