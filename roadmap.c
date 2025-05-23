
Open a terminal and run the command:

# lsblk

What is lsblk?
The lsblk command displays information about all available block devices (disks), such as their size and 
mount points, in a tree format.

1) Boot - Enter Encrypted Disk Password

When you start the virtual machine, it will prompt you to enter the encrypted disk password.
This is the password you set during the installation of Debian. Enter the password to unlock the disk and boot
into the system.

2) Boot -Enter User Credentials

After entering the encrypted disk password, you will be prompted to enter your user credentials.
Enter your username and password to log in to the system.
You will be logged in as the user you created during the installation of Debian.
You will see a bash prompt indicating that you are logged in.
You can now start configuring your system.

In my case the user is rmedeiro 

3) Installing Sudo

Switch to Root User and Install Sudo: Begin by switching to the root user to install sudo. 
Enter su - in the bash prompt and provide the root password. Additionally, install VIM to configure some files. 

2.1) Installing sudo

2.1.1) Switch to root and its environment via su -.

# su -

Password:

*----------------------------------------------------------------------*
| su - : Switch/Log in to root user.                                   |
| su : Switch/Log in to root user without loading the root environment.|
*----------------------------------------------------------------------*

2.1.2) Getting system updates 

# apt-get update -y
# apt-get upgrade -y

*----------------------------------------------------------------------------------------*
| apt-get update -y: Fetching system updates, -y to automate all permission acceptances. |
| apt-get upgrade -y: Upgrading all packages, -y to automate all permission acceptances. |
*----------------------------------------------------------------------------------------*

2.1.3) Install sudo. 

# apt-get install sudo

*-------------------------------------------------------------------------------------------*
| apt-get install sudo: Installing the sudo package to allow users to run commands as root. |
*-------------------------------------------------------------------------------------------*

2.1.4) Rebbot the machine to apply changes:

# sudo reboot

2.1.5) Verify whether sudo was successfully installed

After the reboot, log in as the root user again:

# su-

and check if sudo was installed:

# dpkg -l | grep sudo

*-------------------------------------------------------------------------------------------*
| dpkg -l | grep sudo: Checking if the sudo package is installed.                           |
| dpkg -l: List all installed packages, grep sudo: Filter the list to show only sudo.       |
*-------------------------------------------------------------------------------------------*

2.1.6) CHeck sudo version: 

# sudo -V


2.2) Configuring User and Groups

2.2.1) Adding User to sudo Group 

Create a new user named <youruser> [rmedeiro]

# sudo adduser <youruser>

If already exists, this might give an error if the user was alerady created during Debian installation.

2.2.2) Add the user to the sudo group:

# sudo adduser <youruser> sudo

Alternatively, add user to sudo group via:

# usermod -aG sudo <youruser>

*-------------------------------------------------------------------------------------------------*                   |
| usermod -aG sudo <youruser>: Adds the user <youruser> to the "sudo" group while keeping their   |
|                              existing group memberships intact.                                 | 
|                              Instead of granting individual permissions to each user, groups    | 
|                              act as containers, categorizing users based on their roles,        |  
|                              responsibilities, or access levels. usermod modifies user accounts.|
|																								  |
| 								-a: Append the user to the group.								  |
| 								-G: Specify the group to which the user should be added.          |
*-------------------------------------------------------------------------------------------------*

2.2.3) Verify if the user was successfully added to sudo group:

# getent group sudo

2.2.4) Create a new group called user42:

# sudo addgroup user42   or   # sudo groupadd user42

2.2.5) Add <youruser> to the "user42" group:

# sudo adduser <youruser> user42   or   # sudo usermod -aG user42 <youruser>

2.2.6) Check if the group user42 was created correctly:

# getent group user42

2.2.7) Reboot the system to apply changes:

# sudo reboot

2.2.8) Verify sudopowers via: 

# sudo -v

NOTE: To delete a certain group we use:  # sudo delgroup <groupname> 
NOTE: To delete a certain user we use:  # sudo deluser <username>
NOTE: To see which groups the user account belongs to we use: # groups <username>


3) Installing Git and Vim: 

# sudo apt-get install vim -y
# sudo apt-get install git -y


4) Installing and Configuring SSH

SSH stands for "Secure Shell."
The SSH protocol was designed as a secure alternative to unsecured remote shell protocols. 
It utilizes a client-server, in which clients and servers communicate via a secure channel.
This is an important step for remote management and secure communication between computers 
over an unsecured network. SSH provides a secure way to access and control your virtual 
machine remotely.

4.1) Check for available updates:

# sudo apt-get update

3.2) Install OpenSSH Server:

# sudo apt-get install openssh-server

It will install the component (openssh-server) that is responsible for allowing secure remote 
access to your machine.

Press Y to confirm the installation when prompted.

3.3) Verify whether openssh-server was successfully installed via dpkg -l | grep ssh.

# dpkg -l | grep ssh

3.4) Check SSH Service Status - check if the package was successfully installed and the SSH service is running:

# sudo service ssh status   or    # sudo systemctl status ssh

Systemctl status shows detailed information about whether a service is running, its current state, and recent 
log messages related to the service. Here, we are checking the status of the SSH service on the system.

This should return a status showing that the SSH service is active and running.

3.5) Edit SSH Configuration to customize your SSH settings:

You need root privileges to edit the SSH configuration file. Switch to root using -> su. 
Then, open the SSH configuration file using a text editor like vim:

# sudo vim /etc/ssh/sshd_config

