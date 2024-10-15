import React, { useState } from 'react';
import ExpenseForm from './Expense-tracker-app/src/components/ExpenseForm';
import ExpenseList from './Expense-tracker-app/src/components/ExpenseList';
import ExpenseSummary from './Expense-tracker-app/src/components/ExpenseSummary';
import './App.css'; 

const App = () => {
  const [expenses, setExpenses] = useState([]);

  // Add new expense
  const addExpense = (expense) => {
    setExpenses([...expenses, expense]);
  };

  // Delete expense by id
  const deleteExpense = (id) => {
    setExpenses(expenses.filter((expense) => expense.id !== id));
  };

  // Edit expense
  const editExpense = (updatedExpense) => {
    setExpenses(
      expenses.map((expense) =>
        expense.id === updatedExpense.id ? updatedExpense : expense
      )
    );
  };

  return (
    <div className="app-container">
      <h1>Expense Tracker</h1>
      <ExpenseForm addExpense={addExpense} />
      <ExpenseSummary expenses={expenses} />
      <ExpenseList
        expenses={expenses}
        deleteExpense={deleteExpense}
        editExpense={editExpense}
      />
    </div>
  );
};

export default App;
