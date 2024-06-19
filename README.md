<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>FdF - Wireframe Terrain Renderer</title>
</head>
<body>

<h1>FdF - Wireframe Terrain Renderer</h1>

<p>FdF (Fil de Fer) is a graphical project that involves creating a schematic representation of a terrain in relief. This project is designed to help students learn graphical programming using the MiniLibX library. The final output is a wireframe model of a terrain displayed using isometric projection.</p>

<h2>Table of Contents</h2>
<ul>
    <li><a href="#installation">Installation</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#features">Features</a></li>
    <li><a href="#code-overview">Code Overview</a></li>
    <li><a href="#license">License</a></li>
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

<h2 id="license">License</h2>
<p>This project is licensed under the MIT License. See the LICENSE file for details.</p>

</body>
</html>
