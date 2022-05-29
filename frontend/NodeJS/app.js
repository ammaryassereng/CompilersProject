const express = require("express");
const fs = require("fs");
const path = require("path");
const cors = require("cors");
const bodyParser = require("body-parser");
const exec = require("child_process").execFile;

const app = express();

app.use(bodyParser.json());
app.use(cors());

const port = 5000;

app.post("/write", async (req, res) => {
  try {
    const data = req.body.data;
    const filePath = path.join(__dirname, "../../testfile.txt");
    fs.writeFile(filePath, data, (err) => {
      if (err) {
        console.log(err);
      }
    });
    exec(
      "F:Handasa/CMPN403/Project/CompilersProject/c.exe",
      [],
      (err, result) => {
        if (err) {
          console.log(err);
        }
        console.log("result", result);
        res.status(200).send(result);
      }
    );
  } catch (err) {
    res.status(500).send(err.toString());
  }
});

app.listen(port, () => console.log(`Server started on port ${port}`));
