## Cross-Login Authentication with NTLM in .NET and React.js

### 🎯 Goal

This project demonstrates a cross-login authentication mechanism using **NTLM (NT LAN Manager)** with a **.NET backend** and **React.js frontend**. It allows users to authenticate against an NTLM-enabled server using their credentials via a React-based user interface.

### 🧾 Description

This project contains two folder: one folder **NTLMAuthConnect** contains the backend api which is implemented using ASP.NET Core Web API for NLTM authentication and another folder **ntlm-auth-frontend** contains frontend which is implemented using React.js.

### 🧮 Features Implemented

- NTLM authentication using ASP.NET Core and React.js.
- CORS handling to allow secure communication between the frontend and backend.
- User credentials are authenticated automatically using NTLM (no need to send passwords explicitly).

### 📚 Technologies Implemented

- **Backend:**
  - ASP.NET Core Web API
  - NTLM Authentication
- **Frontend:**
  - React.js
  - Axios
- **Others:**
  - CORS
  - Swagger for API documentation

### 📊 Usage:

- After ensuring that the backend is running at the mentioned url in axios, open the frontend in a browser by navigating to:

```
https://localhost:3000
```

- Click the **Login with NTLM** button. If NTLM authentication is correctly set up, the application will automatically authenticate the user.
- Check the message displayed on successful or failed login attempts.

### 🧮 Known Issues:

- **CORS Errors:** Ensure the frontend and backend URLs match and that `https://` or `http://` is used correctly in both environments that is if `http://` is used in frontend than make sure it is used in backend as well and vice-versa.
- **NTLM Compatibility:** NTLM authentication may not work properly on certain platforms, especially non-Windows environments.

**AYESHA NAZNIN**  
[![GitHub](https://img.shields.io/badge/github-%2312100E.svg?style=for-the-badge&logo=github&logoColor=white)](https://github.com/PhantomANaz) | [![LinkedIn](https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ayesha-naznin-73316a11a/)
