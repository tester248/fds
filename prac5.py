def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

def main():
    n = int(input("Enter the number of students: "))
    percentages = []

    for i in range(n):
        percentage = float(input("Enter the percentage of student {}: ".format(i+1)))
        percentages.append(percentage)

    print("Original percentages:", percentages)

    
    while True:
        print("Menu:")
        print("1. Sort the list of percentages using Selection Sort")
        print("2. Sort the list of percentages using Bubble Sort")
        print("3. Display the top 5 scores")
        print("4. Exit")

        choice = int(input("Enter your choice: "))
        if choice == 1:
            selection_sort(percentages)
            print("Percentages after Selection Sort:", percentages)
        elif choice == 2:
            bubble_sort(percentages)
            print("Percentages after Bubble Sort:", percentages)
        elif choice == 3:
            print("Top 5 Scores:")
            for i in range(n-1, n-6, -1):
                print(percentages[i])
        elif choice == 4:
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()