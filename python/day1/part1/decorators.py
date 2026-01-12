from functools import wraps
import time

def login_required(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        user = args[0] if args else None

        if not user or user.strip() == "":
            print("User not logged in")
            return None
        
        return func(*args, **kwargs)
    return wrapper


def mesaure_time(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()

        print(f"The function {func.__name__} late {end - start:.4f} seconds")

        return result
    return wrapper

@mesaure_time
@login_required
def user_login(name):
    total = 0

    
    for i in range(1_000_000):
        total += i

    return total

while(True):
    try: 
        name = input("Enter a name: ")
        if name.strip() == "":
            raise ValueError
        break
    except ValueError:
        print("Error: Name empty")

user_login(name)