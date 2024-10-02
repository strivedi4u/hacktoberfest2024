import { Routes, Route, Link } from "react-router-dom";
import Home from "./components/Home";
import Posts from "./components/Posts";
import Users from "./components/Users";

const App = () => {
  return (
    <div className="min-h-screen flex flex-col justify-center items-center bg-gray-100">
      <nav className="bg-blue-600 text-white py-4 w-full">
        <div className="container mx-auto flex justify-center items-center">
          <h1 className="text-xl font-bold mr-6">React SPA</h1>
          <ul className="flex space-x-6">
            <li>
              <Link className="hover:underline" to="/">
                Home
              </Link>
            </li>
            <li>
              <Link className="hover:underline" to="/posts">
                Posts
              </Link>
            </li>
            <li>
              <Link className="hover:underline" to="/users">
                Users
              </Link>
            </li>
          </ul>
        </div>
      </nav>

      <div className="container mx-auto py-8 flex-1 flex flex-col justify-center items-center">
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/posts" element={<Posts />} />
          <Route path="/users" element={<Users />} />
        </Routes>
      </div>
    </div>
  );
};

export default App;
