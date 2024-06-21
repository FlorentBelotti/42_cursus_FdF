<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>42_cursus_Fil_de_fer</h1>

<p>FdF (Fil de Fer) is a graphical project that involves creating a schematic representation of a terrain in relief. This project is designed to help students learn graphical programming using the MiniLibX library. The final output is a wireframe model of a terrain displayed using isometric projection.</p>

<h2>Table of Contents</h2>
<ul>
    <li><a href="#installation">Installation</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#features">Features</a></li>
    <li><a href="#code-overview">Code Overview</a></li>
    <li><a href="#feedback">Feedback</a></li>
    <li><a href="#thanks">Thanks</a></li>
</ul>

<h2 id="installation">Installation</h2>
<p>To install and run the FdF project, follow these steps:</p>
<ol>
    <li>Clone the repository:</li>
    <pre><code>git clone https://github.com/yourusername/fdf.git</code></pre>
    <li>Navigate to the project directory:</li>
    <pre><code>cd fdf</code></pre>
    <li>Compile the project using the provided Makefile:</li>
    <pre><code>make</code></pre>
</ol>

<h2 id="usage">Usage</h2>
<p>To use the FdF program, run the following command:</p>
<pre><code>./fdf [path_to_fdf_file]</code></pre>
<p>Example:</p>
<pre><code>./fdf 42.fdf</code></pre>

<h2 id="features">Features</h2>
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

<h2 id="code-overview">Code Overview</h2>
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

<h2 id="feedback">Feedback</h2>
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

<section id="thanks">
    <h2>Thanks</h2>
    <p>To <a href="https://github.com/Rrodor">Romeo Rodor (Rrodor)</a>: who took the time to help me understand the Bresenham algorithm, and more generally the logic of projecting points in space.</p>
</body>
</html>
