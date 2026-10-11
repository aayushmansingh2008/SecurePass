
# 🛡️ SecurePass — Password Pattern Analyzer in C

**SecurePass** is a command-line password analysis project developed using the C programming language. It examines password characteristics, identifies predictable patterns, calculates an educational checklist score, and provides suggestions for improvement.

This project was built independently as part of my programming journey while learning C through **Harvard University's CS50x**. Features

- **Character Analysis:** Counts uppercase letters, lowercase letters, digits, and special characters.
- **Password Length Analysis:** Evaluates length-based criteria.
- **Heuristic Scoring:** Calculates a checklist score from 0 to 100.
- **Repetition Detection:** Identifies consecutive repeated characters.
- **Numerical Pattern Detection:** Recognizes ascending and descending digit sequences such as `1234` and `4321`.
- **Alphabetical Pattern Detection:** Identifies sequences such as `abcd`, `dcba`, and `aBcD`.
- **Pattern Penalties:** Deducts points for repeated characters and predictable sequences.
- **Personalized Suggestions:** Displays feedback based on the detected characteristics. Technologies Used

* **Language:** C (C11)
* **Libraries:** `stdio.h`, `string.h`, `ctype.h`
* **Development Environment:** CS50 Codespace / VS Code
* **Version Control:** Git and GitHub

## &#x20;Installation and Usage

**1. Clone the repository**

```bash
git clone https://github.com/YOUR_USERNAME/SecurePass.git
cd SecurePass
```

Replace `YOUR_USERNAME` with your GitHub username.

**2. Compile the program**

Using Clang:

```bash
clang -std=c11 -Wall -Wextra -o securepass securepass.c
```

Or using GCC:

```bash
gcc -std=c11 -Wall -Wextra -o securepass securepass.c
```

**3. Run SecurePass**

On Linux or macOS:

```bash
./securepass
```

On Windows:

```powershell
.\securepass.exe
```

The program accepts a fictional test string and displays its analysis.

## &#x20;Example Output

```text
Welcome to SecurePass!
Enter a fictional test password: Abcd@1234
Password analysis
Password length: 9
Uppercase: 1
Lowercase: 3
Digits: 4
Special character: 1
Adjacent repetitions: 0
Digit sequences detected: 1
Alphabetical sequences detected: 1
Password Score: 60
Password checklist rating: Moderate

Security Suggestions:
Consider using at least 12 characters
- Predictable numerical sequence detected.
- Predictable alphabetical sequence detected.
```

## &#x20;Scoring Algorithm

SecurePass uses a custom, rule-based educational scoring model.

| Condition                             | Points |
| ------------------------------------- | -----: |
| At least 8 characters                 |    +20 |
| At least 12 characters                |    +20 |
| Contains uppercase letters            |    +15 |
| Contains lowercase letters            |    +15 |
| Contains digits                       |    +15 |
| Contains punctuation                  |    +15 |
| Each adjacent repetition              |     −5 |
| Each qualifying numerical sequence    |    −10 |
| Each qualifying alphabetical sequence |    −10 |

The final score is restricted to the range **0–100**.

**Rating categories:**

- **Weak:** 0–39
- **Moderate:** 40–79
- **High:** 80–100

These categories describe the project's checklist score, not verified real-world password strength.

## &#x20;What I Learned

Building SecurePass helped me practice and strengthen my understanding of:

- Variables, loops, and conditional statements in C
- Strings and character arrays
- User-defined functions and function parameters
- Function declarations, definitions, and return values
- String manipulation using `string.h` and `ctype.h`
- Algorithm development and debugging
- Pattern detection through character comparisons
- Modular programming and code organization
- Basic input validation and standard C compilation

The project gave me an opportunity to apply concepts learned through CS50x to a program developed outside the course assignments.

## &#x20;Important Limitations

SecurePass is an **educational programming project**, not a validated password-security auditing tool.

- Only use fictional test strings. Terminal input is visible while typing.
- The score is based on simple rules and does not reliably measure password entropy, resistance to guessing, or actual security.
- The program does not check breached-password databases, common-password lists, or keyboard patterns.
- Character analysis is designed primarily for basic ASCII input.
- Passwords are not intentionally saved to a file or database.

A high score does not guarantee that a password is secure.

## &#x20;Future Improvements

- Hidden terminal input
- Better handling of input limits and non-ASCII characters
- Detection of common weak patterns
- Improved strength estimation
- Automated unit testing
- Enhanced command-line interface

## &#x20;About the Developer

**Aayushman Singh Thakur**

B.Tech student specializing in Computer Science and Engineering, with interests in cybersecurity, software development, and problem-solving.

SecurePass is my first independent C programming project, built while strengthening my fundamentals through CS50x.

**LinkedIn:** [https://www.linkedin.com/in/aayushman-singh-thakur-aa3b5a439/](https://www.linkedin.com/in/aayushman-singh-thakur-aa3b5a439/)

---

*Built with C, curiosity, and a commitment to learning by doing.*

