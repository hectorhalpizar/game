# VS_2008_Debug_Break_Points.md

## 🛠 Debugging Breakpoints in Visual Studio 2008 (Unit Test + Static Libraries)

### Problem:
> ❌ Breakpoints show:  
> `"The breakpoint will not currently be hit. No executable code is associated with this line."`

This typically happens in **unit test projects** referencing a **static library (`.lib`)**. It may have worked before and suddenly stopped after a rebuild or config change.

---

## ✅ Quick Fix (if using MSTest):

### Use this:

```
Test > Debug All Tests in Test Results
Shortcut: Ctrl + R, Ctrl + D
```

### ❌ Avoid this:

```
Test > Debug > Test in Current Context
Shortcut: Ctrl + R, Ctrl + T
```

⚠️ This often **fails to load symbols from linked libraries**, causing breakpoints to be ignored even if everything seems correct.

> This is likely a **barely known Visual Studio 2008 bug**.  
> It affects symbol loading for test DLLs with linked static `.lib` dependencies.

---

## 🧩 Common Causes and Fixes (Recap)

### 1. PDB Not Loaded

Check via:

Debug > Windows > Modules

Manually load missing `.pdb` if needed.

---

### 2. Compiler/Linker Settings (Library Project)

- `/Zi` debug info
- `/Od` optimization disabled
- `/DEBUG` linker setting
- Strip Private Symbols: leave empty unless needed

Avoid:

/INCREMENTAL:NO with /EDITANDCONTINUE

---

### 3. Multiple Projects = Multiple `.pdb` Files

Ensure your **test DLL loads the correct `.pdb`** from your static library.

---

## 🧪 Optional: Isolated Project Setup

To avoid issues, compile your `.lib` separately and reference it manually in the test project:
- Ensures consistent debug symbols
- Easier cleanup/rebuild
- Better reproducibility

---

## Final Advice

🧠 For Visual Studio 2008 + MSTest + Static Libs:

| Action                            | Works? | Notes                                |
|-----------------------------------|--------|---------------------------------------|
| `Ctrl + R, Ctrl + T`              | ❌     | Breakpoints often not hit            |
| `Ctrl + R, Ctrl + D`              | ✅     | Loads all `.pdb` files properly      |
| `Debug > All Tests in Test Results` | ✅     | Best option for reliable debugging    |

---

