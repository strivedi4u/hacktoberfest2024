import { useEffect, useState } from "react";
import axios from "axios";

interface Users {
  id: number;
  name: string;
  email: string;
}

const Users = () => {
  const [users, setUsers] = useState<Users[]>([]);

  useEffect(() => {
    axios
      .get("https://jsonplaceholder.typicode.com/users")
      .then((response) => setUsers(response.data))
      .catch((error) => console.error("Error fetching users:", error));
  }, []);

  return (
    <div>
      <h2 className="text-2xl font-bold mb-4">Users</h2>
      {users.length ? (
        <ul className="space-y-4">
          {users.map((user) => (
            <li key={user.id} className="bg-white p-6 rounded-lg shadow">
              <h3 className="text-xl font-semibold">{user.name}</h3>
              <p className="text-gray-600">{user.email}</p>
            </li>
          ))}
        </ul>
      ) : (
        <p className="text-lg text-gray-600">Loading users...</p>
      )}
    </div>
  );
};

export default Users;
