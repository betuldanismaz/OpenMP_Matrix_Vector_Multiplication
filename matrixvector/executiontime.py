import matplotlib.pyplot as plt

# Data from the table (Execution Times - Seconds)
thread_counts = [1, 2, 4, 8, 16]

# Data sets
static_time = [0.0870001, 0.043, 0.027, 0.016, 0.013]
dynamic_time = [0.079, 0.0679998, 0.0450001, 0.033, 0.023]
guided_time = [0.076, 0.0440001, 0.026, 0.0150001, 0.017]

# Figure size
plt.figure(figsize=(10, 6))

# Plot lines
plt.plot(thread_counts, static_time, marker='o', label='Static Time', linewidth=2, color='tab:blue')
plt.plot(thread_counts, dynamic_time, marker='s', label='Dynamic Time', linewidth=2, color='tab:orange')
plt.plot(thread_counts, guided_time, marker='^', label='Guided Time', linewidth=2, color='tab:green')

# Axis settings and labels
plt.title('Execution Time by Thread Count', fontsize=14)
plt.xlabel('Thread Count', fontsize=12)
plt.ylabel('Time (Seconds)', fontsize=12)

# Show only table values on x-axis
plt.xticks(thread_counts)

# Starting y-axis from zero makes the graph more readable
plt.ylim(0, 0.10)

# Add grid and legend
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend(fontsize=11)

# Display the plot
plt.show()