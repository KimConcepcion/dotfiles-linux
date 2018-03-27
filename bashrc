# ~/.bashrc: executed by bash(1) for non-login shells.

# Note: PS1 and umask are already set in /etc/profile. You should not
# need this unless you want different defaults for root.
# PS1='${debian_chroot:+($debian_chroot)}\h:\w\$ '
# umask 022

# You may uncomment the following lines if you want `ls' to be colorized:
 export LS_OPTIONS='--color=auto'
 eval "`dircolors`"
 alias ls='ls $LS_OPTIONS'
 alias ll='ls $LS_OPTIONS -l'
 alias l='ls $LS_OPTIONS -lA'
 alias shw_me='cat $SLOTS' 
#
# Some more alias to avoid making mistakes:
# alias rm='rm -i'
# alias cp='cp -i'
# alias mv='mv -i'

# User specific aliases and functions
PS1="[ $(tput setaf 170)\uΣ\h$(tput setaf 46) {\W}$(tput sgr0)]>>";
export PS1;

export SLOTS=/sys/devices/platform/bone_capemgr/slots
export PINS=/sys/kernel/debug/pinctrl/44e10800.pinmux/pins
