#!/usr/bin/env python3
import os
import math
import re
import urllib.parse
from itertools import zip_longest

# Configuration
README = "README.md"
EXCLUDE = {".git", ".github", "scripts", "__pycache__"}
# Override mapping: directory name -> desired header display
OVERRIDES = {
    "Dump_c++": "Dump C++",
    # can add any other overrides
}

# Derive a human-friendly display name for TOC entries
def display_name(name):
    if name in OVERRIDES:
        return OVERRIDES[name]
    # Insert spaces before camelCase boundaries, then replace underscores
    s = re.sub(r'(?<=[a-z0-9])(?=[A-Z])', ' ', name)
    s = s.replace('_', ' ')
    return s.strip()

# Create a GitHub-style slug for IDs
def slugify(name):
    base = OVERRIDES.get(name, name)
    # Split camelCase and underscores
    s = re.sub(r'(?<=[a-z0-9])(?=[A-Z])', ' ', base)
    s = s.replace('_', ' ')
    s = s.lower()
    # Remove plus signs
    s = s.replace('+', '')
    # Keep alphanumeric, spaces, hyphens
    s = re.sub(r"[^\w\s-]", "", s)
    # Collapse spaces into hyphens
    return re.sub(r"\s+", "-", s.strip())

# Convert slug back to a Title Case display without hyphens
def header_display_from_slug(slug):
    disp = slug.replace('-', ' ')
    return disp.title()

# Compute column header ranges
def header_range(col):
    if not col:
        return ""
    first = slugify(col[0])[0].upper()
    last = slugify(col[-1])[0].upper()
    return f"{first}–{last}"

# Collect project directories
projects = sorted(
    [d for d in os.listdir('.')
     if os.path.isdir(d)
     and d not in EXCLUDE
     and not d.startswith('.')],
    key=str.lower
)

# Split into 3 roughly even columns
cols = 3
chunk = math.ceil(len(projects) / cols)
columns = [projects[i*chunk:(i+1)*chunk] for i in range(cols)]

# Build HTML table
lines = [
    '<table style="width:100%; border-collapse: collapse; border:1px solid #ddd;">',
    '  <thead>',
    '    <tr>'
]
for col in columns:
    lines.append(
        f'      <th style="padding:4px 8px; text-align:center; font-weight:bold; border:1px solid #ddd;">{header_range(col)}</th>'
    )
lines += ['    </tr>', '  </thead>', '  <tbody>']

for row in zip_longest(*columns, fillvalue=""):
    lines.append('    <tr>')
    for cell in row:
        if cell:
            slug = slugify(cell)
            disp = display_name(cell)
            lines.append(
                f'      <td style="padding:4px 8px; text-align:center; border:1px solid #ddd;"><a href="#' + slug + f'">{disp}</a></td>'
            )
        else:
            lines.append(
                '      <td style="padding:4px 8px; text-align:center; border:1px solid #ddd;"></td>'
            )
    lines.append('    </tr>')
lines += ['  </tbody>', '</table>']
new_toc = "\n".join(lines)

# Read README.md
with open(README, "r", encoding="utf-8") as f:
    content = f.read()

# Normalize all headers to slug-based Title Case (no underscores or hyphens)
pattern = re.compile(r'^(### \[)([^\]]+)(\]\(\./([^\)]+)\))', re.MULTILINE)
def repl(match):
    raw = match.group(4)
    # Decode URL-encoded directory name
    decoded = urllib.parse.unquote(raw)
    # Generate slug and display
    slug = slugify(decoded)
    disp = header_display_from_slug(slug)
    # Keep original raw in link
    return f"### [{disp}](./{raw})"
content = pattern.sub(repl, content)

# Replace TOC region
toc_re = re.compile(r"(<!-- TOC START -->)(.*?)(<!-- TOC END -->)", re.S)
updated = toc_re.sub(rf"\1\n{new_toc}\n\3", content)

# Write back if changed
if updated != content:
    with open(README, "w", encoding="utf-8") as f:
        f.write(updated)
