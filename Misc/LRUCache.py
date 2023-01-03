#User function Template for python3

# design the class in the most optimal way

class Node:
	def __init__(self, key, value):
		self.key = key
		self.val = value
		self.next = None
		self.prev = None
		
class DoublyList:
	def __init__(self):
		self.head = None
		self.tail = None
		self.size = 0

	def insert(self, key, val):
		node = Node(key, val)
		if self.tail:
			node.prev = self.tail
			self.tail.next = node
			self.tail = self.tail.next
		else:
			self.tail = self.head = node
		self.size += 1
		return node

	def remove(self, mp):
		if self.head:
		    del mp[self.head.key]
			if self.head == self.tail:
				self.tail = None
				self.head = None
			else:
				self.head = self.head.next
			self.size -= 1

	def move_to_front(self, node):
		if not self.head or not node or node == self.tail:
			return
		if self.size == 1:
			return
		if node == self.head:
			self.head = self.head.next
			self.head.prev = None
			self.tail.next = node
			node.prev = self.tail
			self.tail = self.tail.next
			self.tail.next = None
		else:
			node.prev.next = node.next
			node.next.prev = node.prev
			node.next = None
			self.tail.next = node
			node.prev = self.tail
			self.tail = self.tail.next
        
class LRUCache:
	def __init__(self, size):
		self.size = size
		self.list = DoublyList()
		self.mp = {}

	def get(self, key):
		if not self.mp.get(key):
			return -1
		node = self.mp[key]
		self.list.move_to_front(node)
		return node.val

	def set(self, key, val):
		if self.mp.get(key):
			self.mp[key].val = val
			self.list.move_to_front(self.mp[key])
			return
		self.mp[key] = self.list.insert(key, val)
		if self.list.size > self.size:
			self.list.remove(self.mp)
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        cap = int(input())  # capacity of the cache
        qry=int(input())  #number of queries
        a = list(map(str, input().strip().split()))  # parent child info in list
        
        lru=LRUCache(cap)
        
       
        i=0
        q=1
        while q<=qry:
            qtyp=a[i]
            
            if qtyp=='SET':
                lru.set(int(a[i+1]),int(a[i+2]))
                i+=3
            elif qtyp=='GET':
                print(lru.get(int(a[i+1])),end=' ')
                i+=2
            q+=1
        print()
# } Driver Code Ends
