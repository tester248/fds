def get_unique_list(input_list):
    unique_list = []
    for item in input_list:
        if item not in unique_list:
            unique_list.append(item)
    return unique_list

def list_cricket_and_badminton(cricket, badminton):
    result = []
    for student in cricket:
        if student in badminton:
            result.append(student)
    return result

def list_either_cricket_or_badminton_not_both(cricket, badminton):
    result = []
    for student in cricket:
        if student not in badminton:
            result.append(student)
    for student in badminton:
        if student not in cricket:
            result.append(student)
    return result

def count_neither_cricket_nor_badminton(all_students, cricket, badminton):
    count = 0
    for student in all_students:
        if student not in cricket and student not in badminton:
            count += 1
    return count

def count_cricket_and_football_not_badminton(cricket, football, badminton):
    count = 0
    for student in cricket:
        if student in football and student not in badminton:
            count += 1
    return count

def main():
    all_students = get_unique_list(input("Enter all students (comma separated): ").split(","))
    cricket = get_unique_list(input("Enter cricket players (comma separated): ").split(","))
    badminton = get_unique_list(input("Enter badminton players (comma separated): ").split(","))
    football = get_unique_list(input("Enter football players (comma separated): ").split(","))

    while True:
        print("\nMenu:")
        print("1. List of students who play both cricket and badminton")
        print("2. List of students who play either cricket or badminton but not both")
        print("3. Number of students who play neither cricket nor badminton")
        print("4. Number of students who play cricket and football but not badminton")
        print("5. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            result = list_cricket_and_badminton(cricket, badminton)
            print("Students who play both cricket and badminton:", result)
        elif choice == 2:
            result = list_either_cricket_or_badminton_not_both(cricket, badminton)
            print("Students who play either cricket or badminton but not both:", result)
        elif choice == 3:
            result = count_neither_cricket_nor_badminton(all_students, cricket, badminton)
            print("Number of students who play neither cricket nor badminton:", result)
        elif choice == 4:
            result = count_cricket_and_football_not_badminton(cricket, football, badminton)
            print("Number of students who play cricket and football but not badminton:", result)
        elif choice == 5:
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()