def avg_score(marks):
    total_marks = sum(marks)
    count = len(marks)
    return total_marks / count if count > 0 else 0

def high_and_low(marks):
    if not marks:
        return None, None
    highest = max(marks)
    lowest = min(marks)
    return highest, lowest

def absent(marks):
    return marks.count(None)

def highest_freq(marks):
    if not marks:
        return None
    frequency = {}
    for mark in marks:
        if mark is not None:
            if mark in frequency:
                frequency[mark] += 1
            else:
                frequency[mark] = 1
    highest_frequency_mark = max(frequency, key=frequency.get)
    return highest_frequency_mark

def main():
    marks = []
    n = int(input("Enter the number of students: "))
    for i in range(n):
        mark = input(f"Enter the mark for student {i+1} (or 'A' if absent): ")
        if mark.upper() == 'A':
            marks.append(None)
        else:
            marks.append(int(mark))

    while True:
        print("\nMenu:")
        print("1. Average score of class")
        print("2. Highest and lowest score of class")
        print("3. Count of students who were absent for the test")
        print("4. Display mark with highest frequency")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            average = avg_score([mark for mark in marks if mark is not None])
            print("Average score of class:", average)
        elif choice == 2:
            highest, lowest = high_and_low([mark for mark in marks if mark is not None])
            print("Highest score of class:", highest)
            print("Lowest score of class:", lowest)
        elif choice == 3:
            absent_count = absent(marks)
            print("Count of students who were absent for the test:", absent_count)
        elif choice == 4:
            highest_frequency_mark = highest_freq([mark for mark in marks if mark is not None])
            print("Mark with highest frequency:", highest_frequency_mark)
        elif choice == 5:
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()