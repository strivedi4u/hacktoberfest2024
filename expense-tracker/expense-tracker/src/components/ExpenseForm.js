// src/components/ExpenseForm.js
import React, { useState } from 'react';

const ExpenseForm = ({ onAddExpense }) => {
  const [description, setDescription] = useState('');
  const [amount, setAmount] = useState('');
  const [category, setCategory] = useState('Type');

  const handleSubmit = (e) => {
    e.preventDefault();
    if (description && amount && category !== 'Type') {
      onAddExpense({ description, amount: parseFloat(amount), category });
      setDescription('');
      setAmount('');
      setCategory('Type'); // Reset category to default
    }
  };

  return (
    <form onSubmit={handleSubmit}>
      <input 
        type="text" 
        placeholder="Expense Description" 
        value={description} 
        onChange={(e) => setDescription(e.target.value)} 
        required 
      />
      <input 
        type="number" 
        placeholder="Amount" 
        value={amount} 
        onChange={(e) => setAmount(e.target.value)} 
        required 
      />
      <select value={category} onChange={(e) => setCategory(e.target.value)}>
        <option value="Type" disabled>Select Category</option> {/* Default option */}
        <option value="Food">Food</option>
        <option value="Transport">Transport</option>
        <option value="Entertainment">Entertainment</option>
        <option value="Utilities">Utilities</option>
      </select>
      <button type="submit">Add Expense</button>
    </form>
  );
};

export default ExpenseForm;
