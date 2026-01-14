const btn_message = document.querySelector("#btn_message");
const message = document.querySelector("#message");

btn_message.hidden = false;

btn_message.addEventListener("click", ()=> {
    message.textContent = "Hello :)";
    btn_message.classList.toggle("verde");
});