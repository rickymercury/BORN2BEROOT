1) Open a terminal and run the command:

lsblk

    🧠 What is lsblk?
    The lsblk command displays information about all available block devices (disks), such as their size and mount points, in a tree format.

2) Installing Sudo and Configuring User and Groups

Switch to Root User and Install Sudo Begin by switching to the root user to install sudo. Enter su - in the bash prompt and provide the root password. Additionally, install VIM to configure some files. 

2.1) Installing sudo

2.1.1) Switch to root and its environment via su -.

$ su -
Password:
#

2.1.2) Install sudo via apt install sudo.

# apt-get update
# apt-get install vim
# apt install sudo

2.1.3) Verify whether sudo was successfully installed via dpkg -l | grep sudo.

# dpkg -l | grep sudo

2.1.4) Reboot the machine to apply changes:

# sudo reboot

2.1.5) After the reboot, log in as the root user again:

# su-

2.1.6) Verify that sudo was installed successfully:

# sudo -V

2.2) Configuring User and Groups

2.2.1) Create a new user named <youruser> (this might give an error if the user was already created during Debian installation):

# sudo adduser <youruser>

2.2.2) Create a new group called <youruser42>:

# sudo addgroup <youruser42>

2.2.3) Check if the group user42 was created correctly:

# getent group user42

2.2.4) Add the <user> to the <user42> group:

# sudo adduser user user42

2.2.5) Add the <user> to the sudo group:

# sudo adduser user sudo

2.2.6) Verify that the user has been added to both sudo and user42 groups:

# getent group sudo
# getent group user42


3) Installing and Configuring SSH

3.1) Check for available updates:

# sudo apt update

3.2) Install OpenSSH Server:

# sudo apt install openssh-server

Press Y to confirm the installation when prompted.

3.3) Verify whether openssh-server was successfully installed via dpkg -l | grep ssh.

# dpkg -l | grep ssh

3.4) Check SSH Service Status:

# sudo service ssh status

    💡 This should return a status showing that the SSH service is active and running.

3.5) Edit SSH Configuration to customize your SSH settings:

# sudo vim /etc/ssh/sshd_config

3.6) Uncomment and Update Configuration Lines

The # symbol indicates that a line is commented out. Uncomment and update the following lines:

    -> Change #Port 22 to Port 4242

    -> Change #PermitRootLogin prohibit-password to PermitRootLogin no

Save the changes and exit the file.

3.7) Check SSH status again via sudo service ssh status.

# sudo service ssh status

OR

# systemctl status ssh

3.8) Edit the SSH Client Configuration File:

# sudo vim /etc/ssh/ssh_config

Update the following line:

    Change #Port 22 to Port 4242

3.9) Restart the SSH Service To Apply the Changes:

# sudo service ssh restart
# sudo service ssh status

4) Connecting via SSH:

4.1) To connect via SSH, first shut down the virtual machine and go to its settings.

4.2) Configure Network Settings

    Open VirtualBox and select the virtual machine you want to connect to, in this case, Born2beroot.
    Go to Settings
    Go to Network
    Go to Adapter 1
    Change the Attached to setting to Bridged Adapter

    💡 This will allow the VM to use the same network as the host machine.

4.3) sudo reboot to reboot the VM

4.4) Get VirtualMachine IP (in the VM)

# hostname -I

4.5) Open a terminal out of VM and connect to the VM:

# ssh <username>@<VirtualMachine_IP> -p 4242

4.6) Close the connection.

# exit

// fiquei aqui

5) Configuring sudo policies and log

5.1) Create the following file

# touch /etc/sudoers.d/sudo_config

5.2) Return to the terminal outside the VM.
Connect again via SSH

# ssh <username>@<VirtualMachine_IP> -p 4242



4) Installing & Configuring UFW (este passo j'a foi feito)

UFW is a firewall that uses the command line for setting up iptables with a small number of easy commands.

4.1) Install the UFW package by running the following command and typing y when prompted:

# sudo apt-get install ufw

4.2) Enable UFW - Start UFW using the command below. It should display a message indicating that the firewall is active:

# sudo ufw enable

(in case of turn it off we use:
# sudo ufw disable
)

4.3) Allow Connections on Port 4242

Configure the firewall to accept connections on port 4242:

# sudo ufw allow 4242

4.4) Check UFW Status

Verify that everything is configured correctly by checking the status of the firewall:

# sudo ufw status






