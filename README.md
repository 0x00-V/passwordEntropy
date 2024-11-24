Certainly! Here's a more concise README for your password entropy calculator:

---

# Password Entropy Calculator

This program calculates the **entropy** of a password and estimates its strength.

### Formula

The entropy \( H \) is calculated using the formula:

\[
H = L \times \log_2(S)
\]

Where:
- \( L \) is the **length** of the password.
- \( S \) is the **size of the pool of possible symbols** (e.g., lowercase letters, uppercase letters, digits, and symbols).

### Usage

1. **Compile the Program**:
   ```bash
   g++ -o entropy entropy.cpp
   ```

2. **Run the Program**:
   ```bash
   ./entropy {password}
   ```

   Example:
   ```bash
   ./entropy myPassword123
   ```

   Output:
   ```
   Your password is Strong
   Entropy: 56.87 bits
   ```

### Valid Characters

The program supports:
- Lowercase letters: `a-z`
- Uppercase letters: `A-Z`
- Digits: `0-9`
- Printable ASCII characters (excluding whitespace)

---
