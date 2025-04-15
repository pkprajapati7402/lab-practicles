// ✅ Install an IDE if not already (like IntelliJ IDEA Community Edition or Eclipse)

// ✅ Go to https://start.spring.io/

// Project: Maven

// Language: Java

// Spring Boot: latest stable

// Dependencies:

// Spring Web

// Spring Data MongoDB

// Lombok (optional)

// Group: com.employee

// Artifact: management

// Package Name: com.employee.management

// ✅ Extract and open in your IDE.

// Open the files go to main. and create a new file named as EmployeeManagmentSystem.java
// Paste this content there.

package com.employee.managment;
import com.mongodb.client.*;
import com.mongodb.client.model.Filters;
import org.bson.Document;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;

public class EmployeeManagementSystem extends JFrame {
    private static final String ADMIN_PASSWORD = "Admin@123"; // Sample Admin Password.
    private static final String CONNECTION_STRING = "mongodb+srv://<your_cluster_id>:<your_cluster_password>@cluster3.mkswgci.mongodb.net/?retryWrites=true&w=majority&appName=Cluster3"; // YOur Cluster Address.

    private MongoCollection<Document> employeeCollection;

    private JTextField nameField, idField, roleField, emailField;
    private JTable employeeTable;
    private DefaultTableModel tableModel;

    public EmployeeManagementSystem() {
        // Connect to MongoDB
        try {
            MongoClient mongoClient = MongoClients.create(CONNECTION_STRING);
            MongoDatabase database = mongoClient.getDatabase("EmployeeDB");
            employeeCollection = database.getCollection("employees");
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Failed to connect to MongoDB: " + e.getMessage());
            System.exit(1);
        }

        setTitle("Employee Management System - Admin");
        setSize(800, 500);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JPanel panel = new JPanel(new GridLayout(7, 2)); 
        panel.add(new JLabel("Employee ID:"));
        idField = new JTextField();
        panel.add(idField);

        panel.add(new JLabel("Name:"));
        nameField = new JTextField();
        panel.add(nameField);

        panel.add(new JLabel("Role:"));
        roleField = new JTextField();
        panel.add(roleField);

        panel.add(new JLabel("Email:"));
        emailField = new JTextField();
        panel.add(emailField);

        JButton addButton = new JButton("Add");
        panel.add(addButton);

        JButton updateButton = new JButton("Update");
        panel.add(updateButton);

        JButton deleteButton = new JButton("Delete");
        panel.add(deleteButton);

        JButton searchButton = new JButton("Search");
        panel.add(searchButton);

        JButton logoutButton = new JButton("Logout");
        panel.add(logoutButton);

        tableModel = new DefaultTableModel(new String[]{"ID", "Name", "Role", "Email"}, 0);
        employeeTable = new JTable(tableModel);
        JScrollPane tableScroll = new JScrollPane(employeeTable);

        add(panel, BorderLayout.NORTH);
        add(tableScroll, BorderLayout.CENTER);

        loadEmployees();

        addButton.addActionListener(e -> addEmployee());
        updateButton.addActionListener(e -> updateEmployee());
        deleteButton.addActionListener(e -> deleteEmployee());
        searchButton.addActionListener(e -> searchEmployeeById());
        logoutButton.addActionListener(e -> logout());

        employeeTable.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                int row = employeeTable.getSelectedRow();
                if (row >= 0) {
                    idField.setText(tableModel.getValueAt(row, 0).toString());
                    nameField.setText(tableModel.getValueAt(row, 1).toString());
                    roleField.setText(tableModel.getValueAt(row, 2).toString());
                    emailField.setText(tableModel.getValueAt(row, 3).toString());
                }
            }
        });
    }

    private void loadEmployees() {
        tableModel.setRowCount(0);
        FindIterable<Document> docs = employeeCollection.find();
        for (Document doc : docs) {
            tableModel.addRow(new Object[]{
                doc.getString("id"),
                doc.getString("name"),
                doc.getString("role"),
                doc.getString("email")
            });
        }
    }

    private void addEmployee() {
        if (idField.getText().isEmpty() || nameField.getText().isEmpty() || 
            roleField.getText().isEmpty() || emailField.getText().isEmpty()) {
            JOptionPane.showMessageDialog(this, "All fields must be filled!");
            return;
        }
        Document doc = new Document("id", idField.getText())
                .append("name", nameField.getText())
                .append("role", roleField.getText())
                .append("email", emailField.getText());
        employeeCollection.insertOne(doc);
        JOptionPane.showMessageDialog(this, "Employee added!");
        loadEmployees();
    }

    private void updateEmployee() {
        String empId = idField.getText();
        Document updateDoc = new Document("$set", new Document("name", nameField.getText())
                .append("role", roleField.getText())
                .append("email", emailField.getText()));
        employeeCollection.updateOne(Filters.eq("id", empId), updateDoc);
        JOptionPane.showMessageDialog(this, "Employee updated!");
        loadEmployees();
    }

    private void deleteEmployee() {
        String empId = idField.getText();
        employeeCollection.deleteOne(Filters.eq("id", empId));
        JOptionPane.showMessageDialog(this, "Employee deleted!");
        loadEmployees();
    }

    private void searchEmployeeById() {
        String empId = idField.getText();
        if (empId.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Please enter an Employee ID to search!");
            return;
        }
        Document doc = employeeCollection.find(Filters.eq("id", empId)).first();
        if (doc != null) {
            nameField.setText(doc.getString("name"));
            roleField.setText(doc.getString("role"));
            emailField.setText(doc.getString("email"));
            JOptionPane.showMessageDialog(this, "Employee found!");
        } else {
            JOptionPane.showMessageDialog(this, "Employee not found!");
        }
    }

    private void logout() {
        int confirm = JOptionPane.showConfirmDialog(this, "Are you sure you want to logout?", "Logout", JOptionPane.YES_NO_OPTION);
        if (confirm == JOptionPane.YES_OPTION) {
            this.dispose(); 
            showLogin(); 
        }
    }

    private static void showLogin() {
        JPasswordField pwd = new JPasswordField();
        int ok = JOptionPane.showConfirmDialog(null, pwd, "Enter Admin Password", JOptionPane.OK_CANCEL_OPTION);
        if (ok == JOptionPane.OK_OPTION && String.valueOf(pwd.getPassword()).equals(ADMIN_PASSWORD)) {
            new EmployeeManagementSystem().setVisible(true);
        } else {
            JOptionPane.showMessageDialog(null, "Incorrect Password. Exiting.");
            System.exit(0);
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(EmployeeManagementSystem::showLogin);
    }
}
