<h1 align="center">♟️ push_swap – Sorting Algorithm Project (42 / 1337 School) ♟️</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge">
  <img src="https://img.shields.io/badge/Algorithm-Turk%20Method-orange?style=for-the-badge">
  <img src="https://img.shields.io/badge/Project-Push_swap-purple?style=for-the-badge">
</p>

<p style="font-size:17px;">
This project implements a custom sorting algorithm using two stacks <strong>A</strong> and <strong>B</strong>.  
The goal is to sort integers with the minimum number of operations.  
This README explains the <strong>Turk Algorithm</strong> used for sorting up to 100 numbers, matching the exact file structure of this repository.
</p>

<hr>

<h2 align="center">📌 Project Requirements</h2>

<p>The following operations are allowed:</p>

<ul>
  <li><b>sa</b> — swap A</li>
  <li><b>sb</b> — swap B</li>
  <li><b>ss</b> — sa + sb</li>
  <li><b>pa</b> — push B → A</li>
  <li><b>pb</b> — push A → B</li>
  <li><b>ra</b> — rotate A</li>
  <li><b>rb</b> — rotate B</li>
  <li><b>rr</b> — ra + rb</li>
  <li><b>rra</b> — reverse rotate A</li>
  <li><b>rrb</b> — reverse rotate B</li>
  <li><b>rrr</b> — rra + rrb</li>
</ul>

<p>No bonus, no visualizer, no forbidden functions. Memory leaks must be avoided.</p>

<hr>

<h2 align="center">🧠 How the Turk Algorithm Works</h2>

<h3>1️⃣ Push most elements from A → B</h3>
<p>
Keep only 3 elements in stack A.  
Push the rest to stack B using <code>pb</code>.
</p>

<h3>2️⃣ Sort the remaining 3 elements</h3>
<p>Use sa, ra, rra to sort 3 numbers easily.</p>

<h3>3️⃣ For each element in B, compute:</h3>

<ul>
  <li><b>target position</b> in A</li>
  <li><b>cost_a</b> → rotations needed in A</li>
  <li><b>cost_b</b> → rotations needed in B</li>
</ul>

<h3>4️⃣ Execute cheapest cost</h3>

<p>
If <code>cost_a</code> and <code>cost_b</code> have:
</p>

<ul>
  <li><b>same sign</b> → use rr or rrr</li>
  <li><b>different signs</b> → rotate independently</li>
</ul>

<p>
Then <b>pa</b> the element to A.
</p>

<h3>5️⃣ Final rotation</h3>
<p>Rotate A until the smallest indexed number is at the top.</p>

<hr>

<h2 align="center">📁 File Structure (Your Repository)</h2>

<pre style="background:#1e1e1e; color:#00e676; padding:15px; border-radius:8px;">
push_swap/
│
├── algo.c
├── check_error.c
├── ft_split.c
├── Makefile
├── operation.c
├── operation2.c
├── operation3.c
├── operation4.c
├── position.c
├── push_swap.c
├── push_swap.h
├── stack.c
├── utils1.c
├── utils2.c
└── utils4.c
</pre>

<hr>

<h2 align="center">🧩 What Each File Does</h2>

<h3>⚙️ algo.c</h3>
<p>Implements the core sorting logic (Turk algorithm, cost analysis, push strategy).</p>

<h3>⚠️ check_error.c</h3>
<p>Validates arguments: duplicates, invalid characters, overflow.</p>

<h3>🔤 ft_split.c</h3>
<p>Custom string splitting for argument parsing.</p>

<h3>🔀 operation.c / operation2.c / operation3.c / operation4.c</h3>
<p>All swap, rotate, reverse rotate and push operations.</p>

<h3>📍 position.c</h3>
<p>Computes target positions, indexing, and correct insertion points on A.</p>

<h3>♟️ stack.c</h3>
<p>Stack utilities: creating nodes, pushing, popping, adding to front/back.</p>

<h3>🧮 utils1.c / utils2.c / utils4.c</h3>
<p>Helper functions: cost calculations, min/max search, clean print helpers, conversions.</p>

<h3>🚀 push_swap.c</h3>
<p>
Main file:  
• Parses inputs  
• Builds stack A  
• Calls the algorithm  
• Frees memory  
</p>

<h3>🛠 Makefile</h3>
<p>Compiles push_swap using -Wall -Wextra -Werror</p>

<hr>

<h2 align="center">📈 Performance (100 Numbers)</h2>

<p>Using the Turk Algorithm, you should expect:</p>

<ul>
  <li>🔥 <b>500–700 moves</b> → excellent</li>
  <li>👌 <b>700–900 moves</b> → good</li>
  <li>⚠️ <b>900–1200 moves</b> → acceptable</li>
  <li>❌ <b>1200+</b> → needs optimization</li>
</ul>

<hr>

<h2 align="center">🧪 How to Compile & Run</h2>

<pre style="background:#1e1e1e; color:white; padding:12px; border-radius:8px;">
make
./push_swap 4 67 3 87 23
</pre>

<p>Checker example:</p>

<pre style="background:#1e1e1e; color:white; padding:12px; border-radius:8px;">
./push_swap 3 2 1 | wc -l
</pre>

<hr>

<h2 align="center">💡 Helpful Tips</h2>

<ul>
  <li>Index values before sorting.</li>
  <li>Always compute the cheapest move from B.</li>
  <li>Use rr / rrr whenever possible.</li>
  <li>Avoid unnecessary pushes.</li>
  <li>Check for memory leaks frequently.</li>
</ul>

<hr>

<h2 align="center">📜 License</h2>

<p style="font-size:16px;">
This README is provided for students of <strong>42 Network / 1337 School</strong>.  
You may freely use it to learn, optimize, or prepare your push_swap project.
</p>

<hr>

<h1 align="center">🚀 Good Luck! Master the Turk Algorithm & Crush Push_swap 💪</h1>
