document.addEventListener("DOMContentLoaded", ()=> {
    update_table();
});

const form = document.querySelector("form");
const tbody = document.querySelector("#table_person tbody");
const message = document.querySelector("#message");
const btn_clean = document.querySelector("#btn_clean");
const btn_cancel = document.querySelector("#btn_cancel");

let editingId = null;

async function update_table() {
    const res = await fetch("/person", {
        method: "GET"
    });
    const people = await res.json();

    const amount = document.querySelector("#amount");
    amount.textContent = people.length;

    tbody.innerHTML = "";

    people.forEach(person => {
        const tr = document.createElement("tr");

        tr.innerHTML = `
            <td>${person.id}</td>
            <td>${person.name}</td>
            <td>${person.age}</td>
            <td class="actions">
                <button type="button" class="button btn_edit" data-id="${person.id}">Edit</button>
            </td>
            <td>
                <button type="button" class="button btn_delete" data-id="${person.id}">Delete</button>
            </td>
        `;

        tbody.appendChild(tr);
    });
}

tbody.addEventListener("click", async(e)=> {
    const btn_edit = e.target.closest(".btn_edit");
    const btn_delete = e.target.closest(".btn_delete");

    if(btn_edit){
        const row = btn_edit.closest("tr");
        const id = btn_edit.dataset.id;

        editingId = id;

        document.querySelectorAll(".btn_edit").forEach(btn => {
            btn.disabled = true;
        });

        document.querySelectorAll("tr").forEach(tr => {
            tr.classList.remove("editing");
        });

        document.querySelector("#name").value = row.children[1].textContent;
        document.querySelector("#age").value = row.children[2].textContent;

        document.querySelector("#btn_send").textContent = "Update";
        document.querySelector("#btn_cancel").hidden = false;
    }

    if(btn_delete){
        const id = btn_delete.dataset.id;

        if(!confirm(`Delete person with id=${id}?`)) return
        if(!confirm("This action cannot be undone")) return;

        const res = await fetch(`/person/${id}`, {
            method: "DELETE"
        });

        const data = await res.json();

        message.textContent = data.message;
        update_table();
    }
}); 

form.addEventListener("submit", async(e)=> {
    e.preventDefault();

    const name = document.querySelector("#name").value;
    const age = document.querySelector("#age").value;

    let url = "/person";
    let method = "POST";

    if(editingId !== null){
        url = `/person/${editingId}`;
        method = "PUT";
    }

    const res = await fetch(url, {
        method,
        headers: {"Content-Type": "application/json"},
        body: JSON.stringify({
            name: name,
            age: age
        })
    });

    const data = await res.json();

    message.textContent = data.message;

    if(res.ok) resetForm();

    update_table();
});

btn_clean.addEventListener("click", async()=> {
    if(confirm("Are you sure you want to delete everything?")){
        if(confirm("The changes are arriversible, are you sure?")){
            const res = await fetch("/person", {
                method: "DELETE"
            });
            const data = await res.json();
            alert(data.message);
            message.textContent = data.message;

            update_table();
        }
    }
});

btn_cancel.addEventListener("click", ()=> {
    resetForm();
});
function resetForm(){
    form.reset();
    
    editingId = null;
    
    document.querySelectorAll(".btn_edit").forEach(btn => {
        btn.disabled = false;
    });
    document.querySelectorAll("tr").forEach(tr => {
        tr.classList.remove("editing");
    });

    document.querySelector("#btn_send").textContent = "Send";
    document.querySelector("#btn_cancel").hidden = true;
}

const btnSmart = document.querySelector("#smartButton");

window.addEventListener("scroll", ()=> {
    btnSmart.style.display = "block";

    const scrollTop = window.scrollY;
    const windowHeight = window.innerHeight;
    const docHeight = document.documentElement.scrollHeight;

    if(scrollTop + windowHeight >= docHeight - 50){
        btnSmart.textContent = "⬆";
        btnSmart.dataset.action = "up";
    }else{
        btnSmart.textContent = "⬇";
        btnSmart.dataset.action = "down";
    }
});

btnSmart.addEventListener("click", ()=> {
    if(btnSmart.dataset.action === "up"){
        window.scrollTo({
            top: 0,
            behavior: "smooth"
        });
    }else{
        const down = document.documentElement.scrollHeight;
        window.scrollTo({
            top: down,
            behavior: "smooth"
        });
    }
});