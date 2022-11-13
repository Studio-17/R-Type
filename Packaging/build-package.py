#!/usr/bin/env python3

import os
import re


def build_package():
    package_directory = "Packaging/rtype_1.0.0-1_ubuntu2204"

    os.makedirs(package_directory + "/usr/bin/Assets", exist_ok=True)

    os.system('mkdir -p Packaging/rtype_1.0.0-1_ubuntu2204/usr/bin/Assets')
    os.system("cp -r Assets/ Packaging/rtype_1.0.0-1_ubuntu2204/usr/bin/")

    if os.path.isfile("Builds/Client/r-type_client"):
        os.system("cp Builds/Client/r-type_client Packaging/rtype_1.0.0-1_ubuntu2204/usr/bin/")

    config_files_directory = package_directory + "/usr/bin/Assets/Configs/"
    command_list = list()

    for item in os.listdir(config_files_directory):
        if item.endswith(".json"):
            command_list.append((config_files_directory + item).lstrip('Packaging/rtype_1.0.0-1_ubuntu2204 Packaging'))
            with open(config_files_directory + item, 'r') as file:
                content = file.read()
                file.close()
                updated_content = re.sub('Assets', '/usr/bin/Assets', content, flags=re.M)
            with open(config_files_directory + item, 'w') as file:
                file.write(updated_content)
                file.close()

    application_command = "Exec=/usr/bin/r-type_client " + " ".join(command_list) + "\n"
    application_filepath = package_directory + "/usr/share/applications/rtype.desktop"

    if os.path.isfile(application_filepath):
        with open(application_filepath, 'w') as file:
            file.write("\n")
            file.write("[Desktop Entry]\n")
            file.write("Version=1.0.0\n")
            file.write("Name=RType\n")
            file.write("Comment=A replica of the famous R-Type game\n")
            file.write(application_command)
            file.write("Icon=/usr/share/icons/r-type_icon.png\n")
            file.write("Terminal=true\n")
            file.write("Type=Application\n")
            file.write("Categories=Games;\n")
            file.write("Keywords=RType;\n")
            file.close()

    os.chdir(os.getcwd() + "/Packaging/")

    if os.path.isfile("rtype_1.0.0-1_ubuntu2204.deb"):
        os.remove("rtype_1.0.0-1_ubuntu2204.deb")

    os.system("dpkg-deb --build rtype_1.0.0-1_ubuntu2204/")

    return 0


build_package()
