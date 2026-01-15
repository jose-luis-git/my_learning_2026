import json
from functools import wraps

with open("python/day2/part1/scolar_system.json", "r", encoding="utf-8") as archive:
    data = json.load(archive)

def valide_json(key_required):
    def decorator(func):
        @wraps(func)
        def wrapper(data, *args, **kwargs):
            if key_required not in data:
                raise ValueError(f"Missing key: {key_required}")
            return func(data, *args, **kwargs)
        return wrapper
    return decorator

@valide_json("app_name")
def process_scolar_system(data):
    print("Valid JSON, processing users....")
    for user in data["usuarios"]:
        print(f"Name: {user['nombre']} - rol: {user['rol']}")

process_scolar_system(data)