Editing the ssh server configuration file. sshd for SSH daemon is a background process or service that runs on
a server to handle incoming SSH connections. It’s responsible for handling incoming SSH connections, and its 
behavior is determined by the settings in this configuration file. Some of the configurations include Port Number,
PermitRootLogin, PasswordAuthentication, PubkeyAuthentication and AllowUsers or AllowGroups.

3.6) Uncomment and Update Configuration Lines

The # symbol indicates that a line is commented out. Uncomment and update the following lines:

-> Change #Port 22 to Port 4242

-> Change #PermitRootLogin prohibit-password to PermitRootLogin no

Save the changes and exit the file.

/* 
3.8) Edit the SSH Client Configuration File:

# sudo vim /etc/ssh/ssh_config

Update the following line:

    Change #Port 22 to Port 4242
*/

3.9) Restart the SSH Service To Apply the Changes:

# sudo systemctl restart ssh    or    # sudo service ssh restart

And then check SSH status again via:

# sudo service ssh status     or      # systemctl status ssh


4) Connecting via SSH:

4.1) To connect via SSH, first shut down the virtual machine and go to its settings.

	Configure Network Settings

    Open VirtualBox and select the virtual machine you want to connect to, in this case, Born2beroot.
    Go to Settings
    Go to Network
    Go to Adapter 1
    Change NAT to Bridged Adapter. 

This will allow the VM to use the same network as the host machine.

4.3) # sudo reboot to reboot the VM

4.4) Get VirtualMachine IP (in the VM)

# hostname -I

4.5) Open a terminal out of VM and connect to the VM:

# ssh <username>@<VirtualMachine_IP> -p 4242

Note: To close the connection:  # exit     or     # logout


5) Configuring sudo policies (sudoers file) and log (User privileges)

5.1) Create a directory for the sudo log file:

# cd ~/../
# cd var/log
# mkdir sudo

NOTE: Till here, its the same as creating ->  sudo mkdir /var/log/sudo

NOTE: cd /var/log - Access the location where log files are stored, providing information 
      about system events, services, processes.

5.2) Create the sudo log file:

NOTE: Each action using sudo has to be archived, both inputs and outputs. To do so, create a 
      folder (name it sudo for clarity), then create a file.log, and save the path to that file: 

# cd sudo
# touch sudo.log
# cd ~/../

5.4) Configuring the Sudoers Group

To open to Sudoers file.

# sudo visudo   or   # sudo vim /etc/sudoers

Access the sudoers file, that is responsible for defining the rules and permissions that determine 
which users or groups are allowed to execute commands with elevated privileges using the sudo command.

5.5) Edit your sudoers file by adding the rest of the defaults so it should read like this:

Defaults  secure_path  (add :/snap/bin in the end of the path)
Defaults  badpass_message="Wrong Password!"
Defaults  passwd_tries=3
Defaults  iolog_dir="/var/log/sudo"
Defaults  logfile="/var/log/sudo/sudo.log"
Defaults  log_input
Defaults  log_output
Defaults  requiretty

go to the line where there is root	ALL=(ALL:ALL) ALL
put bellow it <username>	ALL=(ALL:ALL) ALL

Save and exit the file.


6) Configuring Password Policy - Setting Up A Strong Password Policy

6.1) Password Max and Min Days 

6.1.1) Configure password age policy via:

# sudo vi /etc/login.defs

Go to line 165 or search for PASS_MAX_DAYS and set: 

PASS_MAX_DAYS 99999 to 30
PASS_MIN_DAYS 0 to 2

To update the password policy run the following command: 

# sudo chage -M 30 <username>   (and # chage -M 30 <username> for root)
# sudo chage -m 2 <username>    (and # chage -m 2 <username> for root)

To confirm that the existing users receive the changes, run the following command:

# sudo chage -l <username>  (and # chage -l <username> for root)

NOTE: REMEMBER TO EXECUTE BOTH COMANDS FOR ROOT AS WELL
NOTE: You can use passwd <username> to change the password of a user. 

6.2) Password Quality - Password Strength

6.2.1) Install PAM package for password quality checking

We are gonna install the Pluggable Authentication Module (PAM) package, which is a framework that allows
the system to enforce authentication policies. It offers features to enforce password policies by configuring
the PAM configuration files on your system.

# sudo apt-get install libpam-pwquality

NOTE: We can verify if the pam package was installed via: # dpkg -l | grep libpam-pwquality

6.2.2) Configure and edit the common-password file

# sudo vim /etc/pam.d/common-password

On the per-package modules section after: "25 password    requisite   pam_pwquality.so retry=3" add:

minlen=10
ucredit=-1
dcredit=-1
lcredit=-1
maxrepeat=3
reject_username
difok=7
enforce_for_root

Save and exit the file. 

Then, # sudo reboot, to reboot the VM and apply the changes.

NOTE: To Test the Password Policy

# sudo passwd <username>
# sudo passwd root


7) Installing & Configuring UFW

UFW is a firewall that uses the command line for setting up iptables with a small number of easy commands.

4.1) Install the UFW package by running the following command and typing y when prompted:

# sudo apt-get install ufw

4.2) Enable UFW

Start UFW using the command below. It should display a message indicating that the firewall is active:

# sudo ufw enable

NOTE: in case of turn it off we use: # sudo ufw disable
NOTE: To show status of ufw and allowed ports we use: sudo ufw status numbered
NOTE: To delete a rule we use: # sudo ufw delete <rule number>

4.3) Allow Connections on Port 4242

Configure the firewall to accept connections on port 4242:

# sudo ufw allow 4242

4.4) Check UFW Status

Verify that everything is configured correctly by checking the status of the firewall:

# sudo ufw status




