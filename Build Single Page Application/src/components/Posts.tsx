import { useEffect, useState } from "react";
import axios from "axios";

interface Post {
  id: number;
  title: string;
  body: string;
}

const Posts = () => {
  const [posts, setPosts] = useState<Post[]>([]);
  const [loading, setLoading] = useState<boolean>(true);
  const [error, setError] = useState<string | null>(null);

  const fetchPosts = async () => {
    try {
      const response = await axios.get("https://jsonplaceholder.typicode.com/posts");
      setPosts(response.data);
    } catch (error) {
      setError("Failed to load posts. Please try again later.");
    } finally {
      setLoading(false);
    }
  };

  useEffect(() => {
    fetchPosts();
  }, []);

  return (
    <div className="flex flex-col items-center justify-center min-h-screen bg-gray-50 px-4">
      <h2 className="text-2xl font-bold mb-6 text-center">Posts</h2>
      
      {loading && !error && (
        <p className="text-lg text-gray-600 text-center" aria-live="polite">
          Loading posts...
        </p>
      )}

      {error && (
        <p className="text-lg text-red-600 text-center" aria-live="assertive">
          {error}
        </p>
      )}

      {!loading && !error && posts.length > 0 && (
        <ul className="space-y-6 max-w-lg mx-auto">
          {posts.map((post) => (
            <li key={post.id} className="bg-white p-6 rounded-lg shadow-md">
              <h3 className="text-xl font-semibold text-center">
                {post.title}
              </h3>
              <p className="text-gray-700 mt-2 text-center">{post.body}</p>
            </li>
          ))}
        </ul>
      )}

      {!loading && !error && posts.length === 0 && (
        <p className="text-lg text-gray-600 text-center">
          No posts found.
        </p>
      )}
    </div>
  );
};

export default Posts;
