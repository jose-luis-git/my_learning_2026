def create_multiplicaction(n):
    def increment(a):
        result = n * a

        return result 
    return increment

one = create_multiplicaction(2)
two = create_multiplicaction(3)

print(one(5))
print(two(5))