import tkinter as tk
from tkinter import ttk
from datetime import datetime
from tkcalendar import Calendar

# Initialize window
window = tk.Tk()
window.title("Desktop App")
window.geometry("500x500")
window.configure(bg="#f0e6f6")  # Set background color to light purple

# Function to display the current time
def show_time():
    time_label.configure(text=datetime.now().strftime("%H:%M:%S"))
    window.after(1000, show_time)

# Function to display the calendar
def show_calendar():
    top = tk.Toplevel(window)
    cal = Calendar(top, selectmode='day', date_pattern='yyyy-mm-dd')
    cal.pack(pady=20)

# Function to add a task to the to-do list
def add_task():
    task = task_entry.get()
    if task != "":
        task_list.insert(tk.END, task)
        task_entry.delete(0, tk.END)

# Function to mark a task as done
def mark_done():
    task_list.delete(tk.ACTIVE)

# Create a frame for the clock
clock_frame = tk.Frame(window, bg="#f0e6f6")
clock_frame.pack(pady=20)

# Add label to display the current time
time_label = tk.Label(clock_frame, font=("Arial", 50), bg="#f0e6f6")
time_label.pack()

# Show the current time
show_time()

# Create a frame for the calendar and to-do list
calendar_frame = tk.Frame(window, bg="#f0e6f6")
calendar_frame.pack(pady=20)

# Add button to display the calendar
cal_button = ttk.Button(calendar_frame, text="Calendar", command=show_calendar)
cal_button.pack(side=tk.LEFT, padx=20)

# Add label for the to-do list
task_label = tk.Label(calendar_frame, text="To-Do List:", font=("Arial", 16), bg="#f0e6f6")
task_label.pack(side=tk.LEFT)

# Create a frame for the to-do list and scrollbar
task_frame = tk.Frame(calendar_frame, bg="#f0e6f6")
task_frame.pack(pady=10)

# Add scrollbar to the to-do list
scrollbar = ttk.Scrollbar(task_frame)
scrollbar.pack(side=tk.RIGHT, fill=tk.Y)

# Add the to-do list
task_list = tk.Listbox(task_frame, width=40, height=10, yscrollcommand=scrollbar.set)
task_list.pack(side=tk.LEFT, fill=tk.BOTH)
scrollbar.config(command=task_list.yview)

# Add entry box for new tasks
task_entry = tk.Entry(window, width=40, font=("Arial", 12))
task_entry.pack(pady=20)

# Add button to add tasks to the to-do list
add_button = ttk.Button(window, text="Add Task", command=add_task)
add_button.pack()

# Add button to mark a task as done
done_button = ttk.Button(window, text="Done", command=mark_done)
done_button.pack(pady=20)

# Run the GUI
window.mainloop()
