<div align="center">

# ⚙️ Operating Systems Algorithms

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=22&pause=1000&color=36BCF7&center=true&vCenter=true&width=600&lines=CPU+Scheduling+Algorithms;Memory+Management+Algorithms;Disk+Scheduling+Algorithms;Deadlock+Avoidance+Algorithms" alt="Typing SVG" />

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/Platform-macOS%20%7C%20Linux-lightgrey?style=for-the-badge)

A curated collection of classic **Operating Systems** algorithms implemented in C and C++ — covering CPU scheduling, memory management, disk scheduling, and deadlock avoidance.

</div>

---

## 📚 Algorithms Included

### 🧠 CPU Scheduling
| Algorithm | File | Language |
|---|---|---|
| First Come First Serve (FCFS) | `fcfs_scheduling.c` | C |
| Shortest Job First (SJF) | `sjf_scheduing.c` | C |
| Priority Scheduling | `priority_scheduling.c` | C |
| Round Robin | `round_robin.c` | C |

### 💾 Memory Management
| Algorithm | File | Language |
|---|---|---|
| LRU Page Replacement | `lru.c` | C |
| FIFO Page Replacement (Demand) | `fifo_d.c` | C |
| FIFO Page Replacement (Preemptive) | `fifo_p.c` | C |
| Optimal Page Replacement | `optimal.c` | C |

### 💿 Disk Scheduling
| Algorithm | File | Language |
|---|---|---|
| SSTF (Shortest Seek Time First) | `sstf.cpp` | C++ |
| (Compiled binary) | `sstf` | — |

### 🔒 Deadlock Avoidance
| Algorithm | File | Language |
|---|---|---|
| Banker's Algorithm | `bankers.cpp` | C++ |

### 🛠️ Utilities
| Program | File | Language |
|---|---|---|
| Sort Array | `sort_array.cpp` | C++ |
| Table Formatter | `table.cpp` | C++ |

---

## 🚀 Getting Started

### Prerequisites
- GCC (for C programs)
- G++ (for C++ programs)

### Compile & Run

**C programs:**
```bash
gcc fcfs_scheduling.c -o fcfs_scheduling
./fcfs_scheduling
```

**C++ programs:**
```bash
g++ bankers.cpp -o bankers
./bankers
```

Replace the filename with any algorithm you want to run.

---

## 📖 Usage

Each program reads its input from **standard input (stdin)**. Follow the on-screen prompts after running the compiled binary. For example:

```bash
$ gcc round_robin.c -o round_robin
$ ./round_robin
Enter number of processes: 4
Enter time quantum: 2
...
```

---

## 🗂️ Project Structure

```
ops/
├── fcfs_scheduling.c
├── sjf_scheduing.c
├── priority_scheduling.c
├── round_robin.c
├── lru.c
├── fifo_d.c
├── fifo_p.c
├── optimal.c
├── sstf.cpp
├── bankers.cpp
├── sort_array.cpp
├── table.cpp
└── README.md
```

---

## 🤝 Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request for:
- New OS algorithms
- Bug fixes or optimizations
- Better input handling / documentation

---

## 👤 Author

**Soman Singhal** — [@somansinghal](https://github.com/somansinghal)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.