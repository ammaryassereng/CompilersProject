import "./App.css";
import "bootstrap/dist/css/bootstrap.min.css";
import React, { useState } from "react";
import instance from "./axios";
function App() {
  const [code, setCode] = useState("");
  const submitHandler = async (event) => {
    event.preventDefault();
    await instance.post("/write", { data: code });
  };
  const inputChangeHandler = (event) => {
    setCode(event.target.value);
  };

  return (
    <div className="app">
      <h1 className="header">TEAM#13 COMPILER</h1>
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
      </form>
    </div>
  );
}

export default App;
