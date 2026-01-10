const btnTop = document.querySelector("#btnTop");
const btnBottom = document.querySelector("#btnBottom");


window.addEventListener("scroll", ()=> {
    const bottomLimit = document.documentElement.scrollHeight - window.innerHeight;

    btnTop.style.display = window.scrollY > 1300? "block": "none";
    
    btnBottom.style.display = window.scrollY > bottomLimit? "none": "block";
});

btnTop.addEventListener("click", ()=> {
    window.scrollTo({
        top: 0,
        behavior: "smooth"
    });
});

btnBottom.addEventListener("click", ()=> {
    const down = document.documentElement.scrollHeight;

    window.scrollTo({
        top: down,
        behavior: "smooth"
    });
});