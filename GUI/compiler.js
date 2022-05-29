const btn = document.getElementById("compile");
btn.addEventListener("click", function handleClick(event) {
  event.preventDefault();
  const code = document.getElementById("code").value;
  const fs = require("fs");

  fs.writeFile("./testfile.txt", code, (err) => {
    if (err) {
      console.error(err);
      return;
    }
  });
});
