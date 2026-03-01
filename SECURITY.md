# Security Policy

## Supported Versions

This repository contains multiple independent C/C++ projects at various stages of development. Security updates are provided on a best-effort basis for all actively maintained projects.

| Project Status | Supported |
| -------------- | --------- |
| Active development | ✅ |
| Stable/Complete | ✅ |
| Experimental/Demo | ⚠️ Limited |
| Archived | ❌ |

## Reporting a Vulnerability

We take the security of our code seriously. If you discover a security vulnerability in any of the projects in this repository, please report it responsibly.

### How to Report

1. **Do NOT** disclose the vulnerability publicly until it has been addressed
2. **Open a private security advisory** via GitHub's Security tab, or
3. **Contact the maintainer directly** by [opening a private issue](../../security/advisories/new)

### What to Include

When reporting a vulnerability, please provide:

- **Project/Subproject affected**: Which specific project contains the vulnerability
- **Description**: A clear description of the vulnerability
- **Steps to reproduce**: Detailed steps to reproduce the issue
- **Impact assessment**: What an attacker could potentially achieve
- **Suggested fix** (optional): If you have ideas on how to address it

### What to Expect

- **Acknowledgment**: We will acknowledge receipt of your report within 48 hours
- **Assessment**: We will assess the vulnerability and its impact
- **Timeline**: We aim to address critical vulnerabilities within 7-14 days
- **Credit**: We will credit you in the security advisory (unless you prefer to remain anonymous)

### Scope

This security policy covers vulnerabilities in:

- C/C++ source code
- Build configurations (CMakeLists.txt, Makefiles)
- Scripts and automation tools
- Dependencies included in this repository

### Out of Scope

The following are generally out of scope:

- Vulnerabilities in upstream dependencies (report to the upstream project)
- Vulnerabilities that require physical access to a user's device
- Social engineering attacks
- Denial of service attacks that don't involve code vulnerabilities

## Security Best Practices

When contributing to this repository, please follow these security guidelines:

1. **Avoid hardcoded credentials** - Never commit passwords, API keys, or secrets
2. **Validate input** - Always validate and sanitize user input
3. **Use safe functions** - Prefer safe string functions (e.g., `strncpy` over `strcpy`)
4. **Check buffer sizes** - Prevent buffer overflow vulnerabilities
5. **Handle errors gracefully** - Don't expose sensitive information in error messages
6. **Keep dependencies updated** - Use the latest stable versions of libraries

## Acknowledgments

We appreciate the security research community's efforts in helping keep this project secure. Contributors who report valid security vulnerabilities will be recognized here (with their permission).

---

Thank you for helping keep CodeConjurer and its users safe! 🔐
