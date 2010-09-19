#
# Regular cron jobs for the seedkit-viewer package
#
0 4	* * *	root	[ -x /usr/bin/seedkit-viewer_maintenance ] && /usr/bin/seedkit-viewer_maintenance
