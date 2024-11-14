def ternary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid1 = left + (right - left) // 3
        mid2 = right - (right - left) // 3

        if arr[mid1] == target:
            return mid1
        elif arr[mid2] == target:
            return mid2
        elif target < arr[mid1]:
            right = mid1 - 1
        elif target > arr[mid2]:
            left = mid2 + 1
        else:
            left = mid1 + 1
            right = mid2 - 1

    return -1  # Target not found

def main():
    n = int(input("Enter the number of club members: "))
    members = []

    for i in range(n):
        roll_no = int(input("Enter roll number of member {}: ".format(i+1)))
        members.append(roll_no)

    while True:
        print("Menu:")
        print("1. Sort the list of roll numbers")
        print("2. Search for a roll number")
        print("3. Exit")
        choice = int(input("Enter your choice:"))

        if choice == 1:

            # Sort the members by roll number
            members.sort()

            print("Sorted list of roll numbers:")
            print(members)
        
        elif choice == 2:
            target_roll = int(input("Enter the roll number to search: "))
            index = ternary_search(members, target_roll)

            if index != -1:
                print("Member with roll number", target_roll, "is found at index", index)
            else:
                print("Member with roll number", target_roll, "is not found")

        elif choice == 3:
            print("Exiting the program.")
            break

        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()