import React from 'react';

const ExpenseSummary = ({ expenses }) => {
  const total = expenses.reduce((acc, expense) => acc + expense.amount, 0);
  return (
    <div className="summary">
      <h2>Total Expenses: ${total.toFixed(2)}</h2>
    </div>
  );
};

export default ExpenseSummary;
