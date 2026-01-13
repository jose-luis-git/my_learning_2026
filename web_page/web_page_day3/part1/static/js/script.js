document.addEventListener("DOMContentLoaded", ()=> {
    update_table();
});

const btn_clean = document.querySelector("#btn_clean");
const form = document.querySelector("form");
const tbody = document.querySelector("#table_person tbody");
const btn_cancel = document.querySelector("#btn_cancel");
const message = document.querySelector("#message");
let editingId = null;

async function update_table(){
    const res = await fetch("/person");
    const people = await res.json();

    const amount = document.querySelector("#amount");
    amount.textContent = `People amount: ${people.length}`;

    tbody.innerHTML = "";
    people.forEach(p => {
        const tr = document.createElement("tr");
        tr.innerHTML = `
            <td>${p.id}</td>
            <td>${p.name}</td>
            <td>${p.age}</td>
            <td>
                <button type="button" class="btn_edit" data-id="${p.id}">Edit</button>
            </td>
            <td>
                <button type="button" class="btn_delete" data-id="${p.id}">Delete</button>
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

        document.querySelectorAll("tr").forEach(tr => {
            tr.classList.remove("editing");
        });
        
        document.querySelectorAll(".btn_edit").forEach(btn => {
            btn.disabled = true;
        });

        document.querySelector("#name").value = row.children[1].textContent;
        document.querySelector("#age").value = row.children[2].textContent;

        document.querySelector("#btn_send").textContent = "Update";
        document.querySelector("#btn_cancel").hidden = false;
    }

    if(btn_delete){
        const id = btn_delete.dataset.id;

        if(!confirm(`Delete person with id=${id}?`)) return;
        if(!confirm("This actino cannot be undonne")) return;

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

    let url = "/person";
    let method = "POST";

    if(editingId !== null){
        url = `/person/${editingId}`;
        method = "PUT";
    }

    const name = document.querySelector("#name").value;
    const age = document.querySelector("#age").value;

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
    if(!confirm("Are you sure you want delete everything?")) return;
    if(!confirm("The changes are irreversible, are you sure?")) return;

    const res = await fetch("/person", {
        method: "DELETE"
    });
    const data = await res.json();

    alert(data.message);
    message.textContent = data.message;
    update_table();
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

const btn_smart = document.querySelector("#btn_smart");

window.addEventListener("scroll", ()=> {
    btn_smart.style.display = "block";

    const scrollTop = window.scrollY;
    const windowHeight = window.innerHeight;
    const docHeight = document.documentElement.scrollHeight;

    if(scrollTop + windowHeight >= docHeight - 50){
        btn_smart.textContent = "⬆";
        btn_smart.dataset.action = "UP";
    }else{
        btn_smart.textContent = "⬇";
        btn_smart.dataset.action = "DOWN";
    }
}); 

btn_smart.addEventListener("click", ()=> {
    if(btn_smart.dataset.action === "UP"){
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