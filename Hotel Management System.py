class HotelManagementSystem:
    def __init__(self):
        self.rooms = {101: None, 102: None, 103: None, 104: None, 105: None}  # Room numbers and availability
        self.customers = {}  # Stores customer details with room number as key

    def check_availability(self):
        available_rooms = [room for room, customer in self.rooms.items() if customer is None]
        if available_rooms:
            print("Available Rooms:", available_rooms)
        else:
            print("No rooms available at the moment.")

    def book_room(self):
        self.check_availability()
        room_number = int(input("Enter the room number you want to book: "))
        if self.rooms.get(room_number) is None:
            name = input("Enter customer name: ")
            phone = input("Enter customer phone number: ")
            self.rooms[room_number] = {"name": name, "phone": phone}
            self.customers[room_number] = {"name": name, "phone": phone}
            print(f"Room {room_number} has been successfully booked by {name}.")
        else:
            print(f"Room {room_number} is already occupied or does not exist.")

    def view_bookings(self):
        if self.customers:
            print("Current Bookings:")
            for room, details in self.customers.items():
                print(f"Room {room} is booked by {details['name']} (Phone: {details['phone']})")
        else:
            print("No bookings available at the moment.")

    def checkout(self):
        room_number = int(input("Enter the room number to checkout: "))
        if self.rooms.get(room_number) is not None:
            print(f"Room {room_number} booked by {self.rooms[room_number]['name']} has been checked out.")
            self.rooms[room_number] = None
            del self.customers[room_number]
        else:
            print(f"Room {room_number} is already vacant or does not exist.")

    def menu(self):
        while True:
            print("\n--- Hotel Management System ---")
            print("1. Check Room Availability")
            print("2. Book a Room")
            print("3. View Bookings")
            print("4. Checkout")
            print("5. Exit")

            choice = input("Enter your choice (1-5): ")

            if choice == '1':
                self.check_availability()
            elif choice == '2':
                self.book_room()
            elif choice == '3':
                self.view_bookings()
            elif choice == '4':
                self.checkout()
            elif choice == '5':
                print("Thank you for using the Hotel Management System. Goodbye!")
                break
            else:
                print("Invalid choice. Please enter a number between 1 and 5.")


if __name__ == "__main__":
    hms = HotelManagementSystem()
    hms.menu()
