

class ListNode:

    def __init__(self, data):
        self._data = data
        self._next = None

    def set_next(self, next):
        self._next = next

    def get_next(self):
        return self._next

    def has_next(self):
        return self._next is not None

    def print_data(self):
        print self._data

def main():
    node = head = ListNode("Dummy Head Node")
    keep_going = True

    while keep_going:
        data = raw_input("data: ")
        if data:
            newnode = ListNode(data)
            node.set_next(newnode)
            node = newnode
        else:
            keep_going = False

    node = head
    while node.has_next():
        node = node.get_next()
        node.print_data()

if __name__ == "__main__":
    main()

