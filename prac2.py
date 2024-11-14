def calculate_average(marks):
    if not marks:
        return 0.0
    return sum(marks) / len(marks)

def find_highest_and_lowest(marks):
    if not marks:
        return None, None
    return max(marks), min(marks)

def count_absentees(marks):
    return marks.count(-1)

def find_most_frequent_mark(marks):
    if not marks:
        return None
    mark_counts = {}
    for mark in marks:
        mark_counts[mark] = mark_counts.get(mark, 0) + 1
    max_count = max(mark_counts.values())
    most_frequent_marks = [mark for mark, count in mark_counts.items() if count == max_count]
    return most_frequent_marks

if __name__ == "__main__":
    N = int(input("Enter the number of students: "))
    marks = []

    print("Enter the marks of each student (-1 for absent):")
    for i in range(N):
        mark = int(input(f"Student {i+1}: "))
        marks.append(mark)

    average_score = calculate_average(marks)
    highest_score, lowest_score = find_highest_and_lowest(marks)
    absent_count = count_absentees(marks)
    most_frequent_mark = find_most_frequent_mark(marks)

    print("Average score of the class:", average_score)
    print("Highest score:", highest_score)
    print("Lowest score:", lowest_score)
    print("Number of absent students:", absent_count)
    print("Marks with highest frequency:", most_frequent_mark)