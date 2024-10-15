import React, { useState } from 'react';

const ExpenseForm = ({ addExpense }) => {
  const [expenseData, setExpenseData] = useState({
    description: '',
    amount: '',
    category: '',
    date: ''
  });

  const handleSubmit = (e) => {
    e.preventDefault();
    // Add new expense with a unique ID
    addExpense({ ...expenseData, id: Date.now() });
    // Reset form fields
    setExpenseData({ description: '', amount: '', category: '', date: '' });
  };

  return (
    <form onSubmit={handleSubmit} className="expense-form">
      <input
        type="text"
        placeholder="Description"
        value={expenseData.description}
        onChange={(e) => setExpenseData({ ...expenseData, description: e.target.value })}
        required
      />
      <input
        type="number"
        placeholder="Amount"
        value={expenseData.amount}
        onChange={(e) => setExpenseData({ ...expenseData, amount: e.target.value })}
        required
      />
      <input
        type="text"
        placeholder="Category"
        value={expenseData.category}
        onChange={(e) => setExpenseData({ ...expenseData, category: e.target.value })}
        required
      />
      <input
        type="date"
        value={expenseData.date}
        onChange={(e) => setExpenseData({ ...expenseData, date: e.target.value })}
        required
      />
      <button type="submit">Add Expense</button>
    </form>
  );
};

export default ExpenseForm;
