Description
--------------------------------------------------------------

Bash script to quickly add Sphinx capabilities to a project.

It aims to provide an easy and quick way to start writing Sphinx
documentation.

When runned for first time on a new project folder, this script setups Sphinx,
creates new source files and generates documentation from that sources. When
the sources already exists this script only generates documentation without
adding any file.

Assuming the current directory is named *example*, the generated directory
layout is shown below:

.. code-block:: bash

 example
 ├── doc
 │   ├── requirements.txt
 │   └── source
 │       ├── author
 │       ├── compatibility
 │       ├── conf.py
 │       ├── description
 │       ├── index
 │       ├── license
 │       ├── links
 │       ├── requirement
 │       ├── _static
 │       ├── _templates
 │       ├── usage
 │       └── variable
 ├── docthis.sh
 ├── README
 └── .readthedocs.yml

Additionally to the documentation generated using the standard *html* and
*rst* Sphinx builders, a  single *rst* file named *README-single* is created on
the project's root folder.