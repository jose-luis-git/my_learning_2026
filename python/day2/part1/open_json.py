import json

with open("python/day2/part1/students.json", "r", encoding="utf-8") as archive:
    data = json.load(archive)

print(f"{data['curso']}")

for student in data["estudiantes"]:
    print(f"Name: {student['nombre']} - {student['edad']} years")

print("\n")

for student in data["estudiantes"]:
    notes = student["notas"]
    average = sum(notes) / len(notes)
    print(f"{student['nombre']} has an average of: {average:.2f}")