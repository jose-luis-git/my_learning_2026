from functools import wraps

def repeat(amount):
    def decorator(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            result = None
            
            for i in range(amount):
                result = func(*args, **kwargs)
            return result
        return wrapper
    return decorator

while(True):
    try:
        name = input("Enter your name: ")   
        if name.strip() == "":
            raise ValueError
        
        amount = int(input("Enter the number of greetings you want: "))
        if amount <= 0:
            raise ValueError("Invalid amount")
        break
    except ValueError:
        print("Error: Invalid data")
            


@repeat(amount)
def greet_user(name):
    print(f"Hello {name}")


greet_user(name)