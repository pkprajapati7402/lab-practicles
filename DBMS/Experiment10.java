// Creating Queries using NOSQL( Document Based)


import java.io.*;
import java.util.*;

public class NoSQLDatabase {
    private static final String DB_FILE = "nsq.txt";
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        while (true) {
            System.out.println("\n--- NoSQL Document DBMS - CLI (File: nsq.txt) ---");
            System.out.println("1. Insert Document");
            System.out.println("2. View All Documents");
            System.out.println("3. Search by ID");
            System.out.println("4. Update Document by ID");
            System.out.println("5. Delete Document by ID");
            System.out.println("6. Exit");
            System.out.print("Choose an option: ");
            int choice = Integer.parseInt(scanner.nextLine());

            switch (choice) {
                case 1 -> insertDocument();
                case 2 -> viewDocuments();
                case 3 -> searchById();
                case 4 -> updateById();
                case 5 -> deleteById();
                case 6 -> {
                    System.out.println("Exiting...");
                    return;
                }
                default -> System.out.println("Invalid option.");
            }
        }
    }

    static void insertDocument() throws IOException {
        System.out.print("Enter ID: ");
        String id = scanner.nextLine();
        if (idExists(id)) {
            System.out.println("❌ ID already exists. Use a different ID.");
            return;
        }

        System.out.print("Enter Name: ");
        String name = scanner.nextLine();
        System.out.print("Enter Age: ");
        String age = scanner.nextLine();

        String record = id + "," + name + "," + age;

        BufferedWriter writer = new BufferedWriter(new FileWriter(DB_FILE, true));
        writer.write(record);
        writer.newLine();
        writer.close();

        System.out.println("✅ Document inserted successfully.");
    }

    static void viewDocuments() throws IOException {
        File file = new File(DB_FILE);
        if (!file.exists() || file.length() == 0) {
            System.out.println("📂 No documents found.");
            return;
        }

        BufferedReader reader = new BufferedReader(new FileReader(DB_FILE));
        String line;
        System.out.println("\n📄 All Documents:");
        System.out.println("ID\tName\tAge");
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(",");
            if (parts.length == 3)
                System.out.println(parts[0] + "\t" + parts[1] + "\t" + parts[2]);
        }
        reader.close();
    }

    static void searchById() throws IOException {
        System.out.print("🔍 Enter ID to search: ");
        String searchId = scanner.nextLine();

        BufferedReader reader = new BufferedReader(new FileReader(DB_FILE));
        String line;
        boolean found = false;

        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(",");
            if (parts.length == 3 && parts[0].equals(searchId)) {
                System.out.println("📄 Found Document:");
                System.out.println("ID: " + parts[0]);
                System.out.println("Name: " + parts[1]);
                System.out.println("Age: " + parts[2]);
                found = true;
                break;
            }
        }
        reader.close();

        if (!found)
            System.out.println("❌ Document not found.");
    }

    static void updateById() throws IOException {
        System.out.print("✏️ Enter ID to update: ");
        String updateId = scanner.nextLine();

        File inputFile = new File(DB_FILE);
        File tempFile = new File("temp.txt");

        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

        String line;
        boolean updated = false;

        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(",");
            if (parts.length == 3 && parts[0].equals(updateId)) {
                System.out.print("Enter new name: ");
                String newName = scanner.nextLine();
                System.out.print("Enter new age: ");
                String newAge = scanner.nextLine();
                writer.write(updateId + "," + newName + "," + newAge);
                updated = true;
            } else {
                writer.write(line);
            }
            writer.newLine();
        }

        reader.close();
        writer.close();

        if (inputFile.delete()) {
            tempFile.renameTo(inputFile);
        }

        System.out.println(updated ? "✅ Document updated." : "❌ Document not found.");
    }

    static void deleteById() throws IOException {
        System.out.print("🗑️ Enter ID to delete: ");
        String deleteId = scanner.nextLine();

        File inputFile = new File(DB_FILE);
        File tempFile = new File("temp.txt");

        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));

        String line;
        boolean deleted = false;

        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(",");
            if (parts.length == 3 && parts[0].equals(deleteId)) {
                deleted = true;
                continue;
            }
            writer.write(line);
            writer.newLine();
        }

        reader.close();
        writer.close();

        if (inputFile.delete()) {
            tempFile.renameTo(inputFile);
        }

        System.out.println(deleted ? "✅ Document deleted." : "❌ Document not found.");
    }

    static boolean idExists(String id) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(DB_FILE));
        String line;
        while ((line = reader.readLine()) != null) {
            String[] parts = line.split(",");
            if (parts.length == 3 && parts[0].equals(id)) {
                reader.close();
                return true;
            }
        }
        reader.close();
        return false;
    }
}
