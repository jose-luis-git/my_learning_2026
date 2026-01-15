import json

with open("python/day2/part1/store.json", "r", encoding="utf-8") as archive:
    data = json.load(archive)

print(f"{data['tienda']}")

for product in data["productos"]:
    print(f"{product['nombre']} - ${product['precio']} - stock: {product['stock']}")

print("\nAvailable products: ")
for product in data["productos"]:
    if product["stock"] > 0:
        print(f"{product['nombre']}")

total_inventory = 0

for product in data["productos"]:
    total_inventory += product["precio"] * product["stock"]

print(f"Total inventory value: ${total_inventory}")