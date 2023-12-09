class Jar:
    def __init__(self, capacity):
        if capacity < 0:
            raise ValueError("Capacity must be a non-negative integer")
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return "🍪" * self._size

    def deposit(self, n):
        if not isinstance(n, int) or n < 0:
            raise ValueError("Number of cookies to deposit must be a non-negative integer")
        self._size += n
        if self._size > self._capacity:
            raise ValueError("Cookie jar capacity exceeded")

    def withdraw(self, n):
        if not isinstance(n, int) or n < 0:
            raise ValueError("Number of cookies to withdraw must be a non-negative integer")
        if n > self._size:
            raise ValueError("Not enough cookies in the jar")
        self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size

def main():
    i = int(input("Capacity: "))
    jar = Jar(i)
    n = int(input("Deposit:  "))
    jar.deposit(n)
    print(jar)
    m = int(input("Withdraw: "))
    jar.withdraw(m)
    print(jar)
    print(jar.capacity)
    print(jar.size)

main()