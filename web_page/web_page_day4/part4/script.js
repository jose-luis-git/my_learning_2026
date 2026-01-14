const form = document.querySelector("form");
const result = document.querySelector("#result");

form.addEventListener("submit", (e)=> {
    e.preventDefault();

    const user_name = document.querySelector("#username");

    result.textContent = `Hello, ${user_name.value}`;
});