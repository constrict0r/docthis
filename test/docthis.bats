#!/usr/bin/env bats
#
# From root folder run: ./testme.sh -d.

load shared

@test "Validate setuptools gets uninstalled." {
    # Uninstall Setuptools
    apt purge -y ${PY_EX}-setuptools
    $PY_EX -m pip install --upgrade pip
    $PY_EX -m pip uninstall -y setuptools
    [[ $(validate_apt "${PY_EX}-setuptools") == 'false' ]]
    [[ $(validate_pip "setuptools") == 'false' ]]
}

@test "Validate setuptools is installed." {
    [[ $(validate_pip 'setuptools') == 'true' ]]
}

@test "Validate all requirements gets installed." {
    # Uninstall Sphinx.
    $PY_EX -m pip uninstall -y sphinx
    [[ $(validate 'Sphinx') == 'false' ]]

    # Uninstall setuptools.
    apt purge -y ${PY_EX}-setuptools
    [[ $(validate "${PY_EX}-setuptools") == 'false' ]]
    $PY_EX -m pip uninstall -y setuptools
    [[ $(validate 'setuptools') == 'false' ]]

    # Uninstall Pip.
    apt purge -y ${PY_EX}-pip
    run $PY_EX -m pip uninstall -y pip
    [[ $(validate "${PY_EX}-pip") == 'false' ]]

    # Uninstall Python.
    apt purge -y $PY_EX ${PY_EX}-minimal
    [[ $(validate "$PY_EX") == 'false' ]]

    # Install requirements.
    INSTALL_REQUIREMENT=true
    install_pip $DOC_PATH
    INSTALL_REQUIREMENT=false

    # Verify sudo is installed.
    [[ $(validate 'sudo') == 'true' ]]

    # Validate python is installed.
    [[ $(validate "$PY_EX") == 'true' ]]

    # Verify pip is installed.
    [[ $(validate "${PY_EX}-pip") == 'true' ]]

    # Verify setuptools is installed.
    [[ $(validate 'setuptools') == 'true' ]]

    # Verify sphinx is installed.
    [[ $(validate 'Sphinx') == 'true' ]]
}

@test "Validate install_pip single package." {
    $PY_EX -m pip uninstall -y sphinx
    run install_pip 'sphinx'
    [[ $(validate_pip 'sphinx') == 'true' ]]
}

@test "Validate install_pip single file." {
    $PY_EX -m pip uninstall -y sphinx
    install_pip $DOC_PATH/requirements.txt
    [[ $(validate_pip 'sphinx') == 'true' ]]
}

@test "Validate install_pip single directory." {
    $PY_EX -m pip uninstall -y sphinx
    install_pip $DOC_PATH
    [[ $(validate_pip 'sphinx') == 'true' ]]
}

@test "Validate sphinx (Sphinx) is installed." {
    [[ $(validate 'Sphinx') == 'true' ]]
}

@test "Validate pip is not installed." {
    apt purge -y ${PY_EX}-pip
    run $PY_EX -m pip uninstall -y pip
    [[ $(validate_pip_installed) == 'false' ]]
}

@test "Validate install py reqs throws error when no-python - non-sudoer." {
    # Uninstall All Python.
    apt purge -y $PY_EX ${PY_EX}-minimal
    [[ $(validate "$PY_EX") == 'false' ]]

    run sudo -u testuser /tmp/docthis.sh -i -p /tmp
    [[ "$output" == *'needs to be installed'* ]]
}

@test "Validate python is not installed." {
    # Uninstall python.
    apt purge -y $PY_EX ${PY_EX}-minimal
    [[ $(validate "$PY_EX") == 'false' ]]
}

@test "Validate python is installed." {
    [[ $(validate "$PY_EX") == 'true' ]]
}

@test "Validate pip is installed." {
   [[ $(validate_pip_installed) == 'true' ]]
}

@test "Validate sphinx (Sphinx) is not installed." {
   $PY_EX -m pip uninstall -y sphinx
   [[ $(validate 'Sphinx') == 'false' ]]
}

@test "Validate install py reqs throws error when no-pip - non-sudoer." {
    # Uninstall Pip.
    apt purge -y ${PY_EX}-pip
    run $PY_EX -m pip uninstall -y pip
    [[ $(validate "${PY_EX}-pip") == 'false' ]]

    run sudo -u testuser /tmp/docthis.sh -i -p /tmp
    [[ "$output" == *'needs to be installed'* ]]
}

@test "Show help with help function." {
    [[ "$(help)" == *'Uses Sphinx'* ]]
}

@test "Show help with docthis script." {
    run ./docthis.sh -h
    [[ "$output" == *'Uses Sphinx'* ]]
}

@test "Get parameters." {
    get_parameters "-p /tmp"
    [[ $PROJECT_PATH == *'/tmp'* ]]
}

@test "Generate documentation." {
    mkdir /tmp/documentation
    ./docthis.sh -p /tmp/documentation
    [[ -f /tmp/documentation/README-single.rst ]]
}
