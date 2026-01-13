from flask import Flask, render_template, request, jsonify
from database import create_table, init_db

app = Flask(__name__)

create_table()

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/person", methods=["POST"])
def save_person():
    data = request.get_json()

    if not data:
        return jsonify({"message": "Data not found"}), 400
    
    name = data.get("name")
    if not name or name.strip() == "":
        return jsonify({"message": "Name not found"}), 400

    age = data.get("age")
    if not age:
        return jsonify({"message": "Age not found"}), 400
    
    try: 
        age = int(age)
        name = name.strip()
        if age <= 0:
            raise ValueError
    except ValueError:
        return jsonify({"message": "Invelid age"}), 400
    
    conn = init_db()
    c = conn.cursor()
    c.execute("INSERT INTO person(name, age) VALUES(?,?)", (name,age))
    conn.commit()
    conn.close()

    return jsonify({"message": "Saved person"})

@app.route("/person", methods=["GET"])
def get_person():
    conn = init_db()
    c = conn.cursor()
    c.execute("SELECT id, name, age FROM person")
    people = c.fetchall()
    conn.close()

    list_person = []


    for person in people:
        list_person.append({"id": person[0], "name": person[1], "age": person[2]})

    return jsonify(list_person)

@app.route("/person/<int:id>", methods=["PUT"])
def update_person(id):
    data = request.get_json()

    if not data:
        return jsonify({"message": "Data no found"}), 400
    
    name = data.get("name").strip()
    if not name:
        return jsonify({"message": "Name not found"}), 400
    
    age = data.get("age")
    if not age:
        return jsonify({"message": "Age not found"}), 400
    
    try:
        age = int(age)
        if age <= 0:
            raise ValueError
    except ValueError:
        return jsonify({"message": "Invelid age"}), 400
    
    conn = init_db()
    c = conn.cursor()
    c.execute("UPDATE person SET name=?, age=? WHERE id=?", (name,age,id))
    conn.commit()
    conn.close()

    return jsonify({"message": "Updated person"})

@app.route("/person/<int:id>", methods=["DELETE"])
def delete_person(id):
    conn = init_db()
    c = conn.cursor()
    c.execute("DELETE FROM person WHERE id=?", (id,))
    conn.commit()
    conn.close()

    return jsonify({"message": "Deleted person"})

@app.route("/person", methods=["DELETE"])
def delete_all():
    conn = init_db()
    c = conn.cursor()
    c.execute("DELETE FROM person")
    conn.commit()
    conn.close()

    return jsonify({"message": "Deleted all people"})

@app.errorhandler(404)
def page_not_found(error):
    return render_template("404.html"), 404

@app.errorhandler(500)
def internal_error(error):
    return render_template("500.html"), 500

if __name__ == "__main__":
    app.run(debug=True)