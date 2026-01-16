import json
from functools import wraps

with open("python/day2/part1/user.json", "r", encoding="utf-8") as archive:
    data = json.load(archive)

def verify_key(required_key):
    def decorator(func):
        @wraps(func)
        def wrapper(data, *args, **kwargs):
            for key in required_key:
                if key not in data:
                    raise ValueError(f"Missing key: {key}")
            return func(data, *args, **kwargs)
        return wrapper
    return decorator

@verify_key(["user", "age", "email"])
def process_user(data):
    print("Valid JSON, process user.....")
    print(f"User: {data['user']} - age: {data['age']} - email: {data['email']}")

process_user(data)