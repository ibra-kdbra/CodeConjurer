# Contributing

Thank you for your interest in contributing to CodeConjurer! This guide will help you get started.

## 📋 Ways to Contribute

There are many ways to contribute to this project:

1. **🐛 Report Bugs** - Found a bug? Open an issue!
2. **💡 Suggest Features** - Have an idea? We'd love to hear it!
3. **📝 Improve Documentation** - Help make docs clearer
4. **🔧 Fix Bugs** - Submit a fix for a known issue
5. **✨ Add Features** - Implement new functionality
6. **🧪 Add Tests** - Improve test coverage
7. **🎨 Improve Code** - Refactor or optimize existing code

## 🚀 Getting Started

### 1. Fork the Repository

Click the "Fork" button on the [repository page](https://github.com/ibra-kdbra/CodeConjurer).

### 2. Clone Your Fork

```bash
git clone https://github.com/YOUR-USERNAME/CodeConjurer.git
cd CodeConjurer
```

### 3. Create a Branch

```bash
git checkout -b feature/your-feature-name
# or
git checkout -b fix/your-bug-fix
```

### 4. Make Your Changes

- Follow the coding style of the project you're modifying
- Write clear, descriptive commit messages
- Add/update tests if applicable
- Update documentation if needed

### 5. Test Your Changes

Make sure your changes work and don't break existing functionality:

```bash
# Navigate to the project directory
cd <project-name>

# Build the project
mkdir build && cd build
cmake ..
cmake --build .

# Run tests if available
ctest
# or
make test
```

### 6. Push and Create a Pull Request

```bash
git push origin feature/your-feature-name
```

Then go to GitHub and create a Pull Request.

## 📐 Coding Guidelines

### General Guidelines

- **Keep it simple** - Write clear, readable code
- **Be consistent** - Follow existing patterns in the codebase
- **Comment wisely** - Explain *why*, not *what*
- **Test thoroughly** - Make sure your code works

### C++ Style

Most projects in this repository follow these conventions:

```cpp
// Use meaningful names
int playerScore;          // Good
int x;                    // Avoid (unless context is clear)

// Use modern C++ features when appropriate
auto result = calculateScore();
std::vector<int> numbers{1, 2, 3, 4, 5};

// Prefer const correctness
const std::string& getName() const;

// Use RAII for resource management
std::unique_ptr<Resource> resource = std::make_unique<Resource>();

// Braces on same line for functions
void doSomething() {
    // code
}

// Descriptive function names
void calculateTotalScore();   // Good
void calc();                  // Avoid
```

### Commit Messages

Write clear commit messages:

```
✨ Add new feature to Chess Engine

- Implement alpha-beta pruning
- Add move ordering heuristics
- Improve evaluation function

Closes #123
```

**Prefixes you can use:**
- `✨` - New feature
- `🐛` - Bug fix
- `📝` - Documentation
- `🔧` - Configuration
- `♻️` - Refactor
- `🧪` - Tests
- `🎨` - Style/formatting

## 📝 Documentation

When adding new features or projects:

1. **Update the project README** - Add usage instructions
2. **Add code comments** - Explain complex logic
3. **Update wiki pages** - If adding a new project, update:
   - [Project Overview](Project-Overview)
   - [Project Categories](Project-Categories)
3. **Include examples** - Show how to use your code

## 🐛 Reporting Issues

We have several issue templates to help you report issues effectively:

### Available Templates

| Template | Use When |
|----------|----------|
| **[Bug Report](https://github.com/ibra-kdbra/CodeConjurer/issues/new?template=bug_report.md)** | Reporting bugs or unexpected behavior |
| **[Feature Request](https://github.com/ibra-kdbra/CodeConjurer/issues/new?template=feature_request.md)** | Suggesting new features or enhancements |
| **[Question](https://github.com/ibra-kdbra/CodeConjurer/issues/new?template=question.md)** | Asking questions or requesting help |
| **[New Project Proposal](https://github.com/ibra-kdbra/CodeConjurer/issues/new?template=new_project_proposal.md)** | Proposing a new C/C++ subproject |

### Bug Reports

When reporting bugs, please include:

1. **Description** - What happened?
2. **Steps to reproduce** - How can we recreate it?
3. **Expected behavior** - What should have happened?
4. **Environment** - OS, compiler version, etc.
5. **Screenshots** - If applicable

Example issue template:

```markdown
## Bug Description
The game crashes when pressing the 'Escape' key during gameplay.

## Steps to Reproduce
1. Start the game
2. Begin a new game
3. Press Escape key
4. Game crashes

## Expected Behavior
Game should pause and show menu

## Environment
- OS: Ubuntu 22.04
- Compiler: GCC 11.3
- SFML Version: 2.5.1

## Error Message
Segmentation fault (core dumped)
```

## 💡 Suggesting Features

For feature requests, please describe:

1. **The problem** - What issue does this solve?
2. **Your solution** - How would you implement it?
3. **Alternatives** - What other solutions exist?
4. **Context** - Why is this important?

## ✅ Pull Request Checklist

We use a [Pull Request Template](https://github.com/ibra-kdbra/CodeConjurer/blob/main/.github/PULL_REQUEST_TEMPLATE.md) that includes a checklist to ensure quality contributions.

Before submitting a PR, ensure:

- [ ] Code compiles without warnings
- [ ] All tests pass
- [ ] New code has appropriate tests
- [ ] Documentation is updated
- [ ] Commit messages are clear
- [ ] Branch is up to date with main
- [ ] PR description explains the changes

## 📜 Code of Conduct

- Be respectful and inclusive
- Provide constructive feedback
- Focus on the code, not the person
- Help newcomers feel welcome

## 🙏 Thank You!

Every contribution, no matter how small, helps make this project better. Thank you for being part of the CodeConjurer community!

---

Questions? Open an issue or reach out to the maintainers.
