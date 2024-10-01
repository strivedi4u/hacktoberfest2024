const express = require('express');
const mongoose = require('mongoose');
const bcrypt = require('bcrypt');
const cors = require('cors');

// Import required modules

// Create an Express app
const app = express();

// Enable CORS
app.use(express.json());
app.use(cors());

// Connect to MongoDB
mongoose.connect('mongodb://localhost:27017/cafe', { useNewUrlParser: true, useUnifiedTopology: true })
    .then(() => {
        console.log('Connected to MongoDB');
    })
    .catch((error) => {
        console.error('Error connecting to MongoDB:', error);
    });

// Define a user schema
const userSchema = new mongoose.Schema({
    username: { type: String, required: true },
    password: { type: String, required: true }
});

// Define a user model
const User = mongoose.model('User', userSchema);
const productSchema = new mongoose.Schema({
    name: { type: String, required: true },
    price: { type: Number, required: true },
    quantity: { type: Number, required: true }
});
const Product = mongoose.model('Product', productSchema);
// Register a new user
app.post('/register', async (req, res) => {
    try {
        const { username, password } = req.body;

        // Check if the username already exists
        const existingUser = await User.findOne({ username });
        if (existingUser) {
            return res.status(400).json({ message: 'Username already exists' });
        }

        // Hash the password
        const hashedPassword = await bcrypt.hash(password, 10);

        // Create a new user
        const newUser = new User({ username, password: hashedPassword });
        await newUser.save();

        res.status(201).json({ message: 'User registered successfully' });
    } catch (error) {
        console.error('Error registering user:', error);
        res.status(500).json({ message: 'Internal server error' });
    }
});

// User login
app.post('/login', async (req, res) => {
    try {
        const { username, password } = req.body;

        // Find the user by username
        const user = await User.findOne({ username });
        if (!user) {
            return res.status(404).json({ message: 'User not found' });
        }

        // Compare the password
        const isPasswordValid = await bcrypt.compare(password, user.password);
        if (!isPasswordValid) {
            return res.status(401).json({ message: 'Invalid password' });
        }

        res.status(200).json({ message: 'Login successful' });
    } catch (error) {
        console.error('Error logging in:', error);
        res.status(500).json({ message: 'Internal server error' });
    }
});

app.get('/products',async (req,res)=>{
    try{
        const products = await Product.find();
        res.status(200).json(products);
    }catch(error){
        console.error('Error getting products:',error);
        res.status(500).json({message:'Internal server error'});
    }
})

app.post('/products',async (req,res)=>{
    try{
        const {name,price,quantity} = req.body;
        const newProduct = new Product({name,price,quantity});
        await newProduct.save();
        res.status(201).json({message:'Product added successfully'});
    }catch(error){
        console.error('Error adding product:',error);
        res.status(500).json({message:'Internal server error'});
    }
})

app.put('/products/:id',async (req,res)=>{
    try{
        const {name,price,quantity} = req.body;
        await Product.findByIdAndUpdate(req.params.id,{name,price,quantity});
        res.status(200).json({message:'Product updated successfully'});
    }catch(error){
        console.error('Error updating product:',error);
        res.status(500).json({message:'Internal server error'});
    }
})

app.delete('/products/:id',async (req,res)=>{
    try{
        await Product.findByIdAndDelete(req.params.id);
        res.status(200).json({message:'Product deleted successfully'});
    }catch(error){
        console.error('Error deleting product:',error);
        res.status(500).json({message:'Internal server error'});
    }
})
// Start the server
app.listen(3000, () => {
    console.log('Server started on port 3000');
});