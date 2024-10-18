import React from 'react';

const ExpenseList = ({ expenses, onDeleteExpense }) => {
  return (
    <ul>
      {expenses.map((expense, index) => (
        <li key={index}>
          <span>{expense.description} - ${expense.amount.toFixed(2)} [{expense.category}]</span>
          <button onClick={() => onDeleteExpense(index)}>Delete</button>
        </li>
      ))}
    </ul>
  );
};

export default ExpenseList;
