class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def __str__(self):
        nodes = []
        current = self.head
        while current:
            nodes.append(str(current.value))
            current = current.next
        return ' -> '.join(nodes)

    def __len__(self):
        return self.size

    def insert_at_head(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node
        self.size += 1

    def insert_at_tail(self, value):

        if not self.head:
            self.head = Node(value)
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = Node(value)
        self.size += 1

    def delete_at_head(self):
        if not self.head:
            return None
        value = self.head.value
        self.head = self.head.next
        self.size -= 1
        return value

    def delete(self, value):
        if not self.head:
            return None
        if self.head.value == value:
            return self.delete_at_head()
        current = self.head
        while current.next:
            if current.next.value == value:
                value = current.next.value
                current.next = current.next.next
                self.size -= 1
                return value
            current = current.next
        return None

    def find(self, value):
        current = self.head
        while current:
            if current.value == value:
                return current
            current = current.next
        return None

linked_list = LinkedList()
linked_list.insert_at_head(1)
linked_list.insert_at_head(2)
linked_list.insert_at_head(3)
print(linked_list)  
print(len(linked_list))  

linked_list.insert_at_tail(4)
print(linked_list)  
print(len(linked_list))  

deleted_value = linked_list.delete_at_head()
print(deleted_value) 
print(linked_list)  
print(len(linked_list)) 

found_node = linked_list.find(2)
print(found_node.value) 