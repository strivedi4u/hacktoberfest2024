import React from 'react';

const ExpenseSummary = ({ expenses }) => {
  const totalExpenses = expenses.reduce((total, expense) => total + parseFloat(expense.amount), 0);

  return (
    <div className="expense-summary">
      <h2>Total Expenses: ${totalExpenses.toFixed(2)}</h2>
      {/* Add filtering by category or date here if needed */}
    </div>
  );
};

export default ExpenseSummary;
