import "./App.css";
import "bootstrap/dist/css/bootstrap.min.css";
import React, { useState } from "react";
import instance from "./axios";
function App() {
  const [code, setCode] = useState("");
  const [trans, setTrans] = useState("");
  const submitHandler = async (event) => {
    event.preventDefault();

    const res = await instance.post("/write", { data: code });
    console.log(res);
    setTrans(res.data.transcript);
  };
  const inputChangeHandler = (event) => {
    setCode(event.target.value);
  };

  return (
    <div className="app">
      <h1 className="header">TEAM#13 COMPILER</h1>
      <h2 className="editor">Code Editor</h2>
      <form method="get" id="compiler" onSubmit={submitHandler}>
        <textarea
          value={code}
          className="input"
          onChange={inputChangeHandler}
          id="code"
        ></textarea>
        <input
          type="submit"
          value="Compile"
          className="btn btn-success ms-5"
        ></input>
        <h2 className="trans">Transcript</h2>
        <textarea
          className="terminal"
          id="terminal"
          rows={8}
          value={trans}
          readOnly
        ></textarea>
      </form>
    </div>
  );
}

export default App;
