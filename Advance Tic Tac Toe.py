import tkinter as tk
from tkinter import messagebox

class TicTacToe:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("Tic Tac Toe")
        self.window.geometry("450x450")  

        self.current_player = "X"
        self.board = [["" for _ in range(3)] for _ in range(3)]
        
        self.mode = tk.StringVar(value="Human")
        self.choose_mode()

    def choose_mode(self):
        self.clear_window()
        
        label = tk.Label(self.window, text="Choose Game Mode", font=("Helvetica", 20))
        label.pack(pady=20)
        
        human_button = tk.Button(self.window, text="Play with Human", font=("Helvetica", 16), command=self.start_human_mode)
        human_button.pack(pady=10)
        
        computer_button = tk.Button(self.window, text="Play with Computer", font=("Helvetica", 16), command=self.start_computer_mode)
        computer_button.pack(pady=10)
    
    def clear_window(self):
        for widget in self.window.winfo_children():
            widget.destroy()
    
    def start_human_mode(self):
        self.mode.set("Human")
        self.create_board()
    
    def start_computer_mode(self):
        self.mode.set("Computer")
        self.create_board()
    
    def create_board(self):
        self.clear_window()
        
        self.buttons = []
        for i in range(3):
            row = []
            for j in range(3):
                button = tk.Button(self.window, text="", width=10, height=5, font=("Helvetica", 18),
                                   bg="lightblue", activebackground="lightgreen",
                                   command=lambda i=i, j=j: self.make_move(i, j))
                button.grid(row=i, column=j)
                row.append(button)
            self.buttons.append(row)
    
    def make_move(self, row, col):
        if self.board[row][col] == "":
            self.board[row][col] = self.current_player
            self.buttons[row][col].config(text=self.current_player)
            if self.check_winner(self.current_player):
                messagebox.showinfo("Game Over", f"Player {self.current_player} wins!")
                self.window.quit()
            elif self.is_board_full():
                messagebox.showinfo("Game Over", "It's a draw!")
                self.window.quit()
            else:
                if self.mode.get() == "Human":
                    self.current_player = "O" if self.current_player == "X" else "X"
                else:
                    self.current_player = "O"
                    self.computer_move()
    
    def computer_move(self):
        move = self.find_best_move()
        if move:
            row, col = move
            self.board[row][col] = self.current_player
            self.buttons[row][col].config(text=self.current_player)
            if self.check_winner(self.current_player):
                messagebox.showinfo("Game Over", "Computer wins!")
                self.window.quit()
            elif self.is_board_full():
                messagebox.showinfo("Game Over", "It's a draw!")
                self.window.quit()
            else:
                self.current_player = "X"

    def find_best_move(self):
        best_val = -1000
        best_move = (-1, -1)
        
        for i in range(3):
            for j in range(3):
                if self.board[i][j] == "":
                    self.board[i][j] = self.current_player
                    move_val = self.minimax(0, False)
                    self.board[i][j] = ""
                    if move_val > best_val:
                        best_move = (i, j)
                        best_val = move_val
                        
        return best_move

    def minimax(self, depth, is_max):
        score = self.evaluate()

        if score == 10:
            return score - depth
        if score == -10:
            return score + depth
        if self.is_board_full():
            return 0

        if is_max:
            best = -1000
            for i in range(3):
                for j in range(3):
                    if self.board[i][j] == "":
                        self.board[i][j] = self.current_player
                        best = max(best, self.minimax(depth + 1, not is_max))
                        self.board[i][j] = ""
            return best
        else:
            best = 1000
            opponent = "O" if self.current_player == "X" else "X"
            for i in range(3):
                for j in range(3):
                    if self.board[i][j] == "":
                        self.board[i][j] = opponent
                        best = min(best, self.minimax(depth + 1, not is_max))
                        self.board[i][j] = ""
            return best

    def evaluate(self):
        for i in range(3):
            if self.board[i][0] == self.board[i][1] == self.board[i][2] != "":
                return 10 if self.board[i][0] == self.current_player else -10
            if self.board[0][i] == self.board[1][i] == self.board[2][i] != "":
                return 10 if self.board[0][i] == self.current_player else -10
        if self.board[0][0] == self.board[1][1] == self.board[2][2] != "":
            return 10 if self.board[0][0] == self.current_player else -10
        if self.board[0][2] == self.board[1][1] == self.board[2][0] != "":
            return 10 if self.board[0][2] == self.current_player else -10
        return 0

    def check_winner(self, player):
        for i in range(3):
            if self.board[i][0] == self.board[i][1] == self.board[i][2] == player:
                return True
            if self.board[0][i] == self.board[1][i] == self.board[2][i] == player:
                return True
        if self.board[0][0] == self.board[1][1] == self.board[2][2] == player:
            return True
        if self.board[0][2] == self.board[1][1] == self.board[2][0] == player:
            return True
        return False
    
    def is_board_full(self):
        for row in self.board:
            if "" in row:
                return False
        return True
    
    def run(self):
        self.window.mainloop()

game = TicTacToe()
game.run()
