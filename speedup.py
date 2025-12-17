import matplotlib.pyplot as plt

# Data from the table
thread_counts = [1, 2, 4, 8, 16]

static_speedup = [0.919541, 1.860470, 2.962970, 5.000012, 6.153862]
dynamic_speedup = [1.012661, 1.176477, 1.777778, 2.424248, 3.478270]
guided_speedup = [1.052634, 1.818182, 3.076931, 5.333311, 4.705894]

# Figure size
plt.figure(figsize=(10, 6))

# Plot lines
plt.plot(thread_counts, static_speedup, marker='o', label='Static Speedup', linewidth=2)
plt.plot(thread_counts, dynamic_speedup, marker='s', label='Dynamic Speedup', linewidth=2)
plt.plot(thread_counts, guided_speedup, marker='^', label='Guided Speedup', linewidth=2)

# Axis settings and labels
plt.title('Speedup Comparison by Thread Count', fontsize=14)
plt.xlabel('Thread Count', fontsize=12)
plt.ylabel('Speedup', fontsize=12)

# Show only table values on x-axis
plt.xticks(thread_counts)

# Add grid and legend
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=11)

# Display the plot
plt.show()