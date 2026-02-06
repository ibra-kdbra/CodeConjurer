# Wiki Documentation Source

This directory contains the source files for the [CodeConjurer GitHub Wiki](https://github.com/ibra-kdbra/CodeConjurer/wiki).

## 📂 Wiki Pages

| File | Description |
|------|-------------|
| `Home.md` | Main wiki homepage |
| `Project-Overview.md` | Complete list of all projects |
| `Getting-Started.md` | How to clone, build, and run projects |
| `Project-Categories.md` | Projects organized by category |
| `Contributing.md` | Contribution guidelines |
| `_Sidebar.md` | Wiki sidebar navigation |

## 🚀 How to Populate the GitHub Wiki

GitHub wikis are stored in a separate repository. Follow these steps to populate the wiki:

### Option 1: Manual Copy (Recommended for First-Time Setup)

1. **Go to your repository's Wiki tab**
   - Navigate to https://github.com/ibra-kdbra/CodeConjurer/wiki
   - Click "Create the first page" if the wiki is empty

2. **Create each page manually**
   - Create a page for each `.md` file in this directory
   - Copy the content from the corresponding file
   - The page name should match the filename (without `.md`)

### Option 2: Clone and Push (For Bulk Updates)

1. **Clone the wiki repository**
   ```bash
   git clone https://github.com/ibra-kdbra/CodeConjurer.wiki.git
   cd CodeConjurer.wiki
   ```

2. **Copy the wiki files**
   ```bash
   # Assuming you're in the wiki repo and the main repo is adjacent
   cp ../CodeConjurer/wiki/*.md .
   ```

3. **Commit and push**
   ```bash
   git add .
   git commit -m "Update wiki content"
   git push
   ```

### Option 3: Using a Script

Create a script to automate the sync:

```bash
#!/bin/bash
# sync-wiki.sh

# Clone wiki if not exists
if [ ! -d "CodeConjurer.wiki" ]; then
    git clone https://github.com/ibra-kdbra/CodeConjurer.wiki.git
fi

# Copy files
cp wiki/*.md CodeConjurer.wiki/

# Push changes
cd CodeConjurer.wiki
git add .
git commit -m "Sync wiki content from main repo"
git push
```

## 📝 Updating Wiki Content

When updating wiki content:

1. **Edit files in this `wiki/` directory** - This keeps wiki content version-controlled with the main repo
2. **Sync to the GitHub Wiki** - Use one of the methods above to push changes
3. **Review on GitHub** - Check the wiki tab to ensure proper formatting

## 🔗 Wiki Links

In GitHub wikis, links work differently than in regular markdown:

- Use `[Link Text](Page-Name)` instead of `[Link Text](Page-Name.md)`
- Page names are case-sensitive
- Spaces in page names become dashes in URLs

## 💡 Tips

- The `_Sidebar.md` file creates a navigation sidebar that appears on all wiki pages
- The `Home.md` file is the wiki homepage
- Images can be added to the wiki by uploading them through the GitHub wiki interface
- Use relative links to reference other wiki pages

## 🔄 Keeping Wiki in Sync

Consider setting up a GitHub Action to automatically sync wiki content when files in this directory change. Example workflow:

```yaml
name: Sync Wiki

on:
  push:
    paths:
      - 'wiki/**'
    branches:
      - main

jobs:
  sync:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      
      - name: Sync Wiki
        uses: Andrew-Chen-Wang/github-wiki-action@v4
        with:
          path: wiki
```

---

For questions or issues, please open an issue in the main repository.
