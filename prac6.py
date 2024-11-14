# Function to perform Quick Sort
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less_than_pivot = [x for x in arr[1:] if x <= pivot]
        greater_than_pivot = [x for x in arr[1:] if x > pivot]
        return quick_sort(less_than_pivot) + [pivot] + quick_sort(greater_than_pivot)

def main():
    percentages = []
    while True:
        print("Menu:")
        print("1. Enter the percentages of students")
        print("2. Quick Sort and display top 5 scores")
        print("3. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            n = int(input("Enter the number of students: "))
            percentages = []
            for i in range(n):
                percentage = float(input("Enter the percentage of student {}: ".format(i+1)))
                percentages.append(percentage)
            print("Percentages entered successfully.")
        elif choice == 2:
            sorted_percentages = quick_sort(percentages)
            print("Top 5 Scores:")
            for i in range(n-1, n-6, -1):
                print(sorted_percentages[i])
        elif choice == 3:
            print("Exiting the program.")
            break

if __name__ == "__main__":
    main()

