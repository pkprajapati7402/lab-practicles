// Employee Managment System Using JDBC Instead of MongoDB.
// Download mysql connector from community j version, (named as mysql-connector-j-0.9.0.jar). Extract this file and save it into same directory lib/this_file.
// Save it as EMS_JDBC.java
// 

import java.sql.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.*;

public class EMS_JDBC extends JFrame {
    private static final String DB_URL = "jdbc:mysql://localhost:3306/EmployeeDB";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "Your_MYSQL_Password";

    private Connection connection;
    private JTextField nameField, idField, roleField, emailField;
    private JTable employeeTable;
    private DefaultTableModel tableModel;

    public EMS_JDBC() {
        // Connect to MySQL
        try {
            connection = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);
            System.out.println("Connected to MySQL successfully!");
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Failed to connect to MySQL: " + e.getMessage());
            System.exit(1);
        }

        setTitle("Employee Management System - JDBC");
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
        String query = "SELECT * FROM employees";
        try (Statement stmt = connection.createStatement();
             ResultSet rs = stmt.executeQuery(query)) {
            while (rs.next()) {
                tableModel.addRow(new Object[]{
                        rs.getString("id"),
                        rs.getString("name"),
                        rs.getString("role"),
                        rs.getString("email")
                });
            }
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Failed to load employees: " + e.getMessage());
        }
    }

    private void addEmployee() {
        String query = "INSERT INTO employees (id, name, role, email) VALUES (?, ?, ?, ?)";
        try (PreparedStatement pstmt = connection.prepareStatement(query)) {
            pstmt.setString(1, idField.getText());
            pstmt.setString(2, nameField.getText());
            pstmt.setString(3, roleField.getText());
            pstmt.setString(4, emailField.getText());
            pstmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Employee added!");
            loadEmployees();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Failed to add employee: " + e.getMessage());
        }
    }

    private void updateEmployee() {
        String query = "UPDATE employees SET name = ?, role = ?, email = ? WHERE id = ?";
        try (PreparedStatement pstmt = connection.prepareStatement(query)) {
            pstmt.setString(1, nameField.getText());
            pstmt.setString(2, roleField.getText());
            pstmt.setString(3, emailField.getText());
            pstmt.setString(4, idField.getText());
            pstmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Employee updated!");
            loadEmployees();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Failed to update employee: " + e.getMessage());
        }
    }

    private void deleteEmployee() {
        String query = "DELETE FROM employees WHERE id = ?";
        try (PreparedStatement pstmt = connection.prepareStatement(query)) {
            pstmt.setString(1, idField.getText());
            pstmt.executeUpdate();
            JOptionPane.showMessageDialog(this, "Employee deleted!");
            loadEmployees();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Failed to delete employee: " + e.getMessage());
        }
    }

    private void searchEmployeeById() {
        String query = "SELECT * FROM employees WHERE id = ?";
        try (PreparedStatement pstmt = connection.prepareStatement(query)) {
            pstmt.setString(1, idField.getText());
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    nameField.setText(rs.getString("name"));
                    roleField.setText(rs.getString("role"));
                    emailField.setText(rs.getString("email"));
                    JOptionPane.showMessageDialog(this, "Employee found!");
                } else {
                    JOptionPane.showMessageDialog(this, "Employee not found!");
                }
            }
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Failed to search employee: " + e.getMessage());
        }
    }

    private void logout() {
        int confirm = JOptionPane.showConfirmDialog(this, "Are you sure you want to logout?", "Logout", JOptionPane.YES_NO_OPTION);
        if (confirm == JOptionPane.YES_OPTION) {
            this.dispose();
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new EMS_JDBC().setVisible(true));
    }
}
