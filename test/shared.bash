# From root folder run: ./testme.sh -d.

setup() {
    # Set globals.
    CURRENT_PATH=${BATS_TEST_DIRNAME%/*}

    # Source docthis script.
    source $CURRENT_PATH/docthis.sh

    DOC_PATH=$(get_doc_path $CURRENT_PATH)

    # Ensure clean test enviroment.
    rm -rf /tmp/documentation
    rm -rf /tmp/docthis.sh
    apt purge -y python python-minimal python-pip

    # Install requirements.
    apt install -y sudo
    INSTALL_REQUIREMENT=true
    run install_pip $DOC_PATH
    INSTALL_REQUIREMENT=false

    # Get python executable.
    PY_EX=$(get_python_exec)

    # Handle test user.
    # Remove non-sudoer user.
    /usr/sbin/userdel testuser &>/dev/null && rm -rf /home/testuser &>/dev/null

    # Create non-sudoer user.
    /usr/sbin/useradd -m -d /home/testuser -g users -s /bin/bash testuser &>/dev/null

    # Kick-out non-sudoer user from sudoers group (ensure clean enviroment).
    run /usr/sbin/deluser testuser sudo &>/dev/null

    # Copy docthis script to /tmp  (prevents file not found on Travis-CI).
    cp $CURRENT_PATH/docthis.sh /tmp/docthis.sh
    chmod a+rwx /tmp/docthis.sh
}

teardown() {
    # Cleanup files.
    rm -rf /tmp/documentation
    rm -rf /tmp/docthis.sh
    rm -rf /tmp/doc
    rm -rf /tmp/README*.rst

    # Kick-out non-sudoer user from sudoers group.
    run /usr/sbin/deluser testuser sudo &>/dev/null

    # Remove non-sudoer user.
    /usr/sbin/userdel testuser &>/dev/null && rm -rf /home/testuser &>/dev/null

    # Reinstall requirements (some tests uninstall things).
    apt install -y sudo
    INSTALL_REQUIREMENT=true
    run install_pip $DOC_PATH
    INSTALL_REQUIREMENT=false
}
