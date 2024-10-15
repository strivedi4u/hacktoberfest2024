import React from 'react';

const ExpenseList = ({ expenses, deleteExpense, editExpense }) => {
  return (
    <div className="expense-list">
      <h2>Expenses</h2>
      {expenses.length === 0 ? (
        <p>No expenses added yet.</p>
      ) : (
        expenses.map((expense) => (
          <div key={expense.id} className="expense-item">
            <span>{expense.description}</span>
            <span>${expense.amount}</span>
            <span>{expense.category}</span>
            <span>{expense.date}</span>
            <button onClick={() => deleteExpense(expense.id)}>Delete</button>
            {/* Add a button for editing */}
          </div>
        ))
      )}
    </div>
  );
};

export default ExpenseList;
