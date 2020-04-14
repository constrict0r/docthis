**docthis-sh**
--------------------------------------------------------------

 Generate documentation with Sphinx, from root run: ./docthish.sh.

Globals
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  **PROJECT_PATH**

      Path to the project used as source, defaults to current path.

  **PYTHON_EXEC**

      Python executable to use: python or python3. Empty by default.

  **INSTALL_REQUIREMENT**

      Install requirements or not.

Functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

   **error_message()**

     Shows an error message.

      :Parameters:
         **$1** (*str*) – Error name: custom, execution, path, sudo, <name>.
         **$2** (*str*) – Optional text to use on error messages.

      :Returns:
         0 if successful, 1 on failure.

      :Return type:
         int

   **escape()**

      Escape especial characters.

      The escaped characters are:

       - Period.
       - Slash.
       - Colon.

      :Parameters:
         **$1** (*str*) – Text to escape.

      :Returns:
         The escaped input.

      :Return type:
         str

   **generate()**

      Setup Sphinx and generate html and rst documentation, generates a single
      README-single file that can be used on github or gitlab.

      :Parameters:
         **$1** (*str*) – Optional project path. Default to current path.
         **$2** (*str*) – Optional CI service to use for generating a coverage badge.

      :Returns:
         0 if successful, 1 on failure, generates *README-single* file
         on project's root directory.

      :Return type:
        int

   **generate_rst()**

      Generate rst documentation using sphinx.

      This function will extract each filename to include from the index file and concatenate
      all files into a single README-single file.

      This function assumes:
        - The project has a file structure as created by generate().
        - The index file contains the *toctree* directive.

      :Parameters:
         **$1** (*str*) – Optional project path. Default to current path.
         **$2** (*str*) – Optional CI service to use for generating a coverage badge.

      :Returns:
         0 if successful, 1 on failure, generates *README-single* file
         on project's root directory.

      :Return type:
         int

   **get_author()**

      Get the author's name.

      :Parameters:
         **$1** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo author's name.

      :Return type:
         str

   **get_doc_path()**

      Obtains the project's documentation directory.

      This function tries:

       - Read a .readthedocs.yml file.
       - Search for the ./docs directory.
       - Default to ./doc directory.

      :Parameters:
         **$1** (*str*) – Optional project path. Default to current path.

      :Returns:
         0 if successful, 1 on failure, echo path to the documentation
	 directory.

      :Return type:
         str

   **get_gitlab_ci_url()**

      Get the continuous integration repository URL for Gitlab.

      If the URL cannot be found, then a default URL is returned.

      This function assumes:
         - The project has a file structure as created by generate().

      :Parameters:
         **$1** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo Gitlab CI URL.

      :Return type:
         str

   **get_gh_cover_url()**

      Get the coverage badge URL for Github (coveralls).

      :Parameters:
         **$1** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo Github coverage (coveralls) URL.

      :Return type:
         str

   **get_gl_cover_url()**

      Get the coverage badge URL for Gitlab.

      :Parameters:
         **$1** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo Gitlab.

      :Return type:
         str

   **get_img_url()**

      Get the images repository URL.

      If the URL cannot be found, then a default Github URL is returned.

      This function assumes:
         - The project has a file structure as created by generate().

      :Parameters:
         **$1** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo images repository URL.

      :Return type:
         str

   **get_parameters()**

      Get bash parameters.

      Accepts:

       - *h* (help).
       - *i* (install requirements).
       - *p* <project_path>.
       - *x* <python_executable>.

      :Parameters:
         **$@** (*str*) – Bash arguments.

      :Returns:
         0 if successful, 1 on failure. Set globals.

      :Return type:
         int

   **get_project()**

      Get the project's name.

      :Parameters:
         **$1** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo project's name.

      :Return type:
         int

   **get_python_exec()**

      Obtains the Python executable to use: python or python3.

      This function tries:
        - Use the $PYTHON_EXEC variable if not empty and like 'python'.
        - Use 'python3' if available.
        - Use 'python' if available.

      :Parameters:
         No arguments.

      :Returns:
         0 if successful, 1 on failure, echo project's name.

      :Return type:
         int

   **get_travis_ci_url()**

      Get the continuous integration repository URL for Travis.

      If the  URL cannot be found, then a default URL is returned.

      This function assumes:
        - The project has a file structure as created by generate().

      :Parameters:
         **$1** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo Travis CI URL.

      :Return type:
         str

   **get_variable()**

      Get a variable from the configuration file.

      This function assumes:
        - The project has a file structure as created by generate().

      :Parameters:
         **$1** (*str*) – Required variable name.
         **$2** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo variable value.

      :Return type:
         str

   **get_variable_from_conf()**

      Get a raw variable from the configuration file.

      :Parameters:
         **$1** (*str*) – Required variable name.
         **$2** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo variable value.

      :Return type:
         str

   **get_variable_from_conf()**

      Get a raw variable from the configuration file.

      :Parameters:
         **$1** (*str*) – Required variable name.
         **$2** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo variable value.

      :Return type:
        str

   **get_variable_line()**

      Get a matching line from the configuration file.

      :Parameters:
         **$1** (*str*) – Required variable name.
         **$2** (*str*) – Path to the configuration file.

      :Returns:
         0 if successful, 1 on failure, echo variable value.

      :Return type:
         str

   **help()**

      Shows help message.

      :Parameters:
         Function has no arguments.

      :Returns:
         0 if successful, 1 on failure.

      :Return type:
         str

   **install_apt()**

      Installs Apt packages.

      :Parameters:
         **$1** (*str*) – List of packages name to install, must be
                          space-separated.

      :Returns:
         0 if successful, 1 on failure.

      :Return type:
         int

   **install_pip()**

      Installs Python packages via pip.

      This function ensures that Python, Pip and Setuptools are installed
      and then installs all required packages.

      You can pass to this function:
      - A filepath to a requirements*.txt file to be installed.
      - A filepath to directory containing requirements*.txt files to install.
      - A single package name.

      If this function is called without passing any argument to it,
      it will search for requirements*.txt files on the to current path.

      This function expects that each requirements filename has the text
      'requirements' included on it and to have the .txt extension.

      This functions will always check for Python, Pip and Setuptools to be
      installed and will try to install them if not present.

      Each package will be checked to see if its installed, if not installed
      then this function proceeds to install it.

      :Parameters:
         **$1** (*str*) – Optional file path or single package name.

      :Returns:
         0 if successful, 1 on failure.

      :Return type:
         int

   **main()**

      Generate documentation using sphinx.

      Generates *README-single* rst on project's root directory.

      :Parameters:
         **$@** (*str*) – Bash arguments string.

      :Returns:
         0 if successful, 1 on failure.

      :Return type:
         int

   **readthedocs_to_rst()**

      Replace reference from readthedocs format to standard rst.

      See `this link <https://github.com/constrict0r/images>`_ for an example
      images repository.

      :Parameters:
         **$1** (*str*) – Path to file where to apply replacements.

         **$2** (*str*) – Optional component name to use in replacements.

      :Returns:
         0 if successful, 1 on failure, modifies passed file.

      :Return type:
         int

   **replace_tokens()**

      Given an input string, replaces the tokens:

        - author
        - project
        - _url
        - _link
        - _badge

      This function is recursive, this means that it will not
      stop replacing tokens until there is no token left.


      :Parameters:
         **$1** (*str*) – Input text where to apply the substitutions.

      :Returns:
         0 if successful, 1 on failure, echo the resulting string.

      :Return type:
         str

   **sanitize()**

      Sanitize input.

      The applied operations are:

        - Trim.
        - Remove unnecesary slashes.

      :Parameters:
         **$1** (*str*) – Text to sanitize.

      :Returns:
         The sanitized input.

      :Return type:
         str

   **trim()**

      Trim whitespace at the beggining and end of a string.

      :Parameters:
         **$1** (*str*) – Text where to apply trim.

      :Returns:
         The trimmed input.

      :Return type:
         str

   **validate()**

      Apply validations.

      The validation categories are:
        - install: Verifies if the current user is capable of installed the given requirement.
        - sudo: Verifies if the current user can obtain administrative permissions.
        - package-name: Verifies if a specific package is installed via apt or pip.

      This function assumes that everything that is not one of the categories
      is a package name.

      :Parameters:
         **$1** (*str*) – A category or a package name.

      :Returns:
         true if valid, false otherwise.

      :Return type:
         str

   **validate_apt**

      Determines if a package is installed via Apt.

      :Parameters:
         **$1** (*str*) – The package name.

      :Returns:
         true if installed via apt, false otherwise.

      :Return type:
         str

   **validate_pip**

      Determines if a package is installed via pip.

      :Parameters:
         **$1** (*str*) – The package name.

      :Returns:
         true if installed via pip, false otherwise.

      :Return type:
         str

   **validate_pip_installed()**

      Verifies if pip is installed.

      :Parameters:
         No arguments.

      :Returns:
         true if installed, false otherwise.

      :Return type:
         str
