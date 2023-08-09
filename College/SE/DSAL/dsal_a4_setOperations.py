class sets:
    """Implementation using list"""
    def __init__(self) :
            self.data = []

    def get_iter(self) :
        return iter(self.data)

    def add(self, elmt):
        if (elmt not in self.data):
            self.data.append(elmt)

    def remove(self, elmt):
        if (elmt in self.data):
            self.data.remove(elmt)
            return True
        else:
            return False

    def contains(self, elmt):
        return (elmt in self.data)

    def size(self) -> int:
        l = 0
        iter1 = self.get_iter()
        for elmt in iter1:
            l += 1
        return l

    def intersection(self, input_set):
        ans = []
        set1 = list(input_set)
        for elmt in set1:
            if (elmt in self.data):
                ans.append(elmt)
        return ans

    def union(self, input_set):
        ans = self.data.copy()
        set1 = list(input_set)
        for elmt in set1:
            if (elmt not in self.data):
                ans.append(elmt)
        return ans

    def difference(self, input_set):
        ans = self.data.copy()
        set1 = list(input_set)
        for elmt in set1:
            if elmt in ans:
                ans.remove(elmt)
        return ans

    def subset(self, input_set):
        for e in input_set:
            if e not in self.data:
                return False
        return True

    def display(self):
        str_set = str(self.data)
        print(str_set.replace('[', '{').replace(']', '}'))


def input_set():
    ans = set()
    n = int(input("Enter number of elements in set:"))
    for i in range(n):
        ans.add(int(input(f"Enter element {i+1}:")))
    return ans


def print_set(lst: list):
    str_set = str(lst)
    print(str_set.replace('[', '{').replace(']', '}'))


def menu():
    print("MENU")
    print("1.Add new element")
    print("2.Remove element")
    print("3.Search element")
    print("4.Display Size of Set")
    print("5.Intersection of Sets")
    print("6.Union of Sets")
    print("7.Difference of Sets")
    print("8.Check if subset of Set")
    print("9.Display Set")
    print("10. exit")
    print("0.Display Menu")


def main():
    s1 = sets()
    choice = 1
    menu()
    while (choice != 10):
        choice = int(input("Enter Your Choice(0 for MENU):"))
        match (choice):
            case (1):
                n = int(input("Enter Number to add:"))
                s1.add(n)
                print("Element added sucessfully")
            case (2):
                n = int(input("Enter Number to Remove:"))
                if (s1.remove(n)):
                    print("Element Removed sucessfully")
                else:
                    print("Element Not present in set")
            case (3):
                n = int(input("Enter Number to Find:"))
                if (s1.contains(n)):
                    print("Element Present in set")
                else:
                    print("Element Not present in set")
            case (4):
                print("Size of the set is ", s1.size())
            case (5):
                s = input_set()
                print("Intersection of sets is ", end="")
                print_set(s1.intersection(s))
            case (6):
                s = input_set()
                print("Union of sets is ", end="")
                print_set(s1.union(s))
            case (7):
                s = input_set()
                print("Difference of sets is ", end="")
                print_set(s1.difference(s))
            case (8):
                s = input_set()
                if (s1.subset(s)):
                    print("Set is Subset")
                else:
                    print("Set is Not subset")
            case (9):
                s1.display()
            case (10):
                print("Thank You!")
            case (0):
                menu()
            case default:
                print("Invalid Choice")

if __name__ == "__main__":
    main()
