#!/usr/bin/env python3
"""
README Table of Contents Generator

This script automatically generates and updates the Table of Contents (TOC)
in the README.md file based on project directories in the repository.
"""
import os
import sys
import math
import re
import urllib.parse
from pathlib import Path
from itertools import zip_longest

# Configuration
README = "README.md"
EXCLUDE = {".git", ".github", "scripts", "__pycache__", "wiki"}
# Override mapping: directory name -> desired header display
OVERRIDES = {
    "Dump_c++": "Dump C++",
    # can add any other overrides
}


def display_name(name):
    """Derive a human-friendly display name for TOC entries."""
    if name in OVERRIDES:
        return OVERRIDES[name]
    # Insert spaces before camelCase boundaries, then replace underscores
    s = re.sub(r'(?<=[a-z0-9])(?=[A-Z])', ' ', name)
    s = s.replace('_', ' ')
    return s.strip()


def slugify(name):
    """Create a GitHub-style slug for anchor IDs."""
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


def header_display_from_slug(slug):
    """Convert slug back to a Title Case display without hyphens."""
    disp = slug.replace('-', ' ')
    return disp.title()


def header_range(col):
    """Compute column header ranges (e.g., 'A-M')."""
    if not col:
        return ""
    first = slugify(col[0])[0].upper()
    last = slugify(col[-1])[0].upper()
    return f"{first}–{last}"


def collect_projects(base_path):
    """Collect and return sorted list of project directories."""
    base = Path(base_path)
    if not base.is_dir():
        raise ValueError(f"Base path '{base_path}' is not a valid directory")
    
    projects = sorted(
        [d.name for d in base.iterdir()
         if d.is_dir()
         and d.name not in EXCLUDE
         and not d.name.startswith('.')],
        key=str.lower
    )
    return projects


def build_toc_table(projects):
    """Build HTML table for the Table of Contents."""
    # Split into 3 roughly even columns
    cols = 3
    chunk = math.ceil(len(projects) / cols) if projects else 1
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
    return "\n".join(lines)


def normalize_headers(content):
    """Normalize all headers to slug-based Title Case (no underscores or hyphens)."""
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
    
    return pattern.sub(repl, content)


def update_toc_in_content(content, new_toc):
    """Replace TOC region in content with new TOC."""
    toc_re = re.compile(r"(<!-- TOC START -->)(.*?)(<!-- TOC END -->)", re.S)
    return toc_re.sub(rf"\1\n{new_toc}\n\3", content)


def main():
    """Main entry point for the TOC generator."""
    readme_path = Path(README)
    
    # Verify README exists
    if not readme_path.is_file():
        print(f"Error: {README} not found in current directory", file=sys.stderr)
        sys.exit(1)
    
    try:
        # Collect project directories
        projects = collect_projects('.')
        
        if not projects:
            print("Warning: No project directories found", file=sys.stderr)
        
        # Build new TOC
        new_toc = build_toc_table(projects)
        
        # Read README.md
        content = readme_path.read_text(encoding="utf-8")
        
        # Normalize headers
        content = normalize_headers(content)
        
        # Replace TOC region
        updated = update_toc_in_content(content, new_toc)
        
        # Write back if changed
        if updated != content:
            readme_path.write_text(updated, encoding="utf-8")
            print(f"✅ {README} updated successfully")
        else:
            print(f"ℹ️  {README} already up to date")
            
    except (OSError, ValueError) as e:
        print(f"Error: {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
