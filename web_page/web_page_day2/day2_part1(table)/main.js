const form = document.querySelector("form");
const tbody = document.querySelector("tbody");

let id = 3;


form.addEventListener("submit", (e)=> {
    e.preventDefault();

    const name = document.querySelector("#name").value = "";
    const age = document.querySelector("#age").value = "";

    if(!name || !age) return;
    if(age < 0) return;

    const tr = document.createElement("tr");

    tr.innerHTML = `
        <td>${id}</td>
        <td>${name}</td>
        <td>${age}</td>
        <td><button type="button" class="button table_file">Delete row</button></td>
    `;

    tbody.appendChild(tr);

    id++;
});

tbody.addEventListener("click", (e)=> {
    if(e.target.classList.contains("table_file")){
        e.target.closest("tr").remove();
    }
});