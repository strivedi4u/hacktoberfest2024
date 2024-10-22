/*I have implemented the Binary Search Tree data structure in java along with all the important functions like:-
 * 1 - insert()
 * 2 - search()
 * 3 - inorder()
 * 4 - preorder()
 * 5 - postorder()
 * 6 - delete()
 * 7 - countNodes().*/

import java.util.Scanner;    //Scanner is for taking input.

//The Node class is used to create objects which are treated as nodes of the Binary Search Tree.
class Node
{
    int value;
    Node left;
    Node right;
    Node()
    {
        value = 0;
        left = right = null;
    }
    Node(int n)
    {
        value = n;
        left = right = null;
    }
}

/*The BinarySearchTree is the class to declare a binary search tree which also has various functions that can be implemented on it.*/
public class BinarySearchTree
{
    //It points to the root of the binary search tree.
    Node root;
    
    static Scanner sc = new Scanner(System.in);
    
    //This is the constuctor function to create a BinarySearchTree class object.
    public BinarySearchTree()
    {
        root = null;
    }
    
    //This is the function to insert a value(node) into the binary search tree.
    Node insert(Node root,int value)
    {
        Node v = new Node(value);
        if(root==null)
        root = v;
        else if(value<root.value)
        {
            root.left = insert(root.left,value);
        }
        else 
        {
            root.right = insert(root.right,value);
        }
        return root;
    }
    
    //This is the function to search for a value in the Binary Search Tree.
    public boolean search(Node root, int value)
    {
        if(root==null)
        return false;
        else if(root.value==value)
        return true;
        else if(value<root.value)
        {
            return search(root.left,value);
        }
        else if(value>root.value)
        {
            return search(root.right,value);
        }
        else
        {
            return false;
        }
    }
    
    //This is the function to delete a value(node) from the Binary Search Tree.
    Node delete(Node root, int value)
    {
        if(root==null)
        {
            System.out.println("BinarySearchTree empty");
            return root;
        }
        if(root.value==value)
        {
            if(root.left==root.right)
            root=null;
            else if(root.left==null)
            root = root.right;
            else if(root.right==null)
            root = root.left;
            else
            {
                Node ptr = root.right;
                while(ptr.left!=null)
                {
                    ptr = ptr.left;
                }
                ptr.left = root.left;
                root = root.right;
                
            }
        }
        else if(value>root.value)
        {
            root.right = delete(root.right,value);
        }
        else
        {
            root.left = delete(root.left,value);
        }
        return root;
    }
    
    //This is the function to print the Binary Search Tree in inorder traversal.
    void inorder(Node root)
    {
        if(root==null)
        return;
        inorder(root.left);
        System.out.print(root.value+" ");
        inorder(root.right);
    }
    
    //This is the function to print the Binary Search Tree in preorder traversal.
    void preorder(Node root)
    {
        if(root==null)
        return;
        System.out.print(root.value+" ");
        preorder(root.left);
        preorder(root.right);
    }
    
    //This is the function to print the Binary Search Tree in postorder traversal.
    void postorder(Node root)
    {
        if(root==null)
        return;
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.value+" ");
    }
    
    //This is the function to count the number of nodes in the Binary Search Tree.
    public int countNodes(Node root)
    {
        if(root==null)
        return 0;
        else
        {
            return 1+countNodes(root.left)+countNodes(root.right);
        }
    }
    
    //An example to work with the various functions and to show how the various functions are implemented.
    public static void main(String args[])
    {
        BinarySearchTree t = new BinarySearchTree();
        System.out.println("Enter the elements into the BinarySearchTree and enter -9999 to exit.");
        int value = sc.nextInt();
        while(value!=-9999)
        {
            t.root = t.insert(t.root,value);
            value = sc.nextInt();
        }
        System.out.println("In inorder the BinarySearchTree is - ");
        t.inorder(t.root);
        System.out.println("\nIn postorder the BinarySearchTree is - ");
        t.postorder(t.root);
        System.out.println("\nIn preorder the BinarySearchTree is - ");
        t.preorder(t.root);
        System.out.println();
        System.out.println("Enter the element to search for");
        int search = sc.nextInt();
        if(t.search(t.root,search))
        {
            System.out.println("Element found in the BinarySearchTree");
        }
        else
        {
            System.out.println("Element not found in the BinarySearchTree");
        }
        System.out.println("Enter the element to be deleted.");
        int delete  = sc.nextInt();
        t.root = t.delete(t.root,delete);
        System.out.println("The BinarySearchTree after deletion is");
        System.out.println("In inorder the BinarySearchTree is - ");
        t.inorder(t.root);
        System.out.println("\nIn postorder the BinarySearchTree is - ");
        t.postorder(t.root);
        System.out.println("\nIn preorder the BinarySearchTree is - ");
        t.preorder(t.root);
        System.out.println();
    }
}
