<div align="left">
### 42_cursus_Fil_de_fer![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<div align="left">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

<nav>
    
### Summary![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)

<ul>
    <li><a href="#features">Features</a></li>
    <li><a href="#code-overview">Code Overview</a></li>
    <li><a href="#feedback">Feedback</a></li>
    <li><a href="#thanks">Thanks</a></li>
</ul>
</nav>

### Features![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="features">

<ul>
    <li>Renders a wireframe model of a terrain using isometric projection.</li>
    <li>Supports dynamic window resizing and smooth rendering.</li>
    <li>Includes keyboard and mouse event handling for interactive terrain exploration.</li>
    <li>Bonus features:
        <ul>
            <li>Additional projection modes (e.g., parallel or conic).</li>
            <li>Zoom in and out functionality.</li>
            <li>Translation (panning) of the terrain.</li>
            <li>Rotation of the terrain view.</li>
        </ul>
    </li>
</ul>

<div align="left">

### Code Overview![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="code-overview">

<p>The project is organized into several source files, each handling different aspects of the program:</p>
<ul>
    <li><code>FdF_main.c</code>: Contains the main function and program entry point.</li>
    <li><code>FdF_bresenham.c</code>: Implements the Bresenham line algorithm for drawing lines.</li>
    <li><code>FdF_clear_draw.c</code>: Handles clearing and redrawing the window content.</li>
    <li><code>FdF_isometric.c</code>: Manages the isometric projection calculations.</li>
    <li><code>FdF_offset.c</code>: Deals with adjusting the terrain offset for proper centering in the window.</li>
    <li><code>FdF_line_error.c</code>: Contains functions for handling line errors.</li>
    <li><code>FdF_token_error.c</code>: Contains functions for handling token errors.</li>
    <li><code>Minilibx_creation.c</code>: Initializes the MiniLibX window and related components.</li>
    <li><code>Minilibx_key_handling.c</code>: Manages keyboard inputs and interactions.</li>
    <li><code>FdF_memory_management.c</code>: Manages memory allocation and deallocation.</li>
    <li><code>FdF_node_management.c</code>: Handles the creation and management of nodes in the terrain model.</li>
    <li><code>FdF_parsing.c</code>: Parses the input .fdf file to create the terrain model.</li>
    <li><code>FdF_bresenham_utils.c</code>: Utility functions for the Bresenham line algorithm.</li>
    <li><code>FdF_draw_utils.c</code>: Utility functions for drawing operations.</li>
    <li><code>FdF_list_utils.c</code>: Utility functions for managing linked lists.</li>
    <li><code>FdF_mvt_utils.c</code>: Utility functions for handling movements (translation, rotation).</li>
    <li><code>FdF_size_utils.c</code>: Utility functions for size and scaling operations.</li>
</ul>

<div align="left">

### Feedback![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="feedback">

<p>
    In the curriculum, the FdF and So_Long projects represent our first ventures into graphical projection. An essential skill to acquire here is mastering the MiniLibX, the specified graphics library. For FdF in particular, it is crucial to understand the principles of the point projection algorithm. My project was thus focused on these two main areas.
</p>
<ul>
    <li>
        <p>The process began with parsing the map, a relatively straightforward step thanks to the data manipulation skills acquired early in the 42 curriculum.</p>
    </li>
    <li>
        <p>The next phase involved learning to display graphics via MiniLibX, including handling window macros and pixel-by-pixel rendering.</p>
    </li>
    <li>
        <p>The most complex phase was implementing Bresenham's algorithm for plotting points. Bresenham's algorithm is essential for drawing straight lines on a pixel grid while minimizing rounding errors and using only integer operations for maximum efficiency. Here’s how it works:</p>
        <p><strong>1. Initialization:</strong> Determine the starting point (x0, y0) and the ending point (x1, y1) of the line.</p>
        <p><strong>2. Calculate Differences:</strong> Compute the difference in x:</p>
        <pre><code>Δx = x1 - x0</code></pre>
        <p>and in y:</p>
        <pre><code>Δy = y1 - y0</code></pre>
        <p>Then determine the signs for advancing on the grid (increment or decrement).</p>
        <p><strong>3. Initial Error Determination:</strong> The initial error is defined as:</p>
        <pre><code>Δy - Δx</code></pre>
        <p>for lines that are more horizontal than vertical.</p>
        <p><strong>4. Plotting Loop:</strong> For each x from x0 to x1:</p>
        <ul>
            <li>Plot the pixel at coordinates (x, y).</li>
            <li>Update the error. If the accumulated error exceeds 0, increment y and adjust the error by subtracting:</li>
            <li>Increment x and adjust the error by adding:</li>
        </ul>
    </li>
</ul>
<p>
    This algorithm is adaptive, adjusting the plotting based on the slope of the line to ensure that each segment of the line is as close as possible to the theoretical line.
</p>
<p>
    Ultimately, the FdF project is one of the most demanding of the initial projects in the curriculum, preceding Minishell. I would not recommend it to those who are not particularly interested in algorithmic challenges.
</p>

<div align="left">

### Thanks![---------------------------------------------------](https://raw.githubusercontent.com/andreasbm/readme/master/assets/lines/rainbow.png)
<section id="thanks">

<p>To <a href="https://github.com/Rrodor">Romeo Rodor (Rrodor)</a>: who took the time to help me understand the Bresenham algorithm, and more generally the logic of projecting points in space.</p>

