# 🧱 SOLID Principles — Ex-Code Academy Session

This repository contains C# code examples for all five SOLID design principles.
Each principle has two files: a ❌ **bad (violating)** example and a ✅ **good (fixed)** example.

---

## 📂 Structure

```
📁 S-SingleResponsibility/
   ├── Bad_UserService.cs
   └── Good_UserService.cs

📁 O-OpenClosed/
   ├── Bad_AreaCalculator.cs
   └── Good_AreaCalculator.cs

📁 L-LiskovSubstitution/
   ├── Bad_Bird.cs
   └── Good_Bird.cs

📁 I-InterfaceSegregation/
   ├── Bad_IWorker.cs
   └── Good_IWorker.cs

📁 D-DependencyInversion/
   ├── Bad_Switch.cs
   └── Good_Switch.cs
```

---

## 📖 Principles

| Letter | Principle | One-liner |
|--------|-----------|----------|
| **S** | Single Responsibility | One class, one job |
| **O** | Open/Closed | Open for extension, closed for modification |
| **L** | Liskov Substitution | Subclasses must be replaceable by their parent |
| **I** | Interface Segregation | Don't force classes to implement unused methods |
| **D** | Dependency Inversion | Depend on abstractions, not concrete classes |

---

> 💡 **Teaching Tip:** For each principle, show the `Bad_` file first and ask students *"What's the problem here?"* — then reveal the `Good_` file.

---

Made with ❤️ by [Ex-Code Academy](https://ex-code.gitbook.io/ex-code-docs/)
