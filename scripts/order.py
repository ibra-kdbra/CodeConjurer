#!/usr/bin/env python3
import os, math, re

# 1) configure
README = "README.md"
EXCLUDE = {".git", ".github", "scripts", "__pycache__"}

# 2) collect project directories (top‑level only)
projects = sorted(
    [d for d in os.listdir(".")
     if os.path.isdir(d) and d not in EXCLUDE and not d.startswith(".")],
    key=str.lower
)

# 3) split into 3 roughly even columns
cols = 3
chunk = math.ceil(len(projects)/cols)
columns = [projects[i*chunk:(i+1)*chunk] for i in range(cols)]

# 4) helper to make header range
def hdr(col):
    if not col: return ""
    a, b = col[0][0].upper(), col[-1][0].upper()
    return f"{a}–{b}"

# 5) build the HTML table
lines = ['<table style="width:100%; border-collapse: collapse; border:1px solid #ddd;">',
         "  <thead><tr>"]
for col in columns:
    lines.append(f'    <th style="padding:4px 8px; text-align:center; font-weight:bold; border:1px solid #ddd;">{hdr(col)}</th>')
lines.append("  </tr></thead>\n  <tbody>")

for row in zip(*columns):
    lines.append("    <tr>")
    for cell in row:
        slug = cell.lower().replace(" ", "-")
        lines.append(f'      <td style="padding:4px 8px; text-align:center; border:1px solid #ddd;"><a href="#{slug}">{cell}</a></td>')
    lines.append("    </tr>")
lines.append("  </tbody></table>")

new_toc = "\n".join(lines)

# 6) read, replace between your markers, write back
with open(README, "r", encoding="utf-8") as f:
    content = f.read()

pattern = re.compile(r"(<!-- TOC START -->)(.*?)(<!-- TOC END -->)", re.S)
updated = pattern.sub(rf"\1\n{new_toc}\n\3", content)

with open(README, "w", encoding="utf-8") as f:
    f.write(updated)
