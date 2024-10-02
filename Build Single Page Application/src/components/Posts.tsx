import { useEffect, useState } from "react";
import axios from "axios";

interface Post {
  id: number;
  title: string;
  body: string;
}

const Posts = () => {
  const [posts, setPosts] = useState<Post[]>([]);

  useEffect(() => {
    axios
      .get("https://jsonplaceholder.typicode.com/posts")
      .then((response) => setPosts(response.data))
      .catch((error) => console.error("Error fetching posts:", error));
  }, []);

  return (
    <div className="flex flex-col items-center justify-center min-h-screen">
      <h2 className="text-2xl font-bold mb-6 text-center">Posts</h2>
      {posts.length ? (
        <ul className="space-y-6 max-w-lg mx-auto">
          {posts.map((post) => (
            <li key={post.id} className="bg-white p-6 rounded-lg shadow">
              <h3 className="text-xl font-semibold text-center">
                {post.title}
              </h3>
              <p className="text-gray-700 mt-2 text-center">{post.body}</p>
            </li>
          ))}
        </ul>
      ) : (
        <p className="text-lg text-gray-600 text-center">Loading posts...</p>
      )}
    </div>
  );
};

export default Posts;
