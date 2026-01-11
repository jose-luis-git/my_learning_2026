from flask import Flask, render_template, request, jsonify
from database import create_table, init_db

app = Flask(__name__)

create_table()

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/person", methods=["POST"])
def saved_person():
    data = request.get_json()
    if not data:
        return jsonify({"message": "No received data"})
    
    name = data.get("name").strip()
    age = data.get("age")

    if not name or not age:
        return jsonify({"message": "Name or age empty"})
    
    try:
        age = int(age)
        if age <= 0:
            return jsonify({"message": "Invalid age"})
    except(ValueError, TypeError):
        return jsonify({"message": f"Error: {ValueError}"})
    
    conn = init_db()
    c = conn.cursor()
    c.execute("INSERT INTO register(name,age) VALUES(?,?)", (name,age))
    conn.commit()
    conn.close()

    return jsonify({"message": "Saved person"})

@app.route("/person", methods=["GET"])
def get_person():
    conn = init_db()
    c = conn.cursor()
    c.execute("SELECT id, name,age FROM register")
    people = c.fetchall()
    conn.close()

    people_list = []


    for person in people:
        people_list.append({"id": person[0], "name": person[1], "age": person[2]})

    return jsonify(people_list)

@app.route("/person/<int:id>", methods=["DELETE"])
def delete_person(id):
    conn = init_db()
    c = conn.cursor()
    c.execute("DELETE FROM register WHERE id=?", (id,))
    conn.commit()
    conn.close()

    return jsonify({"message": "Deleted person"})

@app.route("/person", methods=["DELETE"])
def delete_all():
    conn = init_db()
    c = conn.cursor()
    c.execute("DELETE FROM register")
    conn.commit()
    conn.close()

    return jsonify({"message": "Deleted all people"})

@app.route("/person/<int:id>", methods=["PUT"])
def update_person(id):
    data = request.get_json()
    if not data:
        return jsonify({"message": "No received data"})
    
    name = data.get("name").strip()
    age = data.get("age")

    if not age or not name:
        return jsonify({"message": "Name or age empty"})
    
    try:
        age = int(age)
        if age <= 0:
            return jsonify({"message": "Invalid age"})
    except(ValueError, TypeError):
        return jsonify({"message": f"Error: {ValueError}"})
    
    conn = init_db()
    c = conn.cursor()
    c.execute("UPDATE register SET name=?, age=? WHERE id=?", (name,age,id))
    conn.commit()
    conn.close()

    return jsonify({"message": "Updated person"})

if __name__ == "__main__":
    app.run(debug=True)