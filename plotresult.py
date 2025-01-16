import pandas as pd
import matplotlib.pyplot as plt
df=pd.read_csv('linear_search_results.csv')
size=df['Size']
best_case=df['Best Case']
avg_case=df['Average Case']
worst_case=df['Worst Case']

plt.figure(figsize=(10,6))
plt.plot(size,best_case,label='Best Case',marker='*')
plt.l:\DSA\Basicsplot(size,avg_case,label='Average Case',marker='o')
plt.plot(size,worst_case,label='Worst Case',marker='o')
plt.xlabel('Input size (n)')
plt.ylabel('No. of Comparisons made')
plt.title('Linear search: Best Worst & Average case')
plt.legend()
plt.grid(True)
plt.show()