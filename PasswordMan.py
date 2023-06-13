import sqlite3
import hashlib

# Connect to database or create if it doesn't exist
conn = sqlite3.connect('passwords.db')

# Create table if it doesn't exist
conn.execute('''CREATE TABLE IF NOT EXISTS passwords
                 (id INTEGER PRIMARY KEY AUTOINCREMENT,
                  service TEXT NOT NULL,
                  username TEXT NOT NULL,
                  password TEXT NOT NULL)''')

def add_password(service, username, password):
    # Hash password using SHA-256 algorithm
    hashed_password = hashlib.sha256(password.encode()).hexdigest()

    # Insert password into database
    conn.execute(f"INSERT INTO passwords (service, username, password) VALUES ('{service}', '{username}', '{hashed_password}')")
    conn.commit()
    print("Password added successfully.")

def get_password(service):
    # Retrieve password from database
    cursor = conn.execute(f"SELECT password FROM passwords WHERE service = '{service}'")
    row = cursor.fetchone()

    # If password found, ask user for master password and compare hashes
    if row is not None:
        hashed_password = row[0]
        master_password = input("Enter master password: ")
        if hashlib.sha256(master_password.encode()).hexdigest() == hashed_password:
            print(f"Password for {service}: {row[0]}")
        else:
            print("Incorrect master password.")
    else:
        print("Password not found.")

def main():
    while True:
        choice = input("Enter 1 to add a password, 2 to get a password, or 0 to exit: ")
        if choice == "1":
            service = input("Enter service name: ")
            username = input("Enter username: ")
            password = input("Enter password: ")
            add_password(service, username, password)
        elif choice == "2":
            service = input("Enter service name: ")
            get_password(service)
        elif choice == "0":
            conn.close()
            break
        else:
            print("Invalid choice.")

if __name__ == '__main__':
    main()
