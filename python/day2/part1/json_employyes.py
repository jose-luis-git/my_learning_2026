import json

with open("python/day2/part1/employyes.json", "r", encoding="utf-8") as archive:
    data = json.load(archive)

print(f"{data['empresa']}")

active_employyes = {
    "empresa": data["empresa"],
    "empleados_activos": []
}

for employye in data["empleados"]:
    print(f"Name: {employye['nombre']} - salary: ${employye['salario']} - active: {employye['activo']}")

for employye in data["empleados"]:
    if employye["activo"]:
        active_employyes["empleados_activos"].append(employye)

with open("python/day2/part1/active_employyes.json", "w", encoding="utf-8") as archive:
    json.dump(active_employyes, archive, indent=4)

total_salary = 0
average_salary = 0

for emplooye in active_employyes["empleados_activos"]:
    total_salary += emplooye["salario"]

average_salary = total_salary / len(active_employyes["empleados_activos"])

print(f"\nThe total salary of the employyes is: {total_salary:.2f}")
print(f"The average salary is: {average_salary:.2f}")