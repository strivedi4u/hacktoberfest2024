import React, { useState } from "react";
import axios from "axios";

function Login() {
  const [message, setMessage] = useState("");

  const handleLogin = async (e) => {
    e.preventDefault();

    try {
      const response = await axios.post(
        "http://localhost:5253/api/Auth/login",
        {}, // No body needed for NTLM
        {
          withCredentials: true, // Ensures credentials (NTLM) are sent
        }
      );

      if (response.status === 200) {
        setMessage("Login successful!");
      }
    } catch (error) {
      setMessage("Login failed!");
    }
  };

  return (
    <div>
      <form onSubmit={handleLogin}>
        <button type="submit">Login with NTLM</button>
      </form>
      <p>{message}</p>
    </div>
  );
}

export default Login;
