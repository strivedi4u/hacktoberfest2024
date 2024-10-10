import { useEffect, useState } from "react";
import axios from "axios";

interface User {
  id: number;
  name: string;
  email: string;
}

const Users = () => {
  const [users, setUsers] = useState<User[]>([]);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);

  const fetchUsers = async () => {
    try {
      const response = await axios.get("https://jsonplaceholder.typicode.com/users");
      setUsers(response.data);
    } catch (err) {
      setError("Failed to load users. Please try again later.");
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    fetchUsers();
  }, []);

  return (
    <div className="flex flex-col items-center justify-center min-h-screen bg-gray-50 px-4">
      <h2 className="text-2xl font-bold mb-6 text-center">Users</h2>

      {loading && !error && (
        <p className="text-lg text-gray-600 text-center" aria-live="polite">
          Loading users...
        </p>
      )}

      {error && (
        <p className="text-lg text-red-600 text-center" aria-live="assertive">
          {error}
        </p>
      )}

      {!loading && !error && users.length > 0 && (
        <ul className="space-y-6 max-w-lg mx-auto">
          {users.map((user) => (
            <li key={user.id} className="bg-white p-6 rounded-lg shadow-md">
              <h3 className="text-xl font-semibold text-gray-800">{user.name}</h3>
              <p className="text-gray-600">{user.email}</p>
            </li>
          ))}
        </ul>
      )}

      {!loading && !error && users.length === 0 && (
        <p className="text-lg text-gray-600 text-center">No users found.</p>
      )}
    </div>
  );
};

export default Users;